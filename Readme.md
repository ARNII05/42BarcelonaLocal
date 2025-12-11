# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Readme.md                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abellavi <abellavi@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 10:47:33 by abellavi          #+#    #+#              #
#    Updated: 2025/12/11 10:48:30 by abellavi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SPANISH VERSION:

𝔈𝔰𝔱𝔢 𝔭𝔯𝔬𝔶𝔢𝔠𝔱𝔬 𝔥𝔞 𝔰𝔦𝔡𝔬 𝔠𝔯𝔢𝔞𝔡𝔬 𝔠𝔬𝔪𝔬 𝔭𝔞𝔯𝔱𝔢 𝔡𝔢𝔩 𝔠𝔲𝔯𝔯𝔦𝔠𝔲𝔩𝔬 𝔡𝔢 42 𝔭𝔬𝔯 𝔞𝔟𝔢𝔩𝔩𝔞𝔳𝔦

DESCRIPCION

Este proyecto se llama GetNextLine. 

Trata de una funcion que se puede llamar multiples veces para poder imprimir de un fd(file descriptor).

Cada vez que se llama a esta funcion imprimira hasta que encuentre un salto de linea.

En caso de que no haya salto de linea (por ejemplo: un archivo) se imprimira todo el archivo.

Si hay algun error devolvera NULL.

INSTRUCCIONES:

Este proyecto SE DEBE PODER EJECUTAR!! con y sin unas flags especificas.

Esta es: cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c

El valor de buffer size es un ejemplo, se podria utilizar casi cualquier numero (mientras no pete el pc xd)

Mi valor default es: BUFFER_SIZE=32 (se puede ver en el .h)

Si fd ha cambiado desde la ultima vez que se llamo o el archivo esta en binario, se considera undefined behaviour

RECURSOS

1. Repositorios GIT para hacerme una idea de como la gente lo hizo y darme ideas.
2. He usado ChatGPT para saber como implementar correctamente el uso de Free(), ya que vengo de otros   lenguajes y no tenia ni idea de como se usaba

ENGLISH VERSION:

𝔗𝔥𝔦𝔰 𝔭𝔯𝔬𝔧𝔢𝔠𝔱 𝔴𝔞𝔰 𝔠𝔯𝔢𝔞𝔱𝔢𝔡 𝔞𝔰 𝔭𝔞𝔯𝔱 𝔬𝔣 𝔱𝔥𝔢 42 𝔠𝔲𝔯𝔯𝔦𝔠𝔲𝔩𝔲𝔪 𝔟𝔶 𝔞𝔟𝔢𝔩𝔩𝔞𝔳𝔦

DESCRIPTION

This project is called GetNextLine.

It’s about a function that can be called multiple times to read from an fd (file descriptor).

Each time the function is called, it will read until it finds a newline character.

If there is no newline (for example, when reading a full file), it will return the entire content.

If there is any error, it will return NULL.

INSTRUCTIONS:

This project MUST BE ABLE TO RUN!! both with and without specific flags.

The flags are:
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <files>.c

The buffer size value above is just an example; you can use almost any number (as long as your PC doesn’t explode lol).

My default value is: BUFFER_SIZE=32 (you can see it in the .h file).

If the fd has changed since the last call or the file is binary, it is considered undefined behaviour.

RESOURCES

1. Git repositories to get an idea of how other people implemented it and to gather ideas.

2. I used ChatGPT to understand how to correctly implement the use of free(), since I come from other languages and had no idea how it was used.
