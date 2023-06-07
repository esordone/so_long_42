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

#include <stdio.h>
#include "../so_long.h"

int	finish_program(t_game *game)
{
	if (game)
		mlx_destroy_window (game->mlx, game->window);
	exit (0);
	return (0);
}

int	read_keys(int exit_key, t_game *data)
{
	if (exit_key == ESC || !data)
		finish_program(data->window);
	return (0);
}

void	init_player_struct(t_game *game, t_player *sprites, \
char **map, char *file)
{
	sprites->maula = NULL;
	sprites->roof = NULL;
	sprites->walls = NULL;
	sprites->coll = NULL;
	sprites->exit = NULL;
	sprites->collect = num_collect(game);
	game->map = read_map(file);
	if (!map)
		return ;
	sprites->max_x = ft_strlen(map[0]);
	sprites->max_y = num_lines_split(file);
	game->size = sprites->max_x * sprites->max_y;
	game->images = calloc (sizeof(void *), game->size);
	if (!game->images)
		return ;
	game->moves = 0;
}

int	move_things(int key, t_game *game)
{
	if (key == 53)
		finish_program(game);
	else
		ft_move(key, game);
	return (0);
}

void	**save_image(t_game *game)
{
	game->images = calloc(sizeof(void *), (game->size));
	if (!game->images)
		return (0);
	return (game->images);
}
