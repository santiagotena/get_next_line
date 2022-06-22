/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:51:25 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/22 22:54:43 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

/* Get Next Line */
char	*get_next_line(int fd);
void	ft_read_line(int fd, char **save, char **temp);
char	*ft_prepare_line(char **save, char **temp);
char	*after_nl(char *str);
char	*before_nl(char *str);

/* Utils  */
void	ft_free_strs(char **str, char **str2, char **str3);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	*ft_malloc_zero(size_t count, size_t size);

#endif