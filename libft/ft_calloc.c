/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:15:32 by guilhermeur       #+#    #+#             */
/*   Updated: 2024/11/14 14:48:16 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*ptr;

	if (element_size != 0 && num_elements > (size_t)-1 / element_size)
		return (NULL);
	ptr = malloc(num_elements * element_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, num_elements * element_size);
	return (ptr);
}
/* int main()
{
	char *str = ft_calloc(1000, 100000);
	printf("%p", str);
	return 0;
} */
