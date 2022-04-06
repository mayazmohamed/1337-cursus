/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:57:21 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/05 21:44:46 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>


typedef struct		s_info
{
	char	*n;
	char	*s;
	char	*e;
	char	*w;
	char	*d;
	char	*c;
	char	*f;
	int		test[256];
}					t_info;

typedef struct s_cub
{
	char	**map;
	t_info	info;
}	t_cub;

/*********************************************************/

int	str_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s && (*s++ != c))
		i++;
	return (i);
}

void	free_tab(char **t)
{
	int	i;

	i = 0;
	while (t[i])
		free(t[i++]);
	free(t);
}

int	count_world(const char *s, char c)
{
	int	i;
	int	j;

	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = str_len(s, c);
		s += i;
		if (i)
			j++;
	}
	return (j);
}

char	*str_cpy(const char *s, int size)
{
	char	*t;

	t = malloc((size + 1) * sizeof(char));
	if (!t)
		return (0);
	t[size] = 0;
	while (size--)
		t[size] = s[size];
	return (t);
}

char	**ft_split(char *s, char c)
{
	char	**t;
	int		size;
	int		n;
	int		i;

	if (!s)
		return (NULL);
	size = count_world(s, c);
	t = malloc ((size + 1) * sizeof(char *));
	if (!t)
		return (0);
	i = -1;
	while (++i < size)
	{
		while (*s && *s == c)
			s++;
		n = str_len(s, c);
		t[i] = str_cpy(s, n);
		if (!(t[i]))
			return (free_tab(t), NULL);
		s += n;
	}
	t[size] = 0;
	return (t);
}

/*********************************************************/

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
void ft_concta(char *dest, char *src)
{
	int i;
	int dest_size;

	i = 0;
	dest_size = 0;
	while (dest[dest_size])
		dest_size++;
	while (src[i])
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	int lenght;
	int i;
	char *concat;

	if (size > 0)
		lenght = ft_strlen(sep) * (size - 1);
	i = 0;
	while (i < size)
	{
		lenght += ft_strlen(strs[i]);
		i++;
	}
	concat = malloc(sizeof(char) * (lenght + 1));
	if (!concat)
		return (NULL);
	i = 0;
	*concat = 0;
	while (i < size)
	{
		ft_concta(concat, strs[i]);
		if (i < size - 1)
			ft_concta(concat, sep);
		i++;
	}
	return (concat);
}

static int	is_trim(char const a, char const *b)
{
	while (*b)
	{
		if (a == *b)
			return (1);
		b++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*pt;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	while (*s1 && is_trim(*s1, set))
		s1++;
	if (!*s1)
	{
		pt = malloc(1 * sizeof(char));
		return (pt[0] = 0, pt);
	}
	while (s1[i])
		i++;
	while (is_trim(s1[i - 1], set))
		i--;
	pt = malloc(i + 1 * sizeof (char));
	if (!pt)
		return (NULL);
	pt[i] = 0;
	while (--i >= 0)
		pt[i] = s1[i];
	return (pt);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*t;
	char	*src;

	src = (char *) s;
	i = ft_strlen(src);
	t = malloc((i + 1) * sizeof(char));
	if (t == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		t[i] = src[i];
		i++;
	}
	t[i] = 0;
	return (t);
}

int	ft_atoi(char *nptr)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			b = -b;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		a = a * 10 + *nptr - 48;
		nptr++;
	}
	return (a * b);
}

int	check_file(char *t)
{
	int	i;

	i = 0;
	while (t[i])
		i++;
	i--;
	if (!(t[i] == 'b' && t[i - 1] == 'u' && t[i - 2] == 'c' && t[i - 3] == '.'))
		return (printf("file map must be .cub extension."), 0);
	return (1);
}

int	ft_strcmp(char *s1, char c)
{
	while (*s1 && *s1 == c)
		s1++;
	if (*s1)
		return (1);
	return (0);
}

char	*str_dup(char *tab)
{
	int		i;
	char	*t;

	i = 0;
	while (tab[i])
		i++;
	t = malloc(i +1);
	i = -1;
	while (tab[++i])
		t[i] = tab[i];
	t[i] = 0;
	return (t);
}

char	*read_map(int fd)
{
	int		r;
	char	c;
	char	t[800000];
	int		i;

	r = 1;
	i = 0;
	while (read(fd, &c, 1))
	{
		t[i++] = c;
		if (c == '\n')
			break ;
	}
	t[i] = 0;
	// if (c == '\n' && !t[0])
	// {
	// 	printf("invalid map.");
	// 	exit(1);
	// }
	return (str_dup(t));
}

int	cont_line(char *t)
{
	int		fd;
	int		i;
	char	c;

	i = 0;
	fd = open(t, O_RDONLY);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			i++;
	}
    close(fd);
	return (++i);
}

void		ft_ifspace(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
			|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
}

void	get_res(t_cub *all, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '\r' && line[i] != '\v' && line[i] != '\f')
		i++;
	all->info.res.x = ft_atoi(line);
	all->info.res.y = ft_atoi(line + i);
}

char		*check_texr(t_cub *all, char *line, char *op)
{
	int		j;
	char	**s;
	char	*text;
	int		fd;

	if (!(s = ft_split(line, ' ')))
	{
		printf("1 %s not found", op);
		exit(1);
	}
	text = ft_strdup(s[1]);
	fd = open(text, O_RDONLY);
	if (fd == -1)
	{
		printf("%s texture not found\n", op);
		exit(1);
	}
	if (!text)
	{
		printf("2 %s not found", op);
		exit(1);
	}
	if (s[2])
	{
		printf("3 %s not found", op);
		exit(1);
	}
	j = 0;
	while (s[j])
		free(s[j++]);
	free(s[j]);
	free(s);
	return (text);
}


void		ft_firstcheck(t_cub *all, char c, char d)
{
	if (all->info.test[(int)c] == 0)
		all->info.test[(int)c] += 1;
	else if (c && c != '1')
	{
		printf("dubel symbol %c ", c);
		exit(1);
	}
	if (c == '1')
	{
		if (!(all->info.test[(int)'N'] == 1 && all->info.test[(int)'W']
			== 1 && all->info.test[(int)'E'] == 1 && all->info.test[(int)'S']
			== 1 && all->info.test[(int)('F')] == 1 && all->info.test[(int)'C'] == 1))
		{
			printf("map error");
			exit(1);
		}
	}
	if (c != '1' && c != '0' && (all->info.test[(int)'1'] == 1))
	{
		printf("map error");
		exit(1);
	}
}

void	get_rgb(t_cub *all)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (all->info.f[i] && all->info.f[i] != ',')
		i++;
	j = i + 1;
	while (all->info.f[j] && all->info.f[j] != ',')
		j++;
}

void		ft_parsing_line(t_cub *all, char *line, int i)
{
	ft_ifspace(line, &i);
	ft_firstcheck(all, line[i], line[i + 1]);
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		all->info.n = check_texr(all, line, "NO");
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		all->info.s = check_texr(all, line, "SO");
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		all->info.w = check_texr(all, line, "WE");
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		all->info.e = check_texr(all, line, "EA");
	else if (line[i] == 'D' && line[i + 1] == ' ')
		all->info.d = check_texr(all, line, "D ");
	else if (line[i] == 'F' && line[i + 1] == ' ')
		all->info.f = check_texr(all, line, "F ");
	else if (line[i] == 'C' && line[i + 1] == ' ')
		all->info.c = check_texr(all, line, "c ");
	else if (line[i] && line != '\0' && line[i] != '1')
	{
		printf("pars error");
		exit(1);
	}
}

char	**fil_tab(int line, int fd, t_cub *all)
{
	int		i;
	char	**t;
	char	*s;
	char	*s1;
	int		j;

	i = 0;
	j = 0;
	t = malloc((line + 1) * sizeof(char *));
	if (!t)
		return (NULL);
	while ((i + j) < line)
	{
		s = read_map(fd);
		s1 = ft_strtrim(s, " ");
		if (s1[0] != '1')
		{
			ft_parsing_line(all, s1, 0);
			i++;
			continue ;
		}
		ft_parsing_line(all, s1, 0);
		t[j] = s;
		j++;
	}
	t[j] = 0;
	i = 0;
	return (t);
}

void get_width_height(char **map, int *width, int *height)
{
    int i;

    i = 0;
    while (map[i])
    {
        if (*width < ft_strlen(map[i]))
            *width = ft_strlen(map[i]);
        i++;
    }
    *height = i;
}

int ft_check_map_horizontal(char **map, int width, int height)
{
    int i;
    int j;

    i = 0;
    while (i < height)
    {
        j = 0;
        while (map[i][j])
        {
            while (map[i][j] == ' ')
                j++;
            if (!map[i][j])
                break;
            if (map[i][j] != '1')
                return (printf("i ama here1 i : %d  j : %d \n", i, j), -1);
            else
            {
                while (map[i][j] != ' ' && map[i][j] != '\0')
                    j++;
                if (map[i][j - 1] != '1' && map[i][j] != '\0')
                    return (printf("i am here2\n"), -1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int ft_check_map_vertical(char **map, int width, int height)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (j < width)
    {
        i = 0;
        while (i < height)
        {
            while (i < height && map[i][j] == ' ')
                i++;
            if (i == height)
                break;
            if (map[i][j] != '1')
                return -1;
            while (i < height && map[i][j] != ' ')
                i++;
            if (map[i - 1][j] != '1')
                return -1;
            while (i < height && map[i][j] == ' ')
                i++;
        }
        j++;
    }
    return (0);
}

void ft_remplir_map(char **map, int width, int height)
{
    int i;
    int j;
    char *buffer;

    i = 0;
    j = 0;
    buffer = malloc(sizeof(char) * (width + 1));
    if (!buffer)
        return;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            if (j < ft_strlen(map[i]))
                buffer[j] = map[i][j];
            else
                buffer[j] = ' ';
            j++;
        }
        buffer[j] = '\0';
        free(map[i]);
        map[i] = ft_strdup(buffer);
        i++;
    }
    free(buffer);
}

int main(int ac, char *av[])
{
    t_cub   all;
    int     line;
	int width;
    int height;
	int		fd;
	char	*s;
    if (ac != 2)
        return (printf("cub3d take just 1 arg"), 0);
    if (!check_file(av[1]))
        return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (printf("file not found or permission denied "), 0);
    line = cont_line(av[1]);
    all.map = fil_tab(line, fd, &all);
	line = 0;
	while (all.map[line])
		line++;
	s = ft_strjoin(line, all.map, "\n");
	all.map = ft_split(s, '\n');
    get_width_height(all.map, &width, &height);
    ft_remplir_map(all.map, width, height);
    if (ft_check_map_horizontal(all.map, width, height) == 0 && ft_check_map_vertical(all.map, width, height) == 0)
        write(1, "OK", 2);
    else
        write(1, "error\n", 6);
    return (0);
}