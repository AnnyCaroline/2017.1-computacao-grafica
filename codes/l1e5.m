ELC = imread("imgs/Einstein_low_contrast.png");
EMC = imread("imgs/Einstein_med_contrast.png");

#1
figure;
imshow(ELC);
figure;
imshow(EMC);

#2

#SUBPLOT
figure;
subplot(1,2,1);
imshow(ELC);
subplot(1,2,2);
imshow(EMC);

#SUBIMAGE
figure;
subplot(1,2,1);
subimage(ELC);
subplot(1,2,2);
subimage(EMC);

#3
#TITLE
figure;
imshow(ELC);
title ("Título");

#TITULO NA JANELA
figure('name','Título');
imshow(ELC);
figure('name', 'Título sem número','NumberTitle','off');
imshow(EMC);