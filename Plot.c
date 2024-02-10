/**
 * @file Plot.c
 * @author Badiry Achraf (achraf.badiry@edu.bme.hu)
 * @brief 
 * @version 0.1
 * @date 2024-02-10
 * 
 * @copyright GNU General Public License 2024
 * 
 */

#include "G_dataTypes.h"


void Plot (data* coordinates)
{   

    FILE *GNUpipe1 = NULL,
         *GNUpipe2 = NULL,
         *hare_data = NULL,
         *fox_data = NULL,
         *hare_fox_data = NULL;

    hare_data = fopen("Hdata.dat", "w");
    fox_data = fopen("Fdata.dat", "w");
    hare_fox_data = fopen("HFdata.dat", "w");


    
    while (coordinates != NULL)
    {
        if((*coordinates).type == 'h')
        {
            fprintf(hare_data,"%lf %lf\n", (*coordinates).time, (*coordinates).population);
            fprintf(hare_fox_data, "%lf ",(*coordinates).population);
            coordinates = (*coordinates).next;
        }

        else if((*coordinates).type == 'f')
        {
            fprintf(fox_data, "%lf %lf\n", (*coordinates).time, (*coordinates).population);
            fprintf(hare_fox_data, "%lf\n", (*coordinates).population);
            coordinates = (*coordinates).next;
        }

        else
        {
            printf("Error in data handling :)");
        }

    }

    fflush(fox_data);
    fflush(hare_data);
    fflush(hare_fox_data);

    DeleteLL(head);

    GNUpipe1 = popen("gnuplot -p PlotScript.gp", "w");
    fflush(GNUpipe1);
    GNUpipe2 = popen("gnuplot -p HFPlotScript.gp", "w");
    fflush(GNUpipe2);


    pclose(GNUpipe1);
    pclose(GNUpipe2);
    fclose(hare_data);
    fclose(fox_data);
    fclose(hare_fox_data);

    return;

}
