/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:20:18 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/26 15:20:20 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*l;
	int		count;

	count = 1;
	l = lst;
	if (l == NULL)
		return (0);
	while (l->next)
	{
		count++;
		l = l->next;
	}
	return (count);
}
