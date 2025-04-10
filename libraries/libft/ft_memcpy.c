/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:40:29 by guilhermeur       #+#    #+#             */
/*   Updated: 2024/11/18 11:46:42 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//unsigned char pq mexemos com bytes por bytes, logo convertemos
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (dest);
	i = 0;
	if (n == 0)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*int main()
{
	char src[50] = "Hello, World!";
	char dest[50] = "Goodbye, World!";

	printf("%s", (char *)ft_memcpy(dest, src, 5));
	return 0;
}*/
