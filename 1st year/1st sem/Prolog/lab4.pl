ec(A,B,X):- A\=0, X is -B/A.
ec(A,B,X):- A=0, writeln('nu se poate').

ec2(A,B,C,X1,X2):- A=0,B=0,writeln('Imposibil.').
ec2(A,B,C,X1,X2):- A=0,B\=0,writeln('Ec de gr 1'),X1 is -C/B.
ec2(A,B,C,X1,X2):- A\=0,B\=0,D is B*B-4*A*C,D>0, X1 is (-B-sqrt(D))/(2*A),X2 is (-B+sqrt(D))/(2*A).
ec2(A,B,C,X1,X2):- A\=0,B\=0,D is B*B-4*A*C,D=0, X1 is -B/(2*A),X2=X1.
ec2(A,B,C,X1,X2):- A\=0,B\=0,D is B*B-4*A*C,D<0, writeln('Nu are solutii reale').

elev(ion,4).
elev(marius,8).
elev(adriana,3).
elev(carmen,10).

stare(X):-elev(X,Y),Y>4,writeln('promovat').
stare(X):-elev(X,Y),Y<5,writeln('nepromovat').

discuta(A,B):-cunoaste(A,B).
discuta(A,B):-cunoaste(A,C),discuta(C,B).

cunoaste(maria,ana).
cunoaste(ana,mircea).
cunoaste(mircea,mihai).

factorial1(1,1).
factorial1(N,F):-N1 is N-1,factorial1(N1,F1),F is F1*N.

factorial2(1,P,F):-F=P.
factorial2(N,P,F):-P1 is P*N, N1 is N-1,factorial2(N1,P1,F).

sumaN(1,1).
sumaN(N,F):-N1 is N-1,sumaN(N1,F1),F is F1+N.