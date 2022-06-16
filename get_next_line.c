/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:52:51 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/17 00:28:57 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_returnline(char *saved)
{
	size_t	counter;
	char	*output;

	counter = 0;
	while (saved[counter] != '\n' && saved[counter] != '\0')
		counter++;
	counter++;
	output = ft_calloc((counter + 1), sizeof(char));
	if (!output)
	{
		free(output);
		return (NULL);
	}
	counter = 0;
	while (saved[counter] != '\n' && saved[counter] != '\0')
	{
		output[counter] = saved[counter];
		counter++;
	}
	output[counter] = saved[counter];
	free(saved);
	return (output);
}

char	*ft_savechars(char *saved)
{
	size_t	counter;
	size_t	index;
	char	*output;

	counter = 0;
	index = 0;
	while (saved[counter] != '\n' && saved[counter] != '\0')
		counter++;
	counter++;
	output = ft_calloc((ft_strlen(saved) + 1 - (counter)), sizeof(char));
	if (!output)
		return (NULL);
	while (saved[counter] != '\0')
		output[index++] = saved[counter++];
	return (output);
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
	bytes = 1;
	if (!line)
		line = ft_calloc(1, sizeof(char));
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			return(NULL);
		}
		buffer[bytes] = '\0';
		temp = ft_strjoin(line, buffer);
		free(line);
		line = ft_strdup(temp);
		free(temp);
		if (ft_strchr(line, '\n') != NULL || bytes < BUFFER_SIZE)
			break ;
	}
	if (line[0] == '\0')
		return (NULL);
	temp = ft_strdup(line);
	line = ft_savechars(temp);
	return (ft_returnline(temp));
}

// // ---------- Debugger ---------- //

// void	ft_bzero(void *s, size_t n)
// {
// 	size_t	counter;
// 	char	*ptr;

// 	ptr = (char *)s;
// 	counter = 0;
// 	while (counter < n)
// 	{
// 		if (ptr[counter] != 0)
// 			ptr[counter] = 0;
// 		counter++;
// 	}
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*output;

// 	if (count >= 4294967295 || size >= 4294967295)
// 		return (NULL);
// 	output = malloc(count * size);
// 	if (!output)
// 		return (NULL);
// 	ft_bzero(output, count * size);
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

// char	*ft_strjoin(char const *s1, char const *s2)
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
// 	fd = open("tests/name.txt", O_RDONLY);
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
