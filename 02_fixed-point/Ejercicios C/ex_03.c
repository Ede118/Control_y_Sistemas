#include <stdint.h>
#include <stdio.h>

// Notación Qm.n: m bits para la parte entera, n bits para la parte fraccionaria

#define n 10  // Tu resolución actual
#define fp2fx(f) ((int32_t)((f) * (1 << n)))
#define fx2fp(q) ((float)(q) / (float)(1 << n))

int32_t truncation(int64_t X){
    return (int32_t)(X >> n);
}

int32_t rounding(int64_t X){
    return truncation(X + (1 << (n - 1)));
}

void calcular(double num1, double num2){

    int32_t num1_Q21_10 = fp2fx(num1);
    int32_t num2_Q21_10 = fp2fx(num2);
    
    int64_t product_Q21_10 = (int64_t)(num1_Q21_10 * num2_Q21_10); 
    double product = num1 * num2;
    
    int32_t product_trunc = truncation(product_Q21_10);
    int32_t product_round = rounding(product_Q21_10);
    
    char buffer[100]; // Buffer temporal para armar cada línea

    printf("╔══════════════════════════════════════════════════════╗\n");
    
    printf("║ %-52s ║\n", "Valores Reales:");
    sprintf(buffer, "  num1: %.11f", num1); printf("║ %-52s ║\n", buffer);
    sprintf(buffer, "  num2: %.11f", num2); printf("║ %-52s ║\n", buffer);
    
    printf("║ %-52s ║\n", "Resultados:");

    sprintf(buffer, "   (double) num1*num2: %.11f", product);
    printf("║ %-52s ║\n", buffer);
    
    sprintf(buffer, "   truncation(num1*num2): %.11f", fx2fp(product_trunc));
    printf("║ %-52s ║\n", buffer);
    
    sprintf(buffer, "   rounding(num1*num2): %.11f", fx2fp(product_round));
    printf("║ %-52s ║\n", buffer);
    
    printf("╚══════════════════════════════════════════════════════╝\n");
}


int main(void){

    // Se pasa del rango de Q21.11
    calcular(2000000, 10);
    // Multiplicación de números negativos
    calcular(-1, -10);
    // Multiplicación con 10 números después del punto decimal
    calcular(1.0000000001, 2);
    // Multiplicación dentro del rango de Q21.11
    calcular(100, 48);
    // Multiplicación con 2 números con 5 dígitos después del punto decimal
    calcular(1.11111, 2.55555);
    // Multiplicación arbitraria
    calcular(46.1948, 781.4874);
    
    return 0;
}
