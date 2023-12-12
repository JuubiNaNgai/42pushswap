/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_do.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:44:17 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/07 18:10:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	do_rarb(t_push_swap **stack_a, t_push_swap **stack_b, long nb, char aorb)
{
	if (aorb == 'b')
	{
		while ((*stack_b)->nb != nb && get_index_place_a(*stack_a, nb) > 0)
			rr(stack_a, stack_b, 1);
		while ((*stack_b)->nb != nb)
			rb(stack_b, 1);
		while (get_index_place_a(*stack_a, nb) > 0)
			ra(stack_a, 1);
		pa(stack_a, stack_b, 1);
	}
	else
	{
		while ((*stack_a)->nb != nb && get_index_place_b(*stack_b, nb) > 0)
			rr(stack_a, stack_b, 1);
		while ((*stack_a)->nb != nb)
			ra(stack_a, 1);
		while (get_index_place_b(*stack_b, nb) > 0)
			rb(stack_b, 1);
		pb(stack_a, stack_b, 1);
	}
	return (-1);
}

int	do_rrarrb(t_push_swap **stack_a, t_push_swap **stack_b, long nb, char aorb)
{
	if (aorb == 'b')
	{
		while ((*stack_b)->nb != nb && get_index_place_a(*stack_a, nb) > 0)
			rrr(stack_a, stack_b, 1);
		while ((*stack_b)->nb != nb)
			rrb(stack_b, 1);
		while (get_index_place_a(*stack_a, nb) > 0)
			rra(stack_a, 1);
		pa(stack_a, stack_b, 1);
	}
	else
	{
		while ((*stack_a)->nb != nb && get_index_place_b(*stack_b, nb) > 0)
			rrr(stack_a, stack_b, 1);
		while ((*stack_a)->nb != nb)
			rra(stack_a, 1);
		while (get_index_place_b(*stack_b, nb) > 0)
			rrb(stack_b, 1);
		pb(stack_a, stack_b, 1);
	}
	return (-1);
}

int	do_rrarb(t_push_swap **stack_a, t_push_swap **stack_b, long nb, char aorb)
{
	if (aorb == 'b')
	{
		while (get_index_place_a(*stack_a, nb) > 0)
			rra(stack_a, 1);
		while ((*stack_b)->nb != nb)
			rb(stack_b, 1);
		pa(stack_a, stack_b, 1);
	}
	else
	{
		while ((*stack_a)->nb != nb)
			rra(stack_a, 1);
		while (get_index_place_b(*stack_b, nb) > 0)
			rb(stack_b, 1);
		pb(stack_a, stack_b, 1);
	}
	return (-1);
}

int	do_rarrb(t_push_swap **stack_a, t_push_swap **stack_b, long nb, char aorb)
{
	if (aorb == 'b')
	{
		while (get_index_place_a(*stack_a, nb) > 0)
			ra(stack_a, 1);
		while ((*stack_b)->nb != nb)
			rrb(stack_b, 1);
		pa(stack_a, stack_b, 1);
	}
	else
	{
		while ((*stack_a)->nb != nb)
			ra(stack_a, 1);
		while (get_index_place_b(*stack_b, nb) > 0)
			rrb(stack_b, 1);
		pb(stack_a, stack_b, 1);
	}
	return (-1);
}