/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:16:37 by kkoujan           #+#    #+#             */
/*   Updated: 2025/02/01 17:30:56 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotation(t_list **head, char stack)
{
	if (!head)
		return ;
	if (!*head)
		return ;
	*head = ft_lstrev(*head);
	rotation(head, 's');
	*head = ft_lstrev(*head);
	if (stack == 'a')
		ft_printf("rra\n");
	if (stack == 'b')
		ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrotation(stack_a, 's');
	rrotation(stack_b, 's');
	ft_printf("rrr\n");
}

void	checker_rrr(t_list **stack_a, t_list **stack_b)
{
	rrotation(stack_a, 's');
	rrotation(stack_b, 's');
}

void	checker_rr(t_list **stack_a, t_list **stack_b)
{
	rotation(stack_a, 's');
	rotation(stack_b, 's');
}

void	checker_ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 's');
	swap(stack_b, 's');
}
