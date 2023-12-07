/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:49:50 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/07 19:28:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate_calcul_a(t_push_swap **stack_a, t_push_swap **stack_b)
{
	int			i;
	t_push_swap	*tmp;

	tmp = *stack_b;
	i = instr_to_rbra(stack_a, stack_b, tmp->nb);
	while (tmp)
	{
		if (i > instr_to_rbra(stack_a, stack_b, tmp->nb))
			i = instr_to_rbra(stack_a, stack_b, tmp->nb);
		if (i > instr_to_rrbrra(stack_a, stack_b, tmp->nb))
			i = instr_to_rrbrra(stack_a, stack_b, tmp->nb);
		if (i > instr_to_rrbra(stack_a, stack_b, tmp->nb))
			i = instr_to_rrbra(stack_a, stack_b, tmp->nb);
		if (i > instr_to_rbrra(stack_a, stack_b, tmp->nb))
			i = instr_to_rbrra(stack_a, stack_b, tmp->nb);
		tmp = tmp->next;
	}
	return (i);
}

int	instr_to_rbra(t_push_swap **stack_a, t_push_swap **stack_b, long nb)
{
	int	i;

	i = get_index_place_a(*stack_a, nb);
	if (i < get_index(stack_b, nb))
		i = get_index(stack_b, nb);
	return (i);
}

int	instr_to_rrbrra(t_push_swap **stack_a, t_push_swap **stack_b, long nb)
{
	int	i;

	i = 0;
	if (get_index_place_a(*stack_a, nb) != 0)
		i = ft_lstsize(*stack_a) - get_index_place_a(*stack_a, nb);
	if ((i < ft_lstsize(*stack_b) - get_index(stack_b, nb)) && get_index(stack_b, nb))
		i = ft_lstsize(*stack_b) - get_index(stack_b, nb);
	return (i);
}

int	instr_to_rbrra(t_push_swap **stack_a, t_push_swap **stack_b, long nb)
{
	int	i;

	i = ft_lstsize(*stack_a) - get_index_place_a(*stack_a, nb);
	i += get_index(stack_b, nb);
	return (i);
}

int	instr_to_rrbra(t_push_swap **stack_a, t_push_swap **stack_b, long nb)
{
	int	i;

	i = ft_lstsize(*stack_b) - get_index(stack_b, nb);
	i += get_index_place_a(*stack_a, nb);
	return (i);
}
