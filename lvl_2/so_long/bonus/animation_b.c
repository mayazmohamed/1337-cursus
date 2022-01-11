/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:00:28 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/10 13:10:41 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_tab(char *t, unsigned int nb, unsigned int len)
{
	t[len--] = 0;
	while (nb > 0)
	{
		t[len--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (t);
}

char	*ft_itoa(int n)
{
	char			*t;
	unsigned int	nb;
	unsigned int	len;

	if (n < 0)
	{
		nb = -n;
		len = 1;
	}
	else
	{
		nb = n;
		len = 0;
	}
	len += calcul_len(nb);
	t = malloc(len + 1 * sizeof(char));
	if (!t)
		return (NULL);
	if (nb == 0)
		t[0] = '0';
	if (n < 0)
		t[0] = '-';
	t = ft_tab(t, nb, len);
	return (t);
}

void	put_img(t_map *m, int i, int j)
{
	mlx_put_image_to_window(m->mlx, m->win, m->wl, j * 50, i * 50);
	mlx_destroy_image(m->mlx, m->wl);
}

void	fill_map(char **t, t_map *m)
{
	int	i;
	int	j;
	int	w;
	int	h;

	rand_move(m);
	i = -1;
	while (t[++i])
	{
		j = 0;
		while (t[i][j])
		{
			if (t[i][j] == '1')
			{
				m->wl = mlx_xpm_file_to_image(m->mlx, "./img/w.xpm", &w, &h);
				put_img(m, i, j);
			}
			else
				fill_map_else(t, m, i, j);
			j++;
		}
	}
	mlx_string_put(m->mlx, m->win, 1, 1, 1, ft_itoa(m->m));
}

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
