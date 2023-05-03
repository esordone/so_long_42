/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input_utils_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:19:50 by esordone          #+#    #+#             */
/*   Updated: 2023/05/03 14:19:55 by esordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_double_in_map(char *map, char object, int len)
{
	int	i;
	int	check;

	i = 1;
	check = 0;
	while (i < len && map[i] != '\0')
	{
		if (map[i] == object)
			check++;
		i++;
	}
	return (check);
}

int	object_on_map(char **map, char *file)
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
			if (is_in_map(map[data.y + 1], data.colect, (max_x - 1)) == 1)
				return (1);
			data.x++;
		}
		data.x = 0;
		data.y++;
	}
	check_last_line_map(map, file, data.colect);
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
