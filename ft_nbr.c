/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 05:55:04 by fleger            #+#    #+#             */
/*   Updated: 2019/12/20 06:22:52 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unsigned_nbr_c(unsigned int n)
{
	int nbr_c;

	nbr_c = 1;
	while (n >= 10)
	{
		nbr_c++;
		n = n / 10;
	}
	return (nbr_c);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char			*str;
	int				length;
	unsigned int	n2;

	n2 = (unsigned int)n;
	length = ft_unsigned_nbr_c(n);
	if (!(str = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	str[length] = '\0';
	while (n2 >= 10)
	{
		str[length-- - 1] = (n2 % 10) + 48;
		n2 = n2 / 10;
	}
	str[length - 1] = n2 + 48;
	return (str);
}

int		ft_count(char *str)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (!is_format(str[i]))
				i++;
		}
		i++;
	}
	return (count);
}
