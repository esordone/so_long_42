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

void	make_map(t_game *game)
{
	t_map		data;
	int			n;

	n = 0;
	init_struct(&data);
	while (game->map[data.x])
	{
		data.y = 0;
		while (game->map[data.x][data.y] && game->map[data.x][data.y] != '\n')
		{
			game->images[n] = put_images(game, data.x, data.y);
			if (game->images[n] == NULL)
				exit (0);
			mlx_put_image_to_window(game->mlx, game->window,
				game->sprites.roof, data.y * 50, data.x * 50);
			mlx_put_image_to_window(game->mlx, game->window,
				game->images[n], data.y * 50, data.x * 50);
			n++;
			data.y++;
		}
		data.x++;
	}
}

void	*ft_images(t_game *game, char *image)
{
	void	*img;
	int		img_size;

	img = mlx_xpm_file_to_image(game->mlx, image,
			&img_size, &img_size);
	return (img);
}

void	*put_images(t_game *game, int x, int y)
{
	init_sprites(game);
	if (game->map[x][y] == '1')
		return (ft_images(game, "images/xpm/Wall.xpm"));
	if (game->map[x][y] == '0')
		return (ft_images(game, "images/xpm/Fons.xpm"));
	if (game->map[x][y] == 'C')
		return (ft_images(game, "images/xpm/Collectionable.xpm"));
	if (game->map[x][y] == 'E')
		return (ft_images(game, "images/xpm/Exit.xpm"));
	if (game->map[x][y] == 'P')
		return (ft_images(game, "images/xpm/Maula1.xpm"));
	else
		return (0);
}
