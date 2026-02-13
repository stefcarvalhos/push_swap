/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:34:41 by marvin            #+#    #+#             */
/*   Updated: 2025/02/26 19:34:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_calc_rr(t_stack *a, t_stack *b, int npush, char stackdst)
{
	int	mov;

	mov = 0;
	if (stackdst == 'b')
	{
		mov = ft_find_posit_b(b, npush);
		if (mov < ft_find_index(&a, npush))
			mov = ft_find_index(&a, npush);
	}
	else if (stackdst == 'a')
	{
		mov = ft_find_posit_a(a, npush);
		if (mov < ft_find_index(&b, npush))
			mov = ft_find_index(&b, npush);
	}
	return (mov);
}

int	ft_calc_rrr(t_stack *a, t_stack *b, int npush, char stackdst)
{
	int	mov;

	mov = 0;
	if (stackdst == 'b')
	{
		if (ft_find_posit_b(b, npush))
			mov = ft_stacksize(b) - ft_find_posit_b(b, npush);
		if ((mov < (ft_stacksize(a) - ft_find_index(&a, npush)))
			&& ft_find_index(&a, npush))
			mov = ft_stacksize(a) - ft_find_index(&a, npush);
	}
	else if (stackdst == 'a')
	{
		if (ft_find_posit_a(a, npush))
			mov = ft_stacksize(a) - ft_find_posit_a(a, npush);
		if ((mov < (ft_stacksize(b) - ft_find_index(&b, npush)))
			&& ft_find_index(&b, npush))
			mov = ft_stacksize(b) - ft_find_index(&b, npush);
	}
	return (mov);
}

int	ft_calc_rraerb(t_stack *a, t_stack *b, int npush, char stackdst)
{
	int	mov;

	mov = 0;
	if (stackdst == 'b')
	{
		if (ft_find_index(&a, npush))
			mov = ft_stacksize(a) - ft_find_index(&a, npush);
		mov = ft_find_posit_b(b, npush) + mov;
	}
	else if (stackdst == 'a')
	{
		if (ft_find_posit_a(a, npush))
			mov = ft_stacksize(a) - ft_find_posit_a(a, npush);
		mov = ft_find_index(&b, npush) + mov;
	}
	return (mov);
}

int	ft_calc_raerrb(t_stack *a, t_stack *b, int npush, char stackdst)
{
	int	mov;

	mov = 0;
	if (stackdst == 'b')
	{
		if (ft_find_posit_b(b, npush))
			mov = ft_stacksize(b) - ft_find_posit_b(b, npush);
		mov = ft_find_index(&a, npush) + mov;
	}
	else if (stackdst == 'a')
	{
		if (ft_find_index(&b, npush))
			mov = ft_stacksize(b) - ft_find_index(&b, npush);
		mov = ft_find_posit_a(a, npush) + mov;
	}
	return (mov);
}
