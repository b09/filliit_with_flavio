/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_lines.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 18:49:55 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/05/22 18:49:56 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int free_lines(char **lines, int n_lines)
{
	int	i;

	i = 0;
	while (i < n_lines)
	{
		ft_strdel(&lines[i]);
		i++;
	}
	return (0);
}
