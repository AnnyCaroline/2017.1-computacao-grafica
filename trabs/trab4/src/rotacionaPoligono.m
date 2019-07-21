function retval = rotacionaPoligono(Po, a)
  minX = min(Po(1,:));
  maxX = max(Po(1,:));
  minY = min(Po(2,:));
  maxY = max(Po(2,:));
  
  Pc = [minX+(maxX-minX)/2 minY+(maxY-minY)/2];

  T1 = [1 0 -Pc(1); 0 1 -Pc(2); 0 0 1];
  T2 = [cos(a) -sin(a) 0; sin(a) cos(a) 0; 0 0 1];
  T3 = [1 0 Pc(1); 0 1 Pc(2); 0 0 1];

  T = T3 * T2 * T1;
  Pf = T * Po;
  
  retval = Pf;
  return;
endfunction