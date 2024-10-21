/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:07:13 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/18 14:25:59 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>

# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

char	*get_next_line(int fd);
#define BUFFERS_SIZE 128

#endif
