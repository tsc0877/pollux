#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

typedef struct {
	
	float red;
	float green;
	float blue;
	float alpha;


}tRGBA;


tRGBA Interpolacao(tRGBA color1, tRGBA color2, int dx){ // Pegamos a variação das cores, onde são dadas por: (cor1 - cor2) / dx 
														// 

	float variacaoRed = (color1.red - color2.red) / dx;
	float variacaoGreen = (color1.green - color2.green) / dx;
	float variacaoBlue = (color1.blue - color2.blue) / dx;
	float variacaoAlpha = (color1.alpha - color2.alpha) / dx;

	tRGBA color;


	color.red += variacaoRed;
	color.blue += variacaoBlue;
	color.green += variacaoGreen;
	color.alpha += variacaoAlpha;

	return color;

}


void PutPixel(int x, int y, tRGBA color){ // ( x, y ) coordenadas do pixel a ser rasterizado
	
	tRGBA *ptrRGBA = &color;
	
	x = x * 4; // coordenada x
	y = 4 * y * IMAGE_WIDTH; // IMAGE_WIDTH largura da tela ( número de colunas )
	
	int coordenada = x + y; // Coordenada do pixel em relação ao offset (ponto inicial, ( 0, 0 ))

	FBptr[coordenada + 0] = ptrRGBA->red; // componente R
	FBptr[coordenada + 1] = ptrRGBA->green; // Componente G
	FBptr[coordenada + 2] = ptrRGBA->blue; // Componente B
	FBptr[coordenada + 3] = ptrRGBA->alpha; // Componente A
	
	// escreve um pixel na tela.
}
// Função que renderiza uma linha na tela		

void DrawLine(int x0, int x1, int y0, int y1, tRGBA color1, tRGBA color2){

	int dx, dy, aux0, aux1, x, y;

	int y_1 = y0; // Usamos essa variavel pra guardar o valor de y0, pois pode ser modificada mais tarde


	dx = x1 - x0; // Variação do x
	dy = y1 - y0; // Variação do y

	bool dTroca = false, yTroca = false,xTroca = false;

	if( abs(dy) > abs(dx) ){ /* Caso o dy seja maior que dx, trocamos os eixos y e x.
							   Como trocamos os eixos, utilizamos a variável dTroca para inveter os eixos quando for renderizar.*/

		aux0 = x0; 
		aux1 = x1;

		x0 = y0; // x0 recebe y0
		x1 = y1;

		y0 = aux0; // yo recebe x0;
		y1 = aux1;
		
		dTroca = true; 		// Variável que confirma que foram trocadas os eixos.

	}

	if( x0 > x1 ){ // caso dx seja negativo, invertemos as coordenadas.

		aux0 = x0;
		aux1 = x1;

		x0 = aux1;
		x1 = aux0;

		aux0 = y0;
		aux1 = y1;

		y0 = aux1;
		y1 = aux0;
			
		xTroca = true;

		y_1 = y0; /* Caso x0 seja > x1, a linha será renderizada pelo y_1 = y0, onde será 
			 	decrementada até chegar no ponto realmente inicial*/
 
		
	}

	if(y0 > y1){ // caso dy seja negativo, pegamos seu oposto, fazendo dy = y0 - y1.
		
		y_1 = y0;
					// Caso y0 seja > y1, a linha será renderizada pelo y_1 = y0, onde será 
				   //decrementada até chegar no ponto realmente inicial

		aux0 = y0;
		aux1 = y1;
	
		y0 = aux1;
		y1 = aux0;		

		yTroca = true;  // Variável que confirma que houve a troca das coordenadas 

				
	}

	dx = x1 - x0;   // variação após as condições serem verificadas
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
			

			if(yTroca == true){  // Decrementamos o y pois a variação de y é negativa

				y--;

			}
			else{

				y++;		

			}

		}

		if(dTroca == true){  // Se dy > dx, trocamos as coordenadas, e,consequentemente, mudamos as coordenadas ao renderizar.

			PutPixel(y, x, Interpolacao(color1, color2, dx));

		}
		else{

			PutPixel(x, y, Interpolacao(color1, color2, dx));

		}


	}


}

// Função que redenriza um triângulo na tela.

void DrawTriangle(int x1, int x2, int x3, int y1, int y2, int y3, tRGBA color1, tRGBA color2, tRGBA color3){

		// void DrawLine(int x0, int x1, int y0, int y1, int color)
		// void DrawLine(int x0, int x1, int y0, int y1, tRGBA color1, tRGBA color2)
		DrawLine(x1, x2, y1, y2, color1, color2);
		DrawLine(x2, x3, y2, y3, color2, color3);
		DrawLine(x3, x1, y3, y1, color3, color1);


}

#endif // _MYGL_H_

