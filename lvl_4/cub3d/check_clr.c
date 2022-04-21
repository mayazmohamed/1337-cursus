/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_clr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:39:19 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/21 22:11:15 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_free(t_cub *all)
{
	int	j;

	j = 0;
	while (all->map[j])
		free(all->map[j++]);
	free(all->map);
	free(all->info.e);
	free(all->info.n);
	free(all->info.s);
	free(all->info.w);
}

void	check_charm(t_cub *a, char c)
{
	if (c != '1' && c != '0' && c != ' ' && c != 'N' && c != 'E'
		&& c != 'W' && c != 'S')
	{
		ft_free(a);
		exit(printf("map error1"));
	}
}

void	check_m(t_cub *a, char c)
{
	int	i;
	int	j;
	int	cp;

	i = -1;
	while (a->map[++i])
	{
		j = -1;
		while (a->map[i][++j])
		{
			check_charm(a, a->map[i][j]);
			if (a->map[i][j] == 'N' || a->map[i][j] == 'E'
				|| a->map[i][j] == 'W' || a->map[i][j] == 'S')
				cp++;
		}
	}
	if (cp != 1)
	{
		ft_free(a);
		exit(printf("map error2"));
	}
}

void	check_charb(t_cub *a, char c)
{
	if (c != '1' && c != '0' && c != ' ' && c != 'N' && c != 'E'
		&& c != 'W' && c != 'S' && c != 'D' && c != 'B')
	{
		ft_free(a);
		exit(printf("map error3"));
	}
}

void	check_b(t_cub *a, char c)
{
	int	i;
	int	j;
	int	cp;

	i = -1;
	while (a->map[++i])
	{
		j = -1;
		while (a->map[i][++j])
		{
			check_charb(a, a->map[i][j]);
			if (a->map[i][j] == 'N' || a->map[i][j] == 'E'
				|| a->map[i][j] == 'W' || a->map[i][j] == 'S')
				cp++;
		}
	}
	if (cp != 1)
	{
		ft_free(a);
		exit(printf("map error4"));
	}
}
