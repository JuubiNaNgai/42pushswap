/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:09:00 by marvin            #+#    #+#             */
/*   Updated: 2023/12/09 00:20:23 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_line(t_push_swap **a, t_push_swap **b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a, 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b, 0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(a, b, 0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a, 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b, 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a, 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b, 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	else
		return (1);
	return (0);
}

void	check_lst(t_push_swap **a, t_push_swap **b)
{
	char	*line;
	int		err;

	line = get_next_line(0);
	err = 0;
	while ((line && *line != '\n') || err)
	{
		err = check_line(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (err)
		write(1, "Error\n", 6);
	else if (*b)
		write(1, "KO\n", 3);
	else if (!is_sorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_push_swap	*a;
	t_push_swap	*b;

	if (get_args(argc, argv, &a) == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!is_sorted(a))
		check_lst(&a, &b);
	free_lst(&a);
	free_lst(&b);
	return (0);
}
