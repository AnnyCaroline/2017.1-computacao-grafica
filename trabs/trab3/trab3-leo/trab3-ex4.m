pkg load image;

digital = imread('D:/img/digital.png');
digital = rgb2gray(digital);
digital = im2double(digital);

%figure;
%imshow(digital);
%figure;
%imhist(digital);

limiar = limiarAnt = 0.2;

do
  media_baixo = mean(digital(find(digital < limiar)));
  media_alto = mean(digital(find(digital >= limiar)));
  limiarAnt = limiar;
  limiar = (media_baixo + media_alto) / 2;
until(limiar == limiarAnt)

%matriz_baixo = digital;
%matriz_alto = digital;
%matriz_baixo(find(digital < limiar)) = 0;
%matriz_alto(find(digital >= limiar)) = 0;

%media_baixo = mean(digital(find(digital < limiar)));
%media_alto = mean(digital(find(digital < limiar)));

%figure;
%imshow(matriz_baixo);
%figure;
%imshow(matriz_alto);
%baixo = size(matriz_baixo);
%alto = size(matriz_alto);

%figure;
%imhist(digital);

subplot(1,3,1);
imshow(digital);
subplot(1,3,2);
imhist(digital);
str = cstrcat("Limiar = ", num2str(limiar));
title (str, "fontsize", 50);
subplot(1,3,3);
imshow(digital > limiar);
