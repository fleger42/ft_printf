/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 22:14:28 by fleger            #+#    #+#             */
/*   Updated: 2019/12/20 05:43:27 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*aff_x(unsigned int adr)
{
	char				*base;
	char				*chaine;
	int					i;
	unsigned long int	copy;

	copy = adr;
	base = "0123456789abcdef";
	i = 0;
	if (adr == 0)
		return (ft_strdup("0"));
	while (copy / 16 > 0)
	{
		copy = copy / 16;
		i++;
	}
	chaine = malloc(sizeof(char) * (i + 1));
	chaine[i + 1] = '\0';
	while (adr / 16 > 0)
	{
		chaine[i] = base[(adr % 16)];
		adr = adr / 16;
		i--;
	}
	chaine[i] = base[(adr % 16)];
	return (chaine);
}

char	*aff_bigx(unsigned int adr)
{
	char				*base;
	char				*chaine;
	int					i;
	unsigned long int	copy;

	copy = adr;
	base = "0123456789ABCDEF";
	i = 0;
	if (adr == 0)
		return (ft_strdup("0"));
	while (copy / 16 > 0)
	{
		copy = copy / 16;
		i++;
	}
	chaine = malloc(sizeof(char) * (i + 1));
	chaine[i + 1] = '\0';
	while (adr / 16 > 0)
	{
		chaine[i] = base[(adr % 16)];
		adr = adr / 16;
		i--;
	}
	chaine[i] = base[(adr % 16)];
	return (chaine);
}
