all: test main

compilar_main: reconocedor_automata.o
	cc main.c reconocedor_automata.o -o programa_main

reconocedor_automata.o: reconocedor_automata.c
	cc -c reconocedor_automata.c -o reconocedor_automata.o

compilar_test: reconocedor_automata.o
	cc tests.c reconocedor_automata.o -o programa_tests

test: compilar_test
	./programa_tests

main: compilar_main
	./programa_main

clean: 
	rm -f *.o programa_main programa_tests