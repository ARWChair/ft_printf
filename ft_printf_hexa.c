/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatabay <yatabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:07:27 by yatabay           #+#    #+#             */
/*   Updated: 2022/11/05 22:17:35 by yatabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	hexsmall(unsigned long long n)
{
	char	hex;

	if (n == 15)
		write(1, "f", 1);
	else if (n == 14)
		write(1, "e", 1);
	else if (n == 13)
		write(1, "d", 1);
	else if (n == 12)
		write(1, "c", 1);
	else if (n == 11)
		write(1, "b", 1);
	else if (n == 10)
		write(1, "a", 1);
	else
	{
		hex = n + '0';
		write(1, &hex, 1);
	}
}

static	void	hexsbig(unsigned long long n)
{
	char	hex;

	if (n == 15)
		write(1, "F", 1);
	else if (n == 14)
		write(1, "E", 1);
	else if (n == 13)
		write(1, "D", 1);
	else if (n == 12)
		write(1, "C", 1);
	else if (n == 11)
		write(1, "B", 1);
	else if (n == 10)
		write(1, "A", 1);
	else
	{
		hex = n + '0';
		write(1, &hex, 1);
	}
}

static	void	hexcalc(unsigned long long n, int switcher)
{
	if (n > 15)
	{
		hexcalc(n / 16, switcher);
		hexcalc(n % 16, switcher);
	}
	else
	{
		if (switcher == 1)
			hexsbig(n);
		else
			hexsmall(n);
	}
}

int	printfh(unsigned long long n, int switcher, int counter)
{
	if (switcher == 2)
	{
		if (n == 0)
		{
			write(1, "(nil)", 5);
			return (5);
		}
		else
		{
			write(1, "0x", 2);
			counter += 2;
		}
	}
	if (n == 0)
		counter++;
	hexcalc(n, switcher);
	while (n != 0)
	{
		counter++;
		n /= 16;
	}
	return (counter);
}
