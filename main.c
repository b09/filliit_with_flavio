/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:14:59 by bprado         #+#    #+#                */
/*   Updated: 2019/05/28 16:31:42 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	read_grid(t_grid *grid)
{
	int		i;

	i = 0;
	while (i < grid->size)
	{
		ft_putendl(grid->grid[i]);
		i++;
	}
}

static void	free_at_end(t_grid *grid, t_coord **ttrs, int n_ttrs)
{
	int	i;

	delete_grid(grid);
	i = 0;
	while (i < n_ttrs)
	{
		free(ttrs[i]);
		i++;
	}
}

int			main(int argc, char *argv[])
{
	int		ret;
	char	*ttrs[MAX_TTRS + 1];
	t_coord	**ttrs_output;
	t_grid	*grid;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit input_file");
		return (1);
	}
	ret = get_input(ttrs, argv[1]);
	if (ret == 0 || validate_input(ttrs, ret) == FALSE)
	{
		ft_putendl("usage: ./fillit input_file");
		return (1);
	}
	ttrs_output = transform_input(ttrs, ret);
	grid = solve(ttrs_output, ret);
	read_grid(grid);
	free_at_end(grid, ttrs_output, ret);
	return (0);
}
