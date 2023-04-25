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

int		num_lines(char *map)
{
	int	i;
	int	num_lines;

	i = 0;
	num_lines = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			num_lines++;
		i++;
	}
	printf("mapa = %d\n", i);
	printf("num_lines = %d\n", num_lines);
	return (num_lines);
}

/*int main(int argc, char **argv)
{
	char *map;
	int fd;

	fd = open(argv[1], O_RDONLY);
	map = get_next_line(fd);
	if (!map)
		free(map);
	printf("num_lines = %d\n", num_lines(map));
	if (argc != 2)
		return (0);
	return (0);
}*/

void	window(char **argv, t_game *size)
{
	//ancho
	int		width;
	int		fd;
	char	*map;
	//alto
	int		high;

	fd = open(argv[1], O_RDONLY);
	//cal canviar el get_next line per el split
	map = get_next_line(fd);
	if (!map)
		free(map);
	width = ft_strlen(map) * IMG_SIZE;
	high = num_lines(map) * IMG_SIZE;
	size->mlx = mlx_init();
	size->window = mlx_new_window(size->mlx, width, high, "**** QUARANTAMAULA ****");
	close(fd);
}

void	game_init(t_game *game)
{
	//mlx_hook(game->window, 17, 0, game);
	open_images(game);
	mlx_put_image_to_window(game->mlx, game->window, game->player.current_img, 0, 0);
}

int main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || ft_strrncmp(argv[1], ".ber", 4) == 0)
	{
		ft_printf("Error\n");
		ft_printf("**** Invalid Argument ****\n");
		return (0);
	}
	if (argc == 2)
	{
		window(argv, &game);
		game_init(&game);
		mlx_loop(&game);

	}
	return (0);
}
