/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameutils13.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:38:17 by momayaz           #+#    #+#             */
/*   Updated: 2022/10/21 10:04:45 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	initialiserinter(t_glpos *gl)
{
	gl->intercept.x = 0;
	gl->intercept.y = 0;
	gl->player.x = 0;
	gl->player.y = 0;
	gl->step.x = 0;
	gl->step.y = 0;
	gl->po.x = 0;
	gl->po.y = 0;
	gl->hori.x = 0;
	gl->hori.y = 0;
	gl->verti.x = 0;
	gl->verti.y = 0;
	gl->nbr = 0;
	gl->hori_d = 0;
	gl->verti_d = 0;
	gl->hori_f = false;
	gl->verti_f = false;
}

void	calculhoridis(t_cub *all, t_glpos *glpos, int len)
{
	while ((((int)(glpos->intercept.y / 16) >= 0)
		&& (int)(glpos->intercept.y / 16) < len)
		&& ((int)(glpos->intercept.x / 16) >= 0)
		&& ((int)(glpos->intercept.x / 16) < (int)ft_strlen(
				all->map[(int)glpos->intercept.y / 16]) * 16))
	{
		glpos->nbr = glpos->intercept.y;
		if (all->ray->updirect)
			glpos->nbr--;
		if (checkwall_ray(all, glpos->intercept.x, glpos->nbr))
		{
			glpos->hori_f = false;
			glpos->intercept.x += glpos->step.x;
			glpos->intercept.y += glpos->step.y;
		}
		else
		{
			glpos->hori_f = true;
			glpos->hori.x = glpos->intercept.x;
			glpos->hori.y = glpos->intercept.y;
			break ;
		}
	}
}

void	ft_frame(t_cub *all)
{
	static int	frame;
	static int	i;

	if (frame <= 2)
	{
		frame++;
		if (frame == 2)
		{
			frame = 0;
			i++;
			all->st = i;
		}
		if (i == 14)
			i = 0;
	}
}

void	calctuxter(t_cub *all)
{
	t_data	info;

	all->texture[0].i = mlx_xpm_file_to_image(all->mlx, all->info.n, \
		&all->texture[0].w, &all->texture[0].h);
	if (!all->texture[0].i)
		exit(1);
	all->texture[0].data = (unsigned int *)mlx_get_data_addr(all->texture[0].i,
			&all->img->bits_per_pixel, &info.line_length, &info.endian);
	all->texture[1].i = mlx_xpm_file_to_image(all->mlx, all->info.s,
			&all->texture[1].w, &all->texture[1].h);
	if (!all->texture[1].i)
		exit(1);
	all->texture[1].data = (unsigned int *) mlx_get_data_addr(all->texture[1].i,
			&all->img->bits_per_pixel, &info.line_length, &info.endian);
	all->texture[2].i = mlx_xpm_file_to_image(all->mlx, all->info.e,
			&all->texture[2].w, &all->texture[2].h);
	if (!all->texture[2].i)
		exit(1);
	all->texture[2].data = (unsigned int *) mlx_get_data_addr(all->texture[2].i,
			&all->img->bits_per_pixel, &info.line_length, &info.endian);
	calctuxter1(all, &info);
}

void	calctuxter1(t_cub *all, t_data *info)
{
	all->texture[3].i = mlx_xpm_file_to_image(all->mlx, all->info.w,
			&all->texture[3].w, &all->texture[3].h);
	if (!all->texture[3].i)
		exit(1);
	all->texture[3].data = (unsigned int *) mlx_get_data_addr(all->texture[3].i,
			&all->img->bits_per_pixel, &info->line_length, &info->endian);
	all->texture[4].i = mlx_xpm_file_to_image(all->mlx,
			"./pics/images_64x64.xpm", &all->texture[4].w, &all->texture[4].h);
	if (!all->texture[4].i)
		exit(1);
	all->texture[4].data = (unsigned int *) mlx_get_data_addr(all->texture[4].i,
			&all->img->bits_per_pixel, &info->line_length, &info->endian);
}
