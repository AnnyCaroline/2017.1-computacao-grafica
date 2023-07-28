#1
#help imread;

#2
araraPNG = imread("imgs/arara_full.png");
araraBMP = imread("imgs/arara_full_256.bmp");

#3
whos;

#2 e 3
[araraBMPCorreta MAP] = imread("imgs/arara_full_256.bmp");

#4
figure;
imshow(araraPNG);
figure;
imshow(araraBMP);
figure;
imshow(araraBMPCorreta, MAP);

#fim
#close all force