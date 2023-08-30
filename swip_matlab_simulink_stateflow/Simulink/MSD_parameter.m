% Initial Condition

m = 1;
b = 0.3;
k = 2;

% State-Space
A = [0 1; -k/m -b/m];
B = [0; 1/m];
C = [1 0];
D = 0;

% Trasnfer function
[Num, Den] = ss2tf(A, B, C, D);