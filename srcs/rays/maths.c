/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:03:03 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/25 17:31:40 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// degrees to radians calculator
float	deg_to_rad(int deg)
{
	float	rad;

	rad = deg * (M_PI / 180);
	return (rad);
}

// radians to degrees calculator
int	rad_to_deg(float rad)
{
	int	deg;

	deg = rad * (180 / M_PI);
	return (deg);
}

// float	nor_angle(float angle)	// normalize the angle
// {
// 	if (angle < 0)
// 		angle += (2 * M_PI);
// 	if (angle > (2 * M_PI))
// 		angle -= (2 * M_PI);
// 	return (angle);
// }

int	calculations(t_data *data)
{
	int	x;

	x = 0;
	double pl_dir_y = 0; // replace with pl direction
	double pl_dir_x = -1; // ?
	double planeX = 0;
	double planeY = 0.66;
	double posX = 12; // replace with player pos
	double posY = 5; // replace with player pos
	while (x < S_W)
	{
		double cameraX = 2 * x / (double)S_W - 1;
		double rayDirX = pl_dir_x + planeX * cameraX;
		double rayDirY = pl_dir_y + planeY * cameraX;
		printf("rayDirX = %f\n", rayDirX);
		printf("rayDirY = %f\n", rayDirY);

		int mapX = (int)posX;
		int mapY = (int)posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		 //length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (data->map[mapX][mapY] == '1')
			{
				hit = 1;
			}
		}
		if (side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(S_H / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + S_H / 2;
		if(drawStart < 0)
			drawStart = 0;
		printf("drawStart = %d\n", drawStart);
		int drawEnd = lineHeight / 2 + S_H / 2;
		if(drawEnd >= S_H)
			drawEnd = S_H - 1;
		printf("drawEnd = %d\n", drawEnd);

		int	color;
		if (data->map[mapY][mapX] == '1')
			color = 0xFF0000;
		else
			color = 0xFFFF00;

		if (side == 1)
			color = color / 2;

		put_line(data, x, drawStart, drawEnd, color);

		x++;
	}
	return (0);
}
