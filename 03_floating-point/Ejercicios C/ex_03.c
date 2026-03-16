#include <stdio.h>
#include <math.h>

int main() {
    // 1. Inicialización estándar (Recomendado)
    double pos_inf = INFINITY;
    double neg_inf = -INFINITY;
    double no_es_numero = NAN;

    // 2. Comprobación (No uses '==' con NaN, siempre da falso)
    if (isinf(pos_inf)) {
        printf("Infinito detectado.\n");
    }

    if (isnan(no_es_numero)) {
        printf("NaN detectado.\n");
    }

    return 0;
}