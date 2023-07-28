#separar vegetação do que não é vegetação usando ndvi

#exibindo a img rgb
gr = imread("imgs/gavea_b.png");
gg = imread("imgs/gavea_g.png");
gb = imread("imgs/gavea_b.png");
gnir = imread("imgs/gavea_nir.png");

gr = rgb2gray(gr);
gg = rgb2gray(gg);
gb = rgb2gray(gb);
gnir = rgb2gray(gnir);

grgb = cat(3,gr,gg,gb);

figure;
imshow(grgb);
title("Imagem RGB");

#Calculando o NDVI
gr = im2double(gr);
gg = im2double(gg);
gb = im2double(gb);
gnir = im2double(gnir);

NDVI = (gnir - gr) ./ (gnir + gr);

figure;
imshow(NDVI);
title("Imagem NDVI");

#Montando a img de vegetação
VEG = NDVI > 0.1;
figure;
imshow(VEG);
title("Imagem VEG");

#grafico
PRETO = VEG*0;
grgb = cat(3, PRETO, VEG, PRETO);
figure;


subplot(1,2,1);
imshow(grgb);

vegetacao = {'Vegetação', ''}
quantidadeDePixels = [sum(sum(VEG)), sum(sum(~VEG))];

subplot(1,2,2);

p = pie(quantidadeDePixels, vegetacao);
set(p(1),'facecolor',[0 1 0]);
set(p(3),'facecolor',[0 0 0]);
