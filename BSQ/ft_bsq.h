/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 21:52:09 by gtresa            #+#    #+#             */
/*   Updated: 2020/09/09 20:49:48 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
#include <stdio.h>

typedef	struct
{
	int			x;
	int			y;
	int			column;
	int			line;
	int			size;
	char		obs;
	char		emp;
	char		mark;
	char		buf[1];
}				t_list;

t_list			*ft_create_elem(int x, int y, char emp, char obs);
void			checker(int **map, int i, int j, t_list *params);
int				fill_map(t_list *params, int **map, int fd);
void			ft_putchar(char c);
void			skip_first(int fd);
void			output(int **map, t_list *params);
void			creat_map(t_list *params, char *filename);
void			ft_putstr(char *str);
int				**arr_alloc(int y, int x);
void			arr_free(int **map);
char			*fs_arr_alloc(void);
void			fs_arr_free(char *arr);
char			*arr_fsline(int fd, char *fs_arr);
int				check_sym_fsline(char *fs_arr);
int				check_nbr_fsline(char *fs_arr);
int				check_count_sym(char *str, int nbr, int fd);
int				check_file_map(char *str, int fd);
void			bsq_map(char *filename);
char			*check_tmp_file(void);
void			bsq_input(char *filename);
t_list			*put_params(char *arr, int x, int y);

#endif
