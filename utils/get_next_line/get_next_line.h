/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:04:29 by gcozigon          #+#    #+#             */
/*   Updated: 2023/01/13 21:06:18 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *buffer);
char	*keep_line(char *buffer);
char	*ft_strjoin000(char *s1, char *s2);
char	*ft_strchr000(char *s, int c);
size_t	ft_strlen000(char *str);
char	*ft_strcpy(char *dest, char *src);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup000(char *x);
#endif