/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:13:32 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/30 13:47:19 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# define CONVERSION "cspdiuxX%"

# define FLAGS "-+0 #"
# define DIGITS "0123456789"

# define F_MINUS 2
# define F_PLUS 3
# define F_ZERO 5
# define F_SPACE 7
# define F_HASH 11

# define B_DEC "0123456789"
# define B_HEX_L "0123456789abcdef"
# define B_HEX_U "0123456789ABCDEF"

typedef struct s_general
{
	char	*input;
	va_list	argument;
	int		size;
	int		posit;
}				t_general;

typedef struct s_ident
{
	int		flags;
	int		width;
	int		precision;
	char	conversion;
}				t_ident;

int		ft_printf(const char *format, ...);
int		get_sizes(t_general *gen, t_ident *ident);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(char c);
void	get_flags(t_general *gen, t_ident *ident);
void	ft_print_all(t_general *gen, t_ident ident, char *pre);
void	print_0(int str_len);
char	*ft_get_nbr(long long n, t_ident *ident);
char	*ft_strchr(const char *s, int c);
char	*ft_fill_zeros(char *pref, char *suf, int len_beg, int len_end);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_sufix(long long n, t_ident ident);
char	*ft_itoa_base_u(size_t n, char const *base);
size_t	ft_intsize(size_t n, size_t size, size_t n_base);
char	*ft_prefix(long long *n, t_ident ident);
int		ft_print_space(int cont, t_ident ident);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_strfree(char **str);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	ft_print_ident(t_general *gen, t_ident *ident);
void	ft_init_ident(t_ident *identifier);
void	get_conversion(t_general *gen, t_ident *ident);
void	get_limits(t_general *gen, t_ident *ident);
void	ft_prepare_nbr(t_general *gen, t_ident ident);
void	ft_prepare_pct(t_general *gen, t_ident ident);
void	ft_prepare_p(t_general *gen, t_ident ident);
void	ft_prepare_s(t_general *gen, t_ident ident);
void	ft_prepare_c(t_general *gen, t_ident ident);
#endif
