//#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include <float.h>

#define ValueP 12

using namespace std;
int *shortTermEnergy(char *fileName1, int pitchValue);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int *shortTermEnergy(char *fileName1, int pitchValue)
{
    char data[100];				

    ifstream infile;
    
    cout<< "\n opened file "<< infile;
    infile.open(fileName1);
    cout<< "\n opened file "<< fileName1;
    cout<< "\n opened file "<< infile;
    int arrayPoint = 0, maxPoint;
    long double count = 0, sum = 0, max = 0;
    while (infile >> data)
    {
        long double Value = atoi(data);
        cout<<"\n data "<<data;
        count += 1;
        if (count <= pitchValue)
        { cout<<"trying in all";
            sum = sum + pow(Value, 2);
        }
        if (count == pitchValue)
        {
            long double finalSTE = sum / count;
            count = 0;
            sum = 0;
            cout<<"\nITs STE "<<finalSTE<<" and max is "<<max;

            if (max < finalSTE)
            {
                maxPoint = arrayPoint;
                max = finalSTE;
            }
            arrayPoint++;
        }
    }
    // close the opened file.
	cout<<"\nline closed"   ;
    infile.close();
    int end, start;
    if (maxPoint < 2)
    {
        start = maxPoint;
        end = maxPoint + 4;
    }
    else if (maxPoint > (arrayPoint - 2))
    {
        end = maxPoint;
        start = maxPoint - 4;
    }
    else
    {
        start = maxPoint - 2;
        end = maxPoint + 2;
    }
    end *= 320;
    start *= 320;
    int arr[2] = {start, end};
cout<<"array "<<arr[0]<<" vc  "<<arr[1];
    return arr;
}

int main(int argc, char** argv) {
  // checkVowel("filefor_A", "output_A_Test");
    // checkVowel("filefor_E", "output_E_Test");
    // checkVowel("filefor_I", "output_I_Test");
    // checkVowel("filefor_O", "output_O_Test");
    // checkVowel("filefor_U", "output_U_Test");
    // long double TokhuraDistanceData[10];
    // for (int i = 0; i < 10; i++)
    // {
    //     TokhuraDistanceData[i] = TokhuraDistance("file1");
    // }
    // long double min;
    // int index;
    // for (int i = 0; i < 10; i++)
    // {
    //     if (min < TokhuraDistanceData[i])
    //     {
    //         min = TokhuraDistanceData[i];
    //         index = i;
    //     }
    // }
    // cout << "file " << index << "nearest to vowel"
    //      << "Value " << min;
    cout<<"testing functions";
    int *ar = shortTermEnergy("vowel_a", 320);
    cout<<"array start";ar[0];cout<<"\narray end";ar[1];
    return 0;
}



