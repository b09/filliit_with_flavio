/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 14:54:36 by bprado         #+#    #+#                */
/*   Updated: 2019/05/27 13:36:54 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	add_ttr_to_grid(t_coord *ttr, t_grid *grid, int x, int y)
{
	char	letter;
	int		i;

	i = 0;
	letter = grid->letter + 'A';
	while (i < MAX_COORDS)
	{
		grid->grid[y + ttr[i].y][x + ttr[i].x] = letter;
		++i;
	}
	grid->letter += 1;
}

static void	remove_ttr_from_grid(t_coord *ttr, t_grid *grid, int x, int y)
{
	int		i;

	i = 0;
	while (i < MAX_COORDS)
	{
		grid->grid[y + ttr[i].y][x + ttr[i].x] = '.';
		++i;
	}
	grid->letter -= 1;
}

static int	ttr_check_on_grid(t_coord *ttr, t_grid *grid, int x, int y)
{
	int		i;
	int		x_ttr;
	int		y_ttr;

	i = 0;
	while (i < MAX_COORDS)
	{
		x_ttr = ttr[i].x + x;
		y_ttr = ttr[i].y + y;
		if (!((y_ttr < grid->size) && (x_ttr < grid->size)))
			return (FALSE);
		if (ft_isalpha(grid->grid[y_ttr][x_ttr]))
			return (FALSE);
		++i;
	}
	return (TRUE);
}

static int	ttr_check_all(t_coord **ttr, t_grid *grid, int grid_i, int i)
{
	int		x;
	int		y;

	if (ttr[i] == NULL)
		return (TRUE);
	while ((grid_i / grid->size) < grid->size)
	{
		x = grid_i % grid->size;
		y = grid_i / grid->size;
		if (ttr_check_on_grid(ttr[i], grid, x, y))
		{
			add_ttr_to_grid(ttr[i], grid, x, y);
			i++;
			if (ttr_check_all(ttr, grid, 0, i) == FALSE)
			{
				i--;
				remove_ttr_from_grid(ttr[i], grid, x, y);
			}
			else
				return (TRUE);
		}
		++grid_i;
	}
	return (FALSE);
}

t_grid		*solve(t_coord **ttrs, int n_ttrs)
{
	int		size;
	t_grid	*grid;

	size = 2 * ft_sqrt_floor(n_ttrs);
	grid = init_grid(size);
	while (!ttr_check_all(ttrs, grid, 0, 0))
	{
		delete_grid(grid);
		size++;
		grid = init_grid(size);
	}
	return (grid);
}
