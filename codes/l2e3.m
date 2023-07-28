RGB = imread('imgs/lion.png');

h = fspecial('average', 10);
average = imfilter(RGB,h);

h = fspecial('motion', 20);
motion = imfilter(RGB,h);

h = fspecial('disk', 20);
disk = imfilter(RGB,h);

h = fspecial('gaussian', 20);
gaussian = imfilter(RGB,h);

h = fspecial('log', 20);
log = imfilter(RGB,h);

h = fspecial('laplacian');
laplacian = imfilter(RGB,h);

h = fspecial('unsharp');
unsharp = imfilter(RGB,h);

h = fspecial('motion', 20);
motion = imfilter(RGB,h);

h = fspecial('sobel', 20);
sobel = imfilter(RGB,h);

h = fspecial('prewitt', 20);
prewitt = imfilter(RGB,h);

h = fspecial('kirsch', 20);
kirsch = imfilter(RGB,h);

rows=5;
cols=2;

figure;
subplot(rows,cols,1);
imshow(average);
subplot(rows,cols,2);
imshow(motion);
subplot(rows,cols,3);
imshow(disk);
subplot(rows,cols,4);
imshow(gaussian);
subplot(rows,cols,5);
imshow(log);
subplot(rows,cols,6);
imshow(laplacian);
subplot(rows,cols,7);
imshow(unsharp);
subplot(rows,cols,8);
imshow(sobel);
subplot(rows,cols,9);
imshow(prewitt);
subplot(rows,cols,10);
imshow(kirsch);









