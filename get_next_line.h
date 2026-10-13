/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkoh <stkoh@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:05:29 by stkoh             #+#    #+#             */
/*   Updated: 2026/10/13 18:12:58 by stkoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 4096
# define NEW_LINE_CHAR "\n"

# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);

#endif
