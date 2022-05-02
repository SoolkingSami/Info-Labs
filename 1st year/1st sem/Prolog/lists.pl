% return the length of a list
list_length([], 0).

list_length([_ | Tail], N) :- list_length(Tail, N1), N is N1 + 1.


% return the list yielded by the concatenation of two given lists
list_concat([], L, L).

list_concat([X1 | L1], L2, [X1 | L3]) :- list_concat(L1, L2, L3).


% delete some value from given list (only one occurence)
list_delete(X, [X], []).

list_delete(X, [X | L], L).

list_delete(X, [Y | L1], [Y | L2]) :- list_delete(X, L1, L2).

% delete all occurences of some value from given list
list_remove_all(_, [], []).

% notice the cut (!) operator
list_remove_all(X, [X | T], L) :- list_remove_all(X, T, L), !.

list_remove_all(X, [Y | L1], [Y | L2]) :- list_remove_all(X, L1, L2).