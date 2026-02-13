/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:23:22 by stda-sil          #+#    #+#             */
/*   Updated: 2025/02/06 18:23:22 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Create a new node
t_stack	*ft_newnode(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error();
	new->nbr = n;
	new->next = NULL;
	return (new);
}

//Add a node to the end of the stack
void	ft_addback(t_stack **stack, t_stack *newnode)
{
	if (!stack || !newnode)
		return ;
	if (!*stack)
		*stack = newnode;
	else
		ft_stacklast(*stack)->next = newnode;
}

//Add a node to the top of the stack
void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (stack && new)
	{
		new->next = *stack;
		*stack = new;
	}
}

//Returns the last node in the stack
t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
