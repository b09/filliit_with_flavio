/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:15:32 by bprado         #+#    #+#                */
/*   Updated: 2019/05/22 17:32:13 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <stdio.h>		// for printf
# include <unistd.h>	// for write / read
# include <fcntl.h>		// for open
# include "./libft/libft.h"

int	get_input(char **lines, char *filename);
int free_lines(char **lines, int n_lines);

#endif FILLIT_H
