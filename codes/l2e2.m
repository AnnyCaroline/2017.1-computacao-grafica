LEME = imread("imgs/leme.bmp");
NOVA = imadjust(im2double(LEME),[0 1], [0 1], 3);

figure
subplot(2,2,1);
imshow(LEME);
subplot(2,2,2);
imshow(NOVA);
subplot(2,2,3);
imhist(LEME);
subplot(2,2,4);
imhist(NOVA);
