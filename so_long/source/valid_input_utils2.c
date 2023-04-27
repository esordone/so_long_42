/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:37:39 by esordone          #+#    #+#             */
/*   Updated: 2023/04/27 13:37:43 by esordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strrncmp(char *s1, char *s2, int n)
{
	int	len;
	int	len2;

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

char	**read_map(char *map)
{
	int		fd;
	char	*buffer;
	char	**res;

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

int	num_lines_split(char *map)
{
	int		i;
	char	**res;

	i = 0;
	res = read_map(map);
	while (res[i] != NULL)
		i++;
	return (i);
}
