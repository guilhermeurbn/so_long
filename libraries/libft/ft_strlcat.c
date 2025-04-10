/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:03:31 by guilhermeur       #+#    #+#             */
/*   Updated: 2024/11/18 11:55:02 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (destsize == 0)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (dest_len >= destsize)
		return (src_len + destsize);
	i = 0;
	while (src[i] && (dest_len + i) < (destsize - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*int main()
{
	char a[50] = "hello ";
	char b[50] = "world";

	printf("o tamanho das duas ficam: %zu bytes", ft_strlcat(a, b, 4));
	return (0);
}*/
