/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <stkoh@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:03:38 by stkoh             #+#    #+#             */
/*   Updated: 2026/10/14 00:19:43 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_char(const char *str, const char c, int size_read)
{
	int	i;

	i = 0;
	while (str[i] && ((unsigned char) str[i] != (unsigned char) c))
		i++;
	if (!str[i] && size_read)
		return (-1);
	if (size_read)
		i++;
	return (i);
}

int	read_and_append(char **storage, char *buffer, int fd)
{
	ssize_t	read_size;

	if (BUFFER_SIZE <= 0)
		return (-1);
	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size <= 0)
		return (read_size);
	buffer[read_size] = '\0';
	return (char_join(storage, buffer));
}

#if BUFFER_SIZE <= 0

char	*malloc_buff(char **buff)
{
	(void)buff;
	return (NULL);
}

#else

char	*malloc_buff(char **buff)
{
	*buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!*buff)
		return (NULL);
	return (*buff);
}
#endif

char	*get_next_line(int fd)
{
	static char	*line_storage;
	char		*buff;
	int			read_size;
	char		*line;

	if (fd < 0)
		return (NULL);
	read_size = 1;
	if (!malloc_buff(&buff))
		return (free(line_storage), line_storage = NULL, NULL);
	while (read_size != 0 && (!line_storage
			|| !(find_char(line_storage, NEW_LINE_CHAR, 1) >= 0)))
	{
		read_size = read_and_append(&line_storage, buff, fd);
		if (read_size < 0)
			return (free(buff), free(line_storage), line_storage = NULL, NULL);
	}
	if ((read_size == 0 && !line_storage)
		|| !extract_line(&line_storage, &line, read_size))
		return (free(buff), free(line_storage), line_storage = NULL, NULL);
	if (ft_strlen(line_storage) == 0)
		return (free(buff), free(line_storage), line_storage = NULL, line);
	free(buff);
	return (line);
}
