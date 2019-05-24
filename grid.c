/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 13:10:17 by bprado         #+#    #+#                */
/*   Updated: 2019/05/24 13:21:33 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_grid(int size)
{
	int		i;
	int		j;
	char	**grid;

	i = 0;
	grid = (char **)malloc((sizeof (char*) * size) + 1);
	while (i < size)
	{
		grid[i] = (char*)malloc((sizeof(char) * size) + 1);
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
	grid[i] = NULL;
	return (grid);
}

void	delete_grid(char **grid)
{
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(grid[0]);
	while (i < size + 1)
		ft_strdel(&grid[i++]);
	ft_strdel(grid);
}