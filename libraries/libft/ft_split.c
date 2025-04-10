/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:37:56 by guilhermeur       #+#    #+#             */
/*   Updated: 2025/01/21 13:53:26 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	conta_c(const char *palavra, char letra)
{
	int	i;
	int	count;
	int	in_word;

	in_word = 0;
	count = 0;
	i = 0;
	while (palavra[i])
	{
		if (palavra[i] != letra)
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (count);
}

static void	ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	if (!count)
		return ;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	*strs = NULL;
}

static int	copy_split(char const *s, char c, char **dest)
{
	int	i;
	int	j;
	int	t;

	t = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			dest[t] = ft_substr(s, j, i - j);
			if (!dest[t])
				return (ft_free(dest, t), 0);
			t++;
		}
	}
	dest[t] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		word_conta;

	if (!s)
		return (NULL);
	word_conta = conta_c(s, c);
	dest = malloc((word_conta + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	if (!copy_split(s, c, dest))
		return (ft_free(dest, word_conta), NULL);
	return (dest);
}
/* int	main(void)
{
	char	*s;
	int		i;
	char	**result;

	s = "13 14 12 17";
	i = 0;
	result = ft_split(s, 32);
	while (result[i])
	{
		printf("%s\n", (result[i]));
		free(result[i]);
		i++;
	}
	printf("%s\n", (result[i]));
	free(result);
	return (0);
}*/
