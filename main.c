/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:14:59 by bprado         #+#    #+#                */
/*   Updated: 2019/05/24 13:39:38 by bprado        ########   odam.nl         */
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

int		main(int argc, char *argv[])
{
	int		ret;
	char	*ttrs[MAX_TTRS + 1];
	t_coord	**ttrs_output;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit input_file");
		return (1);
	}
	ret = get_input(ttrs, argv[1]);
	printf("ret is: %d", ret);
	if (ret == 0)
	{
		ft_putendl("usage: ./fillit input_file");
		return (1);
	}
	// read_line_input_variable(ttrs);
	// printf("validate_type return: %d\n", valid_type(ttrs));
	// printf("validate_chars_and_newline return: %d\n", valid_chars_and_newline(ttrs));
	// printf("FINAL valid_input return: %d\n", validate_input(ttrs));
	ttrs_output = transform_input(ttrs, ret);
	read_line_input_variable(ttrs_output);
	return (0);
}
