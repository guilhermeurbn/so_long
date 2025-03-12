/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:44:46 by guilhermeur       #+#    #+#             */
/*   Updated: 2024/11/14 14:50:00 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//me indica a posicao do caractere "x" no intervalo de 0 ate N;
// me retornando a posicao me bytes;

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cc;
	size_t			i;

	str = (unsigned char *)s;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == cc)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
/*int main()
{
	char str[50] = "Hello, World!";
	printf("%s\n", (char *)ft_memchr(str, 'W', 8));
	return 0;
}*/
