/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirgin <ekirgin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:14:57 by ekirgin           #+#    #+#             */
/*   Updated: 2026/05/30 12:36:44 by ekirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);

int	ft_print_char(int c);
int	ft_print_string(char *s);
int	ft_print_number(long n);
int	ft_print_unsigned(unsigned int n);

#endif
