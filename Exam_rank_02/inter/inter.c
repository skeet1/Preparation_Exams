/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:40:02 by mkarim            #+#    #+#             */
/*   Updated: 2021/12/27 18:51:01 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check1(char *s, char c, int i)
{
	while (--i >= 0)
		if (s[i] == c)
			return (0);
	return (1);
}

int ft_check2(char *s, char c)
{
	int	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (ft_check1(argv[1], argv[1][i], i) == 1)
				if (ft_check2(argv[2], argv[1][i]) == 1)
					write(1, &argv[1][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}
