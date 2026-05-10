#include "printf.h"

int	main() {

	 printf("%s : another str: %s\n", "Hello World", "Hello World 2");
	//ft_printf("%10s\n", "Hello World");
	//ft_printf("%-#10.5hhx: after text %.5s again, %%, %-5.12X lakdsfj %#.12llo lklkj\n", "Hello World");
	//ft_printf("%s : another str: %s\n", "Hello World", "Hello World 2");
	ft_printf("%hhd - %hd - %d - %hhd\n",  81029, 90384949399, 85930, 7849);
	ft_printf("%hhx - %hx - %x - %hhx\n",  81029, 90384949399, 85930, 7849);
	ft_printf("%hho - %ho - %o - %hho\n",  81029, 90384949399, 85930, 7849);
	printf("%hho - %ho - %o - %hho\n",  81029, 90384949399, 85930, 7849);
	
	CHECK("%5u\n", 9493);
	CHECK("%-10u -\n", 98403);
	CHECK("%4u\n", 85940);
	CHECK("%010u\n", 7840);
	printf("\n\n\n");
	CHECK("%5x\n", 7584);
	CHECK("%10X\n", 49483);
	CHECK("%#10x\n", 8504);
	CHECK("%#x\n", 85994);
	CHECK("%-10x -\n", 94903);
	CHECK("%-#12x -\n", 95940);
	CHECK("%#010x\n", 8590);
	CHECK("%#02x\n", 8504);
	CHECK("%#10x\n", 0);
	printf("\n\n\n");
	CHECK("%5o\n", 7584);
	CHECK("%10o\n", 49483);
	CHECK("%#10o\n", 8504);
	CHECK("%#o\n", 85994);
	CHECK("%-10o -\n", 94903);
	CHECK("%-#12o -\n", 95940);
	CHECK("%#010o\n", 8590);
	CHECK("%#02o\n", 8504);
	CHECK("%#10o\n", 0);

	CHECK("%10.4hhu\n", 4000);
	CHECK("%-10.4hhu\n", 4000);
	CHECK("%10hhu\n", 4000);

	CHECK("%10.7x\n", 8504);
	CHECK("%-10.7x -\n", 8504);
	CHECK("%#10.6x\n", 8504);
	CHECK("%-#10.6x -\n", 8504);

	//printf("%hhd - %hd - %d - %ld - %lld\n",  81029, 90384949399, 2039884, 589938L, 7483038LL);
	//ft_printf("%d - %ld adfdsa\n", 85040, 85949);
	return (0);
}
