/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:03:03 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/03 23:06:16 by kboulkri         ###   ########.fr       */
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
	// double pl_dir_y = 0; // replace with pl direction
	// double pl_dir_x = -1; // ?
	// double planeX = 0;
	// double planeY = 0.66;
	// if (data->player_dir == 'W')
	// {
	// 	// pl_dir_y = 0;
	// 	// pl_dir_x = 1;
	// 	planeY = -0.66;
	// }
	// double posX = 12; // replace with player pos
	double posX = data->player->posX;
	// double posY = 5;
	double posY = data->player->posY; // replace with player pos
	while (x < S_W)
	{
		double cameraX = 2 * x / (double)S_W - 1;
		double rayDirX = data->player->dirX + data->player->planeX * cameraX;
		double rayDirY = data->player->dirY + data->player->planeY * cameraX;
		// printf("rayDirX = %f\n", rayDirX);
		// printf("rayDirY = %f\n", rayDirY);
//
		int mapX = (int)posX;
		int mapY = (int)posY;

		// collisions avec murs ou pas - distances entre les intersections
		
		//length of ray from current position to next x or y-side (le reste du carré)
		double sideDistX;
		double sideDistY;

		 //length of ray from one x or y-side to next x or y-side 
		 // on est pas dans ces carrés la (un cote du triangle tjrs fixe a 1)
		double deltaDistX = fabs(1 / rayDirX); // fabs puts negative floats to positive
		double deltaDistY = fabs(1 / rayDirY);
		
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 [right or down] or -1 [left or up])
		int stepX; // que des flags
		int stepY; // on va pas check tous les murs, on va juste check les murs qui sont sur le chemin du rayon

		int hit = 0; //was there a wall hit?
		char texture; //which wall hit? for textures

		if (rayDirX < 0)
		{
			stepX = -1; // going left
			sideDistX = (posX - mapX) * deltaDistX; 
		}
		else
		{
			stepX = 1; // going right
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1; // going up
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1; // going down
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		
		 // juste un truc pour avancer de sidedistx ou y selon quelle
		 // intersection et le plus proche, et on regarde si on a un 1 dans cette case
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				if (stepX == -1)
					texture = 'W';
				else
					texture = 'E';
				
				if (mapX + 1 < data->w_map)
					mapX += stepX;
				else
				{
					hit = 1;
					break;
				}

			}
			else
			{
				sideDistY += deltaDistY;
				if (stepY == -1)
					texture = 'N';
				else
					texture = 'S';
				if (mapY + 1 < data->nb_line)
					mapY += stepY;
				else
				{
					hit = 1;
					break;
				}
			}
			//Check if ray has hit a wall
			printf("mapX = %d\n", mapX);
			printf("mapY = %d\n", mapY);
			if (data->map[mapY][mapX] == '1')
			{
				hit = 1;
			}
		}
		// calculate distance to closest wall
		if (texture == 'W' || texture == 'E')
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(S_H / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + S_H / 2;
		if(drawStart < 0)
			drawStart = 0;
		// printf("drawStart = %d\n", drawStart);
		int drawEnd = lineHeight / 2 + S_H / 2;
		if(drawEnd >= S_H)
			drawEnd = S_H - 1;
		// printf("drawEnd = %d\n", drawEnd);

		// replace with wall textures
		int	color;
		if (data->map[mapY][mapX] == '1')
		{
			if (texture == 'N')
				color = 0x00FF00;
			else if (texture == 'S')
				color = 0x0000FF;
			else if (texture == 'W')
				color = 0xFF0000;
			else
				color = 0xFFFF00;
		}
		else
			color = 0x00FFFF;

		put_line(data, x, drawStart, drawEnd, color);
		put_line(data, x, 0, drawStart, 0x123AAA);
		put_line(data, x, drawEnd, S_H, 0x432411);

		x++;
	}
	return (0);
}
