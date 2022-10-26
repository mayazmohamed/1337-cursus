/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameutils11.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:12:03 by momayaz           #+#    #+#             */
/*   Updated: 2022/10/19 12:26:23 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	spriteimginit(t_cub *all)
{
	t_data	info;

	all->spriteimg[0].i = mlx_xpm_file_to_image(all->mlx, "./pics/1.xpm",
			&all->spriteimg[0].w, &all->spriteimg[0].h);
	if (!all->spriteimg[0].i)
		exit(1);
	all->spriteimg[0].data = (unsigned int *)mlx_get_data_addr(
			all->spriteimg[0].i, &all->img->bits_per_pixel,
			&info.line_length, &info.endian);
	all->spriteimg[1].i = mlx_xpm_file_to_image(all->mlx, "./pics/2.xpm",
			&all->spriteimg[1].w, &all->spriteimg[1].h);
	if (!all->spriteimg[1].i)
		exit(1);
	all->spriteimg[1].data = (unsigned int *) mlx_get_data_addr(
			all->spriteimg[1].i, &all->img->bits_per_pixel,
			&info.line_length, &info.endian);
	all->spriteimg[2].i = mlx_xpm_file_to_image(all->mlx, "./pics/3.xpm",
			&all->spriteimg[2].w, &all->spriteimg[2].h);
	if (!all->spriteimg[2].i)
		exit(1);
	all->spriteimg[2].data = (unsigned int *) mlx_get_data_addr(
			all->spriteimg[2].i, &all->img->bits_per_pixel,
			&info.line_length, &info.endian);
	norm1(all);
	spriteimginit2(all);
}

void	spriteimginit1(t_cub *all)
{
	t_data	info;

	all->spriteimg[5].i = mlx_xpm_file_to_image(all->mlx, "./pics/6.xpm",
			&all->spriteimg[5].w, &all->spriteimg[5].h);
	if (!all->spriteimg[5].i)
		exit(1);
	all->spriteimg[5].data = (unsigned int *) mlx_get_data_addr(
			all->spriteimg[5].i, &all->img->bits_per_pixel,
			&info.line_length, &info.endian);
	all->spriteimg[6].i = mlx_xpm_file_to_image(all->mlx, "./pics/7.xpm",
			&all->spriteimg[6].w, &all->spriteimg[6].h);
	if (!all->spriteimg[6].i)
		exit(1);
	all->spriteimg[6].data = (unsigned int *) mlx_get_data_addr(
			all->spriteimg[6].i, &all->img->bits_per_pixel,
			&info.line_length, &info.endian);
	all->spriteimg[7].i = mlx_xpm_file_to_image(all->mlx, "./pics/8.xpm",
			&all->spriteimg[7].w, &all->spriteimg[7].h);
	if (!all->spriteimg[7].i)
		exit(1);
	all->spriteimg[7].data = (unsigned int *) mlx_get_data_addr(
			all->spriteimg[7].i, &all->img->bits_per_pixel,
			&info.line_length, &info.endian);
	norm2(all);
}

void	spriteimginit2(t_cub *all)
{
	t_data	info;

	all->spriteimg[10].i = mlx_xpm_file_to_image(all->mlx, "./pics/11.xpm",
			&all->spriteimg[10].w, &all->spriteimg[10].h);
	if (!all->spriteimg[10].i)
		exit(1);
	all->spriteimg[10].data = (unsigned int *) mlx_get_data_addr(
			all->spriteimg[10].i, &all->img->bits_per_pixel,
			&info.line_length, &info.endian);
	all->spriteimg[11].i = mlx_xpm_file_to_image(all->mlx, "./pics/12.xpm",
			&all->spriteimg[11].w, &all->spriteimg[11].h);
	if (!all->spriteimg[11].i)
		exit(1);
	all->spriteimg[11].data = (unsigned int *) mlx_get_data_addr(
			all->spriteimg[11].i, &all->img->bits_per_pixel,
			&info.line_length, &info.endian);
	all->spriteimg[12].i = mlx_xpm_file_to_image(all->mlx, "./pics/13.xpm",
			&all->spriteimg[12].w, &all->spriteimg[12].h);
	if (!all->spriteimg[12].i)
		exit(1);
	all->spriteimg[12].data = (unsigned int *) mlx_get_data_addr(
			all->spriteimg[12].i, &all->img->bits_per_pixel,
			&info.line_length, &info.endian);
	norm3(all);
}

void	paintmap1(t_cub *all, int i, int j, t_data *img)
{
	int	s;

	s = 0;
	if (all->map[i][j] == '1')
		pixelcarre(all, 16, img, (int)all->info.cc);
	if (all->map[i][j] == 'D')
		pixelcarre(all, 16, img, 0x125AFF);
	if (all->map[i][j] == 'F')
	{
		while (s < all->spritecount)
		{
			if ((int)floor(all->sprite[s].x) == i
				&& (int)floor(all->sprite[s].y) == j)
			{
				if (all->sprite[s].visible)
					pixelcarre(all, 16, img, 0x00ffff);
				else
					pixelcarre(all, 16, img, 0x0000FF);
			}
			s++;
		}
	}
}
