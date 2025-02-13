/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:11:11 by kkoujan           #+#    #+#             */
/*   Updated: 2025/02/09 09:09:14 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft_bonus.h"
# include "get_next_line_bonus.h"
# include "ft_printf_bonus.h"

void	free_arr(char **arr);
char	*remove_leading_zeros(char *str);
int		trim(char *str);
int		check_nums(char *str);
char	*arr_strjoin(char **str, size_t size);
int		is_dup(t_list	*head);
int		is_number(char *str);
int		parse_nums(char *str, t_list **head);
void	swap(t_list **head, char stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_a, t_list **stack_b, char stack);
void	rotation(t_list **head, char stack);
void	rr(t_list **stack_a, t_list **stack_b);
t_list	*ft_lstrev(t_list *lst);
void	rrotation(t_list **head, char stack);
void	rrr(t_list **stack_a, t_list **stack_b);
int		*list_to_arr(t_list *stack_a);
void	checker_rrr(t_list **stack_a, t_list **stack_b);
void	checker_rr(t_list **stack_a, t_list **stack_b);
void	checker_ss(t_list **stack_a, t_list **stack_b);

#endif