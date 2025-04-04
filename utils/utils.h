/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:09:31 by jbellucc          #+#    #+#             */
/*   Updated: 2025/04/04 19:28:34 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *s, ...);
int		ft_check_storage(char storage[BUFFER_SIZE], char **line);
int		ft_strlen(const char *str);
int		ft_cmp(char *s1, char *end);

void	ft_putnbr_base2(unsigned long long n, char *base, int *count);
void	ft_putnbr_base(long long n, char *base, int *count);
void	ft_putchr(char j, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putptr(void *ptr, int *count);
void	ft_format(va_list args, const char frm, int *count);
void	ft_free_strs(char **strs, int flag);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);

char	*get_next_line(int fd);
char	*ft_strchr(char *str, int s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
char	*ft_extraction_storage(char storage[BUFFER_SIZE]);
char	*ft_strdup(const char *s);
char	**ft_strsdup(char **strs);

size_t	ft_strslen(char **mat);

#endif
