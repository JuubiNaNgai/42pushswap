/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:20:40 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/04 15:52:24 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(const char *nbr)
{
	int		sign;
	int		res;
	char	*nb;

	sign = 1;
	res = 0;
	nb = (char *)nbr;
	while ((*nb >= 9 && *nb <= 13) || *nb == 32)
		nb++;
	if (*nb == '+' || *nb == '-')
	{
		if (*nb == '-')
			sign *= -1;
		nb++;
	}
	while (*nb != '\0' && (*nb >= '0' && *nb <= '9'))
	{
		res = res * 10 + (*nb - 48);
		nb++;
	}
	return (res * sign);
}

void	free_lst(t_push_swap **lst)
{
	t_push_swap	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->nb = 0;
		free(*lst);
		*lst = tmp;
	}
}
