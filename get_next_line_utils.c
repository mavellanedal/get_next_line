/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:07:05 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/23 20:25:03 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h";

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;
	int		total_len;

	if (!s1 && !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(total_len);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i ++;
	}
	while (s2[j])
	{
		res[i +j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

char	*ft_strchr(char *str, int c)
{
	int				i;
	int				s_len;
	unsigned char	c_c;

	c_c = c;
	if (str == NULL)
		return(str);
	s_len = ft_strlen(str);
	i = 0;
	while (i < s_len)
	{
		if (str[i] == c_c)
			return ((char *)str + i);
		i++;
	}
	if (c_c == '\0')
		return ((char *)str + i);
	return(NULL);
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
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] = '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	i++;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}
