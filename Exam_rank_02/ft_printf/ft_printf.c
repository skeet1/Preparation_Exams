/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 11:59:52 by mkarim            #+#    #+#             */
/*   Updated: 2021/12/29 12:02:19 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void    ft_putchar(char c, int *count)
{
    write(1, &c, 1);
    (*count)++;
}
void    ft_putnbr(int n, int *count)
{
    long nb;
    
    nb = n;
    if (nb < 0)
    {
        ft_putchar('-', count);
        nb *= -1;
    }
    if (nb > 9)
    {
        ft_putnbr(nb / 10, count);
        ft_putnbr(nb % 10, count);
    }
    else
        ft_putchar(nb + 48, count);
}
void    ft_putstr(char *s, int *count)
{
    int i;

    i = 0;
    while (s[i])
    {
        ft_putchar(s[i], count);
        i++;
    }
}
void    ft_printx(unsigned long nb, int *count)
{
    char    s[] = "0123456789abcdef";
    if (nb < 0)
        nb *= -1;
    if (nb > 15)
    {
        ft_printx(nb / 16, count);
        ft_printx(nb % 16, count);
    }
    else
        ft_putchar(s[nb], count);
}

int ft_printf(const char *s, ...)
{
    va_list p;
    int     i;
    int     count;
    
    va_start(p, s);
    i = 0;
    count = 0;
    while (s[i])
    {
        if (s[i] == '%')
        {
            i++;
            if (s[i] == 'd')
                ft_putnbr(va_arg(p, int), &count);
            else if (s[i] == 's')
                ft_putstr(va_arg(p, char *), &count);
            else if (s[i] == 'x')
                ft_printx(va_arg(p, unsigned int), &count);
        }
        else
            ft_putchar(s[i], &count);
        i++;
    }
    return (count);
}

int main()
{
    ft_printf("%x\n", -2147483647);
    printf("%x\n", -2147483647);
    //printf("%d\n", ft_printf("hello"));
}