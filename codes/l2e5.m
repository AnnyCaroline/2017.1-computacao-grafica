#1
COINS = imread("imgs/Coins.png");
COINS = im2double(COINS);
showImgAndHist(COINS,'1. Imagem original e seu histograma');


#3 - limiar 0.33 identificado por meio do histograma
BIN = COINS > 0.33;
showImgAndHist(BIN,'2. Imagem binária e seu histograma');


#4 - mudar a cor de background usando a imagem binária
COINS_BIN = BIN .* COINS;
showImgAndHist(COINS_BIN, '3. Cor de background alterada usando a imagem binária');


#4 - mudar a cor de background usando diretamente o limiar
COINS_LIM = COINS;
s = size(COINS_LIM);
s = s(1)*s(2);
for i = 1:s
  if COINS_LIM(i) <= 0.33
    COINS_LIM(i) = 0.2;
  endif
endfor
showImgAndHist(COINS_LIM, '4. Cor de background alterada usando diretamente o limiar');


#5
figure('name', '5. Apresente a imagem original e a resultante em uma única figura.','NumberTitle','off');
subplot(2,1,1);
title('Imagem original');
imshow(COINS);
subplot(2,2,3);
title('Imagem com cor de background alterada usando imagem binária');
imshow(COINS_BIN);
subplot(2,2,4);
title('Imagem com cor de background alterada usando diretamente o limiar');
imshow(COINS_LIM);



