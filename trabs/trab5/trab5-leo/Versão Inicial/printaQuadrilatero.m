function printaQuadrilatero(qua)
  figure;
  line (qua(1,1:2), qua(2,1:2), "linestyle", "-", "color", "b");
  line (qua(1,2:3), qua(2,2:3), "linestyle", "-", "color", "b");
  line (qua(1,3:4), qua(2,3:4), "linestyle", "-", "color", "b");
  line ([qua(1,4) qua(1,1)] , [qua(2,4) qua(2,1)], "linestyle", "-", "color", "b");
endfunction