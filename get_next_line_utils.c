/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:52:53 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/16 19:55:08 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Writes n zeroed bytes to the string s. 
 * If n is zero, bzero() does nothing.
 * 
 * @param s 
 * @param n 
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	counter;
	char	*ptr;

	ptr = (char *)s;
	counter = 0;
	while (counter < n)
	{
		if (ptr[counter] != 0)
			ptr[counter] = 0;
		counter++;
	}
}

/**
 * @brief Allocates enough space for count objects that are size bytes of 
 * memory each and returns a pointer to the allocated memory.  The 
 * allocated memory is filled with bytes of value zero. If there is an 
 * error, they return a NULL pointer and set errno to ENOMEM.
 * 
 * @param count 
 * @param size Use sizeof(<data_type>)
 * @return void* 
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*output;

	if (count >= 4294967295 || size >= 4294967295)
		return (NULL);
	output = malloc(count * size);
	if (!output)
		return (NULL);
	ft_bzero(output, count * size);
	return (output);
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
	size_t	count;
	char	*output;
	size_t	index;

	index = 0;
	count = 0;
	while (s1[index] != '\0')
	{
		count++;
		index++;
	}
	output = (char *)malloc((count + 1) * sizeof(char));
	if (!output)
		return (NULL);
	index = 0;
	while (index < count)
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
