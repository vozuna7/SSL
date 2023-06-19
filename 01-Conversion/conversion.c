#include "conversion.h"

double fahrenheit(double celsius){
    return celsius*1.8+32;
}
double celsius(double fahrenheit){
    return (fahrenheit-32)/1.8;
}