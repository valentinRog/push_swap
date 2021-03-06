/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:27:07 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/07 11:27:50 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef struct s_list
{
	int				val;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_ps
{
	t_list	*a;
	t_list	*b;
	size_t	ops;
	bool	print;
	bool	prepare;
}	t_ps;

/*lst*/
t_list			*lst_new(int val);
int				lst_size(t_list *lst);
t_list			*lst_last(t_list *lst);
void			lst_add_front(t_list **alst, t_list *new_node);
void			lst_add_back(t_list **alst, t_list *new_node);

/*op*/
void			swap(t_list **head);
void			rotate(t_list **head);
void			reverse_rotate(t_list **head);
void			push(t_list **a_src, t_list **dst);

/*do_op*/
int				do_op_str(char *str, t_ps *ps);
void			do_op(enum e_op op, t_ps *ps);

/*sort*/
bool			is_sorted(t_list *head);

/*clear*/
void			ps_clear(t_ps *ps);

/*utils*/
size_t			str_len(const char *str);
void			put_str_fd(char *s, int fd);
int				str_cmp(char *s1, char *s2);
int				atoi_error(char *str, bool *error);

/*get_next_line*/
char			*get_next_line(int fd);

#endif
