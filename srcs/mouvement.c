/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:35:59 by camerico          #+#    #+#             */
/*   Updated: 2025/02/27 16:32:29 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y - 1][x] == '1')
		return ;
	else if (game->map[y - 1][x] == 'C')
		game->collectible_left--;
	else if (game->map[y - 1][x] == 'E')
	{
		if (game->collectible_left != 0)
			return ;
		else
		{
			game->player_y = y - 1;
			ft_printf("Congratulations, you've won\n");
			destroy(game);
		}
	}
	game->map[y][x] = '0';
	game->map[y - 1][x] = 'P';
	game->player_y = y - 1;
	game->nb_mvmt++;
}

void	down(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y + 1][x] == '1')
		return ;
	else if (game->map[y + 1][x] == 'C')
		game->collectible_left--;
	else if (game->map[y + 1][x] == 'E')
	{
		if (game->collectible_left != 0)
			return ;
		else
		{
			game->player_y = y + 1;
			ft_printf("Congratulations, you've won\n");
			destroy(game);
		}
	}
	game->map[y][x] = '0';
	game->map[y + 1][x] = 'P';
	game->player_y = y + 1;
	game->nb_mvmt++;
}

void	left(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x - 1] == '1')
		return ;
	if (game->map[y][x - 1] == 'C')
		game->collectible_left--;
	else if (game->map[y][x - 1] == 'E')
	{
		if (game->collectible_left != 0)
			return ;
		else
		{
			game->player_y = x - 1;
			ft_printf("Congratulations, you've won\n");
			destroy(game);
		}
	}
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'P';
	game->player_x = x - 1;
	game->nb_mvmt++;
}

void	right(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x + 1] == '1')
		return ;
	if (game->map[y][x + 1] == 'C')
		game->collectible_left--;
	else if (game->map[y][x + 1] == 'E')
	{
		if (game->collectible_left != 0)
			return ;
		else
		{
			game->player_y = x + 1;
			ft_printf("Congratulations, you've won\n");
			destroy(game);
		}
	}
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'P';
	game->player_x = x + 1;
	game->nb_mvmt++;
}

//associe une action a chaque touches pressees
//keysym = identifiant de chaque touche du clavier
int	key_hook(int keysym, t_game *game)
{
	static int	prev_mvmt = 0;

	if (keysym == XK_Escape)
		destroy(game);
	else if (keysym == 'w' || keysym == 'W')
		up(game);
	else if (keysym == 's' || keysym == 'S')
		down(game);
	else if (keysym == 'a' || keysym == 'A')
		left(game);
	else if (keysym == 'd' || keysym == 'D')
		right(game);
	if (prev_mvmt < game->nb_mvmt)
	{
		ft_printf("Number of mouvments : %d\n", game->nb_mvmt);
		prev_mvmt = game->nb_mvmt;
	}
	display_map(game);
	return (0);
}
