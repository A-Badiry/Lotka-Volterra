#include "G_dataTypes.h"



//alpha : 


int main (void)
{
    int H0_v, F0_v, days_v;
    double alpha_v, beta_v, delta_v, gamma_v;

    printf("Please input the hare initial population: ");
    scanf("%i", &H0_v);

    printf("\nPlease input the fox initial population: ");
    scanf("%i", &F0_v);

    printf("\nPlease input the duration in days for which to track both populations: ");
    scanf("%i", &days_v);

    printf("\nPlease input the growth rate of the hares: ");
    scanf("%lf", &alpha_v);

    printf("\nPlease input the effect of predators on prey: ");
    scanf("%lf", &beta_v);

    printf("\nPlease input the effect of prey on predators: ");
    scanf("%lf", &delta_v);

    printf("\nPlease input the death rate of foxes: ");
    scanf("%lf", &gamma_v);


    CalculateChange(H0_v, F0_v, days_v, 0.01, alpha_v, beta_v, delta_v, gamma_v);

    Plot(start, days_v, 0.01);

    return 0;
}