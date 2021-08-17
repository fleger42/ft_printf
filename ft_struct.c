/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 22:43:27 by fleger            #+#    #+#             */
/*   Updated: 2019/12/20 07:27:52 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_null(t_def *tab_pars)
{
	tab_pars->is_mult = 0;
	tab_pars->is_zero = 0;
	tab_pars->is_dot = 0;
	tab_pars->is_less = 0;
	tab_pars->size_dot = 0;
	tab_pars->size_mult = 0;
	tab_pars->f_size = 0;
	tab_pars->chara = '0';
	tab_pars->str = NULL;
}
