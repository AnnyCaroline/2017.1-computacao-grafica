#contador de imagens
global cont;
cont=1;

function saveImg
  global cont;
  str = strcat("imgs/l2e1/", mat2str(cont), ".jpg");
  print(str,"-djpg")
  cont = cont+1;
endfunction

#1
help imadjust;
help imhist;

#2
ELC = imread("imgs/Einstein_low_contrast.png");
EMC = imread("imgs/Einstein_med_contrast.png");
EHC = imread("imgs/Einstein_high_contrast.png");

#3
ELC = rgb2gray(ELC);
EMC = rgb2gray(EMC);
EHC = rgb2gray(EHC);

#3.a (assumindo que são 3 imagens finais)
function showImgAndHistSP(IMG)
  figure;
  subplot(2,1,1);
  imshow(IMG);
  subplot(2,1,2);
  imhist(IMG);
  
  saveImg();
endfunction

showImgAndHistSP(ELC);
showImgAndHistSP(EMC);
showImgAndHistSP(EHC);


#3.b (assumindo que são 6 imagens finais)
function showImgAndHist(IMG)
  figure;
  imshow(IMG);
  saveImg();
  
  figure;
  imhist(IMG);
  saveImg();
endfunction

showImgAndHist(ELC);
showImgAndHist(EMC);
showImgAndHist(EHC);

#4
ELC_UINT8 = ELC;
ELC_DOUBLE = im2double(ELC_UINT8);
ELC_AJUST = imadjust(ELC_DOUBLE);

#5
showImgAndHistSP(ELC_AJUST);

#fim
close all force