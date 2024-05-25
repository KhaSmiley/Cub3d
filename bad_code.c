
void 	calculate_step_size(t_ray *ray)
{
	if (ray->ray_len.x < ray->ray_len.y)
		ray->ray_len.x += ray->distance_to_wall.x;
	else
		ray->ray_len.y += ray->distance_to_wall.y;
}
 // pos.y - ray_end.y ???
void	calculate_next_step(t_ray *ray)
{
	if (ray->ray_dir < 180)
	{
		// add flag for textures
		ray->next_step.y = ray->ray_end.y - (int)ray->ray_end.y;
	}
	else
	{
		// add flag for textures
		ray->next_step.y = ceil(ray->ray_end.y) - (int)ray->ray_end.y;
	}
	if (ray->ray_dir > 90 && ray->ray_dir < 270)
	{
		// add flag for textures
		ray->next_step.x = ray->ray_end.x - (int)ray->ray_end.x;
	}
	else
	{
		// add flag for textures
		ray->next_step.x = ceil(ray->ray_end.x) - ray->ray_end.x;
	}
	ray->ray_len.x = ray->next_step.x * ray->distance_to_wall.x;
	ray->ray_len.y = ray->next_step.y * ray->distance_to_wall.y;
}

void	calculate_collisions(t_data *data, t_ray *ray, t_player *player)
{
	int			i;
	t_moha2d	map; // i'm in this tile in the map

	i = 0;
	printf("player position y = %f, x = %f\n", player->pos.y, player->pos.x);
	map.x = (int)player->pos.x / TILE_SIZE;
	map.y = (int)player->pos.y / TILE_SIZE;
	printf("map y = %f, x = %f\n", map.y, map.x);
	while (1)
	{
		if (i == 0)
		{
			calculate_next_step(data->ray); // first step (offset to first edge), one time
			i++;
		}
		else
		{
			calculate_step_size(ray); // changes slightly every time due to angle
			map.y += ray->step_size.y; // CHECK THIS
			//ray->side_flag = 1;
		}
		printf(">>>>>>>>>>>>%c %i %i\n", data->map[(int)map.y][(int)map.x], (int)map.y, (int)map.x);
			// printf("next step x = %f\n", ray->next_step.x);
		// x axis is closer
		if (ray->ray_len.x < ray->ray_len.y)
		{
			// and x axis point is a wall
			if (data->map[(int)map.y][(int)map.x + (int)ray->next_step.x] == '1')
			{
				ray->draw_len += ray->ray_len.x;
				ray->ray_end.x = ray->ray_end.x + ray->ray_len.x * ray->next_step.x;
				ray->ray_end.y = ray->ray_end.y - ray->ray_len.x * ray->next_step.y;
			}
			map.x += ray->next_step.x;
			// ray->side_flag = 0;
		}
		else // y axis is closer
		{
			// and y axis point is a wall
			printf("map y = %d, x = %d\n", (int)map.y + (int)ray->next_step.y, (int)map.x);
			if (data->map[(int)map.y + (int)ray->next_step.y][(int)map.x] == '1')
			{
				ray->draw_len += ray->ray_len.y;
				ray->ray_end.x = ray->ray_end.x - ray->ray_len.y * ray->next_step.x;
				ray->ray_end.y = ray->ray_end.y + ray->ray_len.y * ray->next_step.y;
			}
			map.y += ray->next_step.y;
			// ray->side_flag = 1;
		}
		if (data->map[(int)map.y][(int)map.x] == '1') // / TILE_SIZE ?
		{
			// ray->ray_end.x = map.x; // suggested by copilot
			// ray->ray_end.y = map.y; // suggested by copilot
			break ;
		}
		ray->ray_len *= cos(deg_to_rad(ray->ray_dir - player->direction));
	}
}

