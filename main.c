/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:51:48 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/26 17:22:48 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f(){system("leaks push_swap");}

int	main(int ac, char **av)
{
	t_list	*head;
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
	t_list *lb;
	lb = NULL;
	swap(&head,'a');
	printf("\n");
	print_list(head);
	push(&lb, &head, 'b');
	push(&lb, &head, 'b');
	push(&lb, &head, 'b');
	printf("\n");
	print_list(lb);
	printf("\n");
	print_list(head);
	// rotation(&head, 'a');
	// rotation(&lb, 'b');
	rr(&head,&lb);
	print_list(lb);
	printf("\n");
	print_list(head);
	rrr(&head, &lb);
	print_list(lb);
	printf("\n");
	print_list(head);
	swap(&head,'a');
	print_list(lb);
	printf("\n");
	print_list(head);
	push(&head, &lb, 'a');
	push(&head, &lb, 'a');
	push(&head, &lb, 'a');
	print_list(lb);
	printf("\n");
	print_list(head);
}
