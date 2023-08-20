/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:52:09 by yutoendo          #+#    #+#             */
/*   Updated: 2023/08/20 14:31:05 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static char	*so_long_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*str_start;
    char *s1_start;
	size_t	size;

	if (!s1 && !s2)
		return (NULL);
    s1_start = s1;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)ft_calloc(size, sizeof(char));
	if (!str)
		return (NULL);
	str_start = str;
	while (s1 != NULL && *s1)
		*str++ = *s1++;
	while (s2 != NULL && *s2)
		*str++ = *s2++;
	*str = 0;
	str = str_start;
	free(s1_start);
	return (str_start);
}

static char **read_map(char *map_info)  // コード動くか確認していない（多分動かない） 骨格は合ってるハず
{
    int fd; // ファイルディスクリプタ
    char *line; // get_next_line関数で読む1行
    char *concat_lines;  // １行ずつ取り出したmap情報を保持する
    char **map;

    concat_lines = NULL;
    fd = open(map_info, O_RDONLY); // ファイルを開ける
    if (fd == INVALID_FD)
    {
        ft_printf("\x1b[31mError\nMap not found\n\x1b[0m");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        line = get_next_line(fd);   // １行ずつ読んでいく
        if (line == NULL || line[0] == '\n')    // 全行読み切ったかチェック
        {
            break;
        }    // malloc失敗と終端の見分け方? ここなぞ
        concat_lines = so_long_strjoin(concat_lines, line);  // 取り出した１行をそれまで読み取ったマップ情報にくっつける
        
        if (concat_lines == NULL)    // strjoinのmalloc失敗時
        {   
            free(line); // メモリーリーク対策
            ft_printf("\x1b[31mError\nMalloc Error\n\x1b[0m");
            exit(EXIT_FAILURE);
        }
        free(line);
    }
    free(line); 
    close(fd);  
    map =  ft_split(concat_lines, '\n');
    free(concat_lines);
    return (map);  // ft_splitの返り値は二次元配列になる そしてft_splitはナル終端だ！？
}

static t_img get_img(t_data *game_data, char *path)
{
    t_img element;

    // element.img = mlx_xpm_file_to_image(game_data->mlx, path, &element.x, &element.y);   // 
    element.img = mlx_xpm_file_to_image(game_data->mlx, path, &element.cordinate.x, &element.cordinate.y);  
    return (element);
}

void get_game_imgs(t_data *game_data)
{    
    game_data->player = get_img(game_data, PLAYER_PATH);
    game_data->collectible = get_img(game_data, COINS_PATH);
    game_data->wall = get_img(game_data, BACKGROUND_PATH);
    game_data->exit = get_img(game_data, EXIT_PATH);
    game_data->empty = get_img(game_data, EMPTY_PATH);
    game_data->damage = get_img(game_data, DAMAGE_PATH);
}

static int get_coin_num(char **map)
{
    int i;
    int j;
    int coin_num;

    i = 0;
    coin_num = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] == 'C')
                coin_num++;
            j++;
        }
        i++;
    }
    return (coin_num);
}


void get_map(char *map_path, t_data *game_data)
{
    char **map;

    map = read_map(map_path);   // ファイルからマップ情報を取り出す、使いやすい形に整形
    if (map == NULL)    // ft_splitの中身でmalloc失敗時
    {   
        perror("Error\nMalloc Error\n");
        exit(EXIT_FAILURE);
    }
    is_valid_map(map);  // マップがPDFの規定通りかチェック
    game_data->map.map = map;   // マップ情報を構造体に格納
    game_data->map_width =  ft_strlen(map[0]);// マップの横幅を構造体に格納
    game_data->map_height = get_map_len(map); // マップの縦幅を構造体に格納
    game_data->coin_num = get_coin_num(map);  // コインの数を構造体に格納
    is_game_playable(game_data);
}