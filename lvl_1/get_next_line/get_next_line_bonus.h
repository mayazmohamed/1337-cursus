/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:16:05 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/17 13:07:10 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_read_line(int fd, char *str);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s, char *buff);
char	*ft_alloc_line(char *s);
char	*ft_next_str(char *s);
#endif
