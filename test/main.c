#include "printf.h"

int	main() {

	 printf("%s : another str: %s\n", "Hello World", "Hello World 2");
	//ft_printf("%10s\n", "Hello World");
	//ft_printf("%-#10.5hhx: after text %.5s again, %%, %-5.12X lakdsfj %#.12llo lklkj\n", "Hello World");
	//ft_printf("%s : another str: %s\n", "Hello World", "Hello World 2");
	ft_printf("%hhd - %hd - %d - %hhd\n",  81029, 90384949399, 85930, 7849);
	//printf("%hhd - %hd - %d - %ld - %lld\n",  81029, 90384949399, 2039884, 589938L, 7483038LL);
	//ft_printf("%d - %ld adfdsa\n", 85040, 85949);
	return (0);
}
