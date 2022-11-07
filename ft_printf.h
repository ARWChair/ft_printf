/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatabay <yatabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 22:17:38 by yatabay           #+#    #+#             */
/*   Updated: 2022/11/05 22:56:56 by yatabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	printfdi(long long n);
int	printfh(unsigned long long n, int switcher, int counter);
int	ft_printf(const char *str, ...);
int	printfc(int c);

#endif