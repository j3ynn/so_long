#include "utils.h"

char	**ft_strsdup(char **strs)
{
	char	**dup;
	char	*str;
	size_t	i;

	i = 0;
	dup = ft_calloc(ft_strslen(strs) + 1, sizeof(char *));
	if (!dup)
		return (NULL);
	while (strs[i] != NULL)
	{
		str = ft_strdup(strs[i]);
		if (!str)
		{
			ft_free_strs(dup);
			return (NULL);
		}
		dup[i] = str;
		i++;
	}
	return (dup);
}

void	ft_free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs && strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (nmemb > ((size_t)-1) / size)
		return (NULL);
	p = malloc(nmemb * size);
	if ((!p) || (p != 0 && size > SIZE_MAX / nmemb))
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*buffer;
	size_t				p;

	buffer = (unsigned char *)s;
	p = 0;
	while (p < n)
	{
		buffer[p] = c;
		p ++;
	}
	return (s);
}
