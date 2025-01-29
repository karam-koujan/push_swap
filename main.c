/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:51:48 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/29 13:37:58 by kkoujan          ###   ########.fr       */
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

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*sa;
	t_list	*sb;

	sa = *stack_a;
	sb = *stack_b;
	if (ft_lstsize(sa) == 3)
		sort_three(stack_a);
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
	if (is_dup(head) && write(2, "Error\n", 6))
		return (ft_lstclear(&head, free), 1);
	// ft_lstclear(&head, free);
	lb = NULL;
	sort(&head, &lb);
	print_list(head);
}
