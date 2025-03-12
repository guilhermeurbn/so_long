/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:59:55 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/18 11:51:10 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/* static void upper(unsigned int i, char *c)
{//coloca o i para ser "usado"
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}
int main()
{
	char str[] = "hello";

	ft_striteri(str, upper);
	printf("%s", str);
	return (0);
} */
