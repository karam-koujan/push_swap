/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:44:00 by kkoujan           #+#    #+#             */
/*   Updated: 2025/02/07 12:44:25 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_decreasing(t_list **stack_a, int *arr, int size)
{
	int		count;
	int		diff;
	t_list	*la;

	la = *stack_a;
	count = 0;
	while (la && la->next)
	{
		diff = calculate_idx(arr, size, la->content) - \
		calculate_idx(arr, size, la->next->content);
		if (diff == 2 || diff == 3 || diff == 4)
			count++;
		la = la->next;
	}
	if (count * 10 >= size * 6)
		return (1);
	return (0);
}
