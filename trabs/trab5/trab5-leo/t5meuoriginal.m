#{
P0x P0y P0'x P0'y
P1x P1y P1'x P1'y
P2x P2y P2'x P2'y
P3x P3y P3'x P3'y
#}


#{
#Matriz do slide
P = [
  0 0 2 1
  0 1 3 5
  1 1 6 6
  1 0 7 2
];
#}


% Slide 109 - Dados do problema de exemplo
P = [2 3 6 7
     1 5 6 2
     1 1 1 1];
     
M = [0 0 1 1
     0 1 1 0
     1 1 1 1];

% Slide 110 - Matrizes L e A  
L = [
  P(1,1)
  P(2,1)
  P(1,2)
  P(2,2)
  P(1,3)
  P(2,3)
  P(1,4)
  P(2,4)
];

A = [ M(1,1)  M(2,1)  1 0       0       0 -M(1,1)*P(1,1) -M(2,1)*P(1,1)
      0       0       0 M(1,1)  M(2,1)  1 -M(1,1)*P(2,1) -M(2,1)*P(2,1)
      M(1,2)  M(2,2)  1 0       0       0 -M(1,2)*P(1,2) -M(2,2)*P(1,2)
      0       0       0 M(1,2)  M(2,2)  1 -M(1,2)*P(2,2) -M(2,2)*P(2,2)
      M(1,3)  M(2,3)  1 0       0       0 -M(1,3)*P(1,3) -M(2,3)*P(1,3)
      0       0       0 M(1,3)  M(2,3)  1 -M(1,3)*P(2,3) -M(2,3)*P(2,3)
      M(1,4)  M(2,4)  1 0       0       0 -M(1,4)*P(1,4) -M(2,4)*P(1,4)
      0       0       0 M(1,4)  M(2,4)  1 -M(1,4)*P(2,4) -M(2,4)*P(2,4)
];

% Slide 113 - Calculo de x
x = inv(A'*A) * A' * L;

% Transformando linha em coluna (ou o contrario, sei la)
T = [x(1:3)'; x(4:6)'; cat(1, x(7:8), [1])'];
Ti = inv(T);

% Img deve ser em escala de cinza
img = imread('woman.png');

% Não é plano cartesiano - 0x0 = top_left
top_left = T * [1;1;1];
top_left = abs(top_left./top_left(3));

top_right = T * [columns(img);1;1];
top_right = abs(top_right./top_right(3));

bottom_left = T * [1;rows(img);1];
bottom_left = abs(bottom_left./bottom_left(3));

bottom_right = T * [columns(img);rows(img);1];
bottom_right = abs(bottom_right./bottom_right(3));

borda = [top_left'; top_right'; bottom_left'; bottom_right']
max(borda(:, 1));
max(borda(:, 2));





