#contador de imagens
global cont;
cont=1;

function saveImg
  global cont;
  str = strcat("imgs/l1/e4-", mat2str(cont), ".jpg");
  print(str,"-djpg")
  cont = cont+1;
endfunction



#ind2gray
[X MAP] = imread("imgs/arara_full_256.bmp");
imshow(X, MAP);
G = ind2gray(X, MAP);
figure
imshow(G);
saveImg()

#gray2ind
[X, MAP] = gray2ind(G);
figure
imshow(X, MAP);
saveImg()

#rgb2ind
RGB = imread("imgs/arara_full.png");
[X, MAP] = rgb2ind(RGB);
figure
imshow(X,MAP);
saveImg()

#ind2rgb
[X MAP] = imread("imgs/arara_full_256.bmp");
RGB = ind2rgb(X, MAP);
figure
imshow(RGB);
saveImg()

#rgb2gray
RGB = imread("imgs/arara_full.png");
G = rgb2gray(RGB);
figure
imshow(G);
saveImg()

#gray2rgb
#Não existe

#fim
close all force