#include <fcntl.h>      
#include <stdio.h>     
#include "get_next_line.h"

int main(void)
{
   int fd;
   char *line;

			fd = open("archivo.txt", O_RDONLY);
			if (fd == -1)
			{
							perror("Error al abrir el archivo");
							return (1);
			}

			while ((line = get_next_line(fd)) != NULL)
			{
				printf("LINEA: %s", line);
				free(line);
			}
			printf("\nFIN DEL WHILE\n");

			close(fd);
			return (0);
}