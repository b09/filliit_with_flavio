/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:15:32 by bprado         #+#    #+#                */
/*   Updated: 2019/05/24 13:22:45 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <stdio.h>		// for printf
# include <unistd.h>	// for write / read
# include <fcntl.h>		// for open
# include "./libft/libft.h"

# define CHARS_IN_LINE 21
# define MAX_TTRS 26

typedef struct  s_coord
{
	char		x;
	char		y;
}				t_coord;

int				get_input(char **lines, char *filename);
int				validate_input(char **ttrs);
t_coord			**transform_input(char **ttrs_lines, size_t number_of_ttrs);
char			**create_grid(int size);
void			delete_grid(char **grid);

#endif
