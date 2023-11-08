/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:28:29 by bruda-si          #+#    #+#             */
/*   Updated: 2023/11/08 18:22:54 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 40
#endif



int	ft_strlen(char	*str)
{
	int	i;
	
	i = 0;
	if (!str)
		return (0);
	while(str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s)
{
	int	i;
	
	i = 0;
	while (s[i])
	{
		printf("buffer10: %c\n", s[i]);
		if (s[i] == '\n')
			return (NULL);
		i++;
	}
	return (s);
}

char	*ft_strjoin(char *new_line, char *buffer)
{
	int	i;
	int	j;
	char	*dest;

	i = 0;
	j = 0;
	// printf("buffer7: %s\n", buffer);
	dest = (char *)malloc(ft_strlen(new_line) + ft_strlen(buffer) + 1);
	if (!dest)
		return (NULL);
	// printf("buffer8: %s\n", buffer);
	while (new_line[i])
	{
		// printf("buffer3: %s\n", new_line);
		dest[i] = new_line[i];
		// printf("buffer4: %s\n", dest);
		i++;
	}
	// printf("buffer9: %s\n", buffer);
	while (buffer[j])
	{
		// printf("buffer5: %c\n", buffer[j]);
		dest[i++] = buffer[j++];
	}
	dest[i] = 0;
	// printf("buffer6: %s\n", dest);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char	*new_line;
	int	i;

	i = 0;
	new_line = "";
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		while (buffer[i])
			buffer[i] = '\0';
		return (NULL);
	}
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		// printf("buffer1: %s\n", buffer);
		buffer[BUFFER_SIZE] = 0;
		// if (!new_line)
		// {
		// 	new_line = "";
		// }
		// printf("buffer1: %s\n", new_line);
		new_line = ft_strjoin(new_line, buffer);
		// printf("buffer2: %s\n", new_line);
		if (ft_strchr(buffer))
			// nl_handle(buffer);
			break;
	}
	return (new_line);
}

int	main(void)
{
	char	*buffer;
	int		fd;
	int		chars_read;

	fd = open("text.txt", O_RDONLY);
	buffer = get_next_line(fd);
	printf("buff -> %s\n", buffer);

	close(fd);
	return (0);
 }