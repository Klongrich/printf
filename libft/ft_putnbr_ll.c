/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klongric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 22:27:34 by klongric          #+#    #+#             */
/*   Updated: 2017/01/10 15:50:44 by klongric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_ll(signed long long n, int base) {
	int	count;
	char	*symbols;
	unsigned long long nb; 

	count = 0;
	symbols = "0123456789abcdef";
	if (n == 0)
		return (ft_putchar('0'));
	else if (n < 0) {
		count += ft_putchar('-');
		nb = (unsigned long long)-n;
	} else {
		nb = (unsigned long long)n;
    	}
	if (nb >= (unsigned long long)base)
		count += ft_putnbr_ll(nb / base, base);
	count += ft_putchar(symbols[nb % base]);
	return (count);
}
