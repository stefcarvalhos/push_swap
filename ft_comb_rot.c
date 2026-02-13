/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:47:03 by marvin            #+#    #+#             */
/*   Updated: 2025/02/27 11:47:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_comb_rr(t_stack **a, t_stack **b, int npush, char stackfrom)
{
	if (stackfrom == 'a')
	{
		while (ft_find_posit_b((*b), npush) > 0 && (*a)->nbr != npush)
			ft_rr(a, b, 0);
		while ((*a)->nbr != npush)
			ft_ra(a, 0);
		while (ft_find_posit_b((*b), npush) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else if (stackfrom == 'b')
	{
		while (ft_find_posit_a((*a), npush) > 0 && (*b)->nbr != npush)
			ft_rr(a, b, 0);
		while ((*b)->nbr != npush)
			ft_rb(b, 0);
		while (ft_find_posit_a((*a), npush) > 0)
			ft_ra(a, 0);
		ft_pa(b, a, 0);
	}
	return (-1);
}

int	ft_comb_rrr(t_stack **a, t_stack **b, int npush, char stackfrom)
{
	if (stackfrom == 'a')
	{
		while (ft_find_posit_b((*b), npush) > 0 && (*a)->nbr != npush)
			ft_rrr(a, b, 0);
		while ((*a)->nbr != npush)
			ft_rra(a, 0);
		while (ft_find_posit_b((*b), npush) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else if (stackfrom == 'b')
	{
		while (ft_find_posit_a((*a), npush) > 0 && (*b)->nbr != npush)
			ft_rrr(a, b, 0);
		while ((*b)->nbr != npush)
			ft_rrb(b, 0);
		while (ft_find_posit_a((*a), npush) > 0)
			ft_rra(a, 0);
		ft_pa(b, a, 0);
	}
	return (-1);
}

int	ft_comb_rraerb(t_stack **a, t_stack **b, int npush, char stackfrom)
{
	if (stackfrom == 'a')
	{
		while ((*a)->nbr != npush)
			ft_rra(a, 0);
		while (ft_find_posit_b((*b), npush) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else if (stackfrom == 'b')
	{
		while (ft_find_posit_a((*a), npush) > 0)
			ft_rra(a, 0);
		while ((*b)->nbr != npush)
			ft_rb(b, 0);
		ft_pa(b, a, 0);
	}
	return (-1);
}

int	ft_comb_raerrb(t_stack **a, t_stack **b, int npush, char stackfrom)
{
	if (stackfrom == 'a')
	{
		while ((*a)->nbr != npush)
			ft_ra(a, 0);
		while (ft_find_posit_b((*b), npush) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else if (stackfrom == 'b')
	{
		while (ft_find_posit_a((*a), npush) > 0)
			ft_ra(a, 0);
		while ((*b)->nbr != npush)
			ft_rrb(b, 0);
		ft_pa(b, a, 0);
	}
	return (-1);
}
