#{
  Anny Caroline - annycarolinegnr@gmial.com
  UERJ - Computação Gráfica - 2017.1
#}

function deforma(caminhoIMG, P)
  IMG = imread(caminhoIMG);
  IMG = im2double(IMG);
  BANDA_IMG = IMG(:, :, 1);

  L = [P(1:size(P)(1), 3:4)];
  L = transpose(L)(:);

  A1 = [P(:,1)              P(:,2)              ones(size(P)(1),1)  zeros(size(P)(1),1) zeros(size(P)(1),1) zeros(size(P)(1),1) -P(:,1).*P(:,3) -P(:,2).*P(:,3)];
  A2 = [zeros(size(P)(1),1) zeros(size(P)(1),1) zeros(size(P)(1),1) P(:,1)              P(:,2)              ones(size(P)(1),1)  -P(:,1).*P(:,4) -P(:,2).*P(:,4)];
  A = reshape([A1 A2]', 8,  size(P)(1)*2)';

  x = inv(A'*A) * A' * L;
  x(9) = 1;
  T = reshape(x',3,3)';

  #Calcula canvas
  Ptio = [ T * [size(IMG,1) 1 1]', T * [1 1 1]',  T * [1 size(IMG,2) 1]' , T * [size(IMG,1) size(IMG,2) 1]'];

  Ptio(:,1) = Ptio(:,1)/Ptio(3,1);
  Ptio(:,2) = Ptio(:,2)/Ptio(3,2);
  Ptio(:,3) = Ptio(:,3)/Ptio(3,3);
  Ptio(:,4) = Ptio(:,4)/Ptio(3,4);

  sobra_lin = min( (Ptio(1,:)<0) .* Ptio(1,:)) * (-1);
  sobra_col = min( (Ptio(2,:)<0) .* Ptio(2,:)) * (-1);

  Ptio(1,:) = Ptio(1,:) .+ sobra_lin;
  Ptio(2,:) = Ptio(2,:) .+ sobra_col;

  lin = max(Ptio(1,:));
  col = max(Ptio(2,:));

  canvasNRC = zeros(lin, col, size(IMG, 3));
  canvasNRT = zeros(lin, col, size(IMG, 3));

  # Calcula T inverso
  Tinv = inv(T);

  #Pega cada pixel da imagem com zeros
  for k=1:size(IMG, 3)
    for i=1:lin
      for j=1:col
        coord = Tinv * [i-sobra_lin j-sobra_col 1]';
        coord = coord ./ coord(3);
        
        # NRC - se coord dentro imagem original
        coord = round(coord);
        if coord(1) > 0 && coord(1) <= size(IMG,1) && coord(2) >0 && coord(2) <= size(IMG,2) 
          canvasNRC(i,j,k) = IMG(coord(1), coord(2), k);
          canvasNRT(i,j,k) = nrt(IMG(:, :, k), coord(1), coord(2));
        endif
        
      endfor
    endfor
  endfor

  figure;
  imshow(IMG);
  title('Original');
  
  figure;
  imshow(canvasNRC);
  title('Nucleo de reconstrucao constante (vizinho mais proximo)');

  figure;
  imshow(canvasNRT);
  title('Nucleo de reconstrucao triangular 2D (bilinear)');  
end