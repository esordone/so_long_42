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

/*int valid_input(int argc, char **argv)
{

}*/

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
