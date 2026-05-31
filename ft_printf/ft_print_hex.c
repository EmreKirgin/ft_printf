/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirgin <ekirgin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:16:02 by ekirgin           #+#    #+#             */
/*   Updated: 2026/05/30 12:50:24 by ekirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex_base(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_print_hex_base(n / 16, base);
	count += ft_print_char(base[n % 16]);
	return (count);
}

int	ft_print_hex(unsigned int n, char format)
{
	if (format == 'x')
		return (ft_print_hex_base(n, "0123456789abcdef"));
	if (format == 'X')
		return (ft_print_hex_base(n, "0123456789ABCDEF"));
	return (0);
}
