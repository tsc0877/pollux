# pollux
![Triangulo](/pollux/imagens/triangulo.png)

  Trabalho 1 da disciplina de Computação Gráfica. Neste trabalho, fomos desafiados a fazer quatro funções que renderizasse alguns pixels na tela. 
  A PutPixel, função mais utilizada, já que ela renderiza o pixel na tela; a função DrawLine que foi a mais complicada, onde tem o papel de desenhar uma reta; e finalizamos com a DrawTriangle, função que renderiza um triangulo na tela. Também fizemos a Interpolação de cores de cada ponto da reta. 
  A dificuldade maior do trabalho foi adaptar o algoritmo de Bresenham para os outros sete octantes, onde usar o papel foi indispensável para analisar os octantes. A sacada foi transformar os outros sete octantes no primeiro, onde conheciamos e podiamos manusear os resultados.  Usei algumas variáveis para receber valores importantes, como o y final (y_1), já que ao inverter suas coordenadas iria decrementar a coordenada y, e por isso a importância dela no código. 
  A interpolação de cores foi feita seguindo a idéia de que, ao fazer sua variação ( cor1 - cor2 ) e dividir pelo tamanho da reta, ou seja, seu módulo, saberiamos quanto precisariamos decrementar a cor1 e encrementar, na mesma quantidade, a cor2, para obtermos o valor da cor1, na cor2. 
    
  

