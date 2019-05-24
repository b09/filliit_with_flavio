/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:14:59 by bprado         #+#    #+#                */
/*   Updated: 2019/05/24 20:45:28 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void read_line_input_variable(t_coord **lines)
{
	int i;
	int	j;

	i = 0;
	while (lines[i] != NULL)
	{
		j = 0;
		while (j < 4)
		{
			printf("coord y: %d ,", lines[i][j].y);
			printf("coord x: %d\n", lines[i][j].x);
			j++;
		}
		i++;
	}
}

static void read_grid(t_grid *grid)
{
	int i;

	i = 0;
	while (i < grid->size)
	{
		printf("%s\n", grid->grid[i]);
		i++;
	}
}

int		main(int argc, char *argv[])
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
	printf("ret is: %d\n", ret);
	if (ret == 0)
	{
		ft_putendl("usage: ./fillit input_file");
		return (1);
	}
	ttrs_output = transform_input(ttrs, ret);
	read_line_input_variable(ttrs_output);
	grid = solve(ttrs_output, ret);
	printf("yo\n");
	read_grid(grid);
	
	return (0);
}
