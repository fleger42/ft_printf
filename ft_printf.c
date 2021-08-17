/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:54:23 by fleger            #+#    #+#             */
/*   Updated: 2019/12/21 07:51:11 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_dot_format(t_def *tab_pars, char **str)
{
	if (tab_pars->chara != 's' && tab_pars->chara != '%')
	{
		if (tab_pars->str[0] == '-')
		{
			*str = ft_itoa(-ft_atoi(tab_pars->str));
			*str = ft_add_char_f(*str, '0', tab_pars->size_dot);
			*str = ft_add_char_f(*str, '-', ft_strlen(*str) + 1);
		}
		else if (tab_pars->size_dot == 0 && (ft_atoi(tab_pars->str)
		== 0 && ft_isdigit(tab_pars->str[0])))
			*str = ft_strdup("");
		else
			*str = ft_add_char_f(ft_strdup(tab_pars->str), '0',
			tab_pars->size_dot);
	}
	else if (tab_pars->chara == 's' || tab_pars->chara == '%')
	{
		if ((int)ft_strlen(tab_pars->str) < tab_pars->size_dot ||
		tab_pars->size_dot < 0 || tab_pars->chara != 's')
			*str = ft_strdup(tab_pars->str);
		else
			*str = ft_substr(tab_pars->str, 0, tab_pars->size_dot);
	}
	free(tab_pars->str);
}

int		ft_dot(t_def *tab_pars, int size)
{
	char	*str;

	ft_dot_format(tab_pars, &str);
	if (tab_pars->f_size)
	{
		if (tab_pars->is_less)
			str = ft_add_char_b(str, ' ', tab_pars->f_size);
		else if (tab_pars->is_zero == 1 && tab_pars->size_dot < 0)
		{
			if (str[0] == '-' && tab_pars->chara != '%')
			{
				str = ft_itoa(-ft_atoi(str));
				str = ft_add_char_f(str, '0', tab_pars->f_size - 1);
				str = ft_add_char_f(str, '-', ft_strlen(str) + 1);
			}
			else
				str = ft_add_char_f(str, '0', tab_pars->f_size);
		}
		else if (tab_pars->chara == '%' && tab_pars->is_zero == 1)
			str = ft_add_char_f(str, '0', tab_pars->f_size);
		else
			str = ft_add_char_f(str, ' ', tab_pars->f_size);
	}
	size = ft_multprecision(tab_pars, &str);
	return (size);
}

int		ft_multprecision(t_def *tab_pars, char **str)
{
	int size;

	if (tab_pars->is_mult)
	{
		if (tab_pars->size_mult < 0)
			*str = ft_add_char_b(*str, ' ', -(tab_pars->size_mult));
		else if (tab_pars->is_less)
			*str = ft_add_char_b(*str, ' ', tab_pars->size_mult);
		else if (tab_pars->is_zero && tab_pars->size_dot < 0)
			*str = ft_add_char_f(*str, '0', tab_pars->size_mult);
		else
			*str = ft_add_char_f(*str, ' ', tab_pars->size_mult);
	}
	ft_putstr(*str);
	size = ft_strlen(*str);
	free(*str);
	return (size);
}

int		ft_mult(t_def *tab_pars)
{
	char	*str;
	int		size;

	if (tab_pars->size_mult < 0)
		str = ft_add_char_b(tab_pars->str, ' ', -tab_pars->size_mult);
	else if (tab_pars->is_less)
		str = ft_add_char_b(tab_pars->str, ' ', tab_pars->size_mult);
	else if (tab_pars->is_zero)
		str = ft_add_char_f(tab_pars->str, '0', tab_pars->size_mult);
	else
		str = ft_add_char_f(tab_pars->str, ' ', tab_pars->size_mult);
	ft_putstr(str);
	size = ft_strlen(str);
	free(str);
	return (size);
}

int		ft_printf(const char *c, ...)
{
	t_def	*tab_pars;
	va_list start;
	int		i;
	int		ret;

	i = -1;
	va_start(start, c);
	tab_pars = (t_def *)malloc(sizeof(t_def));
	ret = ft_choose(tab_pars, c, &start);
	va_end(start);
	free(tab_pars);
	return (ret);
}
