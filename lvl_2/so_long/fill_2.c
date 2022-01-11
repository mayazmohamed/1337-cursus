/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:05:19 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/10 12:07:28 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	anim_player(t_map *l)
{
	static int	a;
	int			i;
	int			j;

	i = 0;
	j = 0;
	find_p_pos(l->t, &i, &j);
	while (1)
	{
		mlx_put_image_to_window(l->mlx, l->win, l->player[a], j * 50, i * 50);
		a++;
		if (a == 2)
			a = 0;
		break ;
	}
	return (1);
}

void	check_exit(t_map *lst)
{
	if (lst->t[lst->x][lst->y] == 'C')
		lst->c--;
	if (lst->t[lst->x][lst->y] == 'E' && lst->c == 0)
	{
		mlx_destroy_window(lst->mlx, lst->win);
		exit(0);
	}
}
