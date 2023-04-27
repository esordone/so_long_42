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
			if ((map[data.y][data.x] != data.wall) ||
				(map[max_y - 1][data.x] != data.wall))
				return (0);
			data.x++;
		}
		if ((map[data.y][0] != data.wall) ||
			(map[data.y][max_x - 1] != data.wall))
			return (0);
		data.y++;
	}
	return (1);
}

int	rectangular_map(char **map, char *file)
{
	t_map	data;
	int		max_y;

	init_struct(&data);
	map = read_map(file);
	if (!map)
		return (0);
	max_y = num_lines_split(file);
	while (data.y < (max_y - 1))
	{
		if (ft_strlen(map[data.y]) != ft_strlen(map[data.y + 1]))
			return (0);
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
