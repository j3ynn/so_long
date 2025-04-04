/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:31:40 by jbellucc          #+#    #+#             */
/*   Updated: 2025/04/04 19:31:33 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*s_dup;
	char	*s2;

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
