#include "libft.h"

int len_itoa(int n)
{
    int len;
    long nb;  

    len = 0;
    nb = n;    
    if (nb == 0)
        return (1);
    if (nb < 0)
    {
        len++;
        nb = -nb;
    }
    while (nb > 0)
    {
        nb = nb / 10;
        len++;
    }
    return (len);
}

void ft_nbplus(char *result, long nb, int len)
{
    while (nb > 0)
    {
        len--;
        result[len] = (nb % 10) + '0';
        nb = nb / 10;
    }
}

char    *ft_itoa(int n)
{
    char *result;
    int len;
    long nb;  

    nb = n;  
    len = len_itoa(n);
    result = malloc(sizeof(char) * (len + 1));
    if (!result)
        return (NULL);
    result[len] = '\0';
    if (nb == 0)
    {
        result[0] = '0';
        return (result);
    }
    if (nb < 0)
    {
        result[0] = '-';
        nb = -nb;
    }
    ft_nbplus(result , nb , len);
    return (result);
}