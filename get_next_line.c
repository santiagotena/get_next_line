/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:52:51 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/13 10:14:37 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readiter(int fd, char *saved)
{
	char	*buf;
	char	*temp_saved;
	int		flag;

	buf = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	flag = read(fd, buf, BUFFER_SIZE);
	if (flag < 0)
	{
		free(buf);
		return (NULL);
	}
	while (flag != 0)
	{
		temp_saved = ft_strjoin(saved, buf);
		//free(saved);
		saved = temp_saved;
		//free(temp_saved);
		if (ft_strchr(saved, '\n') != NULL || ft_strchr(saved, '\0') != NULL)
			break ;
		flag = read(fd, buf, BUFFER_SIZE);
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
	output = ft_calloc((counter + 1), sizeof(char));
	if (!output)
		return (NULL);
	counter = 0;
	while (saved[counter] != '\n' && saved[counter] != '\0')
	{
		output[counter] = saved[counter];
		counter++;
	}
	output[counter] = saved[counter];
	counter++;
	if (output[0] == '\0')
		output = NULL;
	return (output);
}

char	*ft_savechars(char *saved)
{
	size_t	counter;
	size_t	index;
	char	*output;
	
	counter = 1;
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
	static char	*saved;
	char		*print;
	
	if (!saved)
		saved = ft_calloc(1, sizeof(char));
	print = NULL;
	saved = ft_readiter(fd, saved);
	if (!saved)
		return (NULL);
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

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	(void)argc;
	fd = open("name.txt", O_RDONLY);
	line = "";
	if (fd == -1)
		return (-1);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return (0);
}
