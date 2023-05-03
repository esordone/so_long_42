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

int	valid_input(char **argv, char *file)
{
	if ((walls_map(argv, file) != 1) || (rectangular_map(argv, file) != 1))
	{
		ft_printf("The map is not closed or is not a rectangle.\n");
		return (0);
	}
	if ((exit_on_map(argv, file) != 1))
	{
		ft_printf("There is no exit in the map.\n");
		return (0);
	}
	if ((start_on_map(argv, file) != 1))
	{
		ft_printf("There is no starting position in the map.\n");
		return (0);
	}
	if ((object_on_map(argv, file) != 1))
	{
		ft_printf("There are no collectibles on the map.\n");
		return (0);
	}
	return (1);
}
