#include "statistics.h"

double Find_Std_Dev(
       Item arr[],
       int size
       )
{
       double mean;
       double sumSD = 0, temp1, temp2;
       mean = Find_Mean(arr, size);
       
       for (int i = 0; i < size; i++){
           temp1 = arr[i] - mean;
           temp2 = pow(temp1, 2.0);
           sumSD = sumSD + temp2;
           }
       sumSD = sumSD / size;
       return (sqrt(sumSD));
}

double Find_Std_Dev(
       Item arr[],
       int size,
       double mean
       )
{
       double sumSD = 0, temp1, temp2;
       
       for (int i = 0; i < size; i++){
           temp1 = arr[i] - mean;
           temp2 = pow(temp1, 2.0);
           sumSD = sumSD + temp2;
           }
       sumSD = sumSD / size;
       return (sqrt(sumSD));
}

double Find_Mean(
       Item arr[],
       int size
       )
{
       double sumM = 0;
       
       for (int i = 0; i < size; i++){
           sumM = sumM + arr[i];
           }
       sumM = sumM / size;
       cout << "The mean of your data set is " << sumM << ".";
       cout << endl;
       return sumM;
}
