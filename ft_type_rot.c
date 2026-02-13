/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:28:41 by marvin            #+#    #+#             */
/*   Updated: 2025/02/27 15:28:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_typerot_ab(t_stack *a, t_stack *b)
{
	int		mov;
	t_stack	*temp;

	temp = a;
	mov = ft_calc_rrr(a, b, a->nbr, 'b');
	while (temp)
	{
		if (mov > ft_calc_rr(a, b, temp->nbr, 'b'))
			mov = ft_calc_rr(a, b, temp->nbr, 'b');
		if (mov > ft_calc_rrr(a, b, temp->nbr, 'b'))
			mov = ft_calc_rrr(a, b, temp->nbr, 'b');
		if (mov > ft_calc_rraerb(a, b, temp->nbr, 'b'))
			mov = ft_calc_rraerb(a, b, temp->nbr, 'b');
		if (mov > ft_calc_raerrb(a, b, temp->nbr, 'b'))
			mov = ft_calc_raerrb(a, b, temp->nbr, 'b');
		temp = temp->next;
	}
	return (mov);
}

int	ft_typerot_ba(t_stack *a, t_stack *b)
{
	int		mov;
	t_stack	*temp;

	temp = b;
	mov = ft_calc_rrr(a, b, b->nbr, 'a');
	while (temp)
	{
		if (mov > ft_calc_rr(a, b, temp->nbr, 'a'))
			mov = ft_calc_rr(a, b, temp->nbr, 'a');
		if (mov > ft_calc_rrr(a, b, temp->nbr, 'a'))
			mov = ft_calc_rrr(a, b, temp->nbr, 'a');
		if (mov > ft_calc_rraerb(a, b, temp->nbr, 'a'))
			mov = ft_calc_rraerb(a, b, temp->nbr, 'a');
		if (mov > ft_calc_raerrb(a, b, temp->nbr, 'a'))
			mov = ft_calc_raerrb(a, b, temp->nbr, 'a');
		temp = temp->next;
	}
	return (mov);
}
