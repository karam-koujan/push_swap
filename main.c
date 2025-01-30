/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:51:48 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/30 20:28:50 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (b < a && b < c && a < c)
		swap(stack_a, 'a');
	else if (b < a && b < c && a > c)
		rotation(stack_a, 'a');
	else if (b > a && b > c && a > c)
		rrotation(stack_a, 'a');
	else if (b > c && b < a)
	{
		swap(stack_a, 'a');
		sort_three(stack_a);
	}
	else if (b > c && b > a && a < c)
	{
		swap(stack_a, 'a');
		sort_three(stack_a);
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		a;
	int		b;
	int		c;
	t_list	*sb;

	push(stack_b, stack_a, 'b');
	push(stack_b, stack_a, 'b');
	sb = *stack_b;
	sort_three(stack_a);
	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (sb->content < sb->next->content)
		swap(stack_b, 'b');
	while (sb)
	{
		if (sb->content < a)
			push(stack_a, stack_b, 'a');
		if (sb->content > c)
		{
			push(stack_a, stack_b, 'a');
			rotation(stack_a, 'a');
		}
		else if (sb->content < c && sb->content > a && sb->content < b)
		{
			push(stack_a, stack_b, 'a');
			swap(stack_a, 'a');
		}
		else if (sb->content < c && sb->content > a && sb->content > b)
		{
			rotation(stack_a, 'a');
			rotation(stack_a, 'a');
			push(stack_a, stack_b, 'a');
			rrotation(stack_a, 'a');
			rrotation(stack_a, 'a');
		}
		sb = sb->next;
	}
}

int	calculate_idx(t_list *stack_a, int nb)
{
	int		idx;
	t_list	*la;

	idx = 0;
	la = stack_a;
	while (la)
	{
		if (la->content < nb)
			idx++;
		la = la->next;
	}
	return (idx);
}

void	move_num(t_list **stack_a, t_list **stack_b, int max)
{
	int	i;

	i = -1;
	if (max <= ft_lstsize(*stack_b) / 2)
		while (++i < max)
			rotation(stack_b, 'b');
	else
		while (++i <= max)
			rrotation(stack_b, 'b');
	push(stack_a, stack_b, 'a');
}

void	insertion_sort(t_list **stack_a, t_list **stack_b)
{
	int		max;
	int		max_i;
	t_list	*lb;
	t_list	*lb2;
	int		i;

	max_i = 0;
	lb = *stack_b;
	lb2 = *stack_b;
	while (lb)
	{
		max = lb->content;
		i = 0;
		while (lb2)
		{
			if (lb2->content > max)
			{
				max_i = i;
				max = lb2->content;
			}
			i++;
			lb2 = lb2->next;
		}
		move_num(stack_a, stack_b, max_i);
		lb = lb->next;
		lb2 = lb;
	}
}

void	sort_chunk(t_list **stack_a, t_list **stack_b, int chunk)
{
	t_list	*la;
	int		idx;
	int		b_idx;

	la = *stack_a;
	b_idx = 0;
	while (la)
	{
		idx = calculate_idx(la, la->content);
		if (idx <= b_idx)
			push(stack_b, stack_a, 'b');
		else if (idx <= chunk + b_idx)
		{
			push(stack_b, stack_a, 'b');
			rotation(stack_b, 'b');
		}
		else
			rotation(stack_a, 'a');
		la = la->next;
		b_idx = ft_lstsize(*stack_b);
	}

	insertion_sort(stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*sa;
	t_list	*sb;

	sa = *stack_a;
	sb = *stack_b;
	if (ft_lstsize(sa) == 3)
		sort_three(stack_a);
	if (ft_lstsize(sa) == 5)
		sort_five(stack_a, stack_b);
	if (ft_lstsize(sa) > 5 && ft_lstsize(sa) <= 100)
		sort_chunk(stack_a, stack_b, 16);
	if (ft_lstsize(sa) >= 500)
		sort_chunk(stack_a, stack_b, 32);
}

void	f(){system("leaks push_swap");}

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*lb;
	// atexit(f);
	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		if (!parse_nums(ft_strdup(av[1]), &head) && write(2, "Error\n", 6))
			return (ft_lstclear(&head, free), 1);
	}
	else if (!parse_nums(arr_strjoin(av + 1, ac - 1), &head) \
	&& write(2, "Error\n", 6))
		return (ft_lstclear(&head, free), 1);
	print_list(head);
	printf("\n");
	if (is_dup(head) && write(2, "Error\n", 6))
		return (ft_lstclear(&head, free), 1);
	// ft_lstclear(&head, free);
	lb = NULL;
	sort(&head, &lb);
	print_list(head);
}
