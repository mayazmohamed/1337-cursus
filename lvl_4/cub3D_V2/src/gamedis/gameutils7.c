/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameutils7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:45:21 by ygbouri           #+#    #+#             */
/*   Updated: 2022/10/19 11:51:25 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	keypressed(int key, t_cub *all)
{
	if (key == 124)
		all->p->turndirection = 1;
	else if (key == 123)
		all->p->turndirection = -1;
	if (key == 0)
		all->p->walkdirectionx = -1;
	else if (key == 2)
		all->p->walkdirectionx = 1;
	else if (key == 1)
		all->p->walkdirectiony = -1;
	else if (key == 13)
		all->p->walkdirectiony = 1;
	else if (key == 53)
	{
		printf("Game is finish\n");
		exit(1);
	}
	return (0);
}

void	freenode(t_cub *all)
{
	while ((all->node)->next != NULL)
	{
		free(all->node);
		all->node = (all->node)->next;
	}
	free(all->node);
}

int	moveplayer(t_cub *all)
{
	updat_data(&all);
	ft_frame(all);
	mlx_clear_window(all->mlx, all->mlx_win);
	mlx_destroy_image(all->mlx, all->img->img);
	freenode(all);
	drawimg(all, 1);
	affichminimap(all, 1);
	return (0);
}

int	closewin(int key, t_cub *all)
{
	(void)key;
	(void)all;
	printf("game closed!!!!");
	exit(0);
}

void	paintmap(t_cub *all, t_data *img, int ch)
{
	int		x;
	int		y;
	int		i;
	int		j;

	i = 0;
	j = 0;
	checkplayer(all, ch);
	x = all->pscreenx - 64;
	y = all->pscreeny - 64;
	(void)ch;
	pixelmap(img, 0xff000);
	ifspritevisible(all, all->spritecount);
	while (all->map[i])
	{
		j = 0;
		all->miniy = 16 * i - y;
		while (all->map[i][j] && all->map[i][j] != '\n')
		{
			all->minix = 16 * j - x;
			paintmap1(all, i, j, img);
			j++;
		}
		i++;
	}
}
