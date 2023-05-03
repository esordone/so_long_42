/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:15:12 by esordone          #+#    #+#             */
/*   Updated: 2023/04/25 12:15:28 by esordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_input_map(char **argv, char *file)
{
	if ((walls_map(argv, file) != 1) || (rectangular_map(argv, file) != 1))
	{
		ft_printf("Error\nThe map is not closed or is not a rectangle.\n");
		return (0);
	}
	if ((exit_on_map(argv, file) != 1))
	{
		ft_printf("Error\nThere is no exit in the map.\n");
		return (0);
	}
	if ((start_on_map(argv, file) != 1))
	{
		ft_printf("Error\nThere is no starting position in the map.\n");
		return (0);
	}
	if ((object_on_map(argv, file) != 1))
	{
		ft_printf("Error\nThere are no collectibles on the map.\n");
		return (0);
	}
	return (1);
}

/*int	valid_double_input(char **map, char *file)
{
	t_map	data;

	init_struct(&data);
	if(check_doubles(map,file, data.start) != 1)
	{
		ft_printf("There are more than one starting position in the map.\n");
		return (0);
	}
	if(check_doubles(map,file, data.exit) != 1)
	{
		ft_printf("There are more than one exit in the map.\n");
		return (0);
	}
	return (1);
}*/

int	valid_input(char **argv, char *file)
{
	t_map	data;

	init_struct(&data);
	if (valid_input_map(argv, file) == 0)
		return (0);
	/*if (valid_double_input(argv, file) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}*/
	return (1);
}
