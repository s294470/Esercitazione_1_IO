#include<iostream>
#include<iomanip>
#include <fstream>
#include<sstream>

// Nota preliminare: l'estensione del file di output è .txt perché ho avuto problemi con la corretta lettura dei numeri in notazione scientifica con Excel e voglio essere sicura di trasmettere i numeri nel formato corretto a chi legge il mio file result.



double rescale(double n, int a_old, int b_old, int a_new, int b_new)
{ return ((n-1)*(b_new-a_new)/(b_old-a_old))-1;
}


int main()
{
    int a = 1;
    int b = 5;
    int c = -1;
    int d = 2;
    std::ifstream inFile("data.csv");
    if (inFile.fail())
    {std::cerr << "The file doesn't exist" << std::endl;
        return 1;}

    std::ofstream outFile("result.txt");
    outFile << std::setprecision(16) << std::scientific;
    outFile << "# N Mean" << std::endl;


    double sum = 0;
    unsigned int counter = 0;
    double mean = 0;
    double val;
    while (inFile >> val)
    {
        sum = sum + rescale(val, a, b, c, d);
        counter= counter + 1;
        mean = sum/counter;
        outFile << counter << " " << mean << std::endl;
    }

    outFile.close();


    return 0;
}

