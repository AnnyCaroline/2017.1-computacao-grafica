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
veg_r = gavea_r .* veg;
veg_g = gavea_g .* veg;
veg_b = gavea_b .* veg;
veg = cat(3, veg_r, veg_g, veg_b);
figure;
imshow(veg);

naoVeg = NDVI <= 0.15;
naoVeg_r = gavea_r .* naoVeg;
naoVeg_g = gavea_g .* naoVeg;
naoVeg_b = gavea_b .* naoVeg;
naoVeg = cat(3, naoVeg_r, naoVeg_g, naoVeg_b);
figure;
imshow(naoVeg);

gavea_original = cat(3, gavea_r, gavea_g, gavea_b);
figure;
imshow(gavea_original);