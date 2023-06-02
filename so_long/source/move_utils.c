/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:18:41 by esordone          #+#    #+#             */
/*   Updated: 2023/06/01 11:18:44 by esordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*void	move_empty(t_game *game, t_keypress *type)
{
	keypress->type = start;
	if (game->keypress->type != exit)
		game->keypress->type = roof;
}
*/

void	where_maula(t_game *game, char **map, char *file)
{
	int			x;
	int			y;
	t_player	sprit;

	init_player_struct(game, &sprit, map, file);
	init_sprites(game);
	map = read_map(file);
	if (!map)
		return ;
	y = 0;
	while (y < game->sprites->max_y)
	{
		x = 0;
		while (x < game->sprites->max_x)
		{
			if (map[y][x] == 'P')
				break ;
			x++;
		}
		if (map[y][x] == 'P')
			break ;
		y++;
	}
	game->sprites->mx = x;
	game->sprites->my = y;
}
