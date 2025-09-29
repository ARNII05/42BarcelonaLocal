/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                          :+:      :+:    :+:      */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:38:26 by arnau             #+#    #+#             */
/*   Updated: 2025/09/25 10:38:26 by arnau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    int fd;
    int ret;
    char buffer[BUFFER_SIZE];

    if (argc < 2)
    {
        write(2, "File name missing\n", 18);
        return 1;
    }
    if (argc > 2)
    {
        write(2, "Too many arguments\n", 19);
        return 1;
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        write(2, "Cannot read file\n", 16);
        return 1;
    }
    while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
        write(1, buffer, ret);

    close(fd);
    return (0);
}
