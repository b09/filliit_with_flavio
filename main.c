/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:14:59 by bprado         #+#    #+#                */
/*   Updated: 2019/05/23 15:36:46 by bprado        ########   odam.nl         */
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
	char	*ttrs[MAX_TTRS + 1];

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
	read_line_input_variable(ttrs);
	// printf("validate_type return: %d\n", valid_type(ttrs));
	// printf("validate_chars_and_newline return: %d\n", valid_chars_and_newline(ttrs));
	printf("FINAL valid_input return: %d\n", validate_input(ttrs));
	return (0);
}
