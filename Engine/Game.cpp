/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <cstdio>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	X0( 50 ),
	Y0( 50),
	vertical(false)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}

void Game::ComposeFrame()

{
	/* pasa la linea de barrido vertical  y luego la horizontal alternativamente */
	if (vertical)
	{
		for (int i = 0; i < 72 * 6 + 1; i++)
			for (int j = 0; j < 70 * 6 + 1; j++)
				gfx.PutPixel(X0 + i, Y0 + j, 230, 230, 0);
	}
	else
	{
		for (int j = 0; j < 70 * 6 + 1; j++)
			for (int i = 0; i < 72 * 6 + 1; i++)
				gfx.PutPixel(X0 + i, Y0 + j, 230, 230, 0);
		vertical = !vertical;
	}

	int ancho = 6;
	// cuentah = 0;
	//int cuentav = 0;
	
	/* traza las lineas verticales de la rejilla de 70 filas */
	for (int i = 0; i < 72 * ancho + 1; i++)
		if (i % ancho == 0)
		{ 
			//cuentav++;
			for (int j = 0; j < 70 * ancho + 1; j++)
				gfx.PutPixel(X0 + i, Y0 + j, 0, 60, 0);
		}
	
	/* traza las lineas horizontales de la rejilla de 72 columnas */
	for (int j = 0; j < 70 * ancho + 1; j++)
		if (j % ancho == 0)
		{ 
			//cuentah++;
			for (int i = 0; i < 72 * ancho + 1; i++)
				gfx.PutPixel(X0 + i, Y0 + j, 0, 60, 0);
		}
	
	/* presenta los valores «activos» */
	for (int k = 0; k < 5040; k++)
	{
		int fila = k / 72;
		int columna = k % 72;
		if (k % 29 < 7)
		{
			int posx = 1 + columna * 6;
			int posy = 1 + fila * 6;
			for (int m = 0; m < 5; m++)
				for (int n = 0; n < 5; n++)
				{
					int red = (abs((m - 2) * (n - 2)) == 4) ? 10: 150;
					int green = (abs((m - 2) * (n - 2)) == 2) ? 0 : 40;
					int blue = (abs((m - 2) * (n - 2)) < 1) ? 200 : 0;
					gfx.PutPixel(X0 + posx + m, Y0 + posy + n, red, green, blue);
				}
		}
	}
	

	//cuentav;
	//cuentah;
}
