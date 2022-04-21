/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:57:21 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/21 22:06:09 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_pars(t_cub *all, int width, int height)
{
	int	j;

	j = 0;
	get_width_height(all->map, &width, &height);
	ft_remplir_map(all->map, width, height);
	if (ft_check_map_horizontal(all->map, width, height) == 0
		&& ft_check_map_vertical(all->map, width, height) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "error", 5);
}

void	big_parss1(t_cub *all, char c)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	while (all->map[i])
		free(all->map[i++]);
	free(all->map);
	all->map = ft_split(all->info.s1, '\n');
	free(all->info.s1);
	ft_pars(all, width, height);
	if (c == 'm')
		check_m(all, c);
	else if (c == 'b')
		check_b(all, c);
}

int	big_parss(int ac, char *av[], t_cub *all, char c)
{
	int		line;
	int		fd;

	if (ac != 2)
		return (printf("cub3d take just 1 arg"), 0);
	if (!check_file(av[1]))
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (printf("file not found or permission denied "), 0);
	line = cont_line(av[1]);
	all->map = fil_tab(line, fd, all);
	line = 0;
	while (all->map[line])
		line++;
	all->info.s1 = ft_strjoin(line, all->map, "\n");
	big_parss1(all, c);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub all;

	big_parss(ac, av, &all, 'm');
}