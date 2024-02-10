/**
 * @file main.c
 * @author Badiry Achraf (achraf.badiry@edu.bme.hu)
 * @brief 
 * @version 0.1
 * @date 2024-02-10
 * 
 * @copyright GNU General Public License 2024
 * 
 */

#include "G_dataTypes.h"


data *start = NULL;
data *head = NULL;
data *end = NULL;

double* alpha = NULL;
double* beta = NULL;
double* delta = NULL;
double* gamma = NULL;


int main (void)
{
    int H0_v = 0, F0_v = 0, days_v = 0;
    double alpha_v = 0, beta_v= 0, delta_v= 0, gamma_v= 0;
    alpha = &alpha_v;
    beta = &beta_v;
    delta = &delta_v;
    gamma = &gamma_v;


    printf("Please input the hare initial population: ");
    scanf("%i", &H0_v);

    printf("\nPlease input the fox initial population: ");
    scanf("%i", &F0_v);

    printf("\nPlease input the duration in days for which to track both populations: ");
    scanf("%i", &days_v);

    printf("\nPlease input the growth rate of the hares: ");
    scanf("%lf", alpha);

    printf("\nPlease input the effect of predators on prey: ");
    scanf("%lf", beta);

    printf("\nPlease input the effect of prey on predators: ");
    scanf("%lf", delta);

    printf("\nPlease input the death rate of foxes: ");
    scanf("%lf", gamma);


    CalculateChange(H0_v, F0_v, days_v, 0.1);

    Plot(start);

    return 0;
}