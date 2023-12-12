/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:10:12 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/12 14:24:33 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sortb(t_push_swap **stack_a, t_push_swap **stack_b)
{
	t_push_swap	*tmp;
	int			i;

	if (*stack_a)
		pb(stack_a, stack_b, 1);
	if (*stack_a)
		pb(stack_a, stack_b, 1);
	while (*stack_a)
	{
		tmp = *stack_a;
		i = rotate_calcul_b(stack_a, stack_b);
		while (i != -1)
		{
			if (i == instr_to_rarb(stack_a, stack_b, tmp->nb))
				i = do_rarb(stack_a, stack_b, tmp->nb);
			else if (i == instr_to_rrarrb(stack_a, stack_b, tmp->nb))
				i = do_rrarrb(stack_a, stack_b, tmp->nb);
			else if (i == instr_to_rrarb(stack_a, stack_b, tmp->nb))
				i = do_rrarb(stack_a, stack_b, tmp->nb);
			else if (i == instr_to_rarrb(stack_a, stack_b, tmp->nb))
				i = do_rarrb(stack_a, stack_b, tmp->nb);
			else
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

void	go_to_min(t_push_swap **stack, char pile)
{
	int	i;

	i = get_index(stack, get_min(stack));
	if (pile == 'a')
	{
		if (i > ft_lstsize(*stack) - i)
			while ((*stack)->nb != get_min(stack))
				rra(stack, 1);
		else
		{
			while ((*stack)->nb != get_min(stack))
				ra(stack, 1);
		}
	}
	else
	{
		if (i > ft_lstsize(*stack) - i)
			while ((*stack)->nb != get_min(stack))
				rrb(stack, 1);
		else
		{
			while ((*stack)->nb != get_min(stack))
				rb(stack, 1);
		}
	}
}

void	sort_five(t_push_swap **stack_a, t_push_swap **stack_b)
{
	go_to_min(stack_a, 'a');
	pb(stack_a, stack_b, 1);
	go_to_min(stack_a, 'a');
	pb(stack_a, stack_b, 1);
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
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}

void	ft_sort(t_push_swap **stack_a)
{
	t_push_swap	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) < 2)
		return ;
	if (!is_sorted(*stack_a) && ft_lstsize(*stack_a) == 2)
	{
		sa(stack_a, 1);
		return ;
	}
	if (!is_sorted(*stack_a) && ft_lstsize(*stack_a) == 3)
	{
		sort_three(stack_a);
		return ;
	}
	if (!is_sorted(*stack_a) && ft_lstsize(*stack_a) == 5)
	{
		sort_five(stack_a, &stack_b);
		return ;
	}
	sortb(stack_a, &stack_b);
	go_to_min(&stack_b, 'b');
	rb(&stack_b, 1);
	while (stack_b)
		pa(stack_a, &stack_b, 1);
}
