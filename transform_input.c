/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform_input.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 19:20:43 by bprado         #+#    #+#                */
/*   Updated: 2019/05/23 20:51:07 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_coord	*transform_line_to_ttr(char *str)
{
	t_coord		*ttr;
	int			i;
	int			hash;
	
	ttr = (t_coord*)malloc(sizeof(t_coord) * 4);
	hash = 0;
	i = 0;
	while (i < CHARS_IN_LINE || hash < 4)
	{
		if (str[i] == '#')
		{
			ttr[hash].y = i / 5;
			ttr[hash].x = i % 5;
			++hash;
		}
		++i;
	}
	ft_strdel(str);
	return (ttr);
}

static void		shift_coords_upper_left(t_coord **ttr)
{
	int		low_x;
	int		low_y;
	int		coord_i;

	low_x = FT_INT_MAX;
	low_y = FT_INT_MAX;
	coord_i = 0;
	while (coord_i < 4)
	{
		low_x = ft_min(low_x, (*ttr)[coord_i].x);
		low_y = ft_min(low_y, (*ttr)[coord_i].y);
		++coord_i;
	}
	coord_i = 0;
	while (coord_i < 4)
	{
		(*ttr)[coord_i].x -= low_x;
		(*ttr)[coord_i].y -= low_y;
		++coord_i;
	}

}

t_coord			**transform_input(char **ttrs_lines, size_t number_of_ttrs)
{
	t_coord		**ttrs_output;
	size_t		n;


	n = 0;
	ttrs_output = (t_coord**)ttrs_lines;
	while (n < number_of_ttrs)
	{
		ttrs_output[n] = transform_line_to_ttr(ttrs_lines[n]);
		shift_coords_upper_left(&ttrs_output[n]);
		++n;
	}
	ttrs_output[n] = NULL;
	return (ttrs_output);
}
