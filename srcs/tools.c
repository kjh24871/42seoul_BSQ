/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-pa <yg0585@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:33:44 by young-pa          #+#    #+#             */
/*   Updated: 2022/02/23 21:34:13 by young-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_maperror(int	check, int	*k)
{
	if (check == -1)
		write(1, "map error\n", 10);
	*k += 1;
}

int	read_file(int	fd, char	*buf, int	*readint)
{
	*readint = read(fd, buf, BUF_SIZE);
	return (*readint);
}
