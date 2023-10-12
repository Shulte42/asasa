#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (litlle[i] == '\0')
	{
		return ((char *) s);
	}
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == litlle[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
			{
				return ((char *) &big[i]);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
	}
