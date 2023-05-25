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

/*int	move_things(int key)
{
	if (key == 53)
		finish_program();
	//else
		//move(key, sizes);
	return (0);
}*/
