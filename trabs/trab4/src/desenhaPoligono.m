function retval = desenhaPoligono(P)
  minPx = min(min(P(1,:))) - 1;
  maxPx = max(max(P(1,:))) + 1;
  
  minPy = min(min(P(size(P)(1)-1,:))) - 1;
  maxPy = max(max(P(size(P)(1)-1,:))) + 1;
  
  figure;
  axis ([minPx, maxPx, minPy, maxPy]);
  set (gca, "ygrid", "on");
  set (gca, "xgrid", "on");
  
  hold on;
  
  tam = (size(P)(2));
  for i = 1: tam  
    tmp = mod(i+1, size(P)(2));

    if tmp != 0
      prox = tmp;
    else
      prox = i+1;
    endif

    H(i) = line([P(1, i), P(1, prox)] , [P(2, i), P(2, prox)], "linewidth", 2);
  endfor

endfunction