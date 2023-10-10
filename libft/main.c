/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:13:06 by bruda-si          #+#    #+#             */
/*   Updated: 2023/10/09 11:26:38 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
int	main(void)
{
	const char *src = "abcdefghi";
	const char *src2 = "ABCDEFGHI";
	char	dest[] = "jklmnopqrs";
	char	dest2[] = "JKLMNOPQRS";
	printf("------isalpha-------\n");
		printf("a %d\n", ft_isalpha('a'));
		printf("1 %d\n", ft_isalpha('1'));	
	printf("------isdigit-------\n");
		printf("1 %d\n", ft_isdigit('1'));
		printf("a %d\n", ft_isdigit('a'));
	printf("------isalnum-------\n");
		printf("a %d\n", ft_isalnum('a'));
		printf("1 %d\n", ft_isalnum('1'));
		printf("/ %d\n", ft_isalnum('/'));
	printf("-------isascii------\n");
		printf("a %d\n", ft_isascii('a'));
		printf("DEL %d\n", ft_isascii(127));
		printf("128 (ascii) %d\n", ft_isascii(128));
/*	printf("-------isprint------\n");
		printf("a %d\n", ft_isprint('a'));
		printf("1 %d\n", ft_isprint('1'));
		printf("/ %d\n", ft_isprint('/'));
		printf("NULL %d\n", ft_isprint(0));*/
	printf("------strlen--------\n");
		printf("the lenght of %s is %zu\n", src, ft_strlen(src));
	printf("------memset--------\n");
		ft_memset(dest, '1', 5);
		printf("%s\n", dest);
	printf("------bzero---------\n");
		printf("the initial dest is %s\n", dest);
		ft_bzero(dest, 4);
		printf("the new dest is %s\n", dest);
	printf("------memcpy--------\n");
		ft_memcpy(dest2, src, 5);
		printf("the new dest is %s\n", dest2);
	printf("------memmove-------\n");
		ft_memmove(dest2, src2, 10);
		printf("the new dest is %s\n", dest2);
	printf("------strlcpy-------\n");
		printf("the length of the source is %zu and the dest is %s\n", ft_strlcpy(dest2, src, 5), dest2);
	printf("------strlcat-------\n");
		printf("the length of src + dest is %zu, and the new dest is %s\n", ft_strlcat(dest2, src, 30), dest2);
/*	printf("------toupper-------\n");
        	printf("%d\n", ft_toupper('g'));
		printf("%d\n", ft_toupper('0'));
	printf("------tolower-------\n");
		printf("%d\n", ft_tolower('A'));
		printf("%d\n", ft_tolower('0'));
	printf("------strchr--------\n");
		const char *str = "PIPIPIPOPOPO";
		const char *str2 = "\320";
		printf("%s\n", ft_strchr(str, 'I'));
		printf("%s\n", ft_strchr(str2, 'O'));
		printf("oringinal = %s\n", strchr(str2, 'O'));
		printf("%s\n", ft_strchr(str, 'Z'));
		printf("%s\n", ft_strchr(str, '\0'));
	printf("------strrchr-------\n");
		printf("%s\n", ft_strrchr(str, 'I'));
		printf("%s\n", ft_strrchr(str, 'O'));
		printf("original = %s\n", strrchr(str, 'O'));
		printf("%s\n", ft_strrchr(str, 'R'));
		printf("%s\n", ft_strrchr(str, '\0'));
		printf("original = %s\n", strrchr(str, '\0'));
	printf("------strncmp-------\n");
		const char *s1 = "Nicholasisudhasd";
		const char *s2 = "Nicholas\320sadasdas";
		printf("the diference is %d\n", ft_strncmp(s1, s2, 8));
		printf("the diference is %d\n", ft_strncmp(s1, s2, 14));
		printf("the original diference is %d\n", strncmp(s1, s2, 8));
		printf("the original diference is %d\n", strncmp(s1, s2, 14));
		printf("the diference is %d\n", ft_strncmp(s1, s2, 10));
		printf("the diference is %d\n", ft_strncmp(s1, s2, 0));
	printf("------memchr---------\n");
		const char	*s3 = "PIPIPIPOPOPO";
		printf("the char is %s\n", (char *)ft_memchr(s3, 'P', 8));
		printf("the original char is %s\n", (char *)memchr(s3, 'P', 8));
		printf("the char is %s\n", (char *)ft_memchr(s3, 'p', 6));
		printf("the original char is %s\n", (char *)memchr(s3, 'p', 6));
	printf("------memcmp---------\n");
		const char	*s4 = "PIPI\320POPO";
		printf("the diff  is %d\n", ft_memcmp(s3, s4, 8));
		printf("the original diff is %d\n", memcmp(s3, s4, 8));
		printf("the diff is %d\n",ft_memcmp(s3, s4, 2));
		printf("the original diff is %d\n", memcmp(s3, s4, 2));*/
	return (0);
}
