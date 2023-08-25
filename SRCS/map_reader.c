/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:09:30 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/08/25 17:15:02 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map.h"
#include "libft/libft.h"
#include "../get_next_line.h"
#include "../graphic_management.h"


int is_ber_file(const char *filename)
{
	const char *dot;

	dot = ft_strrchr(filename, '.');
	if (dot && ft_strncmp(dot, ".ber", 4) == 0)
		return (1); // si es .ber
	return (0); // si no es .ber
}


t_game	*infos(void)
{
	static t_game b;
	
	return(&b);
}

char	**read_map(const char *filename)
{
	int		fd; 
	char	*line; // Línea leída del archivo
	char	**map; // Matriz para almacenar el mapa
	int		rows; // Número de filas en el mapa
	int		i; // Índice para recorrer la matriz

	if (!is_ber_file(filename))
		return (NULL);

	fd = open(filename, O_RDONLY);
	if (fd == -1) // Verifica si hubo un error al abrir el archivo
		return (NULL); // Devuelve NULL si no se pudo abrir el archivo

	rows = 0;
	while (get_next_line(fd)) // Lee cada línea del archivo usando get_next_line
		rows++;
	close(fd); // Cierra el archivo

	// Asigna memoria para la matriz de map
	map = (char **)malloc((rows + 1) * sizeof(char *));
	if (!map) 
		return (NULL); // Devuelve NULL si no se pudo asignar memoria

	// Abre nuevamente el archivo para leer el mapa
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(map); // Libera la memoria asignada si hubo un error
		return (NULL);
	}

	i = 0;
	while ((line = get_next_line(fd))) // Lee cada línea del archivo nuevamente
	{
		map[i] = line; // Almacena la línea en la matriz
		i++;
	}
	map[i] = NULL; // Agrega un marcador de final de matriz
	close(fd);

	infos()->height = 0;
	infos()->height = rows;
	infos()->width = strlen(map[0]) - 1;
	printf("map height: %d", infos()->height);
	printf("map width: %d", infos()->width);

	return (map); // Devuelve la matriz con el mapa cargado desde el archivo
}