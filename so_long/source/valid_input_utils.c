/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:00:37 by esordone          #+#    #+#             */
/*   Updated: 2023/04/26 14:00:39 by esordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strrncmp(char *s1, char *s2, int n)
{
	int	len;
	int len2;

	len = ft_strlen(s1) - 1;
	len2 = ft_strlen(s2) - 1;
	if (n == 0)
		return (0);
	while (n > 0 && s1[len] == s2[len2] && s2[len2] != s2[0])
	{
		n--;
		len2--;
		len--;
	}
	if (s1[len] == s2[len2])
		return (1);
	else
		return (0);
}

char **read_map(char *map)
{
	int fd;
	char *buffer;
	char **res;

	fd = open(map, O_RDONLY);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	res = ft_split(buffer, '\n');
	free (buffer);
	close (fd);
	return (res);
}

void	init_struct(t_map *data)
{
	data->wall = '1';
	data->empty = '0';
	data->x = 0;
	data->y = 0;
}

int		num_lines_split(char *map)
{
	int	i;
	char **res;

	i = 0;
	res = read_map(map);
	while(res[i] != NULL)
		i++;
	return (i);
}

int	walls_map(char **map, char *file)
{
	t_map	data;
	int		max_x;
	int		max_y;

	init_struct(&data);
	map = read_map(file);
	if (!map)
		return (0);
	max_x = ft_strlen(map[0]);
	max_y = num_lines_split(file);
	while (data.y <= (max_y - 1))
	{
		while (data.x <= (max_x - 1))
		{
			if (map[data.y][data.x] != data.wall)
			{
				printf("la primera fila no esta tancada\n");
				return (0);
			}
			data.x++;
		}
		if (map[data.y][0] != data.wall)
		{
			printf("la primera columna no esta tancada\n");
			return (0);
		}
		if (map[data.y][max_x - 1] != data.wall)
		{
			printf("l'ultima columna no esta tancada\n");
			return (0);
		}
		data.y++;
	}
	return (1);
}

	/*printf("map[0][0] = %c\n", map[0][0]);
	printf("map[1][0] = %c\n", map[1][0]);
	printf("map[2][0] = %c\n", map[2][0]);
	printf("map[0][1] = %c\n", map[0][1]);
	printf("map[1][1] = %c\n", map[1][1]);
	printf("map[2][1] = %c\n", map[2][1]);
	printf("map[0][2] = %c\n", map[0][2]);
	printf("map[1][2] = %c\n", map[1][2]);
	printf("map[2][2] = %c\n", map[2][2]);
	printf("map[0][3] = %c\n", map[0][3]);
	printf("map[1][3] = %c\n", map[1][3]);
	printf("map[2][3] = %c\n", map[2][3]);*/
