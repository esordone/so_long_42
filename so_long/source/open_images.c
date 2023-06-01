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

void	clear_sprites(t_game *game)
{
	init_sprites(game);
	while (game->sprites->maula)
		mlx_destroy_image(game->mlx, game->sprites->maula);
	while (game->sprites->walls)
		mlx_destroy_image(game->mlx, game->sprites->walls);
	while (game->sprites->coll)
		mlx_destroy_image(game->mlx, game->sprites->coll);
	while (game->sprites->exit)
		mlx_destroy_image(game->mlx, game->sprites->exit);
	while (game->sprites->roof)
		mlx_destroy_image(game->mlx, game->sprites->roof);
}

void	*swap_images(int x, int y, t_game *game)
{
	if (x == y)
		printf("jejjejejeej\n");
	clear_sprites(game);
	mlx_clear_window(game->mlx, game->window);
	ft_printf("moves:%d\n", game->sprites->moves);
	return (0);
}

int	ft_move(int key, t_game *game)
{
	if ((key == KEY_A || key == KEY_LEFT)
		&& (game->map[game->sprites->s_x][game->sprites->s_y - 1] != '1'))
		swap_images(0, -1, game);
	return (0);
}

void	game_init(t_game *game, char **map, char *file)
{
	t_map		data;
	t_player	sprit;

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
			mlx_put_image_to_window(game->mlx, game->window, \
				game->sprites->roof, data.x * 50, data.y * 50);
			if (map[data.y][data.x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->sprites->walls, data.x * 50, data.y * 50);
			if (map[data.y][data.x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->sprites->coll, data.x * 50, data.y * 50);
			if (map[data.y][data.x] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->sprites->maula, data.x * 50, data.y * 50);
			if (map[data.y][data.x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->sprites->exit, data.x * 50, data.y * 50);
			data.x++;
		}
		data.y++;
	}
}
