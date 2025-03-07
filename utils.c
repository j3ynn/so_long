#include "so_long.h"

char    *ft_strdup(const char *s);

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

size_t	ft_strslen(char **mat)
{
	size_t	i;

	i = 0;
	while (mat && mat[i] != NULL)
		i++;
	return (i);
}
