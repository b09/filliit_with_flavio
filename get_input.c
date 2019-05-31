/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:58:52 by fmiceli        #+#    #+#                */
/*   Updated: 2019/05/31 17:23:29 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			free_lines(char **lines, int n_lines)
{
	int		i;

	i = 0;
	while (i < n_lines)
	{
		ft_strdel(&lines[i]);
		i++;
	}
	return (0);
}

static int	read_line(int fd, char *buf, char **line)
{
	int		ret;

	ret = read(fd, buf, CHARS_IN_LINE);
	(*line) = ft_memdup(buf, CHARS_IN_LINE + 1);
	return (ret);
}

int			get_input(char **lines, char *filename)
{
	int		fd;
	int		n_lines;
	char	buf[CHARS_IN_LINE + 1];
	int		ret;

	ft_bzero(buf, CHARS_IN_LINE + 1);
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
	{
		lines = NULL;
		return (0);
	}
	n_lines = 0;
	ret = read_line(fd, buf, &lines[n_lines]);
	n_lines += (ret > 0) ? 1 : 0;
	while (n_lines <= MAX_TTRS && ret == CHARS_IN_LINE)
	{
		ret = read_line(fd, buf, &lines[n_lines]);
		n_lines++;
		buf[ret] = 0;
	}
	if (n_lines > MAX_TTRS || ret != CHARS_IN_LINE - 1)
		return (free_lines(lines, n_lines));
	lines[n_lines] = NULL;
	return (n_lines);
}
