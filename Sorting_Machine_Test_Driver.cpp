#include "Sorting_Machine_2.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
typedef int item;

void PrintSortMach(ofstream& ofile, Sorting_Machine_2& sm);

int main ()
{
    Sorting_Machine_2 sm2;
    item x;
    ofstream outfile("sorted_data.txt");
    ifstream infile("sorttestnumbers.txt");
    
    
    while ( !(infile.eof()))
    {
          infile >> x;
          sm2.Insert(x);
          }
    

    sm2.Change_To_Extraction_Phase();

    outfile << endl << "Sorting Machine 2: " << endl;
    PrintSortMach(outfile, sm2);
    
	//system("PAUSE");
	return EXIT_SUCCESS;
}
//-------------------------------------------
void PrintSortMach(ofstream& ofile, Sorting_Machine_2& sm)
{
     item x;
     while (sm.Size() > 0)
     {
          sm.Remove_First(x);
          ofile << x << endl;
          }
     }
     
