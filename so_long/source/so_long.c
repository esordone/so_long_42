/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:19:01 by esordone          #+#    #+#             */
/*   Updated: 2023/04/24 15:39:54 by esordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//int main(int argc, char **argv)
//
//I should ALWAYS calculate the memory offset using the line length 
//set by mlx_get_data_addr with this formula:
//
//int offset = (y * line_length + x * (bits_per_pixel / 8));

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i = 400;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "**** QUARANTAMAULA ****");
	img.img = mlx_new_image(mlx, 1920, 1080);
	//add es l'adreca del primer pixel;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (i < 1000)
	{
		my_mlx_pixel_put(&img, i, 500, 0x00FF0000);
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
