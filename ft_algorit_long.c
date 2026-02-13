/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorit_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:17:54 by stda-sil          #+#    #+#             */
/*   Updated: 2025/03/21 16:17:54 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb_upto3(t_stack **a, t_stack **b)
{
	int		mov;
	t_stack	*temp;

	while (!ft_checksorted(*a, 'a') && ft_stacksize(*a) > 3)
	{
		mov = ft_typerot_ab(*a, *b);
		temp = *a;
		while (mov >= 0)
		{
			if (mov == ft_calc_rr(*a, *b, temp->nbr, 'b'))
				mov = ft_comb_rr(a, b, temp->nbr, 'a');
			else if (mov == ft_calc_rrr(*a, *b, temp->nbr, 'b'))
				mov = ft_comb_rrr(a, b, temp->nbr, 'a');
			else if (mov == ft_calc_rraerb(*a, *b, temp->nbr, 'b'))
				mov = ft_comb_rraerb(a, b, temp->nbr, 'a');
			else if (mov == ft_calc_raerrb(*a, *b, temp->nbr, 'b'))
				mov = ft_comb_raerrb(a, b, temp->nbr, 'a');
			else
				temp = temp->next;
		}
	}
}

t_stack	*ft_ordermov_b(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	ft_pb(a, &b, 0);
	if (!ft_checksorted(*a, 'a'))
		ft_pb(a, &b, 0);
	if (!ft_checksorted(*a, 'a') && ft_stacksize(*a) > 3)
		ft_pb_upto3(a, &b);
	if (!ft_checksorted(*a, 'a'))
		ft_movthree(a);
	return (b);
}

t_stack	**ft_ordermov_a(t_stack **a, t_stack **b)
{
	int		mov;
	t_stack	*temp;

	while (*b)
	{
		mov = ft_typerot_ba(*a, *b);
		temp = *b;
		while (mov >= 0)
		{
			if (mov == ft_calc_rr(*a, *b, temp->nbr, 'a'))
				mov = ft_comb_rr(a, b, temp->nbr, 'b');
			else if (mov == ft_calc_raerrb(*a, *b, temp->nbr, 'a'))
				mov = ft_comb_raerrb(a, b, temp->nbr, 'b');
			else if (mov == ft_calc_rrr(*a, *b, temp->nbr, 'a'))
				mov = ft_comb_rrr(a, b, temp->nbr, 'b');
			else if (mov == ft_calc_rraerb(*a, *b, temp->nbr, 'a'))
				mov = ft_comb_rraerb(a, b, temp->nbr, 'b');
			else
				temp = temp->next;
		}
	}
	return (a);
}

void	ft_order(t_stack **a)
{
	t_stack	*b;
	int		nbrmin;

	b = ft_ordermov_b(a);
	a = ft_ordermov_a(a, &b);
	nbrmin = ft_find_index(a, ft_nbrmin(*a));
	if (nbrmin < ft_stacksize(*a) - nbrmin)
	{
		while ((*a)->nbr != ft_nbrmin(*a))
			ft_ra(a, 0);
	}
	else
	{
		while ((*a)->nbr != ft_nbrmin(*a))
			ft_rra(a, 0);
	}
}
