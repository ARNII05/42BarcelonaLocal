#include <stdio.h>
#include <unistd.h>

void ft_putnbr(int n)
{
    char c;

    if (n < 0)
    {
        write(1, "-", 1);

        if (n == -2147483648)
        {
            ft_putnbr(-(n / 10));
            c = '0' + -(n % 10);
            write(1, &c, 1);
            return;
        }

        n = -n;
    }

    if (n >= 10)
        ft_putnbr(n / 10);
    c = n % 10 + '0';
    write(1, &c, 1);
}


void ft_foreach(int *tab, int length, void (*f)(int))
{
    int i = 0;
    while (i < length)
    {
        f(tab[i]);
        i++;
    }
}

int main(void)
{
    int tab [] = {1,2,3};
    ft_foreach(tab, 3, &ft_putnbr);
    return (0);
}