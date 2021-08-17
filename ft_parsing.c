/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 08:07:32 by fleger            #+#    #+#             */
/*   Updated: 2019/12/20 08:07:41 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pars_glob(const char *str, t_def *tab_pars, va_list *start, int j)
{
	if (str[j] == '*')
	{
		tab_pars->is_mult = 1;
		tab_pars->size_mult = va_arg(*start, int);
	}
	if (str[j] == '.')
	{
		tab_pars->is_dot = 1;
		if (str[j + 1] == '*')
		{
			tab_pars->size_dot = va_arg(*start, int);
			j++;
		}
		else
		{
			tab_pars->size_dot = (ft_atoi(str + j + 1));
			while (ft_isdigit(str[j + 1]))
				j++;
		}
	}
	if (str[j] == '-')
		tab_pars->is_less = 1;
	return (j);
}

void	ft_parsing(const char *str, t_def *tab_pars, va_list *start)
{
	int j;

	j = -1;
	while (str[++j])
	{
		if (str[j] == '%')
		{
			while (!is_format(str[++j]))
			{
				if (ft_isdigit(str[j]) && str[j] != '0')
				{
					tab_pars->f_size = ft_atoi(str + j);
					while (ft_isdigit(str[j + 1]))
						j++;
				}
				else if (str[j] == '0')
					tab_pars->is_zero = 1;
				j = ft_pars_glob(str, tab_pars, start, j);
			}
			tab_pars->chara = str[j];
			tab_pars->str = cara_specific(str[j], start);
			return ;
		}
	}
}
