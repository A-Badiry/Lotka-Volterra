/**
 * @file GetInput.c
 * @author Badiry Achraf (achraf.badiry@edu.bme.hu)
 * @brief 
 * @version 0.1
 * @date 2024-02-10
 * 
 * @copyright GNU General Public License 2024
 * 
 */

#include "G_dataTypes.h"

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

void DeleteLL(data* head)
{
    while(head != NULL)
    {
        start = head;
        head = (*head).next;
        free(start);
    }
}

double DxDt (double H, double F)
{
    return H * ((*alpha) - (*beta) * F);
}

double DyDt (double H, double F)
{
    return F * ((*delta) * H -(*gamma));
}


void CalculateChange(int H0, int F0, int days, float delta_t)
{

    long double K1X, K1Y, K2X, K2Y, K3X, K3Y, K4X, K4Y;
    double F = F0;
    double H = H0;
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

        H += 1.0/6 * (K1X + 2 * K2X + 2 * K3X + K4X);
        F += 1.0/6 * (K1Y + 2 * K2Y + 2 * K3Y + K4Y);

        AddElement(H, i, 'h');
        AddElement(F, i, 'f');

    }


}
