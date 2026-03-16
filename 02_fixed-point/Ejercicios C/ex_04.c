#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int32_t saturation(int32_t a, int32_t b)
{
    int64_t sum = (int64_t)a + (int64_t)b; // Usamos int64_t para evitar overflow

    if (sum > INT32_MAX) {
        return INT32_MAX; // Saturación positiva
    } else if (sum < INT32_MIN) {
        return INT32_MIN; // Saturación negativa
    } else {
        return (int32_t)sum; // No hay saturación, retornamos la suma normal
    }
}

int main(void)
{
    int32_t a, b, r;

    printf("Prueba normal:\n");
    a = 100;
    b = 200;
    r = saturation(a, b);
    printf("%d + %d = %d\n\n", a, b, r);

    printf("Overflow positivo:\n");
    a = INT_MAX - 10;
    b = 50;
    r = saturation(a, b);
    printf("%d + %d = %d\n\n", a, b, r);

    printf("Overflow negativo:\n");
    a = INT_MIN + 10;
    b = -50;
    r = saturation(a, b);
    printf("%d + %d = %d\n\n", a, b, r);

    printf("Caso límite:\n");
    a = INT_MAX;
    b = 1;
    r = saturation(a, b);
    printf("%d + %d = %d\n", a, b, r);

    return 0;
}