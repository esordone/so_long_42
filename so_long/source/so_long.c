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

int		num_lines(char *map, int fd)
{
	int	i;
	int	num_lines;
	char	line;

	i = 0;
	line = '\n';
	num_lines = 0;
	while(map != NULL)
	{
		map = get_next_line(fd);
		num_lines++;
		if (map != NULL)
			free(map);
	}
	return (num_lines);
}

void	window(char **argv, t_game *size)
{
	int		width;
	int		fd;
	char	*map;
	int		high;

	fd = open(argv[1], O_RDONLY);
	map = get_next_line(fd);
	if (!map)
		free(map);
	width = ft_strlen(map) * IMG_SIZE;
	high = num_lines(map, fd) * IMG_SIZE;
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
	int i;

	i = 0;
	if (argc != 2 || ft_strrncmp(argv[1], ".ber", 4) == 0)
	{
		ft_printf("Error\n");
		ft_printf("The file is not .ber\n");
		return (0);
	}
	if (argc == 2)
	{
		if (walls_map(argv, argv[1]) == 1)
			printf("te parets\n");
		if (walls_map(argv, argv[1]) != 1)
			printf("segueix somiant\n");
		window(argv, &game);
		game_init(&game);
		mlx_loop(&game);

	}
	return (0);
}
