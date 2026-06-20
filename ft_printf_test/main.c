/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirgin <ekirgin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 16:30:24 by ekirgin           #+#    #+#             */
/*   Updated: 2026/05/31 16:30:38 by ekirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static void	test_header(char *title)
{
	printf("\n========== %s ==========\n", title);
}

static void	compare_returns(int p_ret, int ft_ret)
{
	printf("printf return:    %d\n", p_ret);
	printf("ft_printf return: %d\n", ft_ret);
	if (p_ret == ft_ret)
		printf("RETURN: OK\n");
	else
		printf("RETURN: KO\n");
}

int	main(void)
{
	int		p_ret;
	int		ft_ret;
	int		x;
	char	*null_str;
	void	*null_ptr;

	x = 42;
	null_str = NULL;
	null_ptr = NULL;

	test_header("BASIC TEXT");
	p_ret = printf("Hello world\n");
	ft_ret = ft_printf("Hello world\n");
	compare_returns(p_ret, ft_ret);

	test_header("EMPTY STRING");
	p_ret = 0;
	ft_ret = ft_printf("");
	compare_returns(p_ret, ft_ret);

	test_header("CHAR");
	p_ret = printf("[%c] [%c] [%c] [%c]\n", 'A', '0', ' ', '\0');
	ft_ret = ft_printf("[%c] [%c] [%c] [%c]\n", 'A', '0', ' ', '\0');
	compare_returns(p_ret, ft_ret);

	test_header("STRING");
	p_ret = printf("[%s] [%s] [%s]\n", "hello", "", "42 Berlin");
	ft_ret = ft_printf("[%s] [%s] [%s]\n", "hello", "", "42 Berlin");
	compare_returns(p_ret, ft_ret);

	test_header("NULL STRING");
	p_ret = printf("[%s]\n", null_str);
	ft_ret = ft_printf("[%s]\n", null_str);
	compare_returns(p_ret, ft_ret);

	test_header("SIGNED DECIMAL %d");
	p_ret = printf("[%d] [%d] [%d] [%d] [%d]\n",
			0, 1, -1, INT_MAX, INT_MIN);
	ft_ret = ft_printf("[%d] [%d] [%d] [%d] [%d]\n",
			0, 1, -1, INT_MAX, INT_MIN);
	compare_returns(p_ret, ft_ret);

	test_header("SIGNED INTEGER %i");
	p_ret = printf("[%i] [%i] [%i] [%i] [%i]\n",
			0, 1, -1, INT_MAX, INT_MIN);
	ft_ret = ft_printf("[%i] [%i] [%i] [%i] [%i]\n",
			0, 1, -1, INT_MAX, INT_MIN);
	compare_returns(p_ret, ft_ret);

	test_header("UNSIGNED");
	p_ret = printf("[%u] [%u] [%u] [%u]\n",
			0u, 1u, UINT_MAX, (unsigned int)-1);
	ft_ret = ft_printf("[%u] [%u] [%u] [%u]\n",
			0u, 1u, UINT_MAX, (unsigned int)-1);
	compare_returns(p_ret, ft_ret);

	test_header("HEX LOWERCASE");
	p_ret = printf("[%x] [%x] [%x] [%x] [%x] [%x]\n",
			0u, 1u, 10u, 15u, 16u, UINT_MAX);
	ft_ret = ft_printf("[%x] [%x] [%x] [%x] [%x] [%x]\n",
			0u, 1u, 10u, 15u, 16u, UINT_MAX);
	compare_returns(p_ret, ft_ret);

	test_header("HEX UPPERCASE");
	p_ret = printf("[%X] [%X] [%X] [%X] [%X] [%X]\n",
			0u, 1u, 10u, 15u, 16u, UINT_MAX);
	ft_ret = ft_printf("[%X] [%X] [%X] [%X] [%X] [%X]\n",
			0u, 1u, 10u, 15u, 16u, UINT_MAX);
	compare_returns(p_ret, ft_ret);

	test_header("POINTER");
	p_ret = printf("[%p] [%p]\n", &x, null_ptr);
	ft_ret = ft_printf("[%p] [%p]\n", &x, null_ptr);
	compare_returns(p_ret, ft_ret);

	test_header("PERCENT");
	p_ret = printf("[%%] [%%%%] [hello %% world]\n");
	ft_ret = ft_printf("[%%] [%%%%] [hello %% world]\n");
	compare_returns(p_ret, ft_ret);

	test_header("MIXED");
	p_ret = printf("c=%c s=%s p=%p d=%d i=%i u=%u x=%x X=%X %%\n",
			'A', "hello", &x, -42, INT_MIN, UINT_MAX, 3735928559u,
			3735928559u);
	ft_ret = ft_printf("c=%c s=%s p=%p d=%d i=%i u=%u x=%x X=%X %%\n",
			'A', "hello", &x, -42, INT_MIN, UINT_MAX, 3735928559u,
			3735928559u);
	compare_returns(p_ret, ft_ret);

	test_header("MANY CONVERSIONS");
	p_ret = printf("%d%d%d%d%d%d%d%d%d%d\n",
			1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	ft_ret = ft_printf("%d%d%d%d%d%d%d%d%d%d\n",
			1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	compare_returns(p_ret, ft_ret);

	test_header("TRAILING PERCENT");
	printf("printf behavior may be undefined here, so this is only a crash test.\n");
	ft_ret = ft_printf("hello %");
	printf("\nft_printf return: %d\n", ft_ret);
	

	return (0);
}
