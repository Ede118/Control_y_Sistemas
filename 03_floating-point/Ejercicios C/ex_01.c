// Version: 002
// Date:    2022/04/05
// Author:  Rodrigo Gonzalez <rodralez@frm.utn.edu.ar>

// Compile usando el siguiente comando
// compile: gcc -Wall -std=c99 ex_01.c -o ex_01

#include <stdio.h>
#include <float.h>
#include <math.h>
#include <fenv.h>

typedef long int int64_t;

int main(void)
{	
	float a, b, c, f1, f2;
	double d1;

	a = 1000000000.0;	// mil millones		1e9
	b =   20000000.0;	// 20 millones		2e7
	c =   20000000.0;
	
	f1 = (a * b) * c;
	f2 = a * (b * c);

	d1 = (double) (a) * (double) (b) * (double) (c);

	// El resultado debería ser 4e23

	char buffer[100]; // Buffer temporal para armar cada línea

    printf("╔══════════════════════════════════════════════════════╗\n");
    
    printf("║ %-52s ║\n", ">> Resultados:");
    sprintf(buffer, "  f1: %lf", f1); printf("║ %-52s ║\n", buffer);
    sprintf(buffer, "  f2: %lf", f2); printf("║ %-52s ║\n", buffer);
    sprintf(buffer, "  d1: %lf", d1); printf("║ %-52s ║\n", buffer);
	sprintf(buffer, "  Resultado Exacto: 4e+23"); printf("║ %-52s ║\n", buffer);

    printf("║ %-52s ║\n", ">> Error Absoluto:");
    sprintf(buffer, "  f1: %10e", f1 - 400000000000000000000000.0); printf("║ %-52s ║\n", buffer);
    sprintf(buffer, "  f2: %10e", f2 - 400000000000000000000000.0); printf("║ %-52s ║\n", buffer);
    sprintf(buffer, "  d1: %20e", d1 - 400000000000000000000000.0); printf("║ %-52s ║\n", buffer);
    
    printf("║ %-52s ║\n", ">> Error relativo:");
    sprintf(buffer, "  f1: %lf%%", 100*(f1 - 400000000000000000000000.0)/400000000000000000000000.0); printf("║ %-52s ║\n", buffer);
    sprintf(buffer, "  f2: %lf%%", 100*(f2 - 400000000000000000000000.0)/400000000000000000000000.0); printf("║ %-52s ║\n", buffer);
    sprintf(buffer, "  d1: %lf%%", 100*(d1 - 400000000000000000000000.0)/400000000000000000000000.0); printf("║ %-52s ║\n", buffer);

    printf("╚══════════════════════════════════════════════════════╝\n");

		
	double acum_1, acum_2;
	
	acum_1 = 0.0;
	for (int64_t i = 0; i < 10000000; i++){ acum_1 += 0.01; } 

	acum_2 = 0.0;
	b = 0.333;
	for (int64_t i = 0; i < 10000000; i++){ acum_2 += b / b; }
	

	printf("╔══════════════════════════════════════════════════════╗\n");
    
    printf("║ %-52s ║\n", ">> Resultados:");
    sprintf(buffer, "  acum_1: %f", acum_1); printf("║ %-52s ║\n", buffer);
    sprintf(buffer, "  acum_2: %f", acum_2); printf("║ %-52s ║\n", buffer);

    printf("║ %-52s ║\n", ">> Error Absoluto:");
    sprintf(buffer, "  acum_1: %10e", acum_1 - (100000.0)); printf("║ %-52s ║\n", buffer);
    sprintf(buffer, "  acum_2: %10e", acum_2 - (10000000.0)); printf("║ %-52s ║\n", buffer);

    printf("║ %-52s ║\n", ">> Error Relativo:");
    sprintf(buffer, "  acum_1: %f%%", 100*(acum_1 - (100000.0))); printf("║ %-52s ║\n", buffer);
    sprintf(buffer, "  acum_2: %f%%", 100*(acum_2 - (10000000.0))/10000000.0); printf("║ %-52s ║\n", buffer);

    printf("╚══════════════════════════════════════════════════════╝\n");
	
	return 0;
}
