/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:52:51 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/18 12:25:36 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_returnline(char *line)
{
	size_t	counter;
	char	*output;

	counter = 0;
	while (line[counter] != '\n' && line[counter] != '\0')
		counter++;
	counter++;
	output = ft_calloc((counter + 1), sizeof(char));
	if (!output)
	{
		free(output);
		return (NULL);
	}
	counter = 0;
	while (line[counter] != '\n' && line[counter] != '\0')
	{
		output[counter] = line[counter];
		counter++;
	}
	output[counter] = line[counter];
	free(line);
	return (output);
}

char	*ft_savechars(char *line)
{
	size_t	counter;
	size_t	index;
	char	*output;

	counter = 0;
	index = 0;
	while (line[counter] != '\n' && line[counter] != '\0')
		counter++;
	counter++;
	output = ft_calloc((ft_strlen(line) + 1 - (counter)), sizeof(char));
	if (!output)
		return (NULL);
	while (line[counter] != '\0')
		output[index++] = line[counter++];
	return (output);
}

void	ft_free_strs(char **str, char **str2)
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
}

/**
 * @brief Get the next line object. Returns a line read from a file descriptor.
 * Read line:  correct behavior. 
 * NULL: there is nothing else to read, or an error occurred.
 * 
 * @param fd The file descriptor to read from.
 * @return char* 
 */
char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char static	*line;
	char		*temp;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!line)
		line = ft_calloc(1, sizeof(char));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			ft_free_strs(&line, 0);
			return (NULL);
		}
		buffer[bytes] = '\0';
		temp = ft_strjoin(line, buffer);
		ft_free_strs(&line, 0);
		line = ft_strdup(temp);
		ft_free_strs(&temp, 0);
		if (ft_strchr(line, '\n') != NULL || bytes < BUFFER_SIZE)
			break ;
	}
	if (!line || line[0] == '\0')
	{
		ft_free_strs(&line, &temp);
		return (NULL);
	}
	temp = ft_strdup(line);
	ft_free_strs(&line, 0);
	line = ft_savechars(temp);
	return (ft_returnline(temp));
}

// // ---------- Debugger ---------- //

// /**
//  * @brief Allocates enough space for count objects that are size bytes of 
//  * memory each and returns a pointer to the allocated memory.  The 
//  * allocated memory is filled with bytes of value zero. If there is an 
//  * error, they return a NULL pointer and set errno to ENOMEM.
//  * 
//  * @param count 
//  * @param size Use sizeof(<data_type>)
//  * @return void* 
//  */
// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*output;
// 	size_t	counter;
// 	char	*ptr;

// 	if (count >= 4294967295 || size >= 4294967295)
// 		return (NULL);
// 	counter = 0;
// 	output = malloc(count * size);
// 	if (!output)
// 		return (NULL);
// 	ptr = (char *)output;
// 	while (counter < count * size)
// 	{
// 		if (ptr[counter] != 0)
// 			ptr[counter] = 0;
// 		counter++;
// 	}
// 	return (output);
// }

// /**
//  * @brief Allocates sufficient memory for a copy of the string s1, does the 
//  * copy, and returns a pointer to it.  The pointer may subsequently be used 
//  * as an argument to the function free(3).
//  * 
//  * @param s1 
//  * @return char* 
//  */
// char	*ft_strdup(const char *s1)
// {
// 	size_t	count;
// 	char	*output;
// 	size_t	index;

// 	index = 0;
// 	count = 0;
// 	while (s1[index] != '\0')
// 	{
// 		count++;
// 		index++;
// 	}
// 	output = (char *)malloc((count + 1) * sizeof(char));
// 	if (!output)
// 		return (NULL);
// 	index = 0;
// 	while (index < count)
// 	{
// 		output[index] = s1[index];
// 		index++;
// 	}
// 	output[index] = '\0';
// 	return (output);
// }

// /**
//  * @brief Allocates (with malloc(3)) and returns a new string, which is 
//  * the result of the concatenation of ’s1’ and ’s2’.
//  * 
//  * Returns the new string or NULL if the allocation fails.
//  * 
//  * @param s1 
//  * @param s2 
//  * @return char* 
//  */
// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*output;
// 	size_t	output_index;
// 	size_t	index;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	output = (char *)malloc(ft_strlen(s1) \
// 			+ ft_strlen(s2) + 1 * sizeof(char));
// 	if (!output)
// 		return (NULL);
// 	output_index = 0;
// 	index = 0;
// 	while (output_index < ft_strlen(s1))
// 	{
// 		output[output_index++] = s1[index++];
// 	}
// 	index = 0;
// 	while (output_index < ft_strlen(s1) + ft_strlen(s2))
// 	{
// 		output[output_index++] = s2[index++];
// 	}
// 	output[output_index] = '\0';
// 	return (output);
// }

// /**
//  * @brief Computes the length of the string s.  The strnlen() function 
//  * attempts to compute the length of s, but never scans beyond the first 
//  * maxlen bytes of s. Returns the number of characters that precede the 
//  * terminating NUL character.
//  * 
//  * @param str 
//  * @return size_t 
//  */
// size_t	ft_strlen(const char *str)
// {
// 	size_t		counter;

// 	counter = 0;
// 	while (str[counter] != '\0')
// 	{
// 		counter += 1;
// 	}
// 	return (counter);
// }

// /**
//  * @brief Locates the first occurrence of c (converted to a char) in the
//  * string pointed to by s.  The terminating null character is considered to 
//  * be part of the string; therefore if c is `\0', the functions locate the 
//  * terminating `\0'. 
//  * 
//  * Returns a pointer to the located character, or NULL if the character 
//  * does not appear in the string.
//  * 
//  * @param s 
//  * @param c
//  * @return char* 
//  */
// char	*ft_strchr(const char *s, int c)
// {
// 	int		index;
// 	char	*ptr;

// 	ptr = (char *)s;
// 	index = 0;
// 	while (ptr[index] != '\0')
// 	{
// 		if (ptr[index] == (unsigned char) c)
// 		{
// 			return (&ptr[index]);
// 		}
// 		index++;
// 	}
// 	if (c == '\0' && ptr[index] == '\0')
// 		return (&ptr[index]);
// 	return (NULL);
// }

// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include "get_next_line.h"

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*out;

// 	(void)argc;
// 	fd = open("tests/41_with_nl.txt", O_RDONLY);
// 	out = "";
// 	if (fd == -1)
// 		return (-1);
// 	while (out != NULL)
// 	{
// 		out = get_next_line(fd);
// 		printf("%s", out);
// 	}
// 	fd = close(fd);
// 	return (0);
// }
