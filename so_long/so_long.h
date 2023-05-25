/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:22:03 by esordone          #+#    #+#             */
/*   Updated: 2023/04/27 17:08:17 by esordone         ###   ########.fr       */
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
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# define IMG_SIZE 32
# define BUFFER_SIZE 5000
# define ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_W 13

typedef struct s_map
{
	char	wall;
	char	empty;
	char	start;
	char	exit;
	char	colect;
	int		x;
	int		y;
}			t_map;

//player
typedef struct s_player
{
	//void	*img;

    void    *maula;
    void    *walls;
    void    *coll;
    void    *exit;
    void    *roof;
    int max_x;
    int max_y;
	//void	*current_img;
	//void	*action_img;
}	t_player;

//game
typedef struct s_game
{
	void			*mlx;
	void			*window;
	void			*size;
    char            **map;
	//t_player		*player;
    t_player       *sprites;
}					t_game;

int		so_long(int argc, char **argv);
int		num_lines(char *map, int fd);
void	open_images(t_game *game);
//void	game_init(t_game *game);
void	*put_images(t_game *game, int x, int y);


//utils
void init_player_struct(t_game *game, t_player *sprit, char **map, char *file);
int	finish_program (t_game *game);
int read_keys(int exit_key, void *data);

//mlx
int	finish_program (t_game *game);
int read_keys(int exit_key, void *data);

//valid_input
int		valid_input(char **argv, char *file);

//open images
void	game_init(t_game *game, char **map, char *file);
void	init_sprites(t_game *game);

//valid_input_utils
int		walls_map(char **map, char *file);
int		rectangular_map(char **map, char *file);
int	check_last_line_map(char **map, char *file, char object);
int	exit_on_map(char **map, char *file);
int	start_on_map(char **map, char *file);

//valid_input_utils2
int		ft_strrncmp(char *s1, char *s2, int n);
char	**read_map(char *map);
void	init_struct(t_map *data);
int		num_lines_split(char *map);
int 	is_in_map(char *map, char object, int len);

//valid_input_utils3
int	object_on_map(char **map, char *file);
int	is_double_in_map(char *map, char object, int len);
int	check_doubles(char **map, char *file, char object);

#endif
