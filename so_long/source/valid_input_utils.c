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

int	everything_on_map(char **map, char *file)
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
	while ((data.y + 1) <= (max_y - 2))
	{
		while ((data.x + 1) <= (max_x - 2))
		{
			if ((is_in_map(map[data.y + 1], data.exit, (max_x - 1)) == 1) ||
				(is_in_map(map[data.y + 1], data.colect, (max_x - 1)) == 1) ||
				(is_in_map(map[data.y + 1], data.start, (max_x - 1)) == 1))
				return (1);
			data.x++;
		}
		data.x = 0;
		data.y++;
	}
	data.y--;
	while ((data.x + 1) <= (max_x - 2))
	{
		if ((is_in_map(map[data.y + 1], data.exit, (max_x - 1)) != 1) ||
			(is_in_map(map[data.y + 1], data.colect, (max_x - 1)) != 1) ||
			(is_in_map(map[data.y + 1], data.start, (max_x - 1)) != 1))
			return (0);
		else
			return (1);
		data.x++;
	}
	return (0);
}
		//printf("/////// = %c\n", map[data.y + 1][data.x + 1]);
		//printf("estas aci ara = %c\n", map[data.y + 1][data.x + 1]);
		//estas mirant si estan tots els parametres que et demanen
		//en el mapa (objecte, sortida, entrada)
		//vas deixar strchr com a posible forma de fer-ho
		//printf("map[1][max.x -2] = %c\n", map[1][max_x - 2]);
		//printf("map[1][1] = %c\n", map[1][1]);
		//printf("map[max.y - 2][1] = %c\n", map[max_y - 2][1]);
		//printf("map[max.y - 2][max.x - 2] = %c\n", map[max_y - 2][max_x - 2]);
