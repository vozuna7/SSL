#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reconocedor.h"
#include <errno.h>
#include <stdbool.h>
#define estadoInicial 0
#define estadoDeRechazo 3
#define constanteNumerica 1
#define operador 2

FILE* abrirArchivo(char*,char*);
void cerrarArchivo(FILE*);
void escribir_en_archivo(FILE*,char*);
int es_reconocido(char);
void escribir_errores(char*,int);

int main() {
    FILE* archivo_entrada = abrirArchivo("entrada.txt","r");
    FILE* archivo_salida = abrirArchivo("salida.csv","w");
    char * linea = NULL;
    size_t len = 0;
    size_t cantidad_de_caracteres;
    int numero_de_linea = 1;

    fprintf(archivo_salida,"En el codigo, Token\n");
    while ((cantidad_de_caracteres = getline(&linea, &len, archivo_entrada)) != -1) {
        if(reconocer_expresion(linea)){
            escribir_en_archivo(archivo_salida,linea);
        }else{
            escribir_errores(linea,numero_de_linea);
        }
        numero_de_linea++;
    }
    free(linea);
    cerrarArchivo(archivo_entrada);
    cerrarArchivo(archivo_salida);
    return 0;
}
FILE* abrirArchivo(char* nombreArchivo, char* modo)
{
    FILE* archivo = fopen(nombreArchivo, modo);

    if (errno != 0)
    {
        char* tipoError = "Error al abrir el archivo ";
        char* mensajeError = (char*) malloc(1 + sizeof(char*) * (strlen(nombreArchivo) + strlen(tipoError)));
        strcpy(mensajeError, tipoError);
        strcat(mensajeError, nombreArchivo);
        perror(mensajeError);
        system("pause");
        exit(1);
    }

    return archivo;
}

void cerrarArchivo(FILE* archivo)
{
    fclose(archivo);
}
void escribir_en_archivo(FILE* archivo_salida, char* linea) {
            int i = 0;
            int estado_actual = estadoInicial;
            while(i < strlen(linea)) {
                if(es_espacio_o_tabulacion(linea[i])) {
                    i++;
                    continue;
                }
                estado_actual = leer_caracter(linea[i],estado_actual);
                switch (estado_actual)
                {
                case constanteNumerica:
                    fprintf(archivo_salida,"%c, Constante numerica\n",linea[i]);
                    break;
                case operador:
                    fprintf(archivo_salida,"%c, Operador\n",linea[i]);
                    break;
                }
            i++;
        }
        fprintf(archivo_salida,"\n");
}
void escribir_errores(char* linea, int numero_de_linea){
    for(int i = 0; i < strlen(linea) && linea[i]!= '\n'; i++){
            if(!es_espacio_o_tabulacion(es_espacio_o_tabulacion(linea[i])) && !es_reconocido(linea[i])){
                fprintf(stderr, "Error, el caracter %c no es reconocido. Linea %d, columna %d \n", linea[i], numero_de_linea, i);
            }
        }
}
int es_reconocido(char caracter) {
    return leer_caracter(caracter,estadoInicial)!=estadoDeRechazo;
}
