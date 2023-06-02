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
			game->new_img = game->sprites->roof;
			if (map[data.y][data.x] == '1')
				game->new_img = game->sprites->walls;
			if (map[data.y][data.x] == 'C')
				game->new_img = game->sprites->coll;
			if (map[data.y][data.x] == 'P')
				game->new_img = game->sprites->maula;
			if (map[data.y][data.x] == 'E')
				game->new_img = game->sprites->exit;
			mlx_put_image_to_window(game->mlx, game->window, \
				game->sprites->roof, data.x * 50, data.y * 50);
			mlx_put_image_to_window(game->mlx, game->window, \
				game->new_img, data.x * 50, data.y * 50);
			data.x++;
		}
		data.y++;
	}
}

void	clear_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->size)
	{
		mlx_clear_window(game->mlx, game->window);
		i++;
	}
}

void	*swap_images(int x, int y, t_game *game)
{
	if (x == y)
		printf("jejejeej\n");
	clear_sprites(game);
	mlx_clear_window(game->mlx, game->window);
	game->moves++;
	ft_printf("moves:%d\n", game->moves);
	return (0);
}

int	ft_move(int key, t_game *game)
{
	where_maula(game);
	if ((key == KEY_A || key == KEY_LEFT))
		swap_images(game->sprites->mx - 1, game->sprites->my, game);
	if ((key == KEY_D || key == KEY_RIGHT))
		swap_images(game->sprites->mx + 1, game->sprites->my, game);
	if ((key == KEY_S || key == KEY_DOWN))
		swap_images(game->sprites->mx, game->sprites->my - 1, game);
	if ((key == KEY_W || key == KEY_UP))
		swap_images(game->sprites->mx, game->sprites->my + 1, game);
	return (0);
}
