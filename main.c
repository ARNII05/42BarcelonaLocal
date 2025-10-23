#include "ft_printf.h"   
#include "Libft/libft.h"

#include <stdio.h>

int main(void)
{
    int ret1, ret2;
    char c = 'A';
    char *str = "Hola mundo";
    int n = -42;
    unsigned int u = 3000000000;
    void *ptr = str;

    ft_printf("=== Comparacion de ft_printf y printf ===\n\n");

    // %c
    ret1 = ft_printf("char: %c\n", c);
    ret2 = printf("char: %c\n", c);
    ft_printf("Retorno: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // %s
    ret1 = ft_printf("string: %s\n", str);
    ret2 = printf("string: %s\n", str);
    ft_printf("Retorno: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // %p
    ret1 = ft_printf("pointer: %p\n", ptr);
    ret2 = printf("pointer: %p\n", ptr);
    ft_printf("Retorno: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // %d
    ret1 = ft_printf("decimal: %d\n", n);
    ret2 = printf("decimal: %d\n", n);
    ft_printf("Retorno: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // %i
    ret1 = ft_printf("integer: %i\n", n);
    ret2 = printf("integer: %i\n", n);
    ft_printf("Retorno: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // %u
    ret1 = ft_printf("unsigned: %u\n", u);
    ret2 = printf("unsigned: %u\n", u);
    ft_printf("Retorno: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // %x
    ret1 = ft_printf("hex lower: %x\n", u);
    ret2 = printf("hex lower: %x\n", u);
    ft_printf("Retorno: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // %X
    ret1 = ft_printf("hex upper: %X\n", u);
    ret2 = printf("hex upper: %X\n", u);
    ft_printf("Retorno: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // %%
    ret1 = ft_printf("percent: %%\n");
    ret2 = printf("percent: %%\n");
    ft_printf("Retorno: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    return 0;
}

