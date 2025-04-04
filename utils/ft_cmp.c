/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:09:02 by jbellucc          #+#    #+#             */
/*   Updated: 2025/04/04 14:09:03 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_cmp(char *s1, char *end)
{
	int	s1_len;
	int	end_len;

	s1_len = ft_strlen(s1);
	end_len = ft_strlen(end);
	if (s1_len <= end_len)
		return (1);
	s1 += s1_len - end_len;
	while (*s1)
	{
		if (*s1 != *end)
			return (1);
		s1++;
		end++;
	}
	return (0);
}
