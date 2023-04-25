/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:22:03 by esordone          #+#    #+#             */
/*   Updated: 2023/04/24 16:55:09 by esordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# define IMG_SIZE 32

//axis (eixos en angles)
typedef struct  s_axis {
    int x;
    int y;
}   t_axis;

//square
/*typedef struct s_square {

}   t_square;*/

//player
typedef struct s_player {

    void    *img;
    //void    *current_img;
    void    *action_img;
}   t_player;

//data
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

//game
typedef struct s_game
{
	void			*mlx;
	void			*window;
	//t_vector		wndw_size;
	//t_tile			**tilemap;
	t_player		player;
	//t_vector		img_size;
	//t_wall_img		wall_imgs;
	//t_collect_img	collects_imgs;
}	                t_game;

int     so_long(int argc, char **argv);
void    open_images(t_game *game);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	game_init(t_game *game);

#endif
