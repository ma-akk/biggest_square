/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 13:31:22 by wmelly            #+#    #+#             */
/*   Updated: 2020/09/08 23:56:25 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

t_list		*ft_create_elem(int x, int y, char emp, char obs)
{
	t_list *p;

	p = (t_list*)malloc(sizeof(t_list));
	if (p)
	{
		p->x = x;
		p->y = y;
		p->emp = emp;
		p->obs = obs;
	}
	return (p);
}
