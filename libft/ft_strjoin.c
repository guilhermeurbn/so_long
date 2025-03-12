/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:59:38 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/14 14:50:24 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//concatenar tudo na s3
char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	*s3;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = ft_calloc((len1 + len2 + 1), sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		s3[i++] = s1[j++];
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}
/* #include <stdio.h>
int	main(void)
{
	char s1[] = "ola ";
	char s2[] = "hello";

	printf("%s", ft_strjoin(s1, s2));
	return (0);
} */
