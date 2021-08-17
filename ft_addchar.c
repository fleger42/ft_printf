/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 22:45:41 by fleger            #+#    #+#             */
/*   Updated: 2019/12/20 07:44:52 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_char_b(char *str, char cara, int c)
{
	char	*new;
	int		i;

	if (c < 0)
		return (str);
	i = ft_strlen(str);
	if (c > i)
	{
		if (!(new = calloc(sizeof(char), (c + 1))))
			return (NULL);
	}
	else
		return (str);
	ft_strlcat(new, str, i + 1);
	free(str);
	str = NULL;
	while (i < c)
		new[i++] = cara;
	return (new);
}

char	*ft_add_char_f(char *str, char cara, int c)
{
	char	*new;
	int		i;
	int		size;

	if (c < 0)
		return (str);
	if (c > (int)ft_strlen(str))
	{
		if (!(new = calloc(sizeof(char), (c + 1))))
			return (NULL);
	}
	else
		return (str);
	i = 0;
	size = c - ft_strlen(str);
	while (i < size)
		new[i++] = cara;
	ft_strlcat(new, str, c + 2);
	free(str);
	str = NULL;
	return (new);
}

int		ft_nbr_c(int n)
{
	int nbr_c;

	nbr_c = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		nbr_c++;
		n = -n;
	}
	while (n >= 10)
	{
		nbr_c++;
		n = n / 10;
	}
	return (nbr_c);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			length;
	long int	n2;

	n2 = (long int)n;
	length = ft_nbr_c(n);
	if (!(str = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	if (n2 < 0)
	{
		n2 = -n2;
		str[0] = '-';
	}
	str[length] = '\0';
	while (n2 >= 10)
	{
		str[length-- - 1] = (n2 % 10) + 48;
		n2 = n2 / 10;
	}
	str[length - 1] = n2 + 48;
	return (str);
}

int		ft_atoi(const char *nptr)
{
	int				i;
	int				result;
	int				signe;

	signe = 1;
	i = 0;
	result = 0;
	while ((nptr[i] >= 8 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i++] - 48);
	}
	result = result * signe;
	return (result);
}
