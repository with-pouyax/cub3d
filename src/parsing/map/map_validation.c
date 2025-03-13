/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:29:21 by pghajard          #+#    #+#             */
/*   Updated: 2025/03/13 15:29:22 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int map_is_empty(char **map)
{
    int i;
    int j;

    i = 0;
    if (!map || !map[0])
        return (ft_perror("empty map", EINVAL), 1);
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != ' ' && map[i][j] != '\t')
                return (0);
            j++;
        }
        i++;
    }
    
    return (ft_perror("empty map", EINVAL), 1);
}

int is_last_line_empty(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
        i++;
    i--;
    j = 0;
    while (map[i][j])
    {
        if (map[i][j] != ' ' && map[i][j] != '\t')
            return (0);
        j++;
    }
    return (ft_perror("last line empty", EINVAL), 1);
}

void skip_empty_lines(char **map, int *index)
{
    int j;
    while (map[*index])
    {
        j = 0;
        while (map[*index][j])
        {
            if (map[*index][j] != ' ' && map[*index][j] != '\t')
                return;
            j++;
        }
        (*index)++;
    }
}

int no_xpm_extension(char *line)
{
    int len;
    int i;
    char *path;
    
    if (!line)
        return(ft_perror("Error", EINVAL), 1);
    i = 2; // we skip the NO, SO, WE, EA
    while (line[i] && (line[i] == ' ' || line[i] == '\t'))
        i++; // i will be the index of the first character of the path after the NO, SO, WE, EA
    path = line + i; // path will be the path of the texture
    if (!*path)
        return(ft_perror("Empty texture path", EINVAL), 1);
    len = ft_strlen(path); // len will be the length of the path(without the NO, SO, WE, EA)
    while (len > 0 && (path[len - 1] == ' ' || path[len - 1] == '\t'))
        len--; // we remove the spaces and tabs at the end of the path
    if (len < 5) // if the length of the path is less than 5, then the path is too short
        return(ft_perror("Texture path too short", EINVAL), 1); 
    if (len >= 4 && ft_strncmp(path + len - 4, ".xpm", 4) != 0) // if the length of the path is greater than or equal to 4 and the last 4 characters of the path are not ".xpm", then the path is not a valid texture path
        return(ft_perror("Texture file must have .xpm extension", EINVAL), 1);
    if (len > 4 && path[len - 5] == '/')
		return(ft_perror("Texture path must not contain a '/'", EINVAL), 1);
    return (0);
}

int is_direction(char *line, char *dir)
{
	if (line[0] == dir[0] && line[1] == dir[1] && 
		(line[2] == ' ' || line[2] == '\t'))
		return (1);
	return (0);
} 