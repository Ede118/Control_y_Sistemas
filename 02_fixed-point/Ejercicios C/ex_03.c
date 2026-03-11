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

void calcular(int32_t a, int32_t b){
    // Multiplicamos en 64 bits para evitar overflow antes de truncar
    int64_t product = (int64_t)a * b; 
    
    double real_a = fx2fp(a);
    double real_b = fx2fp(b);
    double c_teorico = real_a * real_b;
    
    int32_t c_trunc = truncation(product);
    int32_t c_round = rounding(product);
    
    char buffer[100]; // Buffer temporal para armar cada línea

    printf("╔══════════════════════════════════════════════════════╗\n");
    
    // Línea de encabezado
    printf("║ %-52s ║\n", "Valores Reales:");
    
    // Líneas de datos
    sprintf(buffer, "  a: %.6f", real_a);
    printf("║ %-52s ║\n", buffer);
    
    sprintf(buffer, "  b: %.6f", real_b);
    printf("║ %-52s ║\n", buffer);
    
    sprintf(buffer, "(double) a*b teorico: %.6f", c_teorico);
    printf("║ %-52s ║\n", buffer);
    
    sprintf(buffer, "truncation(a*b) -> Real: %.6f", fx2fp(c_trunc));
    printf("║ %-52s ║\n", buffer);
    
    sprintf(buffer, "rounding(a*b)   -> Real: %.6f", fx2fp(c_round));
    printf("║ %-52s ║\n", buffer);
    
    printf("╚══════════════════════════════════════════════════════╝\n");
}


int main(void){

    // Se pasa del rango de Q21.11
    calcular(fp2fx(2000000), fp2fx(10));
    // Multiplicación de números negativos
    calcular(fp2fx(-1), fp2fx(-10));
    // Multiplicación con 10 números después del punto decimal
    calcular(fp2fx(1.0000000001), fp2fx(2));
    // Multiplicación dentro del rango de Q21.11
    calcular(fp2fx(100), fp2fx(48));
    // Multiplicación con 2 números con 5 dígitos después del punto decimal
    calcular(fp2fx(1.11111), fp2fx(2.55555));
    // Multiplicación arbitraria
    calcular(fp2fx(46.1948), fp2fx(781.4874));
    
    return 0;
}
