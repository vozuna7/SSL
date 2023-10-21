#include <string.h>
#include "reconocedor.h"
#define estadoInicial Q0
#define estadoDeRechazo Q3
#define otro 2
#define operador 0
#define constanteNumerica 1

enum Estados {Q0,Q1,Q2,Q3};

int tabla_de_transiciones(int estado_actual, char carater_leido);
int es_espacio_o_tabulacion(char caracter);
                                   /*Op Const Otro */
int transiciones[4][3] =    {/*Q0*/ {Q2, Q1,  Q3},
                             /*Q1*/ {Q2, Q1,  Q3},
                             /*Q2*/ {Q2, Q1,  Q3},
                             /*Q3*/ {Q3, Q3,  Q3},
                            };

int reconocer_caracter(char caracter, int estado_actual) {
    return tabla_de_transiciones(estado_actual, caracter);
}
int reconocer_expresion(const char* expresion){
    int i = 0;
    int estado_actual = estadoInicial;
    while(estado_actual!=estadoDeRechazo && i < strlen(expresion)) {
        if(!es_espacio_o_tabulacion(expresion[i])) {
            estado_actual = reconocer_caracter(expresion[i],estado_actual);
        }
        i++;
    }
    return estado_actual!=estadoDeRechazo;
}

int tabla_de_transiciones(int estado_actual, char carater_leido) {
    if(carater_leido == '+' || carater_leido == '-' || carater_leido == '/' || carater_leido == '*') return transiciones[estado_actual][operador];
    if(carater_leido >= '0' && carater_leido <= '9') return transiciones[estado_actual][constanteNumerica];
    return transiciones[estado_actual][otro];
}
int es_espacio_o_tabulacion(char caracter) {
    return caracter == ' ' || caracter == '\t';
}
