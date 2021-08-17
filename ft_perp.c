/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 21:57:24 by fleger            #+#    #+#             */
/*   Updated: 2019/12/20 05:41:03 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*aff_p(unsigned long int adr)
{
	char				*base;
	char				*chaine;
	int					i;
	unsigned long int	copy;

	copy = adr;
	base = "0123456789abcdef";
	i = 2;
	while (copy / 16 > 0)
	{
		copy = copy / 16;
		i++;
	}
	chaine = malloc(sizeof(char) * (i + 1));
	chaine[i + 1] = '\0';
	chaine[0] = '0';
	chaine[1] = 'x';
	while (adr / 16 > 0)
	{
		chaine[i] = base[(adr % 16)];
		adr = adr / 16;
		i--;
	}
	chaine[i] = base[(adr % 16)];
	return (chaine);
}
