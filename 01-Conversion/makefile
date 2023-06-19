tablasDeConversion: conversion.o
	gcc tablasDeConversion.c conversion.o -o tablasDeConversion
conversion.o: conversion.c
	gcc -c conversion.c -o conversion.o
conversion_test: conversion.o
	gcc conversion_test.c conversion.o -o conversion_test
tests: conversion_test
	./conversion_test

# clean:
# rm -rf main conversor_test *.o