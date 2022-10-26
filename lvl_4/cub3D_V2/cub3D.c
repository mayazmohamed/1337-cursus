/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:49:50 by momayaz           #+#    #+#             */
/*   Updated: 2022/10/20 18:30:58 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub	all;
	int		i;

	i = 0;
	while (i < 256)
		all.info.test[i++] = 0;
	all.checker = 0;
	all.game_mode = 'm';
	all.ray = (t_rays *)malloc(sizeof(t_rays));
	big_parss(ac, av, &all, 'm');
	all.spritecount = calculspritenumber(&all);
	all.sprite = malloc(sizeof(t_sprite) * all.spritecount);
	all.st = -1;
	all.margin = 0.2;
	locatesprite(&all);
	ft_display(&all);
	freealoc(&all);
	return (0);
}
