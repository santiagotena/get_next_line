/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:52:53 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/09 22:00:38 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
 * @brief Allocates (with malloc(3)) and returns a new string, which is 
 * the result of the concatenation of ’s1’ and ’s2’.
 * 
 * Returns the new string or NULL if the allocation fails.
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	output_index;
	size_t	index;

	if (!s1 || !s2)
		return (NULL);
	output = (char *)malloc(ft_strlen(s1) \
			+ ft_strlen(s2) + 1 * sizeof(char));
	if (!output)
		return (NULL);
	output_index = 0;
	index = 0;
	while (output_index < ft_strlen(s1))
	{
		output[output_index++] = s1[index++];
	}
	index = 0;
	while (output_index < ft_strlen(s1) + ft_strlen(s2))
	{
		output[output_index++] = s2[index++];
	}
	output[output_index] = '\0';
	return (output);
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