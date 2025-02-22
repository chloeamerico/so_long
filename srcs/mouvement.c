/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:35:59 by camerico          #+#    #+#             */
/*   Updated: 2025/02/22 17:09:03 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//keysym = identifiant de chaque touche du clavier
//la fonction explique ce qui sera fait quand une touche sera pressee
int	keypressed(int keysym, t_game *game)
{
	printf("Pressed key : %d\n", keysym);
	if (keysym == XK_Escape)
		destroy(game);
	return (0);
}

// int	keypressed(int keysym, t_game *game)
// {
// 	printf("Pressed key : %d\n", keysym);
// 	// if (keysym == UP)
// 	// 	if (case[x][y - 1] == SOL ou COLL)
// 	// 		change_map(player, x, y - 1); // => game.map[x][y] = G && game.map[x][y - 1] = P
// 	// if (keysym == DOWN)
// 	// 	if (case[x][y + 1] == SOL ou COLL)
// 	// 		change_map(player, x, y + 1); // => game.map[x][y] = G && game.map[x][y + 1] = P
// 	// if (keysym == LEFT)
// 	// 	if (case[x - 1][y] == SOL ou COLL)
// 	// 		change_map(player, x - 1, y); // => game.map[x][y] = G && game.map[x - 1][y] = P
// 	// if (keysym == UP)
// 	// 	if (case[x + 1][y] == SOL ou COLL)
// 	// 		change_map(player, x + 1, y); // => game.map[x][y] = G && game.map[x + 1][y] = P
// 	if (keysym == XK_Escape)
// 		destroy(game);
// 	// print_mouv(++game.mouv_num) // -> printf("Mouvement count : %d\r", game.mouv_num) 
// 	return (0);
// }