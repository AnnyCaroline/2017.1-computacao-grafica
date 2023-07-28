
IMG = imread("imgs/digital.png");
IMG = rgb2gray(IMG);
IMG = im2double(IMG);



#Selecione um limiar inicial T
T = 0.1;

do
  #{
  2. Limiarize a imagem usando T:  Vai gerar dois grupos de pixels: 
  G1(pixels com valores < T ) e G2(pixels com valores = T )
  #}
  G1 = IMG(find(IMG <  T));
  G2 = IMG(find(IMG >= T));

  #3. Calcule a intensidade media de cada grupo (µ1 e µ2)
  U1 = mean(G1);
  U2 = mean(G2);
 
  #4. Calcule um novo limiar:
  Tant = T;
  T = (1/2) * (U1+U2);
until(T == Tant)


subplot(2,1,2);
imhist(IMG);
legend(cstrcat("Limiar: ", num2str(T)));
subplot(2,2,1);
imshow(IMG);
subplot(2,2,2);
imshow(IMG>T);