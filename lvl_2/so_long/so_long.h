/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:09:34 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/10 16:18:18 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_map
{
	int		c;
	int		e;
	int		p;
	int		line;
	int		lent;
	void	*mlx;
	char	**t;
	void	*win;
	void	*wl;
	void	*floor;
	void	*colect;
	void	*player[3];
	void	*f;
	void	*door;
	int		m;
	int		x;
	int		y;
}	t_map;

void	ft_affiche(char **map);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char c);
char	*str_dup(char *tab);
char	*read_map(int fd);
int		cont_line(char *t);
char	**fil_tab(int line, int fd);
void	fill_list(t_map *lst, char *av, int fd);
int		read_map_elem(t_map *lst, int i);
int		check_map(t_map *lst);
int		check_file(char *t);
int		find_p_pos(char **t, int *i, int *j);
int		find_f_pos(char **t, int *i, int *j);
void	put_p_image(t_map *m, int i, int j);
void	put_c_image(t_map *m, int i, int j);
void	put_f_image(t_map *m, int i, int j);
void	fill_map_else(char **t, t_map *m, int i, int j);
int		rand_move1(t_map *map, int i, int j);
void	rand_move(t_map *map);
int		calcul_len(unsigned int nb);
char	*ft_tab(char *t, unsigned int nb, unsigned int len);
char	*ft_itoa(int n);
void	put_img(t_map *m, int i, int j);
void	fill_map(char **t, t_map *map);
int		anim_player(t_map *lst);
void	check_exit(t_map *lst);
int		check_pos_vali_2(t_map *lst, int key, int i, int j);
int		check_pos_vali_1(t_map *lst, int key, int i, int j);
int		check_pos_val(t_map *lst, int key, int i, int j);
int		check_pos_val2(t_map *lst, int key, int i, int j);
int		check_player_pos(t_map *lst, int key);
void	key_hook_1(int key, t_map *map);
int		key_hook(int key, t_map *map);
int		distroy_win(t_map *lst);

#endif
