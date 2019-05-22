/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:14:59 by bprado         #+#    #+#                */
/*   Updated: 2019/05/22 17:16:45 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void read_line_input_variable(char **lines)
{
	int i;

	i = 0;
	while (lines[i] != NULL)
	{
		printf("line %d is: \n%s", i, lines[i]);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int		ret;
	char	*lines_in_input[MAX_TTRS + 1];

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit input_file");
		return (1);
	}
	ret = get_input(lines_in_input, argv[1]);
	printf("ret is: %d", ret);
	if (ret == 0)
	{
		ft_putendl("usage: ./fillit input_file");
		return (1);
	}
	read_line_input_variable(lines_in_input);
	return (0);
}
