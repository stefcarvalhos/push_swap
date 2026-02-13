/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:27:38 by stda-sil          #+#    #+#             */
/*   Updated: 2025/03/21 18:47:32 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index(t_stack **stack, int num)
{
	int		index;
	t_stack	*temp;

	if (!stack)
		return (-1);
	temp = *stack;
	index = 0;
	while (temp->nbr != num)
	{
		temp = temp->next;
		index++;
	}
	return (index);
}

int	ft_nbrmin(t_stack *stack)
{
	int	min;

	min = stack->nbr;
	while (stack)
	{
		if (stack->nbr < min)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}

int	ft_nbrmax(t_stack *stack)
{
	int	max;

	max = stack->nbr;
	while (stack)
	{
		if (stack->nbr > max)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
}

int	ft_find_posit_b(t_stack *b, int npush)
{
	int		p;
	t_stack	*temp;

	p = 1;
	if (npush > b->nbr && npush < ft_stacklast(b)->nbr)
		p = 0;
	else if (npush < ft_nbrmin(b) || npush > ft_nbrmax(b))
		p = ft_find_index(&b, ft_nbrmax(b));
	else
	{
		temp = b->next;
		while (npush > b->nbr || npush < temp->nbr)
		{
			b = b->next;
			temp = b->next;
			p++;
		}
	}
	return (p);
}

int	ft_find_posit_a(t_stack *a, int npush)
{
	int		p;
	t_stack	*temp;

	p = 1;
	if (npush < a->nbr && npush > ft_stacklast(a)->nbr)
		p = 0;
	else if (npush < ft_nbrmin(a) || npush > ft_nbrmax(a))
		p = ft_find_index(&a, ft_nbrmin(a));
	else
	{
		temp = a->next;
		while (npush < a->nbr || npush > temp->nbr)
		{
			a = a->next;
			temp = a->next;
			p++;
		}
	}
	return (p);
}
