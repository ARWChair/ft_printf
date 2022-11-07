/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_indi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatabay <yatabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:46:07 by yatabay           #+#    #+#             */
/*   Updated: 2022/11/05 22:47:58 by yatabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	putnbr(unsigned long long digit)
{
	if (digit > 9)
	{
		putnbr(digit / 10);
		putnbr(digit % 10);
	}
	else
	{
		printfc(digit + '0');
	}
}

int	printfdi(long long n)
{
	int	counter;

	if (n < 0)
	{
		counter = 1;
		write(1, "-", 1);
		n = n * -1;
	}
	else
		counter = 0;
	if (n == 0)
		counter++;
	putnbr(n);
	while (n != 0)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}
