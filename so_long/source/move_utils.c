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

void	where_maula(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->sprites.max_y)
	{
		x = 0;
		while (x < game->sprites.max_x)
		{
			if (game->map[y][x] == 'P')
				break ;
			x++;
		}
		if (game->map[y][x] == 'P')
			break ;
		y++;
	}
	game->sprites.mx = x;
	game->sprites.my = y;
}

void	num_collect(t_game *game)
{
	int	x;
	int	y;
	int	res;

	res = 0;
	y = 0;
	while (y < game->sprites.max_y)
	{
		x = 0;
		while (x < game->sprites.max_x)
		{
			if (game->map[y][x] == 'C')
				res++;
			x++;
		}
		if (game->map[y][x] == 'C')
			res++;
		y++;
	}
	game->num_c = res;
}
