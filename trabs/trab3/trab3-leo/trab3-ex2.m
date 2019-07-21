pkg load image;

ferrari = imread('D:/img/ferrari.jpg');
fg = rgb2gray(ferrari);
figure;
imshow(fg);
title "Monocromática";

fCanny = edge(fg, "Canny");
figure;
imshow(fCanny);
title "Canny";

fKirsch = edge(fg, "Kirsch");
figure;
imshow(fKirsch);
title "Kirsch";

fLindeberg = edge(fg, "Lindeberg");
figure;
imshow(fLindeberg);
title "Lindeberg";

fLoG = edge(fg, "LoG");
figure;
imshow(fLoG);
title "LoG";

fPrewitt = edge(fg, "Prewitt");
figure;
imshow(fPrewitt);
title "Prewitt";

fRoberts = edge(fg, "Roberts");
figure;
imshow(fRoberts);
title "Roberts";

fSobel = edge(fg, "Sobel");
figure;
imshow(fSobel);
title "Sobel";