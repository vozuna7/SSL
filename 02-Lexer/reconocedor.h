#ifndef __RECONOCEDOR_H__
#define __RECONOCEDOR_H__
int leer_caracter(const char caracter,int estado_actual);
int reconocer_expresion(const char* expresion);
int es_espacio_o_tabulacion(char caracter);
#endif