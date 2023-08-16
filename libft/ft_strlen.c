/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:57:39 by yutoendo          #+#    #+#             */
/*   Updated: 2023/07/05 16:58:56 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

// #include <stdio.h>
// #include <string.h>

// void test_ft_strlen(const char *s, size_t expected)
// {
//     size_t len = ft_strlen(s);
//     if(len == expected)
//         printf("PASS: length of \"%s\" is %zu\n", s, len);
//     else
//         printf("FAIL: length of \"%s\" should be %zu but got %zu\n", s,
// 		expected, len);
// }

// int main()
// {
//     // Test with a normal string
//     test_ft_strlen("Hello, world!", 13);

//     // Test with an empty string
//     test_ft_strlen("", 0);

//     // Test with a string containing spaces
//     test_ft_strlen("OpenAI GPT-4", 11);

//     // Test with a NULL string
//     test_ft_strlen(NULL, 0);

//     // Test with a string of all spaces
//     test_ft_strlen("     ", 5);

//     // Test with a string with a single character
//     test_ft_strlen("a", 1);

//     return (0);
// }