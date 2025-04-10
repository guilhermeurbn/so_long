/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:19:24 by guilhermeur       #+#    #+#             */
/*   Updated: 2024/11/06 12:18:30 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
/*int main()
{
    char b[] = "hello";
    char a[6];  // Declarado com 6 para ter certeza de que há espaço para o nulo
    printf("%zu\n", ft_strlcpy(a, b, 5)); // Retorna o comprimento de b
    printf("%s\n", a);
    return (0);
}*/
