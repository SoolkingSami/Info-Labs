% check if a list is sorted

is_sorted([]).
is_sorted([_]).
is_sorted([X, Y | T]) :- 
    X =< Y,
    is_sorted([Y | T]).

% insert an element at a given position

insert_at([], _, _, _).
insert_at([H | T], X, 1, [X | [H | T]]).
insert_at([H | T], X, N, [H | R]) :- 
    N > 1,
    N1 is N - 1,
    insert_at(T, X, N1, R).

% delete the element before a given one

delete_before([], _, []).
delete_before([Y], _, [Y]).
delete_before([_, X | T], X, [X | R]) :-
    delete_before(T, X, R).
delete_before([H | T], X, [H | R]) :- 
    delete_before(T, X, R).

% insert a certain element after a given one

insert_after([], _, _, []).
insert_after([X | T], X, Y, [X | [Y | R]]) :- 
    insert_after(T, X, Y, R).
insert_after([H | T], X, Y, [H | R]) :- 
    H \= Y,
    insert_after(T, X, Y, R).