#contador de imagens
global cont;
cont=5;

function saveImg
  global cont;
  str = strcat("imgs/l1/e3-", mat2str(cont), ".jpg");
  print(str,"-djpg")
  cont = cont+1;
endfunction

#exercicio anterior
araraPNG = imread("imgs/arara_full.png");
[araraBMP MAP] = imread("imgs/arara_full_256.bmp");

#1
imwrite(araraPNG, "arara.bmp");
imwrite(araraBMP, MAP, "arara.png");

#2
araraBMP = imread("arara.bmp");
[araraPNG MAP] = imread("arara.png");

figure;
imshow(araraBMP);
saveImg();
figure;
imshow(araraPNG, MAP);
saveImg();