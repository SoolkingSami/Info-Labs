fac(0, F, F).

fac(N, A, F) :-
    N > 0,
    A1 is N * A,
    N1 is N - 1,
    fac(N1, A1, F).
