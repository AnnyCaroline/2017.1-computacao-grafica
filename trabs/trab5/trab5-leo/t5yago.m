
% Author: Yago

function invtransformation()
  img_path = 'Coins.png';
  img = imread(img_path);
  % defining egdes of image
  e = [
  1 1 50 50
  1 size(img, 2) 1 300
  size(img, 1) 1 390 1
  size(img, 1) size(img, 2) 300 350
  ];
  [dimg1 dimg2] = deform(img_path, e);
end



function [dimg1 dimg2] = deform(img_path, egdes_matrix)
  pkg load image;

  e = egdes_matrix;

  L = [];
  for i=1:length(e)
    L = [L; e(i, 3); e(i, 4)];
  end

  A = [
  e(1,1)  e(1,2)  1 0       0       0 -e(1,1)*e(1,3)  -e(1,2)*e(1,3)
  0       0       0 e(1,1)  e(1,2)  1 -e(1,1)*e(1,4)  -e(1,2)*e(1,4)
  e(2,1)  e(2,2)  1 0       0       0 -e(2,1)*e(2,3)  -e(2,2)*e(2,3)
  0       0       0 e(2,1)  e(2,2)  1 -e(2,1)*e(2,4)  -e(2,2)*e(2,4)
  e(3,1)  e(3,2)  1 0       0       0 -e(3,1)*e(3,3)  -e(3,2)*e(3,3)
  0       0       0 e(3,1)  e(3,2)  1 -e(3,1)*e(3,4)  -e(3,2)*e(3,4)
  e(4,1)  e(4,2)  1 0       0       0 -e(4,1)*e(4,3)  -e(4,2)*e(4,3)
  0       0       0 e(4,1)  e(4,2)  1 -e(4,1)*e(4,4)  -e(4,2)*e(4,4)
  ];

  x = inv(A'*A)*A'*L;
  T = [x(1:3)'; x(4:6)'; cat(1, x(7:8), [1])'];
  Ti = inv(T);
 
 
  img = imread(img_path);
  
  img_band = img(:, :, 1);
  % getting borders of img_band (tl = top-left, tr = top-right, bl = bottom-left, br = bottom-right)
  tl = T * [1;1;1];
  tl = tl./tl(3);
  tr = T * [columns(img_band);1;1];
  tr = tr./tr(3);
  bl = T * [1;rows(img_band);1];
  bl = bl./bl(3);
  br = T * [rows(img_band);columns(img_band);1];
  br = br./br(3);
  b = [tl'; tr'; bl'; br'];
  lines = ceil(max(b(:, 1)) - min(b(:, 1))) + 1;
  cols = ceil(max(b(:, 2)) - min(b(:, 2))) + 1;
  dimg1 = uint8(zeros(lines, cols, size(img, 3)));
  dimg2 = uint8(zeros(lines, cols, size(img, 3)));
  for k=1:size(img, 3)
    img_band = img(:, :, k);
    for i=1:lines
      for j=1:cols
        p = Ti * [i; j; 1];
        p = p./p(3);
        if (p(1) < 1 || p(1) > rows(img_band) || p(2) < 1 || p(2) > columns(img_band))
          continue;
        end
        % dimg1: Vizinho mais proximo
        nnp = round(p);
        if (!(nnp(1) < 1 || nnp(1) > rows(img_band) || nnp(2) < 1 || nnp(2) > columns(img_band)))
          dimg1(i, j, k) = img_band(nnp(1), nnp(2));
        end
        
        % dimg2: nucleo de reconstrução triangular 2D (bilinear)        
        trval = triang_reconst(img_band, p(1), p(2));
        dimg2(i, j, k) = trval;
      end
    end
  end
  
  figure;
  imshow(img);
  title('Original');
  
  figure;
  imshow(dimg1);
  title('Vizinho mais proximo');
  
  figure;
  imshow(dimg2);
  title('Nucleo de reconstrucao triangular 2D');
end

function fc = triang_reconst(m, x, y)
  j = floor(x);
  k = floor(y);
  u = x - j;
  v = y - k;
  fa = (1-v)*m(j,k) + v*m(j,k+1);
  fb = (1-v)*m(j+1,k) + v*m(j+1,k+1);
  fc = (1-u)*fa + u*fb;
end