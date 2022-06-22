/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:52:53 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/22 22:55:13 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Checks for the existence of a string and frees it in case
 * of it existing. If less than 3 parameters are used. Use 0 in the
 * "unused" parameter. For example, ft_free_strs(str, 0, 0).
 * 
 * @param str 
 * @param str2 
 * @param str3 
 */
void	ft_free_strs(char **str, char **str2, char **str3)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	if (str3 && *str3)
	{
		free(*str3);
		*str3 = NULL;
	}
}

/**
 * @brief Allocates sufficient memory for a copy of the string s1, does the 
 * copy, and returns a pointer to it.  The pointer may subsequently be used 
 * as an argument to the function free(3).
 * 
 * @param s1 
 * @return char* 
 */
char	*ft_strdup(const char *s1)
{
	char	*output;
	int		index;

	if (!s1)
		return (ft_strdup(""));
	index = 0;
	while (s1[index])
		index++;
	output = (char *)malloc((index + 1) * sizeof(char));
	if (!output)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		output[index] = s1[index];
		index++;
	}
	output[index] = '\0';
	return (output);
}

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is 
 * the result of the concatenation of ’s1’ and ’s2’.
 * 
 * Returns the new string or NULL if the allocation fails.
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		len;
	int		i;

	len = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1 && s1[len])
		len++;
	i = 0;
	while (s2 && s2[i])
		i++;
	s = ft_malloc_zero(len + i + 1, sizeof * s);
	if (!s)
		return (NULL);
	len = -1;
	while (s1 && s1[++len])
		s[len] = s1[len];
	i = -1;
	while (s2 && s2[++i])
		s[len + i] = s2[i];
	return (s);
}

/**
 * @brief Computes the length of the string s.  The strnlen() function 
 * attempts to compute the length of s, but never scans beyond the first 
 * maxlen bytes of s. Returns the number of characters that precede the 
 * terminating NUL character.
 * 
 * @param str 
 * @return size_t 
 */
size_t	ft_strlen(const char *str)
{
	size_t		counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter += 1;
	}
	return (counter);
}

/**
 * @brief Locates the first occurrence of c (converted to a char) in the
 * string pointed to by s.  The terminating null character is considered to 
 * be part of the string; therefore if c is `\0', the functions locate the 
 * terminating `\0'. 
 * 
 * Returns a pointer to the located character, or NULL if the character 
 * does not appear in the string.
 * 
 * @param s 
 * @param c
 * @return char* 
 */
char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*ptr;

	ptr = (char *)s;
	index = 0;
	while (ptr[index] != '\0')
	{
		if (ptr[index] == (unsigned char) c)
		{
			return (&ptr[index]);
		}
		index++;
	}
	if (c == '\0' && ptr[index] == '\0')
		return (&ptr[index]);
	return (NULL);
}


void	*ft_malloc_zero(size_t count, size_t size)
{
	void			*r;
	unsigned char	*p;
	size_t			total;

	total = count * size;
	r = malloc(total);
	if (!r)
		return (NULL);
	p = (unsigned char *)r;
	while (total != 0)
	{
		*p = '\0';
		p++;
		total--;
	}
	return (r);
}
