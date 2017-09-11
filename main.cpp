	#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//************************************************************************

// void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int cor1, int cor2, int cor3)
// // void DrawLine(int x0, int x1, int y0, int y1, int color)

	tRGBA color1, color2, color3, *ptrRgb = &color1, *ptrRgb1 = &color2, *ptrRgb2 = &color3;

	ptrRgb->red = 0;
	ptrRgb->green = 225;
	ptrRgb->blue = 0;
	ptrRgb->alpha = 0;

	ptrRgb1->red = 225;
	ptrRgb1->green = 0;
	ptrRgb1->blue = 0;
	ptrRgb1->alpha = 0;

	ptrRgb2->red = 0;
	ptrRgb2->green = 0;
	ptrRgb2->blue = 225;
	ptrRgb2->alpha = 0;
		
	DrawTriangle(512, 230, 0, 0, 400 ,0, color1, color2, color3); /* triangulo, x,y, de vertices (512, 0), (230, 400), (0,0)

									e cores verde, vermelho e azul*/

	PutPixel(0, 0, color1);	


}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

	
