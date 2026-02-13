/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:51:01 by stda-sil          #+#    #+#             */
/*   Updated: 2025/03/21 18:44:10 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	ft_addback(stack, first);
}

void	ft_ra(t_stack **a, int j)
{
	if (!a || !*a || !(*a)->next)
		return ;
	ft_rotate(a);
	if (j == 0)
		write (1, "ra\n", 3);
}

void	ft_rb(t_stack **b, int j)
{
	if (!b || !*b || !(*b)->next)
		return ;
	ft_rotate(b);
	if (j == 0)
		write (1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b, int j)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	ft_rotate(a);
	ft_rotate(b);
	if (j == 0)
		write (1, "rr\n", 3);
}
