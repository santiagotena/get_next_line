/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:52:51 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/23 15:22:18 by stena-he         ###   ########.fr       */
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
	output = ft_calloc(index + 1, sizeof * output);
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
	counter = 0;
	while (str[counter] != '\0')
		counter++;
	while (str[index] != '\n' && str[index] != '\0')
		index++;
	if (str[index] == '\n')
		index++;
	output = ft_calloc((counter - index) + 1, sizeof * output);
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
	static char	*save[4096];
	char		*temp;
	char		*line;

	if (fd < 0 || fd >= 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	temp = NULL;
	ft_read_line(fd, &save[fd], &temp);
	if (save[fd] != NULL && *save[fd] != '\0')
		line = ft_prepare_line(&save[fd], &temp);
	if (!line || *line == '\0')
	{
		ft_free_strs(&save[fd], &line, &temp);
		return (NULL);
	}
	return (line);
}

// // ---------- Debugger ---------- //

// // Main //

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
