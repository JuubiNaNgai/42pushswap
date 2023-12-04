/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:50:06 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/04 12:09:50 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_push_swap **stack, int wr)
{
	t_push_swap	*tmp;
	t_push_swap	*tmp2;

	if (!stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	tmp2 = *stack;
	*stack = (*stack)->next;
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp2->next = NULL;
	if (wr)
		write(1, "rra\n", 3);
}

void	rrb(t_push_swap **stack, int wr)
{
	t_push_swap	*tmp;
	t_push_swap	*tmp2;

	if (!stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	tmp2 = *stack;
	*stack = (*stack)->next;
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp2->next = NULL;
	if (wr)
		write(1, "rrb\n", 3);
}

void	rrr(t_push_swap **stack_a, t_push_swap **stack_b, int wr)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (wr)
		write(1, "rrr\n", 3);
}
