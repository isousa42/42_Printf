/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:51:14 by isousa            #+#    #+#             */
/*   Updated: 2021/03/29 12:51:20 by isousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stddef.h>

typedef struct	s_fl
{
	int		zero;
	int		width;
	int		dot;
	int		hiffen;
	int		star;
	char	letter;

}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_start(const char *format, va_list args);
int				ft_spec(const char *format, va_list args, t_flags *s_fl, int i);
int				ft_letter(t_flags s_flags, va_list args);
t_flags			ft_startflags(void);
int				ft_dot(const char *format, va_list args, t_flags *s_fl, int i);
void			ft_hiffen(t_flags *s_fl);
void			ft_star(va_list args, t_flags *s_fl);
void			ft_width(char c, t_flags *s_fl);
int				ft_convchar(char c, t_flags s_flags);
int				ft_putstrdot(int dot, char *str);
int				ft_convstr(char *str, t_flags s_flags);
int				ft_convper(char c, t_flags s_flags);
int				ft_convint(int num, t_flags s_flags);
int				ft_intwidth(t_flags s_flags, char *str, int sign, int nb);
int				ft_printint(t_flags s_flags, int sign, int nb, char *str);
int				ft_callfun(t_flags s_flags, int nb, int sign, char *str);
int				ft_intexep(t_flags s_flags);
int				ft_convunint(unsigned int num, t_flags s_flags);
int				ft_printun(t_flags s_flags, char *str);
int				ft_convpointer(unsigned long long ptr, t_flags s_flags);
int				ft_addrexep(t_flags s_flags);
int				ft_negwidth(t_flags s_flags, char *str);
int				ft_addrwidth(t_flags s_flags, char *str);
int				ft_negexep(t_flags s_flags);
int				ft_convhexa(unsigned int num, int xtype, t_flags s_flags);
int				ft_printhexa(t_flags s_flags, char *hexa);
int				ft_strlen(char *str);
int				ft_putchar(char c);
char			*ft_strdup(char *src);
char			*ft_tolower(char *c);
int				ft_convwidth(int width, int size, int zero);
int				ft_precision(char *str, int dot);
int				ft_let(char c);
int				ft_digit(char c);
int				ft_flag(char c);
char			*ft_itoa(long int n);
char			*ft_unsigneditoa(unsigned long long n, int base);
int				ft_intlen(long int n, int base);
int				ft_unintlen(unsigned long long n, int base);

#endif
