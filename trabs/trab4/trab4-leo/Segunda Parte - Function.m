function animarFigura(figura)

  alfa = 0.1;
  while(alfa < 10)

    % Ponto central
    pcx = (max(figura(1, :)) - min(figura(1, :)))/2.0 + min(figura(1, :));
    pcy = (max(figura(2, :)) - min(figura(2, :)))/2.0 + min(figura(2, :));

    % Matriz para mover para o centro
    t1 = [ 1 0 -pcx,
           0 1 -pcy,
           0 0   1  ];

    % Matriz para girar alfa graus
    t2 = [ cos(alfa) -sin(alfa) 0,
           sin(alfa) cos(alfa)  0,
              0       0     1 ];
           
    % Matriz para mover para a posição original
    t3 = [ 1 0 pcx,
           0 1 pcy,
           0 0  1  ];

    result = t3 * t2 * t1 * figura;
    
    
    % Desenhando figura rotacionada  
    clf;
    hold on;
    plot (5, 5);
    
    qtdPontos = columns(result);

    for i = 1:qtdPontos-1;
      % linha do ponto i ao ponto i+1
      line ([result(1,i), result(1,i+1)],[result(2,i), result(2,i+1)]);
    endfor
    % linha do ponto 1 ao ponto n
    line ([result(1,qtdPontos), result(1,1)],[result(2,qtdPontos), result(2,1)]);
    alfa += 0.1;
    pause (0.1);
  endwhile
    
  
endfunction

