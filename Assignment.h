#include <iostream>

using namespace std;

class Assignment
{
public:  //access modifier anything below
  main(); //constructor
  //~Quiz1(); //destructor - to deallocate Memory, if not memory leaks - speed problem
  //function to get mean
  double getMean(double length, double count)
  {
    double mean = length/count;
  }

  //function to get Varience
  double getVar(double mean, double count)
  {
    double num = ((mean - count) * (mean - count));
  }

  //function to get standard deviation
  double getStanDev(double var)
  {
    double dev = sqrt(var);
  }

  //
  double getSum (double length, double count)
  {
    double sum = length - count;
  }

  //function to get probabilty of pair
  double getPairProb(double pairCurr, double pairTotal)
  {
    double prob = (pairCurr/pairTotal)*100;
  }
};
