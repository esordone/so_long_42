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

int	num_lines(char *map, int fd)
{
	int		i;
	int		num_lines;
	char	line;

	i = 0;
	line = '\n';
	num_lines = 1;
	while (map != NULL)
	{
		map = get_next_line(fd);
		num_lines++;
		if (map != NULL)
			free(map);
	}
	return (num_lines);
}

void	window(char **argv, t_game *game)
{
	int		width;
	int		fd;
	char	*map;
	int		high;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nThe map does not exist.\n");
		exit (0);
	}
	map = get_next_line(fd);
	if (!map)
		free(map);
	width = (ft_strlen(map) - 1) * IMG_SIZE;
	high = (num_lines(map, fd) - 1) * IMG_SIZE;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, width,
			high, "**** QUARANTAMAULA ****");
	close(fd);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || ft_strrncmp(argv[1], ".ber", 4) == 0)
	{
		ft_printf("Error\n");
		ft_printf("The file is not .ber\n");
		return (0);
	}
	if (argc == 2)
	{
		if (valid_input(argv, argv[1]) == 1)
		{
			game.map = read_map(argv[1]);
			game.sprites.max_y = num_lines_split(argv[1]);
			game_init(&game);
			window(argv, &game);
			make_map(&game);
			mlx_key_hook (game.window, read_keys, &game);
			mlx_hook(game.window, 2, 0, move_things, &game);
			mlx_hook(game.window, 17, 0, finish_program, &game);
			mlx_loop(&game);
		}
	}
	return (0);
}
