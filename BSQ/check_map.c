/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 22:56:26 by gtresa            #+#    #+#             */
/*   Updated: 2020/09/09 23:07:03 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		check_count_sym(char *str, int nbr, int fd)
{
	char	buf;
	int		count_str;
	int		count_sym;
	int		sym;

	count_str = -1;
	count_sym = 0;
	fd = open(str, O_RDWR);
	while (read(fd, &buf, 1))
	{
		count_sym++;
		if (buf == '\n')
		{
			if (count_str == 0)
				sym = count_sym;
			if (count_sym != sym && count_str > 0)
				return (-1);
			count_sym = 0;
			count_str++;
		}
	}
	if (count_str != nbr || count_sym != 0)
		return (-1);
	close(fd);
	return (sym - 1);
}

int		check_file_map(char *filename, int fd)
{
	char	*arr_fs;
	t_list	*par;
	int		y;
	int		x;

	arr_fs = arr_fsline(fd, fs_arr_alloc());
	if (check_sym_fsline(arr_fs) == -1)
		return (-1);
	else if (check_nbr_fsline(arr_fs) == -1)
		return (-1);
	else if (check_count_sym(filename, check_nbr_fsline(arr_fs), fd) == -1)
		return (-1);
	y = check_nbr_fsline(arr_fs);
	x = check_count_sym(filename, y, fd);
	par = put_params(arr_fs, x, y);
	creat_map(par, filename);
	fs_arr_free(arr_fs);
	return (0);
}

char	*check_tmp_file(void)
{
	int		fd;
	char	buf;
	int		count;
	char	*filename;

	count = 0;
	fd = open("tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0600);
	while (read(0, &buf, 1))
	{
		write(fd, &buf, 1);
		if (buf == '\n')
			count++;
	}
	close(fd);
	if (count > 1 || (count == 1 && buf != '\n'))
		filename = "tmp.txt";
	else
	{
		fd = open("tmp.txt", O_RDWR);
		filename = arr_fsline(fd, fs_arr_alloc());
		close(fd);
	}
	return (filename);
}
