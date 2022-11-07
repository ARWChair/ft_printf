/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatabay <yatabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:07:38 by yatabay           #+#    #+#             */
/*   Updated: 2022/11/05 23:53:31 by yatabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printfc(int c)
{
	write(1, &c, 1);
	return (1);
}

static	int	printfs(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[counter])
		write(1, &str[counter++], 1);
	return (counter);
}

static	int	controller(char param, va_list args)
{
	if (param == 'c')
		return (printfc(va_arg(args, int)));
	else if (param == 's')
		return (printfs(va_arg(args, char *)));
	else if (param == 'd' || param == 'i')
		return (printfdi(va_arg(args, int)));
	else if (param == 'u')
		return (printfdi(va_arg(args, unsigned int)));
	else if (param == 'p')
		return (printfh(va_arg(args, unsigned long long), 2, 0));
	else if (param == 'x')
		return (printfh(va_arg(args, unsigned int), 0, 0));
	else if (param == 'X')
		return (printfh(va_arg(args, unsigned int), 1, 0));
	else if (param == '%')
		return (printfc('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		c;
	int		i;
	va_list	args;

	i = 0;
	c = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			c += controller(str[i + 1], args);
			i += 2;
		}
		else
			c += printfc(str[i++]);
	}
	va_end(args);
	return (c);
}

int main()
{
	int a = 'f';
	char *b = "String";
	ft_printf("%c\n", a);
	ft_printf("%c\n", '%');
	ft_printf("%s\n", b);
	ft_printf("%p\n", b);
}