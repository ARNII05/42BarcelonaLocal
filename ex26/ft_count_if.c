#include <stdio.h>

int strString(char ** tab)
{
    int i;

    i = 0;
    while (tab[i] != 0)
        i++;
    return (i);
}

int letterCount(char *tab)
{
    int i;

    i = 0;
    while (tab[i] != 0)
        i++;
    return (i);
}

int hasFourLetters(char *tab)
{
    if (letterCount(tab) >= 4)
        return (1);
    return (0);
}

int ft_count_if(char **tab, int (*f)(char*))
{
    int length;
    int i;
    int count;

    length = strString(tab);
    i = 0;
    count = 0;
    while(i < length)
    {
        if (f(tab[i]) == 1)
            count++;    
        i++;
    }
    return (count);
}

int main(void)
{
    char *tab[] = {"hola", "mundo", "te", 0};
    printf("%d", ft_count_if(tab, &hasFourLetters));
    return (0);
}
