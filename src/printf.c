#include "printf.h"

void print_args(t_args args) {
    printf("------- t_args Flags -------\n");
    printf("zero         : %d\n", args.zero);
    printf("left         : %d\n", args.left);
    printf("padding      : %d\n", args.padding);
    printf("pound        : %d\n", args.pound);
    printf("space        : %d\n", args.space);
    printf("plus         : %d\n", args.plus);
    printf("dot          : %d\n", args.dot);
    printf("is_uppercase : %d\n", args.is_uppercase);
    printf("h            : %d\n", args.h);
    printf("hh           : %d\n", args.hh);
    printf("l            : %d\n", args.l);
    printf("ll           : %d\n", args.ll);
    printf("hex          : %d\n", args.hex);
    printf("octal        : %d\n", args.octal);
    printf("decimal      : %d\n", args.decimal);
    printf("string       : %d\n", args.string);
    printf("pointer      : %d\n", args.pointer);
    printf("character    : %d\n", args.character);
    printf("is_float     : %d\n", args.is_float);
    printf("is_signed    : %d\n", args.is_signed);
    printf("is_unsigned  : %d\n", args.is_unsigned);
    printf("----------------------------\n");
}

t_args init() {
    t_args args;

    args.zero = 0;
    args.left = 0;
    args.padding = 0;
    args.pound = 0;
    args.space = 0;
    args.plus = 0;
    args.dot = 0;
    args.is_uppercase = 0;
    args.h = 0;
    args.hh = 0;
    args.l = 0;
    args.ll = 0;
    args.hex = 0;
    args.octal = 0;
    args.decimal = 0;
    args.string = 0;
    args.pointer = 0;
    args.character = 0;
    args.is_float = 0;
    args.is_signed = 0;
    args.is_unsigned = 0;

    return (args);
}

void    set_args(char c, t_args *args) {
	if (c == '#')
		args->pound = 1;
	else if (c == '0')
		args->zero = 1;
	else if (c == '-')
		args->left = 1;
	else if (c == '+')
		args->plus = 1;
	else if (c == ' ')
		args->space = 1;
}

void	parse_args(char *buffer, t_args *args) {
	int i;
	int j;
	char buff[4095];
	char *dot;
	
	i = 0;
	j = 0;
	buff[0] = '\0';
	while (buffer[i] == '#' || buffer[i] == '0' || buffer[i] == '-' || buffer[i] == '+' || buffer[i] == ' ') {
		set_args(buffer[i], args);
		i++;
	}
	while (buffer[i]) {
		buff[j] = buffer[i];	
		i++;
		j++;
	}
	buff[j] = '\0';
	if (j > 0) {
		dot = ft_strchr(buffer, '.');
		if (dot != NULL) {
			dot++;
			args->dot = ft_atoi(dot);
			if (args->dot == 0)
				args->dot = -1;	
		}
		if (buff[j - 1]) {
			args->padding = ft_atoi(buff);
		}
	}
}

int	check_for_datatype(char c) {
	if (c == 'c' || c == 'd' || c == 'i' || c == 's' || c == 'p')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == 'o' || c == 'f')
		return (1);
	if (c == 'h' || c == 'l' || c =='L')
		return (1);
	return (0);
}


void	get_data_format(char *str, int i, t_args *args) {
	if (str[i] == 'o')
		args->octal = 1;
	else if (str[i] == 'x')
		args->hex = 1;
	else if (str[i] == 'X') {
		args->hex = 1;
		args->is_uppercase = 1;
	} else if (str[i] == 'd' || str[i] == 'i') {
		args->decimal = 1;
		args->is_signed = 1;
	} else if (str[i] == 'u') {
		args->decimal = 1;
		args->is_signed = 1;
	}
}

int	get_datatype_args(char *str, int j, t_args *args) {
	int i;

	i = 0;
	if (j == -1)
		return (0);
	i = j + 1;
	printf("str[i]: %c\n", str[i - 1]);
	if (str[i] == 's')
		args->string = 1;
	else if (str[i] == 'c')
		args->character = 1;
	else if (str[i] == 'p')
		args->pointer = 1;
	else if (str[i] == 'o')
		args->octal = 1;
	else if (str[i] == 'x')
		args->hex = 1;
	else if (str[i] == 'X') {
		args->hex = 1;
		args->is_uppercase = 1;
	} else if (str[i] == 'd' || str[i] == 'i') {
		args->decimal = 1;
		args->is_signed = 1;
	} else if (str[i] == 'u') {
		args->decimal = 1;
		args->is_signed = 1;
	} else if (str[i] == 'f')
		args->is_float = 1;
	else if (str[i] == 'h' && str[i + 1] == 'h') {
		args->hh = 1;
		get_data_format(str, i + 2, args);
		return (2);
	}
	else if (str[i] == 'h') {
		args->h = 1;
		get_data_format(str, i + 1, args);
	}
	else if (str[i] == 'l' && str[i] == 'l') {
		args->ll = 1;
		get_data_format(str, i + 2, args);
		return (2);
	}
	else if (str[i] == 'l') {
		args->l = 1;
		get_data_format(str, i + 1, args);
	} else {
		return (0);
	}
	return (1);
}

int	parse_arg_parameters(char *str, int i, t_args *args) {
	char 	buffer[4095];
	int	j;
	int	start;

	j = 0;
	start = i - 1;
	buffer[0] = '\0';
	while(!check_for_datatype(str[i])) {
		if (!str[i])
			return (-1);
		buffer[j++] = str[i++];
	}
	buffer[j] = '\0';
	parse_args(buffer, args);
	j += get_datatype_args(str, j + start, args);
	return (j);
}

int	ft_printf(char *str, ...) {
	va_list list;
	int	i;
	int	res;
	int 	count;
	t_args args;

	i = 0;
	res = 0;
	count = 0;
	va_start(list, str);
	while (str[i]) {
		args = init();
		while (str[i] != '%' && str[i]) 
			count += ft_putchar(str[i++]);
		if (!str[i]) 
			break;
		if (str[i + 1] == '%') {
			count += ft_putchar('%');
			i++;	
		} else  {
			res = parse_arg_parameters(str, i + 1, &args);
			if (res == -1) {
				count += 1;
				break;
			} else
				i += res + 1;
		}
		print_args(args);
		i++;
	}
	return(count);
}
