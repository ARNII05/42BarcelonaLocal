#include "ft_printf.h"   
#include "Libft/libft.h" 

int main(void)
{
    char letra = '%';
    char *nombre = "Arnau";

    // Probar %c
    ft_printf("Letra: %c\n", letra);

    // Probar %s
    ft_printf("Hola, %s!\n", nombre);

    // Mezcla de texto y formatos
    ft_printf("Hola %s, tu inicial es %%.\n", nombre, letra);

    // Texto sin formato
    ft_printf("Esto es solo texto normal.\n");

    return 0;
}
