/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:09:30 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/09/14 16:34:31 by lgomez-g         ###   ########.fr       */
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
		return (1);
	return (0);
}

t_game	*infos(void)
{
	static t_game b;

	return (&b);
}

int verify_map_components(char **map)
{
    int start_count = 0;
    int exit_count = 0;
    int collectible_count = 0;

    int y = 0;
    while (map[y])
    {
        int x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'P')
                start_count++;
            else if (map[y][x] == 'E')
                exit_count++;
            else if (map[y][x] == 'C')
                collectible_count++;

            x++;
        }
        y++;
    }
	if (start_count != 1 || exit_count != 1 || collectible_count < 1)
    {
        fprintf(stderr, "Error: Invalid map components\n");
        return 0;
    }
    return (1);
}

char	**read_map(const char *filename)
{
	int		fd; 
	char	*line; // Línea leída del archivo
	char	**map; // Matriz para almacenar el mapa
	int		rows; // Número de filas en el mapa
	int		i; // Índice para recorrer la matriz


	if (!is_ber_file(filename))	//verifica el .ber
		return (NULL);

	fd = open(filename, O_RDONLY);
	if (fd == -1) // Verifica si hubo un error al abrir el archivo
		return (NULL); 

	rows = 0;
	while (get_next_line(fd)) // Lee cada línea del archivo usando get_next_line
		rows++;
	close(fd); 

	// Asigna memoria para la matriz de map
	map = (char **)malloc((rows + 1) * sizeof(char *));
	if (!map) 
		return (NULL); 

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
	if (!verify_map_components(map)) // verifica los duplicados
    {
        free(map); // Liberar memoria asignada
        return NULL; // Devuelve NULL en caso de error
    }
	
    if (!is_map_rectangular(map, rows))
    {
        fprintf(stderr, "Error: Map is not rectangular");
        free_map(map, rows); // Liberar memoria asignada a las filas
        return NULL;
    }
	if (!valid_walls(map, rows))
	{
		fprintf(stderr, "Error: Map doesn't have valid Walls");
        free_map(map, rows); // Liberar memoria asignada a las filas
        return NULL;
	}

	infos()->height = rows;
	infos()->width = strlen(map[0]) - 1;

	return (map); // Devuelve la matriz con el mapa cargado desde el archivo
}
