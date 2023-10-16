#include <stdio.h>


int main(){
    FILE *input_file;
    int i = 0;
    double sales_num[12];
    
    input_file = fopen("input.txt", "r");
    
    while (fscanf(input_file, "%lf", &sales_num[i]) == 1) {
        i++;
    }
    fclose(input_file);
    
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Monthly Sales Report for 2022: \n\n");
    printf("Months\t\tSales\n\n");
    for (int i = 0; i<12; i++){
        printf("%-11s     $%.2lf \n", months[i], sales_num[i]);
    }
    printf("\nSales Summary: \n\n");
    double min = sales_num[0];
    double max = sales_num[0];
    int minMonthIndex = 0;
    int maxMonthIndex = 0;

    double avgsum = 0;
    for (int i=0; i<12; i++){
        avgsum = avgsum + sales_num[i];
    }
    for (int i = 0; i<12; i++){
        if (sales_num[i] < min){
            min = sales_num[i];
            minMonthIndex = i;
        }
    }
    for (int i = 0; i<12; i++){
        if (sales_num[i] > max){
            max = sales_num[i];
            maxMonthIndex = i;
        }
    }
    char *minMonth = months[minMonthIndex];
    char *maxMonth  = months[maxMonthIndex];
    printf("Minimum Sales: $%.2f  (%s)\n", min, minMonth);
    printf("Maximum Sales: $%.2f  (%s)\n", max, maxMonth);
    printf("Average sales: $%.2f\n", avgsum/12);

    printf("\nSix-month moving average report: \n\n");
    for (int i=0; i<7; i++){
        double six_total = 0;
        for (int j = i; j<i+6; j++){
            six_total = six_total + sales_num[j];
        }
        double six_avg = six_total/6;
        printf("%-10s  -  %-10s %10.2f\n",months[i], months[i+5],six_avg);
    }

    printf("\nSales Report (Highest to Lowest): \n\n");
    double sorted_list[12];
    for(int i=0;i<12;i++){
        sorted_list[i] = sales_num[i];
    } 
    for (int i=0; i<11;i++){
        for (int j=i+1;j<12;j++){
            if (sorted_list[i]<sorted_list[j]){
                double temp = sorted_list[i];
                sorted_list[i] = sorted_list[j];
                sorted_list[j] = temp;
            }
        }
    }
    for (int i=0; i<12; i++){
        for (int j=0; j<12; j++){
            if (sorted_list[i] == sales_num[j]){
                printf("%-10s %10.2f\n", months[j], sorted_list[i]);
            }
        }
    }



    
    



   
    return 0;
}