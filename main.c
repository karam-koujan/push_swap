/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:51:48 by kkoujan           #+#    #+#             */
/*   Updated: 2025/02/16 12:22:08 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_list **stack_a)
{
	t_list	*prev;
	t_list	*la;

	la = *stack_a;
	prev = la;
	while (la)
	{
		if (la->content < prev->content)
			return (0);
		prev = la;
		la = la->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*lb;

	head = NULL;
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
	if (is_dup(head) && write(2, "Error\n", 6))
		return (ft_lstclear(&head, free), 1);
	lb = NULL;
	if (check_sorted(&head))
		return (ft_lstclear(&head, free), 0);
	sort(&head, &lb);
	ft_lstclear(&head, free);
	ft_lstclear(&lb, free);
}
