/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:28:29 by bruda-si          #+#    #+#             */
/*   Updated: 2023/11/09 18:04:22 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif



int	ft_strlen(char	*buffer)
{
	int	i;
	
	i = 0;
	if (!buffer)
		return (0);
	while(buffer[i])
		i++;
	return (i);
}

char	*ft_nlcut(char *new_line)
{
	int	i;
	
	i = 0;
	while (new_line[i])
	{
		if (new_line[i++] == '\n')
		{
			new_line[i] = '\0';
			break;
		}
	}
	return (new_line);
}
// int ft_nlhandle(char *buffer)
// {
// 	int	i;
// 	int	j;
// 	int	nl;

// 	i = 0;
// 	j = 0;
// 	nl = 0;
// 	while(*buffer)
// 	{
// 		if (nl == 1)
// 			buffer[j++] = buffer[i];
// 		if (buffer[i] == '\n')
// 			nl = 1;
// 		buffer[i] = '\0';
// 		i++;
// 	}
// 	return (nl);
// }
int ft_nlhandle(char *buffer)
{
    int	i;
    int	j;

    i = 0;
    j = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
    {
        i++;
        while (buffer[i])
            buffer[j++] = buffer[i++];
    }
    buffer[j] = '\0';
    return (buffer[0] != '\0');
}

char	*ft_strjoin(char *new_line, char *buffer)
{
	int	i;
	int	j;
	char	*dest;

	i = 0;
	j = 0;
	dest = (char *)malloc(ft_strlen(new_line) + ft_strlen(buffer) + 1);
	if (!dest)
		return (NULL);
	while (new_line[i])
	{
		dest[i] = new_line[i];
		i++;
	}
	while (buffer[j])
	{
		dest[i++] = buffer[j++];
	}
	dest[i] = '\0';
	return (ft_nlcut(dest));
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
		new_line = ft_strjoin(new_line, buffer);
		if (ft_nlhandle(buffer) == 1)
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
	buffer = get_next_line(fd);
	printf("buff -> %s\n", buffer);
	buffer = get_next_line(fd);
	printf("buff -> %s\n", buffer);
	free(buffer);

	close(fd);
	return (0);
 }