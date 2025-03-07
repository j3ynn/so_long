#include "so_long.h"

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > ((size_t)-1) / size)
		return (NULL);
	p = malloc(nmemb * size);
	if ((!p) || (p != 0 && size > SIZE_MAX / nmemb))
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

void    ft_bzero(void *s, size_t n)
{
        ft_memset(s, '\0', n);
}

void    *ft_memset(void *s, int c, size_t n)
{
        unsigned char           *buffer;
        size_t                          p;

        buffer = (unsigned char *)s;
        p = 0;
        while (p < n)
        {
                buffer[p] = c;
                p ++;
        }
        return (s);
}

char	*ft_strchr(const char *str, int s)
{
	while (*str)
	{
		if (*str == (char)s)
			return ((char *)str);
		str ++;
	}
	if (s == '\0' && (char)s == '\0')
		return ((char *)str);
	return (0);
}
