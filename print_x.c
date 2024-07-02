/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:41:00 by xiaxu             #+#    #+#             */
/*   Updated: 2024/07/02 23:19:32 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

static int	print_c(int c)
{
	write (1, &c, 1);
	return (1);
}

static int	get_hex_len(uintptr_t num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static void	put_hex(uintptr_t num, char format)
{
	if (num >= 16)
	{
		put_hex(num / 16, format);
		put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			print_c(num + '0');
		else
		{
			if (format == 'x')
				print_c(num - 10 + 'a');
			if (format == 'X')
				print_c(num - 10 + 'A');
		}
	}
}

int	print_x(unsigned int nb, char format)
{
	int	print_len;

	print_len = 0;
	print_len += get_hex_len(nb);
	put_hex(nb, format);
	return (print_len);
}

int	print_p(unsigned long long ptr)
{
	int			print_len;

	if (ptr == 0)
		return (write(1, "(nil)", 5));
	print_len = 0;
	print_len += write(1, "0x", 2);
	print_len += get_hex_len((uintptr_t)ptr);
	put_hex((uintptr_t)ptr, 'x');
	return (print_len);
}
