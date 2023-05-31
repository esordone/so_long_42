/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:38:24 by esordone          #+#    #+#             */
/*   Updated: 2023/05/24 15:40:29 by esordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	finish_program (t_game *game)
{
	if (game)
		mlx_destroy_window (game->window, game->window);
	exit (0);
	return (0);
}

int read_keys(int exit_key, void *data)
{
	t_game *game;

	game = (t_game *)data;
	if (exit_key == ESC || !game)
		finish_program(game->window);
	return (0);
}

void init_player_struct(t_game *game, t_player *sprit, char **map, char *file)
{
	sprit->maula = NULL;
	sprit->roof = NULL;
	sprit->walls = NULL;
	sprit->coll = NULL;
	sprit->exit = NULL;
	sprit->moves = 0;
	sprit->check_x = 0;
	sprit->check_y = 0;
	map = read_map(file);
	if (!map)
		return ;
	sprit->max_x = ft_strlen(map[0]);
	sprit->max_y = num_lines_split(file);
	game->sprites = sprit;
}

/*int	move_things(int key)
{
	if (key == 53)
		finish_program();
	//else
		//move(key, sizes);
	return (0);
}*/
