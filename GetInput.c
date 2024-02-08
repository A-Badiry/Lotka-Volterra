#include "G_dataTypes.h"


double DxDt (double H, double F)
{
    return H * ((*alpha) - (*beta) * F);
}

double DyDt (double H, double F)
{
    return F * ((*delta) * H -(*gamma));
}

void AddElement(double population, double time, char type)
{
    data* new_object = (data*)malloc(sizeof(data));

    if(start == NULL)
    {
        start = new_object;
        (*start).population = population;
        (*start).time = time;
        (*start).type = type;
        head = start;
        end = start;
    }

    else
    {
        (*end).next = new_object;
        (*new_object).population = population;
        (*new_object).time = time;
        (*new_object).type = type;
        end = new_object;
    }
}

void CalculateChange(int H0, int F0, int days, float delta_t)
{

    long double K1X, K1Y, K2X, K2Y, K3X, K3Y, K4X, K4Y;
    double F = F0;
    double H = H0;
    double test;
    AddElement(H0, 0, 'h');
    AddElement(F0, 0, 'f');


    for(float i = delta_t; i <= days; i += delta_t)
    {
        K1X = delta_t * DxDt(H, F);
        K1Y = delta_t * DyDt(H, F);

        K2X = delta_t * DxDt(H + K1X / 2.0, F + K1Y / 2.0);
        K2Y = delta_t * DyDt(H + K1X / 2.0, F + K1Y / 2.0);

        K3X = delta_t * DxDt(H + K2X / 2.0, F + K2Y / 2.0);
        K3Y = delta_t * DyDt(H + K2X / 2.0, F + K2Y / 2.0);

        K4X = delta_t * DxDt(H + K3X, F + K3Y);
        K4Y = delta_t * DyDt(H + K3X, F + K3Y);

        test = 1/6 * (K1X + 2 * K2X + 2 * K3X + K4X);

        H += 1/6 * (K1X + 2 * K2X + 2 * K3X + K4X);
        F += 1/6 * (K1Y + 2 * K2Y + 2 * K3Y + K4Y);

        AddElement(H, i, 'h');
        AddElement(F, i, 'f');

    }

    

   /* for(float t= delta_t; t<= days; t+= delta_t)
    {
        previous_hare_population_v = current_hare_population_v;
        current_hare_population_v += current_hare_population_v * delta_t * (alpha - beta*current_fox_population_v);
        current_fox_population_v += current_fox_population_v * delta_t * (delta*previous_hare_population_v - gamma);
        
        AddElement(current_hare_population_v, t, 'h');
        AddElement(current_fox_population_v, t, 'f');

    }
    */

}
