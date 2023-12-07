/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:39:52 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/07 20:24:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_push_swap
{
	long				nb;
	struct s_push_swap	*next;
}	t_push_swap;

int			check_doublons(t_push_swap **nbrs, char *str);
int			lst_init(t_push_swap **lst, char *str);
t_push_swap	*lst_new(long nb);
t_push_swap	*ft_lstlast(t_push_swap *lst);
void		ft_lstadd_back(t_push_swap **lst, t_push_swap *elem);
int			ft_lstsize(t_push_swap *lst);
int			ft_atoi(const char *nbr);
int			ft_strncmp(const char *s1, const char *s2, size_t n)
void		free_lst(t_push_swap **lst);

void		sa(t_push_swap **stack, int wr);
void		sb(t_push_swap **stack, int wr);
void		ss(t_push_swap **stack_a, t_push_swap **stack_b, int wr);
void		pa(t_push_swap **stack_a, t_push_swap **stack_b, int wr);
void		pb(t_push_swap **stack_a, t_push_swap **stack_b, int wr);
void		ra(t_push_swap **stack, int wr);
void		rb(t_push_swap **stack, int wr);
void		rr(t_push_swap **stack_a, t_push_swap **stack_b, int wr);
void		rra(t_push_swap **stack, int wr);
void		rrb(t_push_swap **stack, int wr);
void		rrr(t_push_swap **stack_a, t_push_swap **stack_b, int wr);

void		ft_sort(t_push_swap **stack_a);
int			is_sorted(t_push_swap *lst);
long		get_min(t_push_swap **stack);
long		get_max(t_push_swap **stack);
int			get_index(t_push_swap **stack, long nb);
int			get_index_place_a(t_push_swap *stack, long nb);
int			get_index_place_b(t_push_swap *stack, long nb);

int			rotate_calcul_b(t_push_swap **stack_a,
				t_push_swap **stack_b);
int			instr_to_rarb(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb);
int			instr_to_rrarrb(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb);
int			instr_to_rarrb(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb);
int			instr_to_rrarb(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb);
int			rotate_calcul_a(t_push_swap **stack_a, t_push_swap **stack_b);
int			instr_to_rbra(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb);
int			instr_to_rrbrra(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb);
int			instr_to_rbrra(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb);
int			instr_to_rrbra(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb);

int			do_rarb(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb, char aorb);
int			do_rrarrb(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb, char aorb);
int			do_rrarb(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb, char aorb);
int			do_rarrb(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb, char aorb);

				
char		*new_line(char *str);
char		*get_line(char *str);
char		*line_to_str(int fd, char *str);
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t count, size_t size);

#endif