function animaPoligono(a_inicial, a_final, Po, pause_time, delta_a)  
  minPx = min(min(Po(1,:))) - 1;
  maxPx = max(max(Po(1,:))) + 1;
  
  minPy = min(min(Po(size(Po)(1)-1,:))) - 1;
  maxPy = max(max(Po(size(Po)(1)-1,:))) + 1;
  
  figure;
  axis ([minPx, maxPx, minPy, maxPy]);
  set (gca, "ygrid", "on");
  set (gca, "xgrid", "on");

  a = a_inicial;
  tam = (size(Po)(2));
  H = zeros(size(Po,2));
  
  while(a < a_final)

    if (a != a_inicial)
      delete(H(:));
    endif
    
    P = rotacionaPoligono(Po, a);
    
    for i = 1: tam
      
      tmp = mod(i+1, size(Po)(2));

      if tmp != 0
        prox = tmp;
      else
        prox = i+1;
      endif
      
      H(i,:) = line([P(1, i), P(1, prox)] , [P(2, i), P(2, prox)], "linewidth", 2);
      
    endfor
    drawnow;
    a = a + delta_a;
    pause(pause_time);
  end
endfunction