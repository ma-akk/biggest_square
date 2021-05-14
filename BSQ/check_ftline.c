/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ftline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 22:32:36 by gtresa            #+#    #+#             */
/*   Updated: 2020/09/09 20:47:51 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

char	*fs_arr_alloc(void)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char) * 255);
	if (arr == NULL)
		return (NULL);
	return (arr);
}

void	fs_arr_free(char *arr)
{
	free(arr);
}

char	*arr_fsline(int fd, char *fs_arr)
{
	char	buf;
	int		i;

	i = 0;
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			break ;
		fs_arr[i] = buf;
		i++;
		if (i > 255)
			return ("map error\n");
	}
    fs_arr[i] = '\0';
	close(fd);
	return (fs_arr);
}

int		check_sym_fsline(char *fs_arr)
{
	int	len;

	len = 0;
	while (fs_arr[len])
	{
		if (fs_arr[len] < 32)
			return (-1);
		len++;
	}
	if (fs_arr[len - 1] != fs_arr[len - 2])
		if (fs_arr[len - 2] != fs_arr[len - 3])
		{
			if (fs_arr[len - 1] != fs_arr[len - 3])
				return (0);
			else
				return (-1);
		}
	return (-1);
}

int		check_nbr_fsline(char *fs_arr)
{
	long	nbr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	nbr = 0;
	while (fs_arr[len])
		len++;
	while (i < (len - 3))
		if (fs_arr[i] >= '0' && fs_arr[i] <= '9')
		{
			nbr = nbr * 10 + (fs_arr[i] - '0');
			i++;
		}
		else
			return (-1);
	if (nbr == 0 || nbr > 2147483647)
		return (-1);
	else
		i = (int)nbr;
	return (i);
}
