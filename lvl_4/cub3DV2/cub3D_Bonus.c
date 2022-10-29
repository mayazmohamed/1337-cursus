/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_Bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:49:59 by momayaz           #+#    #+#             */
/*   Updated: 2022/10/29 02:17:23 by momayaz          ###   ########.fr       */
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
	if (ac != 2)
		return (ft_error("Error\nInvalid number of arguments"));
	all.checker = 0;
	all.game_mode = 'b';
	all.ray = (t_rays *)malloc(sizeof(t_rays));
	big_parss(ac, av, &all, 'b');
	all.spritecount = calculspritenumber(&all);
	all.sprite = malloc(sizeof(t_sprite) * all.spritecount);
	all.st = -1;
	all.margin = 0.2;
	locatesprite(&all);
	ft_display(&all);
	freealoc(&all);
	return (0);
}
