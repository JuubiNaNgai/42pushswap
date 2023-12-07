/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:13:51 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/07 20:10:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_strnbrs(t_push_swap **nbrs, char *argv)
{
	int			i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == 32 || (argv[i] >= 9 && argv[i] <= 13))
			i++;
		else if ((argv[i] >= '0' && argv[i] <= '9')
			|| argv[i] == '-' || argv[i] == '+')
		{
			if (lst_init(nbrs, argv + i) == -1)
				return (-1);
			while (argv[i] >= '0' && argv[i] <= '9')
				i++;
		}
		else
			return (-1);
	}
	return (0);
}

int	get_argsnbrs(int argc, char **argv, t_push_swap **nbrs)
{
	int			i;

	i = 1;
	*nbrs = NULL;
	while (i < argc)
	{
		if (get_strnbrs(nbrs, argv[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}

int	get_args(int argc, char **argv, t_push_swap **nbrs)
{
	if (argc < 2)
		return (-1);
	else
		if (get_argsnbrs(argc, argv, nbrs) == -1)
			return (-1);
	return (0);
}

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
