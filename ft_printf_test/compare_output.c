/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirgin <ekirgin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 13:20:00 by ekirgin           #+#    #+#             */
/*   Updated: 2026/06/20 13:20:00 by ekirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

#define PRINTF_FILE "printf_output.txt"
#define FT_FILE "ft_output.txt"

static int	g_pointer_value = 42;
static char	*g_null_string = NULL;

static int	call_printf(int test_id)
{
	if (test_id == 1)
		return (printf("Hello ft_printf\n"));
	else if (test_id == 2)
		return (printf("String: %s\n", "Hello"));
	else if (test_id == 3)
		return (printf("Null string: %s\n", g_null_string));
	else if (test_id == 4)
		return (printf("Char: %c\n", 'A'));
	else if (test_id == 5)
		return (printf("Null char: %c END\n", '\0'));
	else if (test_id == 6)
		return (printf("Number: %d\n", 42));
	else if (test_id == 7)
		return (printf("Number: %i\n", -42));
	else if (test_id == 8)
		return (printf("INT_MIN: %d\n", INT_MIN));
	else if (test_id == 9)
		return (printf("UINT_MAX: %u\n", UINT_MAX));
	else if (test_id == 10)
		return (printf("Lower hex: %x\n", 255));
	else if (test_id == 11)
		return (printf("Upper hex: %X\n", 255));
	else if (test_id == 12)
		return (printf("Pointer: %p\n", &g_pointer_value));
	else if (test_id == 13)
		return (printf("Null pointer: %p\n", NULL));
	else if (test_id == 14)
		return (printf("Percent: %%\n"));
	else if (test_id == 15)
		return (printf("Mixed: %s %d %x %%\n", "test", 42, 255));
	return (-1);
}

static int	call_ft_printf(int test_id)
{
	if (test_id == 1)
		return (ft_printf("Hello ft_printf\n"));
	else if (test_id == 2)
		return (ft_printf("String: %s\n", "Hello"));
	else if (test_id == 3)
		return (ft_printf("Null string: %s\n", g_null_string));
	else if (test_id == 4)
		return (ft_printf("Char: %c\n", 'A'));
	else if (test_id == 5)
		return (ft_printf("Null char: %c END\n", '\0'));
	else if (test_id == 6)
		return (ft_printf("Number: %d\n", 42));
	else if (test_id == 7)
		return (ft_printf("Number: %i\n", -42));
	else if (test_id == 8)
		return (ft_printf("INT_MIN: %d\n", INT_MIN));
	else if (test_id == 9)
		return (ft_printf("UINT_MAX: %u\n", UINT_MAX));
	else if (test_id == 10)
		return (ft_printf("Lower hex: %x\n", 255));
	else if (test_id == 11)
		return (ft_printf("Upper hex: %X\n", 255));
	else if (test_id == 12)
		return (ft_printf("Pointer: %p\n", &g_pointer_value));
	else if (test_id == 13)
		return (ft_printf("Null pointer: %p\n", NULL));
	else if (test_id == 14)
		return (ft_printf("Percent: %%\n"));
	else if (test_id == 15)
		return (ft_printf("Mixed: %s %d %x %%\n", "test", 42, 255));
	return (-1);
}

static int	capture_output(const char *file, int (*func)(int), int test_id)
{
	int	fd;
	int	stdout_copy;
	int	ret;

	fflush(stdout);
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (-1);
	stdout_copy = dup(STDOUT_FILENO);
	if (stdout_copy < 0)
	{
		close(fd);
		return (-1);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		close(stdout_copy);
		close(fd);
		return (-1);
	}
	ret = func(test_id);
	fflush(stdout);
	if (dup2(stdout_copy, STDOUT_FILENO) < 0)
		ret = -1;
	close(stdout_copy);
	close(fd);
	return (ret);
}

static int	files_are_equal(const char *file1, const char *file2)
{
	int		fd1;
	int		fd2;
	ssize_t	r1;
	ssize_t	r2;
	char	b1;
	char	b2;

	fd1 = open(file1, O_RDONLY);
	fd2 = open(file2, O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
		return (0);
	r1 = read(fd1, &b1, 1);
	r2 = read(fd2, &b2, 1);
	while (r1 > 0 && r2 > 0)
	{
		if (b1 != b2)
		{
			close(fd1);
			close(fd2);
			return (0);
		}
		r1 = read(fd1, &b1, 1);
		r2 = read(fd2, &b2, 1);
	}
	close(fd1);
	close(fd2);
	return (r1 == r2);
}

static int	run_test(int id, const char *name)
{
	int	printf_ret;
	int	ft_ret;
	int	output_match;

	printf_ret = capture_output(PRINTF_FILE, call_printf, id);
	ft_ret = capture_output(FT_FILE, call_ft_printf, id);
	output_match = files_are_equal(PRINTF_FILE, FT_FILE);
	if (printf_ret == ft_ret && output_match)
	{
		printf("[OK]   %s\n", name);
		return (0);
	}
	printf("[FAIL] %s\n", name);
	printf("       printf return:    %d\n", printf_ret);
	printf("       ft_printf return: %d\n", ft_ret);
	printf("       output match:     %s\n", output_match ? "yes" : "no");
	return (1);
}

int	main(void)
{
	int	failures;

	failures = 0;
	failures += run_test(1, "plain text");
	failures += run_test(2, "string");
	failures += run_test(3, "null string");
	failures += run_test(4, "char");
	failures += run_test(5, "null char");
	failures += run_test(6, "positive integer");
	failures += run_test(7, "negative integer");
	failures += run_test(8, "INT_MIN");
	failures += run_test(9, "UINT_MAX");
	failures += run_test(10, "lower hex");
	failures += run_test(11, "upper hex");
	failures += run_test(12, "pointer");
	failures += run_test(13, "null pointer");
	failures += run_test(14, "percent sign");
	failures += run_test(15, "mixed format");
	remove(PRINTF_FILE);
	remove(FT_FILE);
	if (failures == 0)
		printf("\nAll output and return-value tests passed.\n");
	else
		printf("\n%d test(s) failed.\n", failures);
	return (failures);
}
