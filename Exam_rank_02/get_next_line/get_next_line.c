/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 12:03:32 by mkarim            #+#    #+#             */
/*   Updated: 2021/12/30 10:57:59 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char    *ft_strdup(char *s)
{
    int i;
    char    *str;
    
    i = 0;
    str = (char *)malloc(ft_strlen(s) + 1);
    if (!str)
        return (NULL);
    while (s[i])
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char    *get_next_line(int fd)
{
    char    buf[1];
    char    line[1000000];
    int r;
    int i;

    buf[0] = 0;
    i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while ((r = read(fd, buf, 1)) && r > 0)
    {
        line[i++] = buf[0];
        line[i] = '\0';
        if (buf[0] == '\n')
            return (ft_strdup(line));
    }
    if (buf[0] == '\0')
        return (NULL);
    return (ft_strdup(line));
}