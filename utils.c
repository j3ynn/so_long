#include "so_long.h"

char    *ft_strdup(const char *s);
size_t	ft_strslen(char **mat);

size_t	ft_strlen(const char *str)
{
	size_t	p;

	p = 0;
	while (str && str[p] != '\0')
	{
		p ++;
	}
	return (p);
}

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

char    *ft_strdup(const char *s)
{
        size_t  len;
        char    *s_dup;
        char    *s2;

        len = ft_strlen(s);
        s_dup = malloc(sizeof(char) * (len + 1));
        s2 = s_dup;
        while (*s)
        {
                *s_dup = *s;
                s_dup ++;
                s ++;
        }
        *s_dup = '\0';
        return (s2);
}

size_t	ft_strslen(char **mat)
{
	size_t	i;

	i = 0;
	while (mat && mat[i] != NULL)
		i++;
	return (i);
}
