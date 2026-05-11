#include "libft.h"

int	ft_putstr_n(char *str, int n) {
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < n) {
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
