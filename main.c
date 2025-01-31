/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:51:48 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/31 12:50:58 by kkoujan          ###   ########.fr       */
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

int	calculate_idx(int *arr, int size, int nb)
{
	int		idx;
	int		i;

	idx = 0;
	i = 0;
	while (i < size)
	{
		if (arr[i] < nb)
			idx++;
		i++;
	}
	return (idx);
}

void	move_num(t_list **stack_a, t_list **stack_b, int max)
{
	int	size;
	int	i;

	size = ft_lstsize(*stack_b);
	i = -1;
	if (max <= size / 2)
	{
		while (++i < max)
			rotation(stack_b, 'b');
	}
	else
	{
		while (++i < size - max)
			rrotation(stack_b, 'b');
	}
	push(stack_a, stack_b, 'a');
}

void	insertion_sort(t_list **stack_a, t_list **stack_b)
{
	int		max;
	int		max_i;
	t_list	*lb;
	int		i;

	while (*stack_b)
	{
		max = (*stack_b)->content;
		max_i = 0;
		lb = *stack_b;
		i = 0;
		while (lb)
		{
			if (lb->content > max)
			{
				max = lb->content;
				max_i = i;
			}
			lb = lb->next;
			i++;
		}
		move_num(stack_a, stack_b, max_i);
	}
}

int	*list_to_arr(t_list *stack_a)
{
	int		*arr;
	t_list	*la;
	int		i;

	i = -1;
	arr = malloc(ft_lstsize(stack_a) * sizeof(int));
	if (!arr)
		return (NULL);
	la = stack_a;
	while (la)
	{
		arr[++i] = la->content;
		la = la->next;
	}
	return (arr);
}
void	sort_chunk(t_list **stack_a, t_list **stack_b, int chunk)
{
	int		idx;
	int		b_idx;
	int		*arr;
	int		size;

	b_idx = 0;
	arr = list_to_arr(*stack_a);
	if (!arr)
		return ;
	size = ft_lstsize(*stack_a);
	while (*stack_a)
	{
		idx = calculate_idx(arr, size, (*stack_a)->content);
		if (idx <= b_idx)
			push(stack_b, stack_a, 'b');
		else if (idx <= chunk + b_idx)
		{
			push(stack_b, stack_a, 'b');
			rotation(stack_b, 'b');
		}
		else
			rotation(stack_a, 'a');
		b_idx = ft_lstsize(*stack_b);
	}
	return (free(arr), insertion_sort(stack_a, stack_b));
}
void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, 'a');
}
void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*sa;
	t_list	*sb;

	sa = *stack_a;
	sb = *stack_b;
	if (ft_lstsize(sa) == 2)
		sort_two(stack_a);
	if (ft_lstsize(sa) == 3)
		sort_three(stack_a);
	if (ft_lstsize(sa) == 5)
		sort_five(stack_a, stack_b);
	if (ft_lstsize(sa) > 5 && ft_lstsize(sa) <= 100)
		sort_chunk(stack_a, stack_b, 16);
	if (ft_lstsize(sa) > 100)
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
	//print_list(head);
	//printf("\n");
	if (is_dup(head) && write(2, "Error\n", 6))
		return (ft_lstclear(&head, free), 1);
	// ft_lstclear(&head, free);
	lb = NULL;
	sort(&head, &lb);
	//print_list(head);
}
