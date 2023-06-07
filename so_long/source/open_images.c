/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:29:20 by esordone          #+#    #+#             */
/*   Updated: 2023/05/31 17:58:39 by esordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_sprites(t_game *game)
{
	int	img_size;

	game->sprites.maula = mlx_xpm_file_to_image(game->mlx, \
		"images/xpm/Maula1.xpm", &img_size, &img_size);
	game->sprites.roof = mlx_xpm_file_to_image(game->mlx, \
		"images/xpm/Fons.xpm", &img_size, &img_size);
	game->sprites.walls = mlx_xpm_file_to_image(game->mlx, \
		"images/xpm/Wall.xpm", &img_size, &img_size);
	game->sprites.coll = mlx_xpm_file_to_image(game->mlx, \
		"images/xpm/Collectionable.xpm", &img_size, &img_size);
	game->sprites.exit = mlx_xpm_file_to_image(game->mlx, \
		"images/xpm/Exit.xpm", &img_size, &img_size);
	if (!game->sprites.maula || !game->sprites.roof || \
		!game->sprites.walls || !game->sprites.coll || \
		!game->sprites.exit)
		ft_printf("ERROR\nCould not open images");
}

void	game_init(t_game *game, char **map, char *file)
{
	t_map		data;
	void		*new_img;

	init_struct(&data);
	init_player_struct(game, &game->sprites, map, file);
	init_sprites(game);
	while (data.y < game->sprites.max_y)
	{
		data.x = 0;
		while (data.x < game->sprites.max_x)
		{
			new_img = game->sprites.roof;
			if (game->map[data.y][data.x] == '1')
				new_img = game->sprites.walls;
			if (game->map[data.y][data.x] == 'C')
				new_img = game->sprites.coll;
			if (game->map[data.y][data.x] == 'P')
				new_img = game->sprites.maula;
			if (game->map[data.y][data.x] == 'E')
				new_img = game->sprites.exit;
			mlx_put_image_to_window(game->mlx, game->window, \
			game->sprites.roof, data.x * 50, data.y * 50);
			mlx_put_image_to_window(game->mlx, game->window, \
			new_img, data.x * 50, data.y * 50);
			data.x++;
		}
		data.y++;
	}
}

void	clear_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (game->images[i])
	{
		mlx_destroy_image(game->mlx, game->images[i]);
		i++;
	}
}

void	*swap_images(int x, int y, t_game *game)
{
	num_collect(game);
	clear_sprites(game);
	mlx_clear_window(game->mlx, game->window);
	printf("num collectionables = %d\n", game->num_c);
	if (game->map[game->sprites.my + y][game->sprites.mx + x] == 'C')
			game->num_c--;
	if (game->map[game->sprites.my + y][game->sprites.mx + x] == 'E'
		&& game->num_c == 0)
		finish_program(game);
	if (game->map[game->sprites.my + y][game->sprites.mx + x] == 'E'
		&& game->sprites.collect > 0)
	{
		make_map(game);
		return (0);
	}
	game->map[game->sprites.my + y][game->sprites.mx + x] = 'P';
	game->map[game->sprites.my][game->sprites.mx] = '0';
	game->images = save_image(game);
	game->moves++;
	ft_printf("moves:%d\n", game->moves);
	make_map(game);
	return (0);
}

int	ft_move(int key, t_game *game)
{
	where_maula(game);
	if ((key == KEY_A || key == KEY_LEFT)
		&& game->map[game->sprites.my][game->sprites.mx - 1] != '1')
	{
		printf("move left\n");
		swap_images(-1, 0, game);
	}
	if ((key == KEY_D || key == KEY_RIGHT)
		&& game->map[game->sprites.my][game->sprites.mx + 1] != '1')
	{
		printf("move right\n");
		swap_images(+1, 0, game);
	}
	if ((key == KEY_S || key == KEY_DOWN)
		&& game->map[game->sprites.my + 1][game->sprites.mx] != '1')
	{
		printf("move down\n");
		swap_images(0, +1, game);
	}
	if ((key == KEY_W || key == KEY_UP)
		&& game->map[game->sprites.my - 1][game->sprites.mx] != '1')
	{
		printf("move up\n");
		swap_images(0, -1, game);
	}
	return (0);
}
