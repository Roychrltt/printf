/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:41:00 by xiaxu             #+#    #+#             */
/*   Updated: 2024/05/30 08:30:05 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	put_hex(unsigned int num, char format)
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
