#ifndef header
#define header

#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    double population;
    double time;
    char type;
    struct data* next;
}data;

extern data *start,
            *head,
            *end;

void CalculateChange(int H0, int F0, int days, float delta_t, double alpha, double beta, double delta, double gamma);
void AddElement(double population, double time, char type);
void Plot (data* coordinates, int days, float time_step);

#endif