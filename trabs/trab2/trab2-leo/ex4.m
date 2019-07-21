pkg load image;

caminhoImagem = input("Digite o caminho da imagem a ser filtrada:\n", 's');
disp("\nMascaras disponiveis:\n average, disk, gaussian, log, laplacian, unsharp, motion, sobel, prewitt, kirsch\n")
tipoMascara = input("Digite o tipo da mascara a ser utilizada:\n", 's');

imagem = imread(caminhoImagem);

imagem_filtrada = imfilter(imagem, fspecial(tipoMascara));

figure
subplot(1,2,1);
imshow(imagem);
subplot(1,2,2);
imshow(imagem_filtrada);