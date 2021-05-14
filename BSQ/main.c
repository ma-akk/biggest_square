/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 22:52:55 by gtresa            #+#    #+#             */
/*   Updated: 2020/09/09 20:52:35 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc > 1)
		while (i < argc)
		{
			if (i > 1)
				write(1, "\n", 1);
			bsq_map(argv[i]);
			i++;
		}
	if (argc == 1)
		bsq_input(check_tmp_file());
	return (0);
}
