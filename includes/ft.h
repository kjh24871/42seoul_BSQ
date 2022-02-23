/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:35:30 by jukoh             #+#    #+#             */
/*   Updated: 2022/02/23 21:35:59 by young-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define BUF_SIZE 110000000

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_map_data{
	int		row;
	int		column;
	char	bar;
	char	empty;
	char	full;
	int		fd;
	char	*map[100000];
}t_map_data;

void	ft_print_solution(t_map_data	map_data);
char	**ft_fill_map(char	**map, t_map_data	map_data);
int		**ft_find_size_square(char	**map, t_map_data	map_data, \
		int	*count_max);
int		*ft_find_position_square(int	**map_copy, t_map_data	map_data, \
		int	count_max);
int		**ft_generate_map(t_map_data	map_data);
int		ft_min_value(int	a, int	b, int	c);
int		is_digit(char	*a);
int		check_first_row(int	*i, char	*a, t_map_data	*map_data);
int		ft_strlen(char	*a, int	len, t_map_data	md, int	count);
int		check_map(char	*a, int	len, t_map_data	*map_data);
void	ft_putstr(char	*str, t_map_data	map_data);
char	**ft_read_map(t_map_data	map_data);
void	set_fd(int	ac, t_map_data	*map_data);
int		read_file(int	fd, char	*buf, int	*readint);
void	print_maperror(int	check, int		*k);

#endif
