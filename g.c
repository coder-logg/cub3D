#include "cub3d.h"

void clearBuff(t_vars *vars)
{
	for(int y = 0; y < (int) vars->display.y; y++)
		for(int x = 0; x < (int)vars->display.x; x++)
			vars->buff[y][x] = 0;
}

void main_(t_vars *vars)
{
	clearBuff(vars);

	double posX = vars->pozition.x;
	double posY = vars->pozition.y;
	double dirX = vars->dir.x, dirY = vars->dir.y; //initial direction vector
	double planeX = vars->plane.x, planeY = vars->plane.y; //the 2d raycaster version of camera plane
	int a;
	int b;
	int c_;
	for(int x = 0; x < (int)vars->display.x; x++)
	{
			//calculate ray position and direction
			double cameraX = 2 * x / (double)vars->display.x - 1; //x-coordinate in camera space
			double rayDirX = dirX + planeX*cameraX;
			double rayDirY = dirY + planeY*cameraX;

			//which box of the map we're in
			int mapX = (int)(posX);
			int mapY = (int)(posY);

			//length of ray from current position to next x or y-side
			double sideDistX;
			double sideDistY;

			//length of ray from one x or y-side to next x or y-side
			double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
			double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
			double perpWallDist;

			//what direction to step in x or y-direction (either +1 or -1)
			int stepX;
			int stepY;

			int hit = 0; //was there a wall hit?
			int side; //was a NS or a EW wall hit?

			//calculate step and initial sideDist
			if(rayDirX < 0)
			{
				b=0;
				a=0;
				c_=0;
				stepX = -1;
				sideDistX = (posX - mapX) * deltaDistX;
			}
			else
			{
				b=0;
				a=0;
				c_=1;
				stepX = 1;
				sideDistX = (mapX + 1.0 - posX) * deltaDistX;
			}

			if(rayDirY < 0)
			{
				b=0;
				a=3;

				stepY = -1;
				sideDistY = (posY - mapY) * deltaDistY;
			}
			else
			{
				b=2;
				a=0;

				stepY = 1;
				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
			}
			//perform DDA
			while (hit == 0)
			{
				//jump to next map square, either in x-direction, or in y-direction
				if(sideDistX < sideDistY)
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
				if(vars->worldMap[mapX][mapY] > 0) hit = 1;
			}

			//Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
			if(side == 0) perpWallDist = (sideDistX - deltaDistX);
			else          perpWallDist = (sideDistY - deltaDistY);

			//Calculate height of line to draw on screen
			int lineHeight = (int)(vars->display.y / perpWallDist);


			int pitch = 100;

			//calculate lowest and highest pixel to fill in current stripe
			int drawStart = -lineHeight / 2 + vars->display.y / 2 + pitch;
			if(drawStart < 0) drawStart = 0;
			int drawEnd = lineHeight / 2 + vars->display.y / 2 + pitch;
			if(drawEnd >= (int)vars->display.y) drawEnd = vars->display.y - 1;

			//texturing calculations
			///!!int texNum = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!

			//calculate value of wallX
			double wallX; //where exactly the wall was hit
			if(side == 0) wallX = posY + perpWallDist * rayDirY;
			else          wallX = posX + perpWallDist * rayDirX;
			wallX -= floor((wallX));

			//x coordinate on the texture
			int texX = (int)(wallX * (double)(vars->texWidth));
			if(side == 0 && rayDirX > 0) texX = vars->texWidth - texX - 1;
			if(side == 1 && rayDirY < 0) texX = vars->texWidth - texX - 1;

			// TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
			// How much to increase the texture coordinate per screen pixel
			double step = 1.0 * vars->texHeight / lineHeight;
			// Starting texture coordinate
			double texPos = (drawStart - pitch - vars->display.y / 2 + lineHeight / 2) * step;
			for(int y = drawStart; y < drawEnd; y++)
			{
				// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
				int texY = (int)texPos & (vars->texHeight - 1);
				texPos += step;
				Uint32 color = vars->texs[side*(b+a)+(!side)*c_][vars->texHeight * texY + texX];
				//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
				//if(side == 1) color = (color >> 1) & 8355711;
				if (!color)
					color=1;
				vars->buff[y][x] = color;
			}
		}
	int i=0;
	int j;

	while(i < vars->display.y)
	{
		j=0;
		while(j < vars->display.x)
		{
			t_point2D p;
			p.a = j;
			p.b =i;
			p.color = vars->buff[i][j];
			if (!p.color)
			{
				if (i < vars->gorizont)
					p.color=vars->Ceilling_color;
				else
					p.color=vars->Floor_color;
			}
			geom_pixel_put(vars->img, p);
			j++;
		}
		i++;
	}
}
