/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:30:11 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/28 17:09:28 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	unsigned char	c_c;
	int				s_len;
	int				i;

	c_c = c;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len)
	{
		if (s[i] == c_c)
			return ((char *)s + i);
		i++;
	}
	if (c_c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char *left_str, char *buffer)
{
	char	*s;
	int		i;
	int		j;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buffer)
		return (NULL);
	s = malloc(sizeof(char) * (ft_strlen(left_str) + ft_strlen(buffer) + 1));
	if (s == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			s[i] = left_str[i];
	while (buffer[j] != '\0')
		s[i++] = buffer[j++];
	s[ft_strlen(left_str) + ft_strlen(buffer)] = '\0';
	free(left_str);
	return (s);
}

char	*get_new_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		left_str = NULL;
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	left_str = NULL;
	return (str);
}
