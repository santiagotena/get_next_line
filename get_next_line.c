/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:52:51 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/11 01:06:29 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readiter(int fd, char *saved)
{
	char	*buf;
	ssize_t	flag;
	// size_t	BUFFER_SIZE = 42;

	flag = 1;
	buf = (char *) malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (0);
	while (flag != 0)
	{
		flag = read(fd, buf, BUFFER_SIZE);
		if (flag < 0)
		{
			free(buf);
			return (NULL);
		}
		saved = malloc(ft_strlen(ft_strjoin(saved, buf)) * sizeof(char));
		saved = ft_strjoin(saved, buf);
		if (ft_strchr(saved, '\n') != NULL)
			break ;
	}
	free (buf);
	return (saved);
}

char	*ft_returnline(char *saved)
{
	size_t	counter;
	char	*output;
	
	counter = 1;
	while (saved[counter] != '\n' && saved[counter] != '\0')
		counter++;
	counter++;
	output = malloc((counter + 1) * sizeof(char));
	if (!output)
		return (NULL);
	counter = 0;
	while (saved[counter] != '\n' && saved[counter] != '\0')
	{
		output[counter] = saved[counter];
		counter++;
	}
	output[counter] = '\0';
	return (output);
}

char	*ft_savechars(char *saved)
{
	size_t	counter;
	size_t	index;
	char	*output;
	
	counter = 1;
	index = 0;
	while (saved[counter] != '\n')
		counter++;
	counter++;
	output = malloc((ft_strlen(saved) - (counter + 1)) * sizeof(char));
	if (!output)
		return (NULL);
	while (saved[counter] != '\0')
		output[index++] = saved[counter++];
	output[index] = '\0';
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
	static char	*saved;
	char		*print;
	// size_t	BUFFER_SIZE = 42;

	saved = "";
	print = NULL;
	saved = ft_readiter(fd, saved);
	if (saved)
	{
		print = ft_returnline(saved);
		saved = ft_savechars(saved);
	}
	if (!print)
	{
		free(saved);
		free(print);
		return (NULL);
	}
	return (print);
}

// // Debugger //

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
// 	char	*line;

// 	(void)argc;
// 	fd = open("compilation.txt", O_RDONLY);
// 	line = "";
// 	if (fd == -1)
// 		return (-1);
// 	while (line != NULL)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 	}
// 	fd = close(fd);
// 	return (0);
// }