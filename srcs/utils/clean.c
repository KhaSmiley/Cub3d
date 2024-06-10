/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:44:54 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/10 18:08:57 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_destroy(t_data *data)
{
	if (data->textures->img)
		mlx_destroy_image(data->mlx->mlx_ptr, data->textures->img);
	if (data->mlx->screen_buffer)
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->screen_ptr);
	if (data->mlx->mlx_win)
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->mlx_win);
	if (data->mlx->mlx_ptr)
	{
		mlx_destroy_display(data->mlx->mlx_ptr);
		free(data->mlx->mlx_ptr);
	}
	free_tab(data->map);
	free_tab(data->texture);
	exit(0);
	return (0);
}
