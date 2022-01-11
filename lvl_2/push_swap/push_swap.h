/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:16:07 by momayaz           #+#    #+#             */
/*   Updated: 2021/12/31 13:50:55 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	int				value;
	int				index;
	int				keep;
	struct s_stack	*next;
}	t_stack;

typedef struct s_utils
{
	int	max_size;
	int	groups;
	int	group_size;
	int	dist;
	int	big_loop;
	int	lst_size;
	int	rot_a;
	int	rot_b;
}	t_utils;

void	free_list(t_stack *a);
int		ft_strcmp(char *s1, char *s2);
void	max_val(long rst);
long	ft_atoi(char *str);
int		get_min(t_stack *lst);
int		get_max(t_stack *lst);
void	ft_affiche(t_stack *lst);
int		ft_isdigit(char c);
int		ft_abs(int n);
int		ft_strlen(char *str);
void	ft_concta(char *dest, char *src);
char	*ft_strjoin(int size, char **strs, char *sep);
int		str_len(const char *s, char c);
void	free_tab(char **t);
int		count_world(const char *s, char c);
char	*str_cpy(const char *s, int size);
char	**ft_split(char *s, char c);
t_stack	*ft_new_node(int value);
int		ft_lstcount(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_check_input_type(char **args);
void	ft_check_double(char **args);
t_stack	*ft_fill_stack(char **args);
t_stack	*ft_devide_args(char **args);
int		ft_check_sort_asc(t_stack *lst);
int		ft_check_sort_des(t_stack *lst);
void	ft_swap_a(t_stack **a, int b);
void	ft_f_swap(t_stack **a);
void	ft_swap_b(t_stack **b, int i);
void	ft_ss(t_stack **a, t_stack **b, int i);
void	ft_push_a(t_stack **b, t_stack **a, int i);
void	ft_push_b(t_stack **a, t_stack **b, int i);
void	ft_rotate_a(t_stack **a, int print);
void	ft_rotate_b(t_stack **b, int print);
void	ft_rev_rot_a(t_stack **a, int print);
void	ft_rev_rot_b(t_stack **b, int print);
void	ft_rr(t_stack **a, t_stack **b, int i);
void	ft_rrr(t_stack **a, t_stack **b, int i);
int		ft_is_sorted(t_stack *lst);
int		*ft_copy_tab(t_stack **lst);
void	ft_swap(int *a, int *b);
void	ft_sort_int_tab(int *tab, int size);
int		ft_get_min(int a, int b);
int		ft_get_max(int a, int b);
void	ft_index_lst(t_stack **a);
int		ft_get_head(t_stack *a, t_stack *p, int set);
int		ft_big_loop(t_stack *a, int set);
void	ft_in_util(t_utils *p, t_stack *a);
int		ft_while(t_stack **p, int size);
t_stack	*ft_check_push(t_stack **a, int size);
int		ft_swap_test(t_stack **a, t_utils *util);
int		ft_cont_inst(t_stack **a, t_stack *p);
void	ft_doub_rot(t_stack **a, t_stack **b, int *rot_a, int *rot_b);
void	ft_do_rotat(t_stack **a, t_stack **b, int rot_a, int rot_b);
void	ft_firts_step(t_stack **a, t_stack **b, int group, t_utils *p);
int		ft_insert_placement(t_stack *b, int cur_index, int size);
int		ft_dist_b(int i, int size);
void	ft_cont_rot(t_stack **b, t_stack **a, t_utils *utils, int max_dist);
void	ft_push_to_a(t_stack **a, t_stack **b, t_utils *p);
void	ft_big_sort(t_stack **a, t_stack **b, int group);

#endif