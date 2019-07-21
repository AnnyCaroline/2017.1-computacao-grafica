#{
  Anny Caroline - annycarolinegnr@gmial.com
  UERJ - Computação Gráfica - 2017.1
#}

function fc = nrt(f, x, y, banda)
  j = floor(x);
  k = floor(y);
  u = x - j;
  v = y - k;
  
  #{
  fa = (1-v)*f(j,k) + v*f(j,k+1);
  fb = (1-v)*f(j+1,k) + v*f(j+1,k+1);
  fc = (1-u)*fa + u*fb;
  #}
  
  fa = (1-v)*f(j,k);
  
  if ((j+1) <= size(f,1))
    fb = (1-v)*f(j+1,k);
  else
    fb = 0;
  endif
  
  if (((j+1) <= size(f,1)) && ((k+1) <= size(f,2)))
    fb = fb + v*f(j+1,k+1);
  endif
  
  if ((k+1) <= size(f,2))
    fa = fa + v*f(j,k+1);
  endif
  
  fc = (1-u)*fa + u*fb;
end