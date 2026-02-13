/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:44:05 by stda-sil          #+#    #+#             */
/*   Updated: 2025/03/21 18:44:49 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ft_sa(t_stack **a, int j)
{
	if (!a || !*a || !(*a)->next)
		return ;
	ft_swap(a);
	if (j == 0)
		write (1, "sa\n", 3);
}

void	ft_sb(t_stack **b, int j)
{
	if (!b || !*b || !(*b)->next)
		return ;
	ft_swap(b);
	if (j == 0)
		write (1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b, int j)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	ft_swap(a);
	ft_swap(b);
	if (j == 0)
		write (1, "ss\n", 3);
}
