#RGB

global cont;
cont=3;

function saveImg
  global cont;
  str = strcat("imgs/l1e2/", mat2str(cont), ".jpg");
  print(str,"-djpg")
  cont = cont+1;
endfunction

#1
RED   = [1 0 0; 1 0 1; 1 0 0.5];
GREEN = [0 0 1; 1 0 0; 1 1 0.5];
BLUE  = [0 0 0; 0 1 1; 1 1 0.5];

#2
disp(">> RED");
RED
disp(">> GREEN");
GREEN
disp(">> BLUE");
BLUE

#3
#help cat
RGB = cat (3, RED, GREEN, BLUE);

#4
disp(">> RGB");
RGB #visualizar o conteúdo da matriz
disp(">> RGB(:,:,1)");
RGB(:,:,1)
disp(">> RGB(:,:,2)");
RGB(:,:,2)
disp(">> RGB(:,:,3)");
RGB(:,:,3)

#5
imshow(RGB);
saveImg();