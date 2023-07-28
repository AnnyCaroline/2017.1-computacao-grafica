global cont;
cont=5;

function saveImg
  global cont;
  str = strcat("imgs/l1e2/e2-", mat2str(cont), ".jpg");
  print(str,"-djpg")
  cont = cont+1;
endfunction

X = [0.1 0.5 0.9];

figure;
imshow (X);
saveImg();

figure;
imshow (X, [0 1]);
saveImg();

figure;
imshow (X, [0 2]);
saveImg();

figure;
imshow (X, [0 16]);
saveImg();

#fim
close all force