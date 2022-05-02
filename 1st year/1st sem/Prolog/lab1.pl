% frate(dan, maria).

% Prolog admits predicates (facts and rules) which describe relationships
% family relationships

% fail/0 is used to force backtracking
% convention => (1) is predicate_name for (2)

% parinte/2
% (1) este parinte pt (2)

parinte(andrei, cristi).
parinte(andrei, elena).

parinte(cristi, adriana).
parinte(cristi, marius).
parinte(cristi, ovidiu).
parinte(cristi, alina).

parinte(elena, ana).
parinte(ana, george).

% barbat/1

barbat(andrei).
barbat(cristi).
barbat(marius).
barbat(ovidiu).
barbat(george).
barbat(dan).
barbat(marcel).
barbat(mihai).
barbat(ion).

% femeie/1

femeie(elena).
femeie(adriana).
femeie(ana).
femeie(ioana).
femeie(paula).
femeie(dana).
femeie(maria).
femeie(otilia).
femeie(alina).

% frate/2
% (1) este frate pt (2)

frate(X, Y) :- parinte(P, X), parinte(P, Y), barbat(X), X \= Y.

% sora/2
% (1) este sora pt (2)

sora(X, Y) :- parinte(P, X), parinte(P, Y), femeie(X), X \= Y.

% nepot/2
% (1) este nepot pt (2)

nepot(X, Y) :- parinte(P, X), parinte(Y, P).

% fiu/2
% (1) este fiu pt (2)

fiu(X, Y) :- parinte(Y, X), barbat(X).

% fiica/2
% (1) este fiica pt (2)

fiica(X, Y) :- parinte(Y, X), femeie(X).

% add cuplu and new people
% be careful at predicates with multiple definitions!!!

% cuplu/2
% (1) este sotia, iar (2) este sotul

cuplu(ioana, andrei).
cuplu(dana, cristi).
cuplu(adriana, dan).
cuplu(otilia, marius).
cuplu(maria, ovidiu).
cuplu(elena, mihai).
cuplu(ana, marcel).
cuplu(paula, george).
cuplu(alina, ion).

% (1) este sotul, iar (2) este sotia
cuplu(andrei, ioana).
cuplu(cristi, dana).
cuplu(dan, adriana).
cuplu(marius, otilia).
cuplu(ovidiu, maria).
cuplu(mihai, elena).
cuplu(marcel, ana).
cuplu(george, paula).
cuplu(ion, alina).

% soacra/2
% (1) este soacra pt (2)

% case 1: 
/*
         X
         |
    Y -- T

*/
soacra(X, Y) :- cuplu(T, Y), parinte(X, T), femeie(X).

% case 2:
/*
    X -- Z
         |
    Y -- T

*/
soacra(X, Y) :- cuplu(T, Y), parinte(Z, T), cuplu(Z, X), femeie(X).

% cumnat/2
% (1) este cumnat pt (2)

% case 1:
/*
    Y <--> T -- X

*/
cumnat(X, Y) :- sora(T, Y), cuplu(X, T), barbat(X).

% case 2:
/*
    Y -- T <--> X

*/
cumnat(X, Y) :- cuplu(T, Y), frate(X, T).

% case 3:
/*
    Y -- T <--> Z -- X

*/
cumnat(X, Y) :- cuplu(T, Y), sora(Z, T), cuplu(Z, X), barbat(X).

% ginere/2
% (1) este ginere pt (2)

% case 1:
/*
    Y
    |
    T -- X

*/
ginere(X, Y) :- fiica(T, Y), cuplu(T, X).

% case 2:
/*
    Y -- T
         |
    x -- Z 

*/
ginere(X, Y) :- cuplu(T, Y), fiica(Z, T), cuplu(Z, X).

/*
    X <--> Y: X este sora/frate cu Y
    X -- Y: X este in cuplu cu Y
    X
    | : X este parinte pt Y
    Y
*/