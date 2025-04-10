/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:02:47 by guilhermeur       #+#    #+#             */
/*   Updated: 2024/11/13 11:26:36 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//completa a memoria com a constante C.
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
/*int main()
{
	char str[31];
	printf("%s", (char *)ft_memset(str, 'a', 30));
	return 0;
}*/
