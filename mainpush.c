/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:00:21 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/18 17:09:47 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = ft_check_creat(argc, argv);
	if (argc < 2)
		return (0);
	if (!ft_checksorted(a, 'a'))
	{
		if (ft_stacksize(a) == 2)
			ft_sa(&a, 0);
		else if (ft_stacksize(a) == 3)
			ft_movthree(&a);
		else if (ft_stacksize(a) == 4)
			ft_movfour(&a);
		else if (ft_stacksize(a) == 5)
			ft_movfive(&a);
		else
			ft_order(&a);
	}
	ft_stackfree(&a);
	ft_stackfree(&b);
	return (0);
}
