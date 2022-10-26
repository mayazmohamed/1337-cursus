/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameutils15.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:24:12 by momayaz           #+#    #+#             */
/*   Updated: 2022/10/20 14:02:48 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	norm1(t_cub *all)
{
	t_data	info;

	all->spriteimg[3].i = mlx_xpm_file_to_image(all->mlx, "./pics/4.xpm",
			&all->spriteimg[3].w, &all->spriteimg[3].h);
	if (!all->spriteimg[3].i)
		exit(1);
	all->spriteimg[3].data = (unsigned int *) mlx_get_data_addr(
			all->spriteimg[3].i, &all->img->bits_per_pixel,
			&info.line_length, &info.endian);
	all->spriteimg[4].i = mlx_xpm_file_to_image(all->mlx, "./pics/5.xpm",
			&all->spriteimg[4].w, &all->spriteimg[4].h);
	if (!all->spriteimg[4].i)
		exit(1);
	all->spriteimg[4].data = (unsigned int *) mlx_get_data_addr(
			all->spriteimg[4].i, &all->img->bits_per_pixel,
			&info.line_length, &info.endian);
	spriteimginit1(all);
}

void	norm2(t_cub *all)
{
	t_data	info;

	all->spriteimg[8].i = mlx_xpm_file_to_image(all->mlx, "./pics/9.xpm",
			&all->spriteimg[8].w, &all->spriteimg[8].h);
	if (!all->spriteimg[8].i)
		exit(1);
	all->spriteimg[8].data = (unsigned int *) mlx_get_data_addr(
			all->spriteimg[8].i, &all->img->bits_per_pixel,
			&info.line_length, &info.endian);
	all->spriteimg[9].i = mlx_xpm_file_to_image(all->mlx, "./pics/10.xpm",
			&all->spriteimg[9].w, &all->spriteimg[9].h);
	if (!all->spriteimg[9].i)
		exit(1);
	all->spriteimg[9].data = (unsigned int *) mlx_get_data_addr(
			all->spriteimg[9].i, &all->img->bits_per_pixel,
			&info.line_length, &info.endian);
}

void	norm3(t_cub *all)
{
	t_data	info;

	all->spriteimg[13].i = mlx_xpm_file_to_image(all->mlx, "./pics/14.xpm",
			&all->spriteimg[13].w, &all->spriteimg[13].h);
	if (!all->spriteimg[13].i)
		exit(1);
	all->spriteimg[13].data = (unsigned int *) mlx_get_data_addr(
			all->spriteimg[13].i, &all->img->bits_per_pixel,
			&info.line_length, &info.endian);
	all->spriteimg[14].i = mlx_xpm_file_to_image(all->mlx, "./pics/15.xpm",
			&all->spriteimg[14].w, &all->spriteimg[14].h);
	if (!all->spriteimg[14].i)
		exit(1);
	all->spriteimg[14].data = (unsigned int *) mlx_get_data_addr(
			all->spriteimg[14].i, &all->img->bits_per_pixel,
			&info.line_length, &info.endian);
}
