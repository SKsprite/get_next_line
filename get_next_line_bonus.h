/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <stkoh@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:05:29 by stkoh             #+#    #+#             */
/*   Updated: 2026/10/15 01:21:36 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef NEW_LINE_CHAR
#  define NEW_LINE_CHAR '\n'
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_linked_fd
{
	int					fd;
	char				*storage;
	struct s_linked_fd	*next;
}	t_linked_fd;

char		*get_next_line(int fd);
int			find_char(const char *str, const char c, int size_read);
int			char_join(char **storage, char *content);
int			extract_line(char **storage, char **line, int size_read);
size_t		ft_strlen(const char *str);
t_linked_fd	*find_fd_storage(t_linked_fd **fd_storage, int fd);
int			i_need_to_save_space(int fd, int *read_size,
				t_linked_fd **fd_storage, t_linked_fd **current);
#endif
