/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorit_shorts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:18:34 by stda-sil          #+#    #+#             */
/*   Updated: 2025/03/21 16:18:34 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_movthree(t_stack **a)
{
	t_stack	*fir;
	t_stack	*sec;
	t_stack	*thi;

	fir = *a;
	sec = fir->next;
	thi = sec->next;
	if (fir->nbr < sec->nbr && fir->nbr > thi->nbr)
		ft_rra(a, 0);
	else if (fir->nbr > sec->nbr && fir->nbr > thi->nbr)
	{
		ft_ra(a, 0);
		if (!ft_checksorted (*a, 'a'))
			ft_sa(a, 0);
	}
	else if (fir->nbr < sec->nbr && sec->nbr > thi->nbr)
	{
		ft_rra(a, 0);
		ft_sa(a, 0);
	}
	else if (!ft_checksorted (*a, 'a'))
		ft_sa(a, 0);
}

void	ft_movfour(t_stack **a)
{
	t_stack	*b;
	int		index_min;

	if (!a || !*a || !(*a)->next)
		return ;
	b = NULL;
	index_min = ft_find_index(a, ft_nbrmin(*a));
	if (index_min == 0)
		ft_pb(a, &b, 0);
	else if (index_min == 1)
		ft_sa(a, 0);
	else if (index_min == 2)
	{
		ft_rra(a, 0);
		ft_rra(a, 0);
	}
	else
		ft_rra(a, 0);
	if (index_min)
		ft_pb(a, &b, 0);
	ft_movthree(a);
	ft_pa(&b, a, 0);
}

void	ft_movfive(t_stack **a)
{
	t_stack	*b;

	if (!a || !*a || !(*a)->next)
		return ;
	b = NULL;
	ft_pb(a, &b, 0);
	ft_pb(a, &b, 0);
	if (!ft_checksorted(b, 'b'))
		ft_sb(&b, 0);
	ft_movthree(a);
	if (b->nbr > (ft_nbrmax(*a)))
	{
		ft_pa(&b, a, 0);
		ft_ra(a, 0);
	}
	while (ft_stacksize(b) != 0)
	{
		if (((b->nbr < (*a)->nbr) && (b->nbr > (ft_stacklast(*a)->nbr)))
			|| ((b->nbr < (ft_nbrmin(*a))) && (ft_checksorted(*a, 'a'))))
			ft_pa(&b, a, 0);
		else
			ft_rra(a, 0);
	}
	while (!ft_checksorted(*a, 'a'))
		ft_rra(a, 0);
}
