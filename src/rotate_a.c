/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:49:50 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/04 15:59:51 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate_calcul_a(t_push_swap **stack_a, t_push_swap **stack_b)
{
	int			i;
	t_push_swap	*tmp;

	tmp = *stack_a;
	i = instr_to_rarb(stack_a, stack_b, tmp->nb);
	while (tmp->next)
	{
		if (i < instr_to_rarb(stack_a, stack_b, tmp->nb))
			i = instr_to_rarb(stack_a, stack_b, tmp->nb);
		if (i < instr_to_rrarrb(stack_a, stack_b, tmp->nb))
			i = instr_to_rrarrb(stack_a, stack_b, tmp->nb);
		if (i < instr_to_rrarb(stack_a, stack_b, tmp->nb))
			i = instr_to_rrarb(stack_a, stack_b, tmp->nb);
		if (i < instr_to_rarrb(stack_a, stack_b, tmp->nb))
			i = instr_to_rarrb(stack_a, stack_b, tmp->nb);
		tmp = tmp->next;
	}
	return (i);
}

int	instr_to_rbra(t_push_swap **stack_a, t_push_swap **stack_b, long nb)
{
	int	i;

	i = get_index_place_a(stack_a, nb);
	if (i < get_index(stack_b, nb))
		i = get_index(stack_b, nb);
	return (i);
}

int	instr_to_rrbrra(t_push_swap **stack_a, t_push_swap **stack_b, long nb)
{
	int	i;

	i = 0;
	i = ft_lstsize(*stack_a) - get_index_place_a(stack_a, nb);
	if (i < ft_lstsize(*stack_b) - get_index_place_a(stack_b, nb))
		i = ft_lstsize(*stack_b) - get_index_place_a(stack_b, nb);
	return (i);
}

int	instr_to_rbrra(t_push_swap **stack_a, t_push_swap **stack_b, long nb)
{
	int	i;

	i = ft_lstsize(*stack_b) - get_index(stack_b, nb);
	i += get_index_place_a(stack_a, nb);
	return (i);
}

int	instr_to_rrbra(t_push_swap **stack_a, t_push_swap **stack_b, long nb)
{
	int	i;

	i = ft_lstsize(*stack_a) - get_index_place_a(stack_a, nb);
	i += get_index(stack_b, nb);
	return (i);
}
