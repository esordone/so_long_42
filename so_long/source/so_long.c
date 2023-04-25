/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:19:01 by esordone          #+#    #+#             */
/*   Updated: 2023/04/24 16:55:18 by esordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*void	window()
{
	//cal calcular l'alt i l'ample del joc, de la finestra (.ber)
	init + new_window
}*/

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			IMG_SIZE,
			IMG_SIZE,
			"**** QUARANTAMAULA ****");
	//mlx_hook(game->window, 17, 0, game);
	open_images(game);
	mlx_put_image_to_window(game->mlx, game->window, game->player.action_img, 0, 0);
}

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2 || ft_strrncmp(argv[1], ".ber", 4) == 0)
	{
		ft_printf("Error\n");
		ft_printf("**** Invalid Argument ****\n");
		return (0);
	}
	if (argc == 2)
	{
		game_init(&game);
		mlx_loop(&game);
	}
	return (0);
}
