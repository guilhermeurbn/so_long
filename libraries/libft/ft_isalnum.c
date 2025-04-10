/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:42:59 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/14 14:49:43 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//verifica se é um numero ou uma letra do alfabeto
int	ft_isalnum(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/*int main()
{
	printf("%d", ft_isalnum('!'));
	return (0);
}*/
