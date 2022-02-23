/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:01:07 by jukoh             #+#    #+#             */
/*   Updated: 2022/02/23 16:05:47 by young-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_digit(char	*a)
{
	if (a[0] >= '0' && a[0] <= '9')
		return (1);
	return (0);
}

int	check_duplicate(int	i, char	*a)
{
	if (a[i] == a[i - 1] || a[i] == a[i - 2] || a[i - 1] == a[i - 2])
		return (-1);
	return (i - 3);
}

int	check_integer(int	i, char	*a)
{
	int	ret_int;
	int	square;

	square = 1;
	ret_int = 0;
	while (i >= 0)
	{
		if (a[i] < '0' || a[i] > '9')
			return (-1);
		ret_int = ret_int + (a[i] - '0') * square;
		square *= 10;
		i--;
	}
	return (ret_int);
}

void	set_fd(int	ac, t_map_data	*map_data)
{
	if (ac == 1)
		map_data->fd = 0;
}

int	check_first_row(int	*i, char	*a, t_map_data	*map_data)
{
	int	ret_int;

	*i = 0;
	while (read(map_data->fd, &a[*i], 1))
	{
		if (a[*i] == '\n')
			break ;
		*i += 1;
	}
	*i -= 1;
	if (*i < 3)
		return (-1);
	*i = check_duplicate(*i, a);
	if (*i == -1)
		return (-1);
	ret_int = check_integer(*i, a);
	*i += 3;
	map_data->full = a[*i];
	map_data->bar = a[*i - 1];
	map_data->empty = a[*i - 2];
	map_data->row = ret_int;
	if (ret_int == 0)
		ret_int = -1;
	return (ret_int);
}
