/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 05:56:38 by fleger            #+#    #+#             */
/*   Updated: 2019/12/21 07:25:58 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s++);
	}
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*cara_specific(char c, va_list *start)
{
	char *str;

	if (c == 's')
	{
		str = va_arg(*start, char*);
		if (str == NULL)
			return (ft_strdup("(null)"));
		return (ft_strdup(str));
	}
	else if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(*start, int)));
	else if (c == 'c')
		return (dup_car(va_arg(*start, int)));
	else if (c == 'p')
		return (aff_p(va_arg(*start, unsigned long int)));
	else if (c == 'u')
		return (ft_unsigned_itoa(va_arg(*start, unsigned int)));
	else if (c == 'x')
		return (aff_x(va_arg(*start, unsigned int)));
	else if (c == 'X')
		return (aff_bigx(va_arg(*start, unsigned int)));
	else if (c == '%')
		return (dup_car('%'));
	return (NULL);
}
