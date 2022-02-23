/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_return_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:26:36 by jukoh             #+#    #+#             */
/*   Updated: 2022/02/23 20:43:13 by young-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

char	**ft_fill_map(char	**map, t_map_data	map_data)
{
	int	i;
	int	j;
	int	count_max;
	int	*pos;
	int	**map_copy;

	count_max = 0;
	map_copy = ft_find_size_square(map, map_data, &count_max);
	pos = ft_find_position_square(map_copy, map_data, count_max);
	i = pos[0] - count_max + 1;
	while (i <= pos[0])
	{
		j = pos[1] - count_max + 1;
		while (j <= pos[1])
		{
			map[i][j] = map_data.full;
			j++;
		}
		i++;
	}
	return (map);
}

void	ft_putstr(char	*str, t_map_data	map_data)
{
	int	i;

	i = 0;
	while (i < map_data.column)
	{
		write(1, str + i, 1);
		i++;
	}
}

char	**ft_read_map(t_map_data	map_data)
{
	char	**map;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	map = malloc(sizeof(char *) * map_data.row);
	while (i < map_data.row)
	{
		j = 0;
		map[i] = malloc(sizeof(char) * map_data.column);
		while (j < map_data.column)
			map[i][j++] = map_data.map[0][k++];
		k++;
		i++;
	}
	if (map_data.map[0][k] != 0)
		return (0);
	return (map);
}

void	ft_print_solution(t_map_data	map_data)
{
	char	**map;
	int		j;

	j = 0;
	map = ft_read_map(map_data);
	if (map == 0)
	{
		write(1, "map error\n", 10);
		close (map_data.fd);
		return ;
	}
	ft_fill_map(map, map_data);
	while (j < map_data.row)
	{
		ft_putstr(map[j], map_data);
		write(1, "\n", 1);
		j++;
	}
	close (map_data.fd);
}
