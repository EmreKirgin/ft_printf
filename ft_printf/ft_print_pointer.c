/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirgin <ekirgin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:12:22 by ekirgin           #+#    #+#             */
/*   Updated: 2026/05/31 22:14:30 by ekirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_pointer_hex(unsigned long n)
{
	int			count;
	const char	*base;

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

	if (ptr == NULL)
		return (ft_print_string("(nil)"));
	count = 0;
	address = (unsigned long)ptr;
	count += ft_print_string("0x");
	count += ft_print_pointer_hex(address);
	return (count);
}
