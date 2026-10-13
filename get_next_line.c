/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <stkoh@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:03:38 by stkoh             #+#    #+#             */
/*   Updated: 2026/10/13 21:51:40 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_char(const char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i] || (unsigned char) str[i] != (unsigned char) c)
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

int	has_new_line_char(char *storage)
{
	return (find_char(storage, NEW_LINE_CHAR) >= 0);
}

int	read_and_append(char **storage, char *buffer, int fd)
{
	ssize_t	read_size;

	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size > 0)
		return (char_join(storage, buffer));
	else if (read_size == 0)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*line_storage;
	char		buff[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0)
		return (NULL);
	while (!line_storage || !has_new_line_char(line_storage))
	{
		if (!read_and_append(&line_storage, buff, fd))
			return (NULL);
	}
	if (!extract_line(&line_storage, &line))
		return (NULL);
	return (line);
}
