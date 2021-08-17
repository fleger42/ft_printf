/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:50:47 by fleger            #+#    #+#             */
/*   Updated: 2019/12/21 07:50:17 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_def
{
	int		is_less;
	int		is_dot;
	int		is_mult;
	int		is_zero;
	int		size_dot;
	int		size_mult;
	int		f_size;
	char	chara;
	char	*str;
}					t_def;
char				*ft_add_char_b(char *str, char cara, int c);
char				*ft_add_char_f(char *str, char cara, int c);
char				*aff_p(unsigned long int adr);
char				*aff_x(unsigned int adr);
char				*aff_bigx(unsigned int adr);
int					ft_isdigit(int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);
void				ft_putchar(char c);
int					is_format(char c);
char				*ft_strdup(const char *s1);
char				*dup_car(char c);
int					ft_nbr_c(int n);
char				*ft_itoa(int n);
int					ft_atoi(const char *nptr);
void				ft_putstr(char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_unsigned_nbr_c(unsigned int n);
char				*ft_unsigned_itoa(unsigned int n);
char				*cara_specific(char c, va_list *start);
void				ft_parsing(const char *str, t_def *tab_pars,
va_list *start);
int					ft_dot(t_def *tab_pars, int size);
int					ft_mult(t_def *tab_pars);
int					ft_choose(t_def *tab_pars, const char *str, va_list *start);
int					ft_count(char *str);
int					ft_printf(const char *c, ...);
void				ft_init_null(t_def	*tab_pars);
int					ft_multprecision(t_def *tab_pars, char **str);
#endif
