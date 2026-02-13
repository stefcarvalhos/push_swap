/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:51:57 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/18 16:52:36 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
}			t_stack;

int		ft_atoicheck(const char *str, t_stack *stack, char **temp);
int		ft_duplicate(t_stack *stack, int n);
t_stack	*ft_strcheck(char **av);
t_stack	*ft_check_creat(int ac, char **av);
int		ft_checksorted(t_stack *stack, char s);
void	ft_error(void);
void	ft_checkdigits(const char *str, t_stack *stack, char **temp);
void	ft_strfree(char **str);
void	ft_stackfree(t_stack **stack);
t_stack	*ft_newnode(int n);
void	ft_addback(t_stack **stack, t_stack *newnode);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_swap(t_stack **stack);
void	ft_addback(t_stack **stack, t_stack *newnode);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_stacklast(t_stack *stack);
int		ft_stacksize(t_stack *stack);
void	ft_push(t_stack **stack_from, t_stack **stack_to);
void	ft_pa(t_stack **b, t_stack **a, int j);
void	ft_pb(t_stack **a, t_stack **b, int j);
void	ft_swap(t_stack **stack);
void	ft_sa(t_stack **a, int j);
void	ft_sb(t_stack **b, int j);
void	ft_ss(t_stack **a, t_stack **b, int j);
void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **a, int j);
void	ft_rb(t_stack **b, int j);
void	ft_rr(t_stack **a, t_stack **b, int j);
void	ft_reverse_rotate(t_stack **stack);
void	ft_rra(t_stack **a, int j);
void	ft_rrb(t_stack **b, int j);
void	ft_rrr(t_stack **a, t_stack **b, int j);
void	ft_movthree(t_stack **a);
int		ft_find_index(t_stack **stack, int num);
int		ft_nbrmin(t_stack *stack);
int		ft_nbrmax(t_stack *stack);
void	ft_movfour(t_stack **a);
void	ft_movfive(t_stack **a);
int		ft_find_posit_b(t_stack *b, int npush);
int		ft_find_posit_a(t_stack *a, int npush);
int		ft_calc_rr(t_stack *a, t_stack *b, int npush, char stackdst);
int		ft_calc_rrr(t_stack *a, t_stack *b, int npush, char stackdst);
int		ft_calc_rraerb(t_stack *a, t_stack *b, int npush, char stackdst);
int		ft_calc_raerrb(t_stack *a, t_stack *b, int npush, char stackdst);
int		ft_comb_rr(t_stack **a, t_stack **b, int npush, char stackfrom);
int		ft_comb_rrr(t_stack **a, t_stack **b, int npush, char stackfrom);
int		ft_comb_rraerb(t_stack **a, t_stack **b, int npush, char stackfrom);
int		ft_comb_raerrb(t_stack **a, t_stack **b, int npush, char stackfrom);
int		ft_typerot_ab(t_stack *a, t_stack *b);
int		ft_typerot_ba(t_stack *a, t_stack *b);
void	ft_pb_upto3(t_stack **a, t_stack **b);
t_stack	*ft_ordermov_b(t_stack **a);
t_stack	**ft_ordermov_a(t_stack **a, t_stack **b);
void	ft_order(t_stack **a);
void	ft_checker_mov(t_stack **a, t_stack **b, const char *mov);
void	ft_checker(t_stack **a, t_stack **b);
void	ft_checker_fnl(t_stack **a, t_stack **b);
#endif
