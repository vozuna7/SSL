#include <string.h>
#include "reconocedor.h"
#define estadoInicial Q0
#define estadoDeRechazo Q3
#define otro 2
#define operador 0
#define constanteNumerica 1

enum Estados {Q0,Q1,Q2,Q3};

int tabla_de_transiciones(int estado_actual, char carater_leido);
int es_operador(char caracter);
int es_constante_numerica(char caracter);
int es_espacio_o_tabulacion(char caracter);
                                   /*Op Const Otro */
int transiciones[4][3] =    {/*Q0*/ {Q2, Q1,  Q3},
                             /*Q1*/ {Q2, Q1,  Q3},
                             /*Q2*/ {Q2, Q1,  Q3},
                             /*Q3*/ {Q3, Q3,  Q3},
                            };

int leer_caracter(char caracter, int estado_actual) {
    return tabla_de_transiciones(estado_actual, caracter);
}
int reconocer_expresion(const char* expresion){
    int i = 0;
    int estado_actual = estadoInicial;
    while(estado_actual!=estadoDeRechazo && i < strlen(expresion) && expresion[i] != '\n') {
        if(!es_espacio_o_tabulacion(expresion[i])) {
            estado_actual = leer_caracter(expresion[i],estado_actual);
        }
        i++;
    }
    return estado_actual!=estadoDeRechazo && estado_actual!=estadoInicial;
}

int tabla_de_transiciones(int estado_actual, char carater_leido) {
    if(es_operador(carater_leido)) return transiciones[estado_actual][operador];
    if(es_constante_numerica(carater_leido)) return transiciones[estado_actual][constanteNumerica];
    return transiciones[estado_actual][otro];
}
int es_espacio_o_tabulacion(char caracter) {
    return caracter == ' ' || caracter == '\t';
}
int es_operador(char caracter) {
    return caracter == '+' || caracter == '-' || caracter == '/' || caracter == '*' || caracter == '(' || caracter == ')';
}
int es_constante_numerica(char caracter) {
    return caracter >= '0' && caracter <= '9';
}
