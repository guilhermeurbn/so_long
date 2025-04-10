/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:56:51 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/14 14:50:32 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//aplica uma funcao 'f' a cada caractere da da string
//resultando numa nova string modificada.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*dest;

	if (!s || !(f))
		return (NULL);
	i = ft_strlen(s);
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
char	upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
char	lower(unsigned int i, char c)
{
	(void)i;
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
int	main(void)
{
	char *a = "HELLO";
	char *result;
	char *resulta;

	result = ft_strmapi(a, upper);
	resulta = ft_strmapi(a, lower);
	printf("%s\n", result);
	printf("%s", resulta);
	return (0);
} */
