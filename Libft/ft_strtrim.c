/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:09:26 by arnau             #+#    #+#             */
/*   Updated: 2025/09/01 12:09:26 by arnau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    size_t start;
    size_t end;
    char *res;

    if (!s1 || !set)
        return (0);
    end = ft_strlen(s1);
    start = 0;
    while (s1[start] && ft_strchr(set, s1[start]))
        start++;
    while (end > start && ft_strchr(set, s1[end - 1]))
        end--;
    res = malloc(end - start + 1); 
    if (!res)
        return (0);
    ft_strlcpy(res, &s1[start], end);
    return res;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *s1 = "1234a1234bcd4321";
    char *set = "1234";

    char *res = ft_strtrim(s1, set);
    if (res) {
        printf("Original: \"%s\"\n", s1);
        printf("Trimmed:  \"%s\"\n", res);
        free(res);  // siempre liberar la memoria de malloc
    } else {
        printf("Error en ft_strtrim\n");
    }

    // Otro ejemplo donde todo se elimina
    s1 = "12131234";
    res = ft_strtrim(s1, set);
    if (res) {
        printf("Original: \"%s\"\n", s1);
        printf("Trimmed:  \"%s\"\n", res);
        free(res);
    }

    // Ejemplo donde no hay caracteres que eliminar
    s1 = "abcd";
    set = "1234";
    res = ft_strtrim(s1, set);
    if (res) {
        printf("Original: \"%s\"\n", s1);
        printf("Trimmed:  \"%s\"\n", res);
        free(res);
    }

    return 0;
}