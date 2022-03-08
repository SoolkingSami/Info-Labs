adauga([], []).
adauga([X|R], L) :- L = [X|R1], adauga(R, R1).

adauga2([], L, L).
adauga2([X|R], L, L2) :- R1 = [X|L], adauga2(R, R1, L2).

numar(3).
numar(8).
numar(9).

program([X|_R], E, C, P) :- C1 is C+1, X=E, P=C1.
program([_X|R], E, C, P) :- C1 is C+1, program(R, E, C1, P).

pred([], _, []).
pred([N|R], M, Rez) :- N = M, pred(R, N, Rez).
pred([M|R], N, [M|Rez]) :- pred(R, N, Rez).

calc(N, K) :- I is N/2, K > I.
calc(N, K) :- R is N mod K, R \= 0, K1 is K + 1, calc(N, K1).

lista([],[]).
lista([X|R],[X|R1]) :- lista(R,R1).