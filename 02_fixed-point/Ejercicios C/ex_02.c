/*Ejercicio2
Cree 2 funciones en C:
1. Una función para pasar de punto fijo a punto flotante, fx2fp( ).
2. Una función para pasar de punto flotante a punto fijo, fp2fx( ).
3. Verifique el correcto funcionamiento haciendo,
b = fx2fp( fp2fx( 2.4515) )
4. Compare b con 2.4515 para Q23.8 y Q21.10.*/


#include <stdio.h>
#include <stdint.h>
#include <math.h>

int32_t fp2fx(double x, int n) // Convierte un número de punto flotante a formato fijo Qm.n
{
    return (int32_t)(x * (1 << n));
}

double fx2fp(int32_t x_fx, int n) // Convierte un número de formato fijo Qm.n a punto flotante
{
    return (double)x_fx / (double)(1 << n);
}

int main(void)
{
    double x = 2.4515;
    double b_q23_8, b_q21_10;  // Variables para almacenar los valores convertidos de formato fijo a punto flotante
    int32_t fx_q23_8, fx_q21_10;  // Variables para almacenar los valores convertidos de punto flotante a formato fijo

    // Q23.8
    fx_q23_8 = fp2fx(x, 8); 
    b_q23_8 = fx2fp(fx_q23_8, 8);

    // Q21.10
    fx_q21_10 = fp2fx(x, 10); 
    b_q21_10 = fx2fp(fx_q21_10, 10); 

    printf("Valor original: %.10f\n\n", x);

    printf("Q23.8:\n");
    printf("  fijo = %d\n", fx_q23_8);
    printf("  b = %.10f\n", b_q23_8);
    printf("  error = %.10f\n\n", b_q23_8 - x);

    printf("Q21.10:\n");
    printf("  fijo = %d\n", fx_q21_10);
    printf("  b = %.10f\n", b_q21_10);
    printf("  error = %.10f\n", b_q21_10 - x);

    return 0;
}