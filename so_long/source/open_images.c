/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:29:20 by esordone          #+#    #+#             */
/*   Updated: 2023/04/25 10:32:48 by esordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_sprites(t_game *game)
{
	int	img_size;

	game->sprites->maula = mlx_xpm_file_to_image(game->mlx, \
		"images/xpm/Maula1.xpm", &img_size, &img_size);
	game->sprites->roof = mlx_xpm_file_to_image(game->mlx, \
		"images/xpm/Fons.xpm", &img_size, &img_size);
	game->sprites->walls = mlx_xpm_file_to_image(game->mlx, \
		"images/xpm/Wall.xpm", &img_size, &img_size);
	game->sprites->coll = mlx_xpm_file_to_image(game->mlx, \
		"images/xpm/Collectionable.xpm", &img_size, &img_size);
	game->sprites->exit = mlx_xpm_file_to_image(game->mlx, \
		"images/xpm/Exit.xpm", &img_size, &img_size);
	if (!game->sprites->maula || !game->sprites->roof || \
		!game->sprites->walls || !game->sprites->coll || \
		!game->sprites->exit)
		ft_printf("ERROR\nCould not open images");
}

void	game_init(t_game *game, char **map, char *file)
{
	t_map	data;
	t_player sprit;

	init_struct(&data);
	init_player_struct(game, &sprit, map, file);
	init_sprites(game);
	map = read_map(file);
	if (!map)
		return ;
	while (data.y < game->sprites->max_y)
	{
		data.x = 0;
		while (data.x < game->sprites->max_x)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->sprites->roof, \
				data.x * 64, data.y * 64);
			if (map[data.y][data.x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->sprites->walls, data.x * 64, data.y * 64);
			if (map[data.y][data.x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->sprites->coll, data.x * 64, data.y * 64);
			if (map[data.y][data.x] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->sprites->maula, data.x * 64, data.y * 64);
			if (map[data.y][data.x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->sprites->exit, data.x * 64, data.y * 64);
			data.x++;
		}
		data.y++;
	}
}
