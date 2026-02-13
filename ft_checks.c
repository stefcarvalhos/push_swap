/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:13:55 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/18 16:49:07 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_atoicheck(const char *str, t_stack *stack, char **temp)
{
	int				sig;
	long long int	num;

	num = 0;
	sig = 1;
	if (ft_strlen(str) > 11)
		ft_checkdigits("a", stack, temp);
	while (*str == 32 || *str == '\t')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sig = -1;
		str++;
	}
	ft_checkdigits(&*str, stack, temp);
	while (*str)
	{
		ft_checkdigits(&*str, stack, temp);
		num = num * 10 + (*str - 48);
		str++;
	}
	if ((num * sig) > 2147483647 || (num * sig) < -2147483648)
		ft_checkdigits("a", stack, temp);
	return (num * sig);
}

int	ft_duplicate(t_stack *stack, int n)
{
	while (stack)
	{
		if (stack->nbr == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_stack	*ft_strcheck(char **av)
{
	t_stack	*a;
	char	**temp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	temp = ft_split(av[1], 32);
	while (temp[i])
	{
		j = ft_atoicheck(temp[i], a, temp);
		if (ft_duplicate(a, j))
		{
			ft_strfree(temp);
			free(temp);
			ft_stackfree(&a);
			ft_error ();
		}
		ft_addback(&a, ft_newnode(j));
		i++;
	}
	ft_strfree(temp);
	free(temp);
	return (a);
}

t_stack	*ft_check_creat(int ac, char **av)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (ac == 2)
		a = ft_strcheck(av);
	else
	{
		while (i < ac)
		{
			j = ft_atoicheck(av[i], a, NULL);
			if (ft_duplicate(a, j))
			{
				ft_stackfree(&a);
				free(a);
				ft_error ();
			}
			ft_addback(&a, ft_newnode(j));
			i++;
		}
	}
	return (a);
}

int	ft_checksorted(t_stack *stack, char s)
{
	t_stack	*temp;

	if (!stack || !(stack)->next)
		return (1);
	temp = stack;
	if (s == 'a')
	{
		while (temp->next)
		{
			if (temp->next->nbr < temp->nbr)
				return (0);
			temp = temp->next;
		}
	}
	if (s == 'b')
	{
		while (temp->next)
		{
			if (temp->next->nbr > temp->nbr)
				return (0);
			temp = temp->next;
		}
	}
	return (1);
}
