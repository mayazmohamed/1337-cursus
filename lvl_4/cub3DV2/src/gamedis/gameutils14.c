/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameutils14.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:18:50 by momayaz           #+#    #+#             */
/*   Updated: 2022/10/18 22:06:15 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_isdigit(char c)
{
	if ((c >= '0' && c <= '9') || c == ',')
		return (1);
	return (0);
}

void	if_digit(char *s)
{
	int	i;

	i = 0;
	s = ft_strtrim(s, "\n");
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			ft_error("rgb error1\n");
		i++;
	}
	free(s);
}

void	chosedistance2(t_cub *all, t_glpos *glpos)
{
	glpos->po.x = glpos->hori.x ;
	glpos->po.y = glpos->hori.y;
	all->ray->distance = glpos->hori_d;
	all->hitv = false;
	glpos->verti_f = false;
	all->raydist[all->hitindex] = glpos->hori_d;
}

void	fillplayer(t_cub *all)
{
	all->pp = all->map[all->yp][all->xp];
	all->pscreenx = all->w + 8;
	all->pscreeny = all->h + 8;
}
