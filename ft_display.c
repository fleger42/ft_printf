/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 08:05:58 by fleger            #+#    #+#             */
/*   Updated: 2019/12/21 07:42:35 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display_formatsize(t_def *tab_pars, int ret, char *temp)
{
	if (tab_pars->is_less)
		ft_putstr(temp = ft_add_char_b(tab_pars->str, ' ',
	tab_pars->f_size));
	else if (tab_pars->is_zero)
	{
		if (tab_pars->str[0] == '-')
		{
			ft_putchar('-');
			ret++;
			temp = ft_itoa(-ft_atoi(tab_pars->str));
			ft_putstr(temp = ft_add_char_f(temp, '0',
			tab_pars->f_size - 1));
			free(tab_pars->str);
		}
		else
			ft_putstr(temp = ft_add_char_f(tab_pars->str,
			'0', tab_pars->f_size));
	}
	else if (tab_pars->is_less)
		ft_putstr(temp = ft_add_char_b(tab_pars->str, ' ', tab_pars->f_size));
	else
		ft_putstr(temp = ft_add_char_f(tab_pars->str, ' ', tab_pars->f_size));
	ret += ft_strlen(temp);
	free(temp);
	return (ret);
}

int		ft_display(t_def *tab_pars, int ret)
{
	char	*temp;
	int		size;

	size = 0;
	temp = NULL;
	if (tab_pars->is_dot == 1)
		ret += ft_dot(tab_pars, size);
	else if (tab_pars->is_mult == 1)
		ret += ft_mult(tab_pars);
	else if (tab_pars->f_size)
		ret = ft_display_formatsize(tab_pars, ret, temp);
	else
	{
		if (tab_pars->str[0] != '\0')
			ret += ft_strlen(tab_pars->str);
		else if (tab_pars->chara == 'c')
		{
			ft_putchar('\0');
			ret++;
		}
		ft_putstr(tab_pars->str);
		free(tab_pars->str);
	}
	return (ret);
}

int		ft_choose(t_def *tab_pars, const char *str, va_list *start)
{
	int		i;
	int		ret;
	int		j;

	j = 0;
	i = -1;
	ret = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			ft_init_null(tab_pars);
			ft_parsing(str + i++, tab_pars, &*start);
			ret = ft_display(tab_pars, ret);
			j++;
			while (!is_format(str[i]))
				i++;
		}
		else
		{
			ft_putchar(str[i]);
			ret++;
		}
	}
	return (ret);
}
