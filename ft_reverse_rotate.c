/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:22:51 by stda-sil          #+#    #+#             */
/*   Updated: 2025/03/21 18:43:26 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*penul;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		penul = last;
		last = last->next;
	}
	penul->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	ft_rra(t_stack **a, int j)
{
	if (!a || !*a || !(*a)->next)
		return ;
	ft_reverse_rotate(a);
	if (j == 0)
		write (1, "rra\n", 4);
}

void	ft_rrb(t_stack **b, int j)
{
	if (!b || !*b || !(*b)->next)
		return ;
	ft_reverse_rotate(b);
	if (j == 0)
		write (1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b, int j)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	if (j == 0)
		write (1, "rrr\n", 4);
}
