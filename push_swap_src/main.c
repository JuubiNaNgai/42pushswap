/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:13:51 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/12 14:34:42 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	*nums;

	if (get_args(argc, argv, &nums) == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!is_sorted(nums))
		ft_sort(&nums);
	free_lst(&nums);
	return (0);
}
