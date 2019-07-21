#Po = [1 2 2 1; 1 1 2 2; 1 1 1 1]; #quadrado
#Po = [2 6 6 2; 2 2 4 4; 1 1 1 1]; #retangulo
#Po = [1 2 1; 1 1 2; 1 1 1]; #triangulo
Po = [1 2 2 1.5 1; 1 1 2 1.5 2; 1 1 1 1 1]; #bandeirinha

a = pi/2;

desenhaPoligono(Po);

desenhaPoligono(rotacionaPoligono(Po, a));

animaPoligono(0, 5, Po, 0.01, 0.05); #a_inicial, a_final, Po, pause_time, delta_a