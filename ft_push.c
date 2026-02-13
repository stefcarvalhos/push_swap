/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:16:50 by stda-sil          #+#    #+#             */
/*   Updated: 2025/03/21 18:42:02 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*first_from;

	if (!(*stack_from) || !stack_from)
		return ;
	first_from = *stack_from;
	*stack_from = first_from->next;
	first_from->next = NULL;
	ft_stackadd_front(stack_to, first_from);
}

void	ft_pa(t_stack **b, t_stack **a, int j)
{
	if (!b || !*b)
		return ;
	ft_push(b, a);
	if (j == 0)
		write (1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b, int j)
{
	if (!a || !*a)
		return ;
	ft_push(a, b);
	if (j == 0)
		write (1, "pb\n", 3);
}
