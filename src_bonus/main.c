/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:26:08 by vrogiste          #+#    #+#             */
/*   Updated: 2022/05/26 11:27:07 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "get_next_line.h"

static void	init_ps(t_ps *ps, bool prepare, bool print)
{
	ps->a = NULL;
	ps->b = NULL;
	ps->ops = 0;
	ps->prepare = prepare;
	ps->print = print;
}

static int	fill_arg(t_ps *ps, int argc, char **argv)
{
	int		i;
	t_list	*node;

	i = 1;
	while (i < argc)
	{
		node = lst_new(atoi_error(argv[i], NULL));
		if (!node)
		{
			ps_clear(ps);
			exit(EXIT_FAILURE);
		}
		lst_add_back(&ps->a, node);
		i++;
	}
	return (0);
}

static bool	check_error(int argc, char **argv)
{
	int		i;
	int		j;
	bool	error;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (++j < argc)
			if (!str_cmp(argv[i], argv[j]) && i != j)
				return (true);
		atoi_error(argv[i], &error);
		if (error)
			return (true);
	}
	return (false);
}

static void	exec_op(t_ps *ps)
{
	char	*op;

	op = get_next_line(STDIN_FILENO);
	while (op)
	{
		if (do_op_str(op, ps))
		{
			free(op);
			ps_clear(ps);
			put_str_fd("Error\n", STDERR_FILENO);
			exit(EXIT_SUCCESS);
		}
		free(op);
		op = get_next_line(0);
	}
	if (op)
		free(op);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc > 1)
	{
		if (check_error(argc, argv))
		{
			put_str_fd("Error\n", STDERR_FILENO);
			return (0);
		}
		init_ps(&ps, false, false);
		fill_arg(&ps, argc, argv);
		exec_op(&ps);
		if (is_sorted(ps.a) && !ps.b)
			put_str_fd("OK\n", STDOUT_FILENO);
		else
			put_str_fd("K0\n", STDOUT_FILENO);
		ps_clear(&ps);
	}
	return (0);
}
