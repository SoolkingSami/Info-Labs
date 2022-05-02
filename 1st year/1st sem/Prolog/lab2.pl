copii(X) :- parinte(X, Copil), writeln(Copil), fail.
copii(_X).
nepoti(Y) :- parinte(Y, Copil), parinte(Copil, Nepot), writeln(Nepot), fail.
nepoti(_Y).

descendenti(X) :- copii(X), nepoti(X).

% DFS house

% connections
is_connection(birou, hol).
is_connection(birou, bucatarie).

is_connection(hol, curte).
is_connection(hol, sufragerie).
is_connection(hol, birou).

is_connection(sufragerie, hol).
is_connection(sufragerie, bucatarie).

is_connection(bucatarie, sufragerie).
is_connection(bucatarie, subsol).
is_connection(bucatarie, birou).

is_connection(subsol, bucatarie).

check_outdoor(Room) :- Room \= curte.

% objects
exist(masa, birou).
exist(calculator, birou).
exist(scaun, birou).

exist(cuier, hol).

exist(televizor, sufragerie).
exist(canapea, sufragerie).
exist(fotolii, sufragerie).
exist(biblioteca, sufragerie).

exist(aragaz, bucatarie).
exist(frigider, bucatarie).
exist(masa, bucatarie).
exist(scaune, bucatarie).
exist(biscuiti, bucatarie).
exist(mere, bucatarie).

exist(masina_de_spalat, subsol).
exist(rufe_murdare, subsol).

% start/1
show_room(Room) :- write('Te afli in '), writeln(Room).
show_objs(Room) :- writeln('Aici poti vedea: '), exist(Obiect, Room), writeln(Obiect), fail.
show_objs(_Room).
show_next(Room) :- writeln('Unde vrei sa mergi?'), is_connection(Room, Next_Room), writeln(Next_Room), fail.
show_next(_Room).

start(Room) :- show_room(Room),
               show_objs(Room),
               show_next(Room),
               read(Next), check_outdoor(Next), start(Next).