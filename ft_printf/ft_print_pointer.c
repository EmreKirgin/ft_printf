/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirgin <ekirgin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:16:14 by ekirgin           #+#    #+#             */
/*   Updated: 2026/05/30 13:01:40 by ekirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_pointer_hex(unsigned long n)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;

	if (n >= 16)
		count += ft_print_pointer_hex(n / 16);
	count += ft_print_char(base[n % 16]);
	return (count);
}

int	ft_print_pointer(void *ptr)
{
	int				count;
	unsigned long	address;

	count = 0;
	address = (unsigned long)ptr;
	count += ft_print_string("0x");
	count += ft_print_pointer_hex(address);
	return (count);
}
