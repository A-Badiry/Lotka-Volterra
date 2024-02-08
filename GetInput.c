#include "G_dataTypes.h"

data *start = NULL;
data *head = NULL;
data *end = NULL;


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

void CalculateChange(int H0, int F0, int days, float delta_t, double alpha, double beta, double delta, double gamma)
{

    double current_hare_population_v = H0;
    double current_fox_population_v = F0;
    double previous_hare_population_v= 0;

    AddElement(H0, 0, 'h');
    AddElement(F0, 0, 'f');

    for(float t= delta_t; t<= days; t+= delta_t)
    {
        previous_hare_population_v = current_hare_population_v;
        current_hare_population_v += current_hare_population_v * delta_t * (alpha - beta*current_fox_population_v);
        current_fox_population_v += current_fox_population_v * delta_t * (delta*previous_hare_population_v - gamma);
        
        AddElement(current_hare_population_v, t, 'h');
        AddElement(current_fox_population_v, t, 'f');

    }


}
