/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:04:52 by yutoendo          #+#    #+#             */
/*   Updated: 2023/08/19 17:48:19 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <fcntl.h>    //open
#include <unistd.h>    //close, read, write
#include <stdio.h>    // perror
#include <stdlib.h>    // malloc, free, exit
#include <string.h>    // strerror
#include <stdbool.h>    // boolean  true/false を使えるようにする

#include "libft/libft.h"    // バリバリ使ってます
#include "get_next_line/get_next_line.h"    // ファイルからマップ情報を抜き出す際に使用
#include "ft_printf/ft_printf.h"   

# define CORRECT_ARGC 2 // 標準入力から受け取る引数の数
# define MAP_ARGC 1 // マップがあるはずの標準入力（二次元配列）のインデックス
# define MAP_EXTENTION ".ber" // マップの拡張子
# define INVALID_FD -1 // ファイルディスクリプタが不正な時の値
# define DELETE_EVENT 33
# define DELETE_MASK 1L<<17
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2


# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define EMPTY '0'
# define DAMAGE 'D'

#define PLAYER_PATH "./textures/player.xpm"
#define COINS_PATH "./textures/coins.xpm"
#define BACKGROUND_PATH "./textures/background.xpm"
#define EXIT_PATH "./textures/exit.xpm"
#define EMPTY_PATH "./textures/empty.xpm"
#define DAMAGE_PATH "./textures/damage.xpm"

# define NEIGHBORS 4

# define TILE_SIZE 32 // 一つのタイルの大きさ

// typedef struct s_img{
//     void *img;
//     int x;
//     int y;
// }               t_img;

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
	void *mlx;  // 一つのマップにつき一つ必要、マップの情報をmlxライブラリに行き来させるのに使用
    void *win;  // ウィンドウの情報 フレームの大きさとか閉じたか？とか（多分）
    int map_width;  // ウィンドウの横幅
    int map_height; // ウィンドウの縦幅
    int coin_num;
    t_map map;  // マップの情報を格納する構造体
    t_img player;  // 画像の情報を格納する構造体
    t_img collectible;
    t_img wall;
    t_img empty;
    t_img exit;
    t_img damage;
    
}				t_data;

void render_map(t_data *game_data);
void is_valid_input(int argc, char *argv[]);
void get_map(char *map_path, t_data *game_data);
void is_valid_map(char **map);
size_t get_map_len(char **map);
void free_2d_array(char **str);
void is_valid_map_shape(char **map);
void is_map_walled(char **map);
void is_valid_map_elements(char **map);
void is_game_playable(t_data *game_data);
int main(int argc, char *argv[]);
void get_game_imgs(t_data *game_data);
int key_hook(int keycode, t_data *game_data);
void move_player(t_data *game_data, int next_x, int next_y);
#endif