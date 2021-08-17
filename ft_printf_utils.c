/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:42:10 by fleger            #+#    #+#             */
/*   Updated: 2019/12/21 07:02:33 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	int		i;

	i = 0;
	if (ft_strlen(s) < start)
		return (NULL);
	if (!(tab = malloc(sizeof(char) * (len + 2))))
		return (NULL);
	while (s[start] && i < (int)len)
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}

int		is_format(char c)
{
	char	*set;
	int		i;

	i = -1;
	set = "cpsdiuxX%";
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*tab;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
		i++;
	if (!(tab = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*dup_car(char c)
{
	char *tab;

	if (!(tab = malloc(sizeof(char) * 2)))
		return (NULL);
	tab[0] = c;
	tab[1] = '\0';
	return (tab);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		res;

	j = 0;
	i = 0;
	res = 0;
	while (dst[i])
		i++;
	while (src[res])
		res++;
	if (size < i)
		res += size;
	else
		res += i;
	while (src[j] && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
