/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:45:43 by yuendo            #+#    #+#             */
/*   Updated: 2023/06/30 16:59:37 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	va_list	args_copy;
	int		str_length;
	char	*str_copy;

	str_copy = (char *)str;
	if (!str)
		return (0);
	va_start(args, str);
	va_copy(args_copy, args);
	str_length = is_valid_args(str_copy, args);
	va_end(args);
	if (!str_length)
		return (0);
	return (str_length);
}

// #include <stdio.h>
// #include <limits.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

// int main(void){
//     size_t count = 100;
//     int a = INT_MAX;
//     unsigned int b = INT_MIN;
//     int c = -9999;
//     char d = 20;
//     char *s = NULL;
//     char *s2 = "Hello_World!";
//     int e = -10;
//     int my_length, original_length;

//     while(count--){
//         my_length = ft_printf("\\%%%dd%i %x%X%u %c %s%s%p%p%x\n", a, b, c, c,
// c, d, s, s2, s2, s2-count, e);
//         original_length = printf("\\%%%dd%i %x%X%u %c %s%s%p%p%x\n", a, b, c,
// c, c, d, s, s2, s2, s2-count, e);
//         ft_printf("my length is %d original length is %d\n", my_length,
// original_length);
//         a++;b++;c++;d++;e++;
//     }

// 	int i = -5;
// 	while(i < 30){
// 		int a = ft_printf("%c", i);
// 		int b = printf("%c", i);
// 		printf("\nascii: %d my--%d ori--%d\n", i , a, b);
// 		i++;
// 	}

//     return (0);
// }