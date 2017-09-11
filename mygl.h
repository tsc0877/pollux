#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include "math.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************


void PutPixel(int x, int y, int color){ // ( x, y ) coordenadas do pixel a ser rasterizado
	
	
	x = x * 4; // coordenada x
	y = 4 * y * IMAGE_WIDTH; // IMAGE_WIDTH largura da tela ( número de colunas )
	
	int coordenada = x + y; // Coordenada do pixel em relação ao offset (ponto inicial, ( 0, 0 ))

	FBptr[coordenada + 0] = color; // componente R
	FBptr[coordenada + 1] = 0; // Componente G
	FBptr[coordenada + 2] = 0; // Componente B
	FBptr[coordenada + 3] = 0; // Componente A
	
	// escreve um pixel na tela.
}

void DrawLine(int x0, int x1, int y0, int y1, int color){

	int dx, dy, aux0, aux1, dxI, dyI, x, y, y_1;

	y_1 = y0;

	dx = x1 - x0;
	dy = y1 - y0;

	bool dTroca = false, xTroca = false, yTroca = false;

	if( abs(dy) > abs(dx) ){ // condição para que troque os valores de dx e dy

		aux0 = x0; // variável auxiliar
		aux1 = x1;

		x0 = y0; // x0 recebe y0
		x1 = y1;

		y0 = aux0; // yo recebe x0;
		y1 = aux1;
		
		dTroca = true;

	}


	if( x0 > x1 ){ // caso dx seja negativo, invertemos os eixos.

		aux0 = x0;
		aux1 = x1;

		x0 = aux1;
		x1 = aux0;

		aux0 = y0;
		aux1 = y1;

		y0 = aux1;
		y1 = aux0;
		

		xTroca = true;

	}

	if(y0 > y1){ // caso dy seja negativo
		
		y_1 = y0;

		aux0 = y0;
		aux1 = y1;

		y0 = aux1;
		y1 = aux0;

		yTroca = true;

	}

	dx = x1 - x0;
	dy = y1 - y0;

	x = x0;
	y = y_1;

	int d = 2 * dy - dx;

	int incLeste = 2 * dy;
	int incNordeste = 2 * (dy - dx);

	
	while(x < x1){

		if(d <= 0){

			d += incLeste;
			x++;

		}
		else{

			d +=incNordeste;
			x++;	
			

			if(yTroca == true){

				y--;

			}
			else{

				y++;		

			}

		}

		if(dTroca == true){
	
			PutPixel(y, x, color);

		}
		else{

			PutPixel(x, y, color);

		}


	}


}



#endif // _MYGL_H_

