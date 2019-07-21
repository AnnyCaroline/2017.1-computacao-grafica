#{
P0x P0y P0'x P0'y
P1x P1y P1'x P1'y
P2x P2y P2'x P2'y
P3x P3y P3'x P3'y
#}

IMG = imread("woman.png");
imshow(IMG);

#Matriz do slide
P = [
  0 0 2 1
  0 1 3 5
  1 1 6 6
  1 0 7 2
];

#Matriz dada no exercicio
P = [
 1   1   50  50; 
 1   350 1   300; 
 390 1   390 1;
 390 350 300 350
];

#Matriz que eu esperava
P = [
 1   1   50  50; 
 1   350 1   300; 
 390 350 300 350;
 390 1   390 1
];


figure
axis([0, 400, 0, 400]);
set(gca, "ygrid", "on");
set(gca, "xgrid", "on");
line ( [P(1,1) P(2,1)] , [P(1,2) P(2,2)], "linestyle", "-", "color", "b");
line ( [P(2,1) P(3,1)] , [P(2,2) P(3,2)], "linestyle", "-", "color", "b");
line ( [P(3,1) P(4,1)] , [P(3,2) P(4,2)], "linestyle", "-", "color", "b");
line ( [P(4,1) P(1,1)] , [P(4,2) P(1,2)], "linestyle", "-", "color", "b");


L = [ #observaç~oes
  P(1,3)
  P(1,4)
  P(2,3)
  P(2,4)
  P(3,3)
  P(3,4)
  P(4,3)
  P(4,4)
];


A = [ #coeficientes
  P(1,1) P(1,2) 1 0      0      0 -P(1,1)*P(1,3) -P(1,2)*P(1,3)
  0      0      0 P(1,1) P(1,2) 1 -P(1,1)*P(1,4) -P(1,2)*P(1,4)
  P(2,1) P(2,2) 1 0        0    0 -P(2,1)*P(2,3) -P(2,2)*P(2,3)
  0      0      0 P(2,1) P(2,2) 1 -P(2,1)*P(2,4) -P(2,2)*P(2,4)
  P(3,1) P(3,2) 1 0        0    0 -P(3,1)*P(3,3) -P(3,2)*P(3,3)
  0      0      0 P(3,1) P(3,2) 1 -P(3,1)*P(3,4) -P(3,2)*P(3,4)
  P(4,1) P(4,2) 1 0        0    0 -P(4,1)*P(4,3) -P(4,2)*P(4,3)
  0      0      0 P(4,1) P(4,2) 1 -P(4,1)*P(4,4) -P(4,2)*P(4,4)
];

x = inv(A'*A) * A' * L
T = [
  x(1:3)'
  x(4:6)'
  x(7:8)' 1
];

P
# acha a imagem transformada e faz o canvas dela
figT = [[0;0;0] [0;0;0] [0;0;0] [0;0;0]];

figT(:,1) = T*[P(1,1:2) 1]';
figT(:,1) = figT(:,1)/figT(3,1)

figT(:,2) = T*[P(2,1:2) 1]';
figT(:,2) = figT(:,2)/figT(3,2)

figT(:,3) = T*[P(3,1:2) 1]';
figT(:,3) = figT(:,3)/figT(3,3)

figT(:,4) = T*[P(4,1:2) 1]';
figT(:,4) = figT(:,4)/figT(3,4)

figure;
set(gca, "ygrid", "on");
set(gca, "xgrid", "on");
line (figT(1,1:2), figT(2,1:2), "linestyle", "-", "color", "b");
line (figT(1,2:3), figT(2,2:3), "linestyle", "-", "color", "b");
line (figT(1,3:4), figT(2,3:4), "linestyle", "-", "color", "b");
line ([figT(1,4) figT(1,1)] , [figT(2,4) figT(2,1)], "linestyle", "-", "color", "b");

#Calcula canvas
maxX = max(figT(1,:));
maxY = max(figT(2,:));
canvas = zeros(maxX, maxY);
######################

# Calcula T inverso
Tinv = inv(T);

#######
