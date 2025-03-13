/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:27:25 by pghajard          #+#    #+#             */
/*   Updated: 2025/03/13 15:39:50 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_file	*map;

	if (init_map(&map))
		return (1);
	if (parse_args(ac, av, &map))
	{
		cleanup(&map);
		return (1);
	}
	printf("\nwe are good to go\n");
	cleanup(&map);
	return (0);
}
