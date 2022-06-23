/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:52:53 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/23 14:17:41 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*output;
	size_t	counter;
	char	*ptr;

	if (count >= 4294967295 || size >= 4294967295)
		return (NULL);
	counter = 0;
	output = malloc(count * size);
	if (!output)
		return (NULL);
	ptr = (char *)output;
	while (counter < count * size)
	{
		if (ptr[counter] != 0)
			ptr[counter] = 0;
		counter++;
	}
	return (output);
}

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
	while (s1[index] != '\0')
		index++;
	output = (char *)malloc((index + 1) * sizeof(char));
	if (!output)
		return (NULL);
	index = 0;
	while (s1[index] != '\0')
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
	char	*output;
	int		s1_i;
	int		s2_i;

	if (!s1 && !s2)
		return (NULL);
	s1_i = 0;
	s2_i = 0;
	while (s1[s1_i])
		s1_i++;
	while (s2[s2_i])
		s2_i++;
	output = ft_calloc(s1_i + s2_i + 1, sizeof(char));
	if (!output)
		return (NULL);
	s1_i = -1;
	while (s1[++s1_i])
		output[s1_i] = s1[s1_i];
	s2_i = -1;
	while (s2[++s2_i])
		output[s1_i + s2_i] = s2[s2_i];
	return (output);
}
