% Flights
flight(flight1, source1, destination1, 8:00, 10:00).
flight(flight2, source2, destination2, 9:30, 11:30).
flight(flight3, source3, destination3, 11:00, 13:00).
% Add more flight facts as needed

% Cargo shipments
cargo(cargo1, source1, destination1, 8:30).
cargo(cargo2, source2, destination2, 10:00).
cargo(cargo3, source3, destination3, 12:00).
% Add more cargo facts as needed

% Predicate to find flights departing from a specific source
departing_flights(Source) :-
    flight(Flight, Source, _, StartTime, EndTime),
    write('Flight: '), write(Flight), write(' | Departure: '), write(StartTime), write(' | Arrival: '), write(EndTime), nl,
    fail.

% Predicate to find flights arriving at a specific destination
arriving_flights(Destination) :-
    flight(Flight, _, Destination, StartTime, EndTime),
    write('Flight: '), write(Flight), write(' | Departure: '), write(StartTime), write(' | Arrival: '), write(EndTime), nl,
    fail.

% Predicate to find cargo shipments with a specific source and destination
cargo_shipments(Source, Destination) :-
    cargo(Cargo, Source, Destination, StartTime),
    write('Cargo: '), write(Cargo), write(' | Source: '), write(Source), write(' | Destination: '), write(Destination), write(' | Departure: '), write(StartTime), nl,
    fail.

% User interaction
start :-
    write('Welcome to the flight and cargo schedule system!'), nl,
    repeat,
    write('What would you like to do?'), nl,
    write('1. Find departing flights from a specific source'), nl,
    write('2. Find arriving flights at a specific destination'), nl,
    write('3. Find cargo shipments with a specific source and destination'), nl,
    write('4. Exit'), nl,
    read(Choice),
    process_choice(Choice),
    Choice = 4,
    write('Goodbye!'), nl.

process_choice(1) :-
    write('Enter the source: '),
    read(Source),
    nl,
    write('Departing flights from '), write(Source), write(':'), nl,
    (   departing_flights(Source) ->
        true
    ;   write('No flights available from '), write(Source), nl
    ),
    nl.

process_choice(2) :-
    write('Enter the destination: '),
    read(Destination),
    nl,
    write('Arriving flights at '), write(Destination), write(':'), nl,
    (   arriving_flights(Destination) ->
        true
    ;   write('No flights available at '), write(Destination), nl
    ),
    nl.

process_choice(3) :-
    write('Enter the source: '),
    read(Source),
    write('Enter the destination: '),
    read(Destination),
    nl,
    write('Cargo shipments from '), write(Source), write(' to '), write(Destination), write(':'), nl,
    (   cargo_shipments(Source, Destination) ->
        true
    ;   
	write('No cargo shipments available from '), write(Source), write(' to '), write(Destination), nl
    ),
    nl.

process_choice(4).
