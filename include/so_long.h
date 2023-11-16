/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:04:52 by yutoendo          #+#    #+#             */
/*   Updated: 2023/11/16 22:48:12 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <fcntl.h>   
#include <unistd.h>    
#include <stdlib.h>         
#include <stdbool.h>    

#include "../libftprintf/libft/libft.h"
#include "../get_next_line/get_next_line.h"    
#include "../libftprintf/ft_printf/ft_printf.h"   

// ARGUMENTS & KEYCODES
# define CORRECT_ARGC 1
# define MAP_ARGC 1 
# define MAP_EXTENTION ".ber" 
# define INVALID_FD -1 
# define DELETE_EVENT 17
# define DELETE_MASK 1L<<17
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define MOVEMENT_COLOR 0x00FFFFFF
# define MOVEMENTS "Moves: "
# define UNIQUE 1

// MAP ELEMENTS
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define EMPTY '0'
# define VALID_ELEMENTS "01CEP"

// TEXTURES
#define PLAYER_PATH "./textures/player.xpm"
#define COINS_PATH "./textures/coins.xpm"
#define BACKGROUND_PATH "./textures/background.xpm"
#define EXIT_PATH "./textures/exit.xpm"
#define EMPTY_PATH "./textures/empty.xpm"

# define NEIGHBORS 4
# define UNEXPLORED 'U'

// XPM IMAGE SIZE
# define TILE_SIZE 32

// ERROR MESSAGES
# define MALLOC_ERROR 1
# define EMPTY_MAP 2
# define INVALID_ARGS 3
# define MAP_NOT_FOUND 4
# define INVALID_ELEMENTS 5
# define INVALID_MAP_SHAPE 6
# define MAP_NOT_WALLED 7
# define MAP_UNPLAYABLE 8


typedef struct s_point{
    int x;
    int y;
}               t_point;

typedef struct s_img{
    void *img;
    t_point cordinate;
}               t_img;

typedef struct s_map{
    char **map;
    int player_x;
    int player_y;
}               t_map;

typedef struct	s_data {
	void *mlx;  
    void *win;  
    int map_width;  
    int map_height; 
    int coin_num;
    int move_count;
    t_map map;  
    t_img player;  
    t_img collectible;
    t_img wall;
    t_img empty;
    t_img exit;
    
}				t_data;

t_data*     initialize_game_data(void);
void		error_exit(int error_num);
void		is_valid_input(int argc, char *argv[]);
void		load_map(char *map_path, t_data *game_data);
void		is_valid_map_shape(char **map);
void		is_map_walled(char **map);
void		is_valid_map_elements(char **map);
size_t		get_map_len(char **map);
int			count_elements(char **map, char c);
void		is_game_playable(t_data *game_data);
t_point		find_unique_element_cordinates(t_data *game_data, char element);
void		load_game_imgs(t_data *game_data);
void		render_map(t_data *game_data);
int			key_hook(int keycode, t_data *game_data);
int	closes(t_data *game_data);
#endif