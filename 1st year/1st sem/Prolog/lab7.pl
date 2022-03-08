% print list
print([]).
print([X|T]) :- write(X), write(" "), print(T).

% check if a given element belongs to a list
belong(X, [X | _]).
belong(Y, [X | T]) :- X \= Y, belong(Y, T).

% compute the length of a list
len([], 0).
len([_ | T], L) :- len(T, L1), L is L1 + 1.

% get the last element of a list
last([X | []], X).
last([_ | T], U) :- last(T, U).

% compute the sum of all elements of a list
sum([], 0).
sum([X | T], S) :- sum(T, S1), S is X + S1.

% compute the product of all elements of a list
prod([], 1).
prod([X | T], P) :- prod(T, P1), P is X * P1.

% compute the sum of all positive elements of a list
sum_pos([], 0).
sum_pos([X | T], S) :- X >= 0, sum_pos(T, S1), S is X + S1.
sum_pos([X | T], S) :- X < 0, sum_pos(T, S).

% compute the sum of all even elements of a list
sum_even([], 0).
sum_even([X | T], S) :- X mod 2 =:= 0, sum_even(T, S1), S is X + S1.
sum_even([X | T], S) :- X mod 2 =\= 0, sum_even(T, S).

% compute the average of all elements of a list
avg([], 0).
avg([X | T], A) :- sum(T, S1), S is X + S1, len(T, L1), L is 1 + L1, A is S / L.

% compute the maximum of all elements of a list
max_list([X], X).
max_list([X | T], M) :- max_list(T, M1), M is max(X, M1).

% find the position of an element in a list
pos([X | _], X, 1).
pos([_ | T], X, P) :- pos(T, X, P1), P is P1 + 1.

% find the position of the maximum element in a list
max_list([X | Xs], Max, Index):-
    max_list(Xs, X, 0, 0, Max, Index).

max_list([], OldMax, OldIndex, _, OldMax, OldIndex).

max_list([X | Xs], OldMax, _, CurrentIndex, Max, Index):-
    X > OldMax,
    NewCurrentIndex is CurrentIndex + 1,
    NewIndex is NewCurrentIndex,
    max_list(Xs, X, NewIndex, NewCurrentIndex, Max, Index).

max_list([X | Xs], OldMax, OldIndex, CurrentIndex, Max, Index):-
    X =< OldMax,
    NewCurrentIndex is CurrentIndex + 1,
    max_list(Xs, OldMax, OldIndex, NewCurrentIndex, Max, Index).

% compute the maximum of all elements of a list by removing all elements smaller than the maximum
% max_rem([X], [X], X).
% max_rem([X, Y | T], [X | T1], M) :- X > Y, max_rem(T, T1, M).
% max_rem([X, Y | T], [Y | T1], M) :- X =< Y, max_rem(T, T1, M).

% delete the first occurrence of a given element from a list
delete(X, [X | T], T).
delete(X, [Y | T], [Y | T1]) :- X \= Y, delete(X, T, T1).

% delete all ocurrences of a given element from a list
delete_all(_, [], []).
delete_all(X, [X | T], T1) :- delete_all(X, T, T1).
delete_all(X, [Y | T], [Y | T1]) :- X \= Y, delete_all(X, T, T1).

% copy elements from one list to another
copy([], []).
copy([X | T], [X | T1]) :- copy(T, T1).

% copy even elements from one list to another
copy_even([], []).
copy_even([X | T], [X | T1]) :- X mod 2 =:= 0, copy_even(T, T1).
copy_even([X | T], T1) :- X mod 2 =\= 0, copy_even(T, T1).

% reverse elements of a list
reverse1([], []).
reverse1([X | T], R) :- reverse1(T, R1), append(R1, [X], R).

% reverse elements of a list without using append
list_reverse([], Lt, Lt).
list_reverse([X | T], Lt, Linv) :- Lt1 = [X | Lt], list_reverse(T, Lt1, Linv).

% count positive elements of a list
count_positive([], 0).
count_positive([X | T], N) :- X >= 0, count_positive(T, N1), N is N1 + 1.
count_positive([X | T], N) :- X < 0, count_positive(T, N).