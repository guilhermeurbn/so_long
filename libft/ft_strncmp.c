/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:37:30 by guilhermeur       #+#    #+#             */
/*   Updated: 2024/11/14 14:50:35 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char )s1[i] - (unsigned char )s2[i]));
		i++;
	}
	return (0);
}
/*int main()
{
    char str1[50] = "Hello, World!";
    char str2[50] = "Hello, World!";
    printf("%d\n", ft_strncmp(str1, str2, 5));
    return 0;
}*/
