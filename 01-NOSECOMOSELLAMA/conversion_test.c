#include <assert.h>
#include "conversion.h"

int main(void){
    assert(fahrenheit(20)==68);
    assert(fahrenheit(-10)==14);
    assert(celsius(50)==10);
    assert(celsius(-4)==-20);
    return 0;
}