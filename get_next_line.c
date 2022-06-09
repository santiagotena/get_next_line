/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:52:51 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/09 22:43:00 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_readiter(int fd, size_t BUFFER_SIZE)
{
	void		*buf;
	ssize_t		flag;
	static void	*saved;

	flag = 1;
	saved = NULL;
	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (0);
	while (flag != 0)
	{
		flag = read(fd, &buf, BUFFER_SIZE);
		if (flag == -1)
		{
			free(buf);
			return (0);
		}
		saved = ft_strjoin(saved, buf);
		if (ft_strchr(saved, '\n') != NULL)
			break ;
	}
}

char	*ft_returnline(saved)
{
	size_t	counter;
	char	*output;
	
	counter = 0;
	while (saved[counter] != '\n' && saved[counter] != '\0')
	{
		counter++;
	}
	output = malloc((counter + 1) * sizeof(char));
	counter = 0;
	while (saved[counter] != '\n' && saved[counter] != '\0')
	{
		output[counter] = saved[counter];
		counter++;
	}
	output[counter] = '\0';
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
}

// Debugger

int	main(void)
{
	int	fd;

	fd = open("fichier.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	get_next_line(fd);
	close(fd);
	return (0);
}