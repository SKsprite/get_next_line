/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <stkoh@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:06:56 by stkoh             #+#    #+#             */
/*   Updated: 2026/10/13 21:08:15 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	char_join(char	**storage, char *content)
{
	size_t	storage_size;
	size_t	content_size;
	char	*allocated;

	if (!*storage)
	{
		*storage = malloc(1);
		if (!*storage)
			return (0);
		(*storage)[0] = '\0';
	}
	storage_size = ft_strlen(*storage);
	content_size = ft_strlen(content);
	allocated = malloc((storage_size + content_size + 1) * sizeof(char));
	if (!allocated)
		return (free(*storage), *storage = NULL, 0);
	allocated[storage_size + content_size] = '\0';
	while (content_size--)
		allocated[storage_size + content_size] = content[content_size];
	while (storage_size--)
		allocated[storage_size] = (*storage)[storage_size];
	free(*storage);
	*storage = allocated;
	return (1);
}

int	extract_line(char **storage, char **line)
{
	size_t	storage_size;
	size_t	content_size;
	size_t	remaining;
	char	*allocated;

	storage_size = ft_strlen(*storage);
	content_size = find_char(*storage, NEW_LINE_CHAR);
	*line = malloc((content_size + 1) * sizeof(char));
	if (!*line)
		return (0);
	remaining = storage_size - content_size;
	allocated = malloc((remaining + 1) * sizeof(char));
	if (!allocated)
		return (free(*storage), *storage = NULL, 0);
	allocated[remaining] = '\0';
	while (remaining--)
		allocated[remaining] = (*storage)[content_size + remaining];
	line[content_size] = '\0';
	while (content_size--)
		line[content_size] = (*storage)[content_size];
	free(*storage);
	*storage = allocated;
	return (1);
}
