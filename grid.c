/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 13:10:17 by bprado         #+#    #+#                */
/*   Updated: 2019/05/28 16:30:17 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**create_grid(int size)
{
	int		i;
	int		j;
	char	**grid;

	i = 0;
	grid = (char **)malloc((sizeof(char*) * size));
	while (i < size)
	{
		grid[i] = (char*)malloc((sizeof(char) * size) + 1);
		++i;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			grid[i][j] = '.';
			++j;
		}
		grid[i][j] = '\0';
		++i;
	}
	return (grid);
}

void		delete_grid(t_grid *grid)
{
	int	i;

	i = 0;
	while (i < grid->size)
	{
		ft_strdel(&(grid->grid)[i]);
		i++;
	}
	free(grid);
	grid = NULL;
}

t_grid		*init_grid(int size)
{
	t_grid	*grid_addr;

	grid_addr = (t_grid*)malloc(sizeof(t_grid));
	grid_addr->grid = create_grid(size);
	grid_addr->size = size;
	grid_addr->letter = 0;
	return (grid_addr);
}
