#include <stdint.h>
#include <stdio.h>

// Notación Qm.n: m bits para la parte entera, n bits para la parte fraccionaria
#define n 10  // Tu resolución actual
#define fp2fx(f) ((int32_t)((f) * (1 << n)))
#define fx2fp(q) ((float)(q) / (float)(1 << n))

int32_t truncation(int64_t X){
    return (int32_t)(X >> n);
}

int main(){
    float X[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float Y[5] = {6.6, 7.7, 8.8, 9.9, 10.10};

    int32_t X_fx[5] = {0}, Y_fx[5] = {0};

    for(int i = 0; i < 5; i++){
        X_fx[i] = fp2fx(X[i]);
        Y_fx[i] = fp2fx(Y[i]);
    }

    int32_t acum_32a = 0, acum_32b = 0;
    int64_t acum_64 = 0;

    for(int i = 0; i < 5; i++){
        acum_32a += (int32_t ) ( truncation( (int64_t)(X_fx[i] * Y_fx[i] ) ));
        acum_64 += (int64_t) ( (int64_t) (X_fx[i] * Y_fx[i] ) );
    }   

    acum_32b += (int32_t) acum_64;

    double dX[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double dY[5] = {6.6, 7.7, 8.8, 9.9, 10.10};

    double acum_double = 0.0;

    for(int i = 0; i < 5; i++){
        acum_double += dX[i] * dY[i];
    }

    printf("Acumulado con truncation: %f\n", fx2fp(acum_32a));
    printf("Acumulado con acumulación en 64 bits: %f\n", fx2fp(acum_64));
    printf("Acumulado con acumulación en 32 bits: %f\n", fx2fp(acum_32b));
    printf("Acumulado con double: %f\n", acum_double);

    return 0;
}