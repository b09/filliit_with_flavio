/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:41:52 by fmiceli        #+#    #+#                */
/*   Updated: 2019/05/22 21:18:03 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
	type of chars ie '.' '#' '\n'
	correct ttrs type
	number of #
	correct placement of \n
*/

int		valid_chars_and_newline(char **ttrs)
{
	int		i;
	int		j;
	int		hashes;
	char	temp;

	j = 0;
	while (ttrs[j] != NULL)
	{
		hashes = 0;
		i = 0;
		while (ttrs[j][i] != '\0')
		{
			temp = ttrs[j][i];
			if (temp == '#')
				++hashes;
			if !(temp == '\n' && (((i + 1) % 5 == 0) || i == 20))
				return (FALSE);
			else if ((temp != '.' && temp != '#') && ((i + 1) % 5) && i != 20)
				return (FALSE);
			++i;
		}
		if (hashes != 4)
			return (FALSE);
		++j;
	}
	return (TRUE);
}

int		valid_type(char **ttrs)
{
	int		i;
	int		j;
	int		num;

	j = 0;
	while (ttrs[j] != NULL)
	{
		i = 0;
		num = 0;
		while (ttrs[j][i] != '\0')
		{
			if (ttrs[j][i] == '#')
			{
				num += ((i > 0) && (ttrs[j][i - 1] == '#')) ? 1 : 0;
				num += ((i < 20) && (ttrs[j][i + 1] == '#')) ? 1 : 0;
				num += ((i > 5) && (ttrs[j][i - 5] == '#')) ? 1 : 0;
				num += ((i < 15) && (ttrs[j][i + 5] == '#')) ? 1 : 0;
			}
			++i;
		}
		if (num != 6 && num != 8)
			return (FALSE);
		++j;
	}
	return (TRUE);
}

int		validate_input(char **ttrs)
{
	if (valid_type(ttrs) && valid_chars_and_newline(ttrs))
		return (TRUE);
	return (FALSE);
}
