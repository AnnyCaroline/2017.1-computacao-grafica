function showImgAndHist(IMG, titulo)
  figure('name', titulo,'NumberTitle','off');
  subplot(2,1,1);
  imshow(IMG);
  subplot(2,1,2);
  imhist(IMG);
endfunction