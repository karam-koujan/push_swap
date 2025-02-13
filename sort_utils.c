/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:22:02 by kkoujan           #+#    #+#             */
/*   Updated: 2025/02/13 21:01:23 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_limit_idx(int	*arr, int size, char type)
{
	int	i;
	int	limit;
	int	limit_idx;

	i = -1;
	limit = arr[i + 1];
	limit_idx = 0;
	while (++i < size)
	{
		if (arr[i] > limit && type == 'x')
		{
			limit = arr[i];
			limit_idx = i;
		}
		if (arr[i] < limit && type == 'n')
		{
			limit = arr[i];
			limit_idx = i;
		}
	}
	return (limit_idx);
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

void	move_num(t_list **stack_a, t_list **stack_b, int max, char stack)
{
	int		size;
	int		i;
	char	rs;

	size = ft_lstsize(*stack_b);
	i = -1;
	if (stack == 'a')
		rs = 'b';
	else
		rs = 'a';
	if (max <= size / 2)
	{
		while (++i < max)
			rotation(stack_b, rs);
	}
	else
	{
		while (++i < size - max)
			rrotation(stack_b, rs);
	}
	push(stack_a, stack_b, stack);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*sa;
	t_list	*sb;
	int		*arr;

	sa = *stack_a;
	sb = *stack_b;
	if (ft_lstsize(sa) == 1)
		return ;
	arr = list_to_arr(*stack_a);
	if (!arr)
		return ;
	if (ft_lstsize(sa) == 2)
		return (sort_two(stack_a), free(arr));
	if (ft_lstsize(sa) == 3)
		return (sort_three(stack_a), free(arr));
	if (ft_lstsize(sa) > 3 && ft_lstsize(sa) <= 5)
		return (sort_five(stack_a, stack_b), free(arr));
	if (ft_lstsize(sa) > 5 && ft_lstsize(sa) <= 100)
		sort_chunk(stack_a, stack_b, arr, 16);
	if (ft_lstsize(sa) > 100)
		sort_chunk(stack_a, stack_b, arr, 32);
	free(arr);
}
