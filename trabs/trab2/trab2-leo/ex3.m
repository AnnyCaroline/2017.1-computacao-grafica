pkg load image;

caminhoImagem = input("Digite o caminho da imagem a ser filtrada:\n", 's');
tamanhoMascara = input("Digite o tamanho da mascara a ser utilizada:\n");

imagem = imread(caminhoImagem);

mascara = ones(tamanhoMascara) .* (1/(tamanhoMascara * tamanhoMascara));

imagem_filtrada = imfilter(imagem, mascara);

figure
subplot(1,2,1);
imshow(imagem);
subplot(1,2,2);
imshow(imagem_filtrada);
