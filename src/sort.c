/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:10:12 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/04 16:08:09 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sortb(t_push_swap **stack_a, t_push_swap **stack_b)
{
	t_push_swap	*tmp;
	int			i;

	if (!is_sorted(*stack_a) && ft_lstsize(*stack_a) >= 3)
	{
		pb(stack_a, stack_b, 1);
		pb(stack_a, stack_b, 1);
	}
	while (!is_sorted(*stack_a) && ft_lstsize(*stack_a) >= 3)
	{
		tmp = *stack_a;
		i = rotate_calcul_b(stack_a, stack_b);
		while (i != -1)
		{
			if (i == instr_to_rarb(stack_a, stack_b, tmp->nb))
				do_rarb(stack_a, stack_b, tmp->nb, 'b');
			if (i == instr_to_rrarrb(stack_a, stack_b, tmp->nb))
				do_rrarrb(stack_a, stack_b, tmp->nb, 'b');
			if (i == instr_to_rrarb(stack_a, stack_b, tmp->nb))
				do_rrarb(stack_a, stack_b, tmp->nb, 'b');
			if (i == instr_to_rarrb(stack_a, stack_b, tmp->nb))
				do_rarrb(stack_a, stack_b, tmp->nb, 'b');
			tmp = tmp->next;
		}
	}
}

void	sort_three(t_push_swap **stack_a)
{
	if ((*stack_a)->nb == get_min(stack_a))
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if ((*stack_a)->nb == get_max(stack_a))
	{
		ra(stack_a, 1);
		if (!is_sorted(*stack_a))
			sa(stack_a, 1);
	}
	else
	{
		if (get_index(stack_a, get_max(stack_a)) == 1)
			rra(stack_a, 1);
		else
			sa(stack_a, 1);
	}
}

void	sorta(t_push_swap **stack_a, t_push_swap **stack_b)
{
	t_push_swap	*tmp;
	int			i;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = rotate_calcul_a(stack_a, stack_b);
		while (i != -1)
		{
			if (i == instr_to_rbra(stack_a, stack_b, tmp->nb))
				do_rarb(stack_a, stack_b, tmp->nb, 'a');
			if (i == instr_to_rrbrra(stack_a, stack_b, tmp->nb))
				do_rrarrb(stack_a, stack_b, tmp->nb, 'a');
			if (i == instr_to_rrbra(stack_a, stack_b, tmp->nb))
				do_rrarb(stack_a, stack_b, tmp->nb, 'a');
			if (i == instr_to_rbrra(stack_a, stack_b, tmp->nb))
				do_rarrb(stack_a, stack_b, tmp->nb, 'a');
			tmp = tmp->next;
		}
	}
}

void	ft_sort(t_push_swap **stack_a)
{
	t_push_swap	*stack_b;
	int			i;

	if (!is_sorted(*stack_a) && ft_lstsize(*stack_a) == 2)
	{
		sa(stack_a, 1);
		return ;
	}
	sortb(stack_a, &stack_b);
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	sorta(stack_a, &stack_b);
	i = get_index(stack_a, get_min(stack_a));
	if (i > ft_lstsize(*stack_a) - i)
		while ((*stack_a)->nb != get_min(stack_a))
			rra(stack_a, 1);
	else
		while ((*stack_a)->nb != get_min(stack_a))
			ra(stack_a, 1);
}
