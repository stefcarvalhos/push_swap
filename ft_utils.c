/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:03:43 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/17 20:01:41 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_checkdigits(const char *str, t_stack *stack, char **temp)
{
	if (!ft_isdigit(*str))
	{
		ft_stackfree(&stack);
		free(stack);
		if (temp)
		{
			ft_strfree(temp);
			free(temp);
		}
		ft_error();
	}
}

void	ft_strfree(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

void	ft_stackfree(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		(*stack)->nbr = 0;
		free(*stack);
		*stack = temp;
	}
}
