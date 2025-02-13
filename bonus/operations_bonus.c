/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:17:46 by kkoujan           #+#    #+#             */
/*   Updated: 2025/02/08 09:27:25 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_list **head, char stack)
{
	int		tmp;
	t_list	*l;

	if (!head && !*head)
		return ;
	l = *head;
	if (ft_lstsize(l) < 2)
		return ;
	tmp = l->content;
	l->content = l->next->content;
	l->next->content = tmp;
	if (stack == 'a')
		ft_printf("sa\n");
	if (stack == 'b')
		ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 's');
	swap(stack_b, 's');
	ft_printf("ss\n");
}

void	push(t_list **stack_a, t_list **stack_b, char stack)
{
	t_list	*lb;
	t_list	*top_b;

	if (!stack_b || !*stack_b)
		return ;
	lb = *stack_b;
	top_b = lb->next;
	lb->next = *stack_a;
	*stack_a = lb;
	*stack_b = top_b;
	if (stack == 'a')
		ft_printf("pa\n");
	else if (stack == 'b')
		ft_printf("pb\n");
}

void	rotation(t_list **head, char stack)
{
	int		top;
	t_list	*l;
	t_list	*top_l;

	if (!head)
		return ;
	if (!*head)
		return ;
	top_l = *head;
	l = *head;
	top = l->content;
	while (l->next)
	{
		swap(&(l->next), 's');
		l = l->next;
	}
	top_l->content = l->content;
	l->content = top;
	if (stack == 'a')
		ft_printf("ra\n");
	if (stack == 'b')
		ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotation(stack_a, 's');
	rotation(stack_b, 's');
	ft_printf("rr\n");
}
