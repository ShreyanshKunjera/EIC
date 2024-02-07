#include "math.h"

int sum(int a, int b){
	return a+b;
}
int sub(int a, int b){
	return a-b;
}
int mul(int a, int b){
	return a*b;
}
double div(int a, int b) {
    if (b != 0) {
        return (double)a / b;
    } else {
        return 0; // Handle division by zero
    }
}


