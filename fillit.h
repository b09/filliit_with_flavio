/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:15:32 by bprado         #+#    #+#                */
/*   Updated: 2019/05/28 16:25:11 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define CHARS_IN_LINE 21
# define MAX_TTRS 26
# define MAX_COORDS 4

typedef struct	s_coord
{
	char		x;
	char		y;
}				t_coord;

typedef struct	s_grid
{
	char		**grid;
	char		size;
	char		letter;
}				t_grid;

int				get_input(char **lines, char *filename);
int				validate_input(char **ttrs, int n_lines);
t_coord			**transform_input(char **ttrs_lines, size_t number_of_ttrs);
void			delete_grid(t_grid *grid);
t_grid			*solve(t_coord **ttrs, int n_ttrs);
t_grid			*init_grid(int size);
int				free_lines(char **lines, int n_lines);

#endif
