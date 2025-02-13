/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:40:23 by kkoujan           #+#    #+#             */
/*   Updated: 2025/02/13 21:01:06 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_chunk(t_list **stack_a, t_list **stack_b, int *arr, int chunk)
{
	int		idx;
	int		b_idx;
	int		size;

	b_idx = 0;
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
		else if (is_decreasing(stack_a, arr, size))
			rrotation(stack_a, 'a');
		else
			rotation(stack_a, 'a');
		b_idx = ft_lstsize(*stack_b);
	}
	return (insertion_sort(stack_a, stack_b));
}

void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, 'a');
}

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
	int		limit;
	int		*arr;
	int		size;

	arr = list_to_arr(*stack_a);
	size = ft_lstsize(*stack_a);
	if (!arr)
		return ;
	limit = find_limit_idx(arr, ft_lstsize(*stack_a), 'n');
	free(arr);
	move_num(stack_b, stack_a, limit, 'b');
	if (size == 5)
	{
		arr = list_to_arr(*stack_a);
		if (!arr)
			return ;
		limit = find_limit_idx(arr, ft_lstsize(*stack_a), 'x');
		move_num(stack_b, stack_a, limit, 'b');
		free(arr);
	}
	sort_three(stack_a);
	if (size < 5)
		return (push(stack_a, stack_b, 'a'));
	return (push(stack_a, stack_b, 'a'), rotation(stack_a, 'a') \
	, push(stack_a, stack_b, 'a'));
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
		move_num(stack_a, stack_b, max_i, 'a');
	}
}
