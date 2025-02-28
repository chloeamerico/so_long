/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:40:57 by camerico          #+#    #+#             */
/*   Updated: 2025/02/28 17:57:31 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_initial_position(t_game *game)
{
	int	x;
	int	y;
	int	found = 0; //on pourra supprimer cette variable a la fin

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				found = 1;
			}
			x++;
		}
		y++;
	}
	if (!found) // on pourra suppr apres
		ft_printf("Error: No starting position found in the map\n");
}

//creer une copie de la cap pour ne pas affecter l'initiale
char **copy_map(char **map)
{
	char	**copy;
	int	i; 				//i represente chaque colonne
	int	map_size;

	map_size = 0;
	while (map[map_size])
		map_size++;
	copy = malloc(sizeof (char *) * (map_size + 1)); //+1 pour le pointeur NULL
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map_size)
	{
		copy[i] = ft_strdup(map[i]); // on duplique une chaine de char
		if (!copy[i]) //si ca a echoue, on libere les lignes deja allouees
		{
			while (i > 0)  // Libère les lignes déjà copiées
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

//fonction pour explorer la map
void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'V';
		return ;
	}
	map[y][x] = 'V'; //on marque la case comme deja visitee;
	flood_fill(map, x - 1, y, game); // aller a gauche
	flood_fill(map, x + 1, y, game); // aller a droite
	flood_fill(map, x, y - 1, game); // aller en haut;
	flood_fill(map, x, y + 1, game); // aller en bas;
}

//la fonction qui verifie si le chemin est valide
int	valid_path(t_game *game)
{
	char	**copy;
	int	x;
	int	y;

	copy = NULL; 		// voir si ca peut etre retire
	copy = copy_map(game->map);
	if (!copy)
		return (ft_printf("Error: failed to copy map\n"), 1);
	find_initial_position(game);
	flood_fill(copy, game->player_x, game->player_y, game);
	y = -1;
	while (copy[++y])		// on va parcourir toute la map pour voir s'il reste des C ou E
	{
		x = -1;
		while (copy[y][++x])
		{
			if (copy[y][x] == 'C' || copy[y][x] == 'E')
			{
				ft_printf("Error : map design is invalid\n");
				return (free_map(copy), 1);
			}
		}
	}
	return (free_map(copy), 0);
}

//verifier qu'il existe un chemin valide pour collecter tous les collectibles
// et atteindre la sortie
// fonction flood_fill