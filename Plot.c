#include "G_dataTypes.h"


void Plot (data* coordinates, int days, float time_step)
{


    FILE *GNUpipe1 = NULL,
         //*GNUpipe2 = NULL,
         *hare_data = NULL,
         *fox_data = NULL,
         *hare_fox_data = NULL;

    hare_data = fopen("Hdata.dat", "w");
    fox_data = fopen("Fdata.dat", "w");
    hare_fox_data = fopen("HFdata.dat", "w");
    GNUpipe1 = popen("gnuplot -p", "w");
    //GNUpipe2 = popen("gnuplot -persist", "w");


    fprintf(GNUpipe1, "set term qt\n");
    fprintf(GNUpipe1, "set title \"hare and fox populations\"\n");
    
    while (coordinates != NULL)
    {
        if((*coordinates).type == 'h')
        {
            fprintf(hare_data,"%lf %lf\n", (*coordinates).population, (*coordinates).time);
            fflush(hare_data);
            fprintf(hare_fox_data, "%lf ",(*coordinates).population);
            coordinates = (*coordinates).next;
        }

        else if((*coordinates).type == 'f')
        {
            fprintf(fox_data, "%lf %lf\n", (*coordinates).population, (*coordinates).time);
            //fflush(fox_data);
            fprintf(hare_fox_data, "%lf\n", (*coordinates).population);
            coordinates = (*coordinates).next;
        }

        else
        {
            printf("Error in data handling :)");
        }

        fprintf(GNUpipe1,"plot 'Hdata.dat' using 2:1 with lines lt rgb \"green\" lw 2\n");
        fflush(GNUpipe1);
        /*fprintf(GNUpipe1,"plot 'Fdata.dat' using 1:2 with lines lt rgb \"red\" lw 2\n");
        fflush(GNUpipe1);*/
        usleep(11000);

    }

    fclose(GNUpipe1);

    return;

}