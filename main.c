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

int		main(int argc, char *argv[])
{
	char	*lines_in_input[MAX_TTRS];

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit input_file");
		return (1);
	}
	get_input(lines_in_input, argv[1]);
	if (!lines_in_input)
	{
		ft_putendl("usage: ./fillit input_file");
		return (1);
	}
	return (0);
}
