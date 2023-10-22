#include <assert.h>
#include <stdbool.h>
#include "reconocedor.h"

int main(void) {
assert(reconocer_expresion("-0 14") == true);
assert(reconocer_expresion("24-10-") == true);
assert(reconocer_expresion("2") == true);
assert(reconocer_expresion("-") == true);
assert(reconocer_expresion("2-") == true);
assert(reconocer_expresion("soy un marmota") == false);
assert(reconocer_expresion("2*  4+(3-5)") == true);
assert(reconocer_expresion("2* 4+1") == true);
assert(reconocer_expresion("5/4") == true);
assert(reconocer_expresion("((()))") == true);
assert(reconocer_expresion("AA") == false);
assert(reconocer_expresion("((((a") == false);
assert(reconocer_expresion("1+3+5//B") == false);
assert(reconocer_expresion("") == false);
assert(reconocer_expresion("1 1 1 1") == true);
return 0;
}

/*
*Par correr los tests:
* gcc -o test_de_reconocimiento tests.c reconocedor_automata.c 
* ./test_de_reconocimiento
* Si pasan no va a dar ningun resultado, si falla alguno va a tirar un error
*/