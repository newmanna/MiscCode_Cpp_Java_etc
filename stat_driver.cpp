//Author: Nathan Newman
//Date: 4/20/2010
//Program: Asks the user to input a data set, and then asks them whether they have the 
//         mean or if they need to compute it.  Then using the given values of the
//         data set and mean, if applicable, finds the standard variation of the 
//         data set.

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "statistics.h"

using namespace std;
//here are the function declarations in case I didn't split the files properly

//typedef int Item; //makes item an alias for int
//double Find_Std_Dev (Item[], int); //computes the std dev for some data set and computes the mean
//double Find_Std_Dev (Item[], int, double); //computes the std dev for some data set given the mean
//double Find_Mean (Item[], int); // computes the mean for some data set if needed

int main()
{

    int MAX = 100;
    double stdDev;
    Item dataSet [MAX];
    
    cout << "Please enter a number to add to the data set (enter 0 to stop): ";
    int i, count = 0;
    cin >> i;
    dataSet[count] = i;
    while (i != 0){
          count++;
          if (count == 100){
             i = 0;
             cout << "Sorry you have exceeded the MAX number of entries.";
                    }
          else {
               cout << "Please enter a number to add to the data set (enter 0 to stop): ";
               cin >> i;
               dataSet[count] = i;
          }
    }
    int size = count;
    
    //asks the user if he/she already knows the mean or needs to compute it
    cout << "Do you know the mean of your data set already (y/n)? ";
    char response;
    cin >> response;
    if (response == 'n' || response == 'N'){
       stdDev = Find_Std_Dev(dataSet, size);}//finds std dev by first finding mean usinf Find_Mean
    else if (response == 'y' || response == 'Y'){
         cout << "Please enter the value of the mean: ";
         double mean;
         cin >> mean;
         stdDev = Find_Std_Dev(dataSet, size, mean);}//bypasses Find_Mean and uses the value given by the user
    
    cout << "The standard deviation of your data set is " << stdDev << ".";
    cout << endl;
    
    system("PAUSE");
    return 0;
}
//here is all the function bodies in case I didn't split the files up properly

/* double Find_Std_Dev(
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
} */
       






