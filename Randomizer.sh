gcc -o Randomizer.o -c Randomizer.c
gcc -o Accidents.o -c Accidents.c
gcc -o Persons.o -c Persons.c
gcc -o DataStructs.o -c DataStructs.c

gcc -o FinalRandomizer Randomizer.o Accidents.o Persons.o DataStructs.c
