sumOnNAcc(1, Acc, Acc).
sumOnNAcc(N, Acc, Res) :- AccNew is Acc + 1/N, N1 is N-1, sumOnNAcc(N1, AccNew, Res).

fibo(1, 1).
fibo(2, 1).
fibo(N, F) :- N1 is N-1, N2 is N-2, fibo(N1, F1), fibo(N2, F2), F is F1 + F2.

fiboAcc(1, N, _, N).
fiboAcc(N, F1, F2, Res) :-
    N > 0,
    N1 is N-1,
    Fnew is F1 + F2,
    fiboAcc(N1, Fnew, F1, Res).

pow(1, N, N).
pow(M, N, Res) :- M1 is M-1, pow(M1, N, Rnew), Res is Rnew * N.

powAcc(0, _, Acc, Acc).
powAcc(M, N, Acc, Res) :- M1 is M-1, AccNew is Acc * N, powAcc(M1, N, AccNew, Res).

ackermann(0, N, Res) :- Res is N+1.
ackermann(M, 0, Res) :- M1 is M-1, ackermann(M1, 1, R1), Res is R1.
ackermann(M, N, Res) :- M1 is M-1, N1 is N-1, ackermann(M, N1, R1), ackermann(M1, R1, R2), Res is R2.

cmmdc(A, 0, Res) :- Res is A.
cmmdc(A, B, Res) :- Rmod is A mod B, cmmdc(B, Rmod, R1), Res is R1.

gen(0) :- write(0), write(" ").
gen(N) :- N1 is N-1, gen(N1), write(N), write(" ").

isDiv(N, K, Res) :- Res is N mod K.
genDiv(N, N, 0) :- write(N), write(" ").
genDiv(N, C, 0) :- write(C), write(" "), C1 is C+1, isDiv(N, C1, R1), genDiv(N, C1, R1).
genDiv(N, C, _) :- C1 is C+1, isDiv(N, C1, R1), genDiv(N, C1, R1).
genDivMain(N) :- genDiv(N, 1, 0).

getParity(N, Res) :- Res is N mod 2.
genEven(N, N, 0) :- write(N), write(" ").
genEven(N, N, _).
genEven(N, C, 0) :- write(C), write(" "), C1 is C+1, getParity(C1, R1), genEven(N, C1, R1).
genEven(N, C, _) :- C1 is C+1, getParity(C1, R1), genEven(N, C1, R1).
genEvenMain(N) :- genEven(N, 0, 0).