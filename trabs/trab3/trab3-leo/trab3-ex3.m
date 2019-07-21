pkg load image;

gavea_nir = imread('D:/img/gavea_nir.png');
gavea_r = imread('D:/img/gavea_r.png');
gavea_g = imread('D:/img/gavea_g.png');
gavea_b = imread('D:/img/gavea_b.png');

gavea_nir = rgb2gray(gavea_nir);
gavea_r = rgb2gray(gavea_r);
gavea_g = rgb2gray(gavea_g);
gavea_b = rgb2gray(gavea_b);

gavea_nir_d = im2double(gavea_nir);
gavea_r_d = im2double(gavea_r);

NDVI = (gavea_nir_d - gavea_r_d) ./ (gavea_nir_d + gavea_r_d);

veg = NDVI > 0.15; % 0.1 - 0.15
mascaraVerde = [0 0 0; 0 1 0];
vegVerde = gray2ind(veg);
figure;
imshow(vegVerde, mascaraVerde);

naoVeg = NDVI <= 0.15;
mascaraVermelha = [0 0 0; 1 0 0];
naoVegVermelho = gray2ind(naoVeg);
figure;
imshow(naoVeg, mascaraVermelha);

gavea_original = cat(3, gavea_r, gavea_g, gavea_b);
figure;
imshow(gavea_original);