function girarFigura(figura, alfa)

  % ponto central de uma figura regular
  pcx = (max(figura(1, :)) - min(figura(1, :)))/2.0 + min(figura(1, :));
  pcy = (max(figura(2, :)) - min(figura(2, :)))/2.0 + min(figura(2, :));

  % matriz para mover para o centro
  t1 = [ 1 0 -pcx,
         0 1 -pcy,
         0 0   1  ];

  % matriz para girar alfa graus
  t2 = [ cos(alfa) -sin(alfa) 0,
         sin(alfa) cos(alfa)  0,
            0       0     1 ];
         
  % matriz para mover para a posicao original
  t3 = [ 1 0 pcx,
         0 1 pcy,
         0 0  1  ];

  result = t3 * t2 * t1 * figura;

  % desenhando figura  
  clf;
  hold on;
  plot (5, 5);
  
  qtdPontos = columns(result);
  
  for i = 1:qtdPontos-1;
     % linha do ponto i ao ponto i+1
    line ([result(1,i), result(1,i+1)],[result(2,i), result(2,i+1)]);
  endfor
  line ([result(1,qtdPontos), result(1,1)],[result(2,qtdPontos), result(2,1)]);

endfunction

quadrado = [1 4 4 1,
      1 1 4 4,
      1 1 1 1 ];
      
hexagono = [1 2 3 4 3 2,
      2 1 1 2 3 3,
      1 1 1 1 1 1 ];

i = 1;
while(i < 10)
  girarFigura(hexagono, i);
  i += 0.1;
  pause (0.1);
endwhile
