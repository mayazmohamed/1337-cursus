/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameutils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:35:34 by ygbouri           #+#    #+#             */
/*   Updated: 2022/10/20 18:34:33 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_strleny(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < W && y >= 0 && y < H)
	{
		dst = data->addr + (y * data->line_length + x * \
		(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	drawimg(t_cub *all, int ch)
{
	all->img->img = mlx_new_image(all->mlx, W, H);
	all->img->addr = mlx_get_data_addr(all->img->img, \
		&all->img->bits_per_pixel, \
		&all->img->line_length, &all->img->endian);
	if (ch == 0)
		affichminimap(all, 0);
}

void	ft_display(t_cub *all)
{
	all->img = (t_data *)malloc(sizeof(t_data));
	all->mlx = mlx_init();
	all->mlx_win = mlx_new_window(all->mlx, W, H, "CUB3D");
	all->hitindex = 0;
	drawimg(all, 0);
	mlx_hook(all->mlx_win, 3, 1L << 1, keyrelease, all);
	mlx_hook(all->mlx_win, 2, 1L << 0, keypressed, all);
	mlx_hook(all->mlx_win, 17, 0, closewin, all);
	mlx_loop_hook(all->mlx, moveplayer, all);
	if (all->game_mode == 'b')
		mlx_hook(all->mlx_win, 6, 0, ft_mouse, all);
	mlx_loop(all->mlx);
}

void	pixelcarre(t_cub *all, int pi, t_data *img, int color)
{
	int	i;
	int	j;

	i = all->miniy;
	j = all->minix;
	while (i < all->miniy + pi)
	{
		j = all->minix;
		while (j < all->minix + pi)
		{
			if ((i >= 0 && i < 128) && (j >= 0 && j < 128))
				my_mlx_pixel_put(img, j, i, color);
			j++;
		}
		i++;
	}
}
