/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <stkoh@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:05:29 by stkoh             #+#    #+#             */
/*   Updated: 2026/10/13 22:37:34 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef NEW_LINE_CHAR
#  define NEW_LINE_CHAR '\n'
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		find_char(const char *str, const char c, int size_read);
int		char_join(char **storage, char *content);
int		extract_line(char **storage, char **line, int size_read);
size_t	ft_strlen(const char *str);
#endif
