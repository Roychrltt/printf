/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:29:02 by xiaxu             #+#    #+#             */
/*   Updated: 2024/05/30 13:13:06 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

static int	get_ptr_len(uintptr_t p)
{
	int	len;

	len = 0;
	if (p == 0)
		return (1);
	while (p)
	{
		p /= 16;
		len++;
	}
	return (len);
}

static void	put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		put_ptr(num / 16);
		put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			print_c(num + '0');
		else
			print_c(num - 10 + 'a');
	}
}

int	print_p(unsigned long long ptr)
{
	int			print_len;
	uintptr_t	p;

	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	p = (uintptr_t)ptr;
	print_len = 0;
	print_len += write(1, "0x", 2);
	print_len += get_ptr_len(p);
	put_ptr(p);
	return (print_len);
}
