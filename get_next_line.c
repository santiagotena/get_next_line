/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:52:51 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/22 22:54:16 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*before_nl(char *str)
{
	char	*output;
	int		index;

	index = 0;
	while (str[index] != '\n' && str[index] != '\0')
		index++;
	if (str[index] == '\n')
		index++;
	output = ft_malloc_zero(index + 1, sizeof * output);
	if (!output)
		return (NULL);
	index = 0;
	while (str[index] != '\n' && str[index] != '\0')
	{
		output[index] = str[index];
		index++;
	}
	if (str[index] == '\n')
		output[index] = str[index];
	return (output);
}

char	*after_nl(char *str)
{
	char	*output;
	int		index;
	int		counter;

	index = 0;
	counter = ft_strlen(str);
	while (str[index] != '\n' && str[index] != '\0')
		index++;
	if (str[index] == '\n')
		index++;
	output = ft_malloc_zero((counter - index) + 1, sizeof * output);
	if (!output)
		return (NULL);
	counter = 0;
	while (str[index + counter])
	{
		output[counter] = str[index + counter];
		counter++;
	}
	return (output);
}

void	ft_read_line(int fd, char **save, char **temp)
{
	char	*buffer;
	int		bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return ;
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			ft_free_strs(&buffer, save, temp);
			return ;
		}
		buffer[bytes] = '\0';
		*temp = ft_strdup(*save);
		ft_free_strs(save, 0, 0);
		*save = ft_strjoin(*temp, buffer);
		ft_free_strs(temp, 0, 0);
		if (ft_strchr(*save, '\n') != NULL)
			break ;
	}
	ft_free_strs(&buffer, 0, 0);
}

char	*ft_prepare_line(char **save, char **temp)
{
	char	*output;

	*temp = ft_strdup(*save);
	ft_free_strs(save, 0, 0);
	*save = after_nl(*temp);
	output = before_nl(*temp);
	ft_free_strs(temp, 0, 0);
	return (output);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*temp;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	temp = NULL;
	ft_read_line(fd, &save, &temp);
	if (save != NULL && *save != '\0')
		line = ft_prepare_line(&save, &temp);
	if (!line || *line == '\0')
	{
		ft_free_strs(&save, &line, &temp);
		return (NULL);
	}
	return (line);
}

// // ---------- Debugger ---------- //

// /**
//  * @brief Checks for the existence of a string and frees it in case
//  * of it existing. If less than 3 parameters are used. Use 0 in the
//  * "unused" parameter. For example, ft_free_strs(str, 0, 0).
//  * 
//  * @param str 
//  * @param str2 
//  * @param str3 
//  */
// void	ft_free_strs(char **str, char **str2, char **str3)
// {
// 	if (str && *str)
// 	{
// 		free(*str);
// 		*str = NULL;
// 	}
// 	if (str2 && *str2)
// 	{
// 		free(*str2);
// 		*str2 = NULL;
// 	}
// 	if (str3 && *str3)
// 	{
// 		free(*str3);
// 		*str3 = NULL;
// 	}
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
// 	char	*output;
// 	int		index;

// 	if (!s1)
// 		return (ft_strdup(""));
// 	index = 0;
// 	while (s1[index])
// 		index++;
// 	output = (char *)malloc((index + 1) * sizeof(char));
// 	if (!output)
// 		return (NULL);
// 	index = 0;
// 	while (s1[index])
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

// 	if (!s2 | !s1)
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
