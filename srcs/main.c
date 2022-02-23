/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-pa <young-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:14:58 by young-pa          #+#    #+#             */
/*   Updated: 2022/02/23 21:34:33 by young-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	ft_strlen(char	*a, int	len, t_map_data	md, int	count)
{
	int	i;
	int	j;
	int	column;
	int	col_count;

	i = 0;
	j = 0;
	while (i++ < md.row)
	{
		col_count = 0;
		while (md.map[0][j] != '\n' && md.map[0][j] != '\0')
		{
			if (md.map[0][j] != a[len - 1] && md.map[0][j] != a[len - 2])
				return (-1);
			j++;
			col_count++;
		}
		j++;
		if (count++ != 0 && column != col_count)
			return (-1);
		column = col_count;
	}
	return (column);
}

void	ft_concat(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	while (*s2 != '\n' && *s2 != '\0')
	{
		s1[i] = *s2;
		i++;
		s2++;
	}
	s1[i++] = *s2++;
	s1[i] = '\0';
}

int	check_map(char	*a, int	len, t_map_data	*map_data)
{
	int		column;
	int		i;
	char	*buf;
	int		readint;

	i = 0;
	buf = malloc(sizeof(char) * BUF_SIZE);
	map_data->map[0] = malloc(sizeof(char) * BUF_SIZE);
	map_data->map[0][0] = '\0';
	while (read_file(map_data->fd, buf, &readint) > 0)
	{
		if (map_data->fd == 0)
		{
			ft_concat(map_data->map[0], buf);
			free(buf);
			buf = malloc(sizeof(char) * BUF_SIZE);
		}
		else
		{
			buf[readint] = '\0';
			map_data->map[0] = buf;
		}
	}
	column = ft_strlen(a, len, *map_data, 0);
	return (column);
}

void	find_answer(int	ac, int	k, char	**av, int	i)
{
	t_map_data	map_data;
	int			check;
	char		a[1000000];

	while (k < ac)
	{
		map_data.fd = open(av[k], O_RDWR);
		set_fd(ac, &map_data);
		check = check_first_row(&i, a, &map_data);
		if (check == -1)
		{
			print_maperror(check, &k);
			continue ;
		}
		map_data.column = check_map(a, i, &map_data);
		close(map_data.fd);
		if (map_data.column == -1)
		{
			print_maperror(map_data.column, &k);
			continue ;
		}
		map_data.fd = open(av[k++], O_RDWR);
		set_fd(ac, &map_data);
		ft_print_solution(map_data);
	}
}

int	main(int	ac, char	**av)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	if (ac == 1)
		k = 0;
	find_answer(ac, k, av, i);
	return (0);
}
