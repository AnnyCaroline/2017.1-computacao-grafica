LEME = imread("imgs/leme.bmp");
NOVA = imadjust(im2double(LEME),[0 1], [0 1], 0.8);

figure
subplot(1,2,1);
imshow(LEME);
subplot(1,2,2);
imshow(NOVA);