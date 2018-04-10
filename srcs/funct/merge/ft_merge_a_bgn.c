/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_a_bgn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:08:47 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/10 17:32:13 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static void	ft_pb_ra(t_stack *a, t_ret *ret, int i, int pos)
{
	if (a->bgn->pos <= pos)
	{
		a->bgn->m = i;
		ft_pb(a, a->s_b, ret);
	}
	else
		ft_ra(a, ret);
}

int			ft_merge_a_bgn(t_stack *a, t_ret *ret, int p)
{
	int pos;
	int tmp;
	int m;
	int i;

	tmp = ft_check_m(a) / 2;
	pos = (p + 1) - tmp;
	i = a->bgn->m + 1;
	m = a->end->m;
	while (a->bgn->next != NULL)
	{
		if (ft_is_sort(a, p))
			break ;
		if (ft_check_pos(a->bgn, pos))
		{
			i++;
			if (tmp != 1)
				tmp = tmp / 2;
			pos = tmp + pos;
		}
		ft_pb_ra(a, ret, i, pos);
	}
	return (a->bgn->pos - 1);
}
