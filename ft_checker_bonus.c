/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:33:28 by marvin            #+#    #+#             */
/*   Updated: 2025/03/10 15:33:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checker_mov(t_stack **a, t_stack **b, const char *mov)
{
	if (ft_strncmp(mov, "sa\n", 3) == 0)
		ft_sa(a, 1);
	else if (ft_strncmp(mov, "sb\n", 3) == 0)
		ft_sb(b, 1);
	else if (ft_strncmp(mov, "ss\n", 3) == 0)
		ft_ss(a, b, 1);
	else if (ft_strncmp(mov, "pa\n", 3) == 0)
		ft_pa(b, a, 1);
	else if (ft_strncmp(mov, "pb\n", 3) == 0)
		ft_pb(a, b, 1);
	else if (ft_strncmp(mov, "ra\n", 3) == 0)
		ft_ra(a, 1);
	else if (ft_strncmp(mov, "rb\n", 3) == 0)
		ft_rb(b, 1);
	else if (ft_strncmp(mov, "rr\n", 3) == 0)
		ft_rr(a, b, 1);
	else if (ft_strncmp(mov, "rra\n", 4) == 0)
		ft_rra(a, 1);
	else if (ft_strncmp(mov, "rrb\n", 4) == 0)
		ft_rrb(b, 1);
	else if (ft_strncmp(mov, "rrr\n", 4) == 0)
		ft_rrr(a, b, 1);
	else
		ft_error();
}

void	ft_checker_fnl(t_stack **a, t_stack **b)
{
	if (!ft_checksorted(*a, 'a') || *b)
		write (1, "KO\n", 3);
	else if (*b)
		write (1, "KO\n", 3);
	else if (ft_checksorted(*a, 'a') && !*b && *a)
		write (1, "OK\n", 3);
	else
		exit(1);
}

void	ft_checker(t_stack **a, t_stack **b)
{
	char	mov[5];
	int		i;
	int		j;

	while (1)
	{
		i = 0;
		while (i < 4)
		{
			j = read(0, &mov[i], 1);
			if (j <= 0 || mov[i] == '\n')
				break ;
			i++;
		}
		if (j <= 0)
			break ;
		mov[i] = '\n';
		mov[i + 1] = '\0';
		ft_checker_mov(a, b, mov);
	}
	ft_checker_fnl(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = ft_check_creat(argc, argv);
	ft_checker(&a, &b);
	ft_stackfree(&b);
	ft_stackfree(&a);
	return (0);
}
