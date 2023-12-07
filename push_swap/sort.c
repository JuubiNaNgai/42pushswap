/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:10:12 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/07 19:30:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sortb(t_push_swap **stack_a, t_push_swap **stack_b)
{
	t_push_swap	*tmp;
	int			i;

	if (!is_sorted(*stack_a) && ft_lstsize(*stack_a) > 3)
		pb(stack_a, stack_b, 1);
	if (!is_sorted(*stack_a) && ft_lstsize(*stack_a) > 3)
		pb(stack_a, stack_b, 1);
	while (!is_sorted(*stack_a) && ft_lstsize(*stack_a) > 3)
	{
		tmp = *stack_a;
		i = rotate_calcul_b(stack_a, stack_b);
		while (i != -1)
		{
			if (i == instr_to_rarb(stack_a, stack_b, tmp->nb))
				i = do_rarb(stack_a, stack_b, tmp->nb, 'a');
			else if (i == instr_to_rrarrb(stack_a, stack_b, tmp->nb))
				i = do_rrarrb(stack_a, stack_b, tmp->nb, 'a');
			else if (i == instr_to_rrarb(stack_a, stack_b, tmp->nb))
				i = do_rrarb(stack_a, stack_b, tmp->nb, 'a');
			else if (i == instr_to_rarrb(stack_a, stack_b, tmp->nb))
				i = do_rarrb(stack_a, stack_b, tmp->nb, 'a');
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
				i = do_rarb(stack_a, stack_b, tmp->nb, 'b');
			else if (i == instr_to_rrbrra(stack_a, stack_b, tmp->nb))
				i = do_rrarrb(stack_a, stack_b, tmp->nb, 'b');
			else if (i == instr_to_rrbra(stack_a, stack_b, tmp->nb))
				i = do_rarrb(stack_a, stack_b, tmp->nb, 'b');
			else if (i == instr_to_rbrra(stack_a, stack_b, tmp->nb))
				i = do_rrarb(stack_a, stack_b, tmp->nb, 'b');
			else
				tmp = tmp->next;
		}
	}
}

void	ft_sort(t_push_swap **stack_a)
{
	t_push_swap	*stack_b;
	int			i;

	stack_b = NULL;
	if (!is_sorted(*stack_a) && ft_lstsize(*stack_a) == 2)
	{
		sa(stack_a, 1);
		return ;
	}
	sortb(stack_a, &stack_b);
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	t_push_swap	*tmpa = *stack_a;
	printf("A ; \n");
	while (tmpa)
	{
		printf("%ld - ", tmpa->nb);
		tmpa = tmpa->next;
	}
	t_push_swap	*tmpb = stack_b;
	printf("\nB ; \n");
	while (tmpb)
	{
		printf("%ld - ", tmpb->nb);
		tmpb = tmpb->next;
	}
	sorta(stack_a, &stack_b);
	
	i = get_index(stack_a, get_min(stack_a));
	if (i > ft_lstsize(*stack_a) - i)
		while ((*stack_a)->nb != get_min(stack_a))
			rra(stack_a, 1);
	else
	{
		while ((*stack_a)->nb != get_min(stack_a))
		{
			ra(stack_a, 1);
		}
	}
	
	while (*stack_a)
	{
		printf("%ld - ", (*stack_a)->nb);
		*stack_a = (*stack_a)->next;
	}
	printf("\nB : \n");
	while (stack_b)
	{
		printf("%ld - ", stack_b->nb);
		stack_b = stack_b->next;
	}
	return ;
}
