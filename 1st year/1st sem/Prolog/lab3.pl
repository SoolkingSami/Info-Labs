sum(A, B, S) :- S is A + B.

numar(3).
numar(4).
numar(5).

inc(A, I) :- I is A + 1.
pow2(A, P) :- P is A * A.

max2(A, B, N) :- N is A, A >= B.
max2(A, B, N) :- N is B, B > A.

max3(A, B, C, N) :- max2(A, B, P), max2(P, C, V), N is V.

abs1(A, M) :- A >= 0, M is A.
abs1(A, M) :- A < 0, M is -A.

% 0 - even, 1 - odd
parity(X, R) :- R is X mod 2.

positivity(X, S) :- X >= 0, S is 1.
positivity(X, S) :- X < 0, S is 0.

f1(X, P) :- P is 3 * X * X - 4.
f2(X, P) :- P is 4 * X * X + 2 * X - 3.
f3(X, P) :- X > 0, P is X - 1.
f3(X, P) :- X =< 0, P is 0.
f4(X, P) :- abs1(X, M), P is M - 4.
f5(X, P) :- abs1(X - 3, M), P is 2 * M.
f6(X, P) :- X > 10, P is X * X + 2.
f6(X, P) :- X =< 10, P is X - 4.
f7(X, P) :- parity(X, R), R =:= 0, P is 2 * X * X + 1.
f7(X, P) :- parity(X, R), R =:= 1, P is X - 7.