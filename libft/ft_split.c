/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:36:49 by yuendo            #+#    #+#             */
/*   Updated: 2023/06/13 12:17:30 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_word_count(char const *s, char c)
{
	size_t	count;
	size_t	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*my_strncpy(char *destination, const char *source, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num && source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	while (i < num)
	{
		destination[i] = '\0';
		i++;
	}
	return (destination);
}

static char	*my_make_word(char const *s, size_t len)
{
	char	*word;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	word[len] = '\0';
	my_strncpy(word, s, len);
	return (word);
}

static int	my_process_word(char const **s, char c, char **split, int i)
{
	size_t	len;

	len = 0;
	while ((*s)[len] != c && (*s)[len] != '\0')
		len++;
	split[i] = my_make_word(*s, len);
	if (split[i] == NULL)
	{
		while (i > 0)
			free(split[--i]);
		free(split);
		return (-1);
	}
	*s += len;
	return (i + 1);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**split;
	int		i;

	if (!s)
		return (NULL);
	words = my_word_count(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i = my_process_word(&s, c, split, i);
			if (i == -1)
				return (NULL);
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}

// #include <stdio.h>
// int main(void)
// {
//     char s[] = "h\0ello\0hello s ";
//     char sep = 'e';
//     char **a;
//     a = ft_split(s,sep);
// 	size_t i;
// 	i = 0;
//    while(a[i]){
// 	printf("%s\n", a[i]);
// 	i++;
//    }
//     return (0);
// }