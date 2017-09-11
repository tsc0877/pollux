# Trabalho 1 de Introdução a Computação Gráfica

  Trabalho 1 da disciplina de Computação Gráfica. Neste trabalho, fomos desafiados a fazer quatro funções que renderizasse alguns pixels na tela. 
  A PutPixel, função mais utilizada, já que ela renderiza o pixel na tela; a função DrawLine que foi a mais complicada, onde tem o papel de desenhar uma reta; e finalizamos com a DrawTriangle, função que renderiza um triangulo na tela. Também fizemos a Interpolação de cores de cada ponto da reta. 
  A dificuldade maior do trabalho foi adaptar o algoritmo de Bresenham para os outros sete octantes, onde usar o papel foi indispensável para analisar os octantes. A sacada foi transformar os outros sete octantes no primeiro, onde conheciamos e podiamos manusear os resultados. A ideia da troca dos eixos, quando o dy > dx, é que teriamos uma reta com inclinação 0 <= m <= 1, onde é útil o algoritmo. Como trocamos os eixos, trocamos também y -> x na hora de renderizar. Se o x0 > x1, ou seja, dx < 0, e dy >= 0; trocamos as coordenadas x0 -> x1 e y0 -> y1, onde temos agora uma reta no 8vo octante, mas como queremos no 1ro octante, invertemos o valor de dy, e assim passamos para uma váriavel que a troca foi feita, assim avisando ao PutPixel que devemos decrementar o y.
  Usei algumas variáveis para receber valores importantes, como o y inicial (y_1), variável que irá receber o valor de y0 em caso de y0 > y1, para que, na hora de decrementar, esteja o maior valor.
  A interpolação de cores foi feita seguindo a idéia de que, ao fazer sua variação ( cor1 - cor2 ) e dividir pelo tamanho da reta, ou seja, seu módulo, saberiamos quanto precisariamos decrementar a cor1 e encrementar, na mesma quantidade, a cor2, para obtermos o valor da cor1, na cor2. Percemos isso ao pensar que a cada pixel da reta corresponderá à uma variação de cor. Logo, por isso dividimos pelo seu módulo. 
    
  

