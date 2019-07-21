pkg load image;

sobel_y = [-1 -2 -1; 0 0 0; 1 2 1];
sobel_x = [-1 0 1; -2 0 2; -1 0 1];

ferrari = imread('D:/img/Ferrari.jpg');

figure
imshow(ferrari);

ferrari = rgb2gray(ferrari);
ferrari = im2double(ferrari);

ferrari = imfilter(ferrari, fspecial('gaussian', [5 5]));
ferrari_x = imfilter(ferrari, sobel_x);
ferrari_y = imfilter(ferrari, sobel_y);

mag = abs(ferrari_x) + abs(ferrari_y);
imag = mag;
imag(find(mag < 0.3)) = 0;
figure
imshow(imag);

ang = atan(ferrari_y ./ ferrari_x);
iang = zeros(size(ang, 1), size(ang, 2));

iang(find(ang < (pi/6) & ang > -(pi/6))) = 2; % 0 graus (amarelo)
iang(find(ang < (pi/3) & ang > (pi/6))) = 3; % 45 graus (verde)
iang(find(ang < -(pi/6) & ang > -(pi/3))) = 5; % 135 graus (vermelho)
iang(find(ang > (pi/3))) = 4; % 90 graus (azul)
iang(find(ang < -(pi/3))) = 4; % -270 graus (azul)

iang(find(mag < 0.3)) = 0;
map = [0 0 0; 1 1 0; 0 1 0; 0 0 1; 1 0 0];

figure
imshow(iang, map);




