/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:22:02 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/31 21:23:18 by kkoujan          ###   ########.fr       */
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
	if (ft_lstsize(sa) > 3 && ft_lstsize(sa) <= 5)
		sort_five(stack_a, stack_b);
	if (ft_lstsize(sa) > 5 && ft_lstsize(sa) <= 100)
		sort_chunk(stack_a, stack_b, 16);
	if (ft_lstsize(sa) > 100)
		sort_chunk(stack_a, stack_b, 32);
}