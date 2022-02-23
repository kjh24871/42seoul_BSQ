/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:05:32 by jukoh             #+#    #+#             */
/*   Updated: 2022/02/23 20:00:00 by young-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_min_value(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

int	**ft_generate_map(t_map_data map_data)
{
	int	**map2;
	int	i;

	i = 0;
	map2 = malloc(sizeof(int *) * map_data.row);
	if (!map2)
		return (0);
	while (i < map_data.row)
	{
		map2[i] = malloc(sizeof(int) * map_data.column);
		if (!map2[i])
			return (0);
		i++;
	}
	return (map2);
}

int	**ft_find_size_square(char	**map, t_map_data	map_data, int	*count_max)
{
	int	i;
	int	j;
	int	**map_copy;

	i = 0;
	map_copy = ft_generate_map(map_data);
	while (i < map_data.row)
	{
		j = 0;
		while (j < map_data.column)
		{
			if (map[i][j] == map_data.bar)
				map_copy[i][j] = 0;
			else if (i == 0 || j == 0)
				map_copy[i][j] = 1;
			else
				map_copy[i][j] = ft_min_value(map_copy[i - 1][j],
						map_copy[i][j - 1], map_copy[i - 1][j - 1]) + 1;
			if (map_copy[i][j] > *count_max)
				*count_max = map_copy[i][j];
			j++;
		}
		i++;
	}
	return (map_copy);
}

int	*ft_find_position_square(int **map_copy, t_map_data map_data, int count_max)
{
	int	i;
	int	j;
	int	*p;

	i = 0;
	p = malloc(sizeof(int) * 2);
	while (i < map_data.row)
	{
		j = 0;
		while (j < map_data.column)
		{
			if (map_copy[i][j] == count_max)
			{
				p[0] = i;
				p[1] = j;
				free(map_copy);
				return (p);
			}
			j++;
		}
		i++;
	}
	return (0);
}
