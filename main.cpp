#include <iostream>
#include <fstream>
#include <string>
#include <ctdlib>
#include <math>

using namespace std;

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

int main(int argc, char **argv)
{
  double lineCount = 0; //Total number of lines
  double lineLength = 0; //length of lines
  double mean = 0; //mean for number of strings in file

  double varSum = 0; //sum Var for calculation
  double varLength = 0; //length Var for calculation

  double nucCount = 0; //Count total Nucleotide
  double nucA = 0; // Count Nucleotide A
  double nucT = 0; // Count Nucleotide T
  double nucG = 0; // Count Nucleotide G
  double nucC = 0; // Count Nucleotide C

  double biCount = 0; //Count total binucleotides
  double biAA = 0;
  double biAT = 0;
  double biAG = 0;
  double biAC = 0;
  double biTA = 0;
  double biTT = 0;
  double biTG = 0;
  double biTC = 0;
  double biGA = 0;
  double biGT = 0;
  double biGG = 0;
  double biGC = 0;
  double biCA = 0;
  double biCT = 0;
  double biCG = 0;
  double biCC = 0;

  string line;

  ifstream inputstream; //inputstream

  inputStream.open(argv[1]); //read first argument

  if(inputStream.good()) //Checks to see if the end of the file has been reached
  {
    while(getline(inputStream, line)) //reads through each line of the input file
    {
      for(int i = 0; i < line.length(); ++i)
      {
        if(line[i] == 'A' || line[i] == 'a')
          nucA++;
        else if(line[i] == 'T' || line[i] == 't')
          nucT++;
        else if(line[i] == 'G' || line[i] == 'g')
          nucG++;
        else if(line[i] == 'C' || line[i] == 'c')
          nucC++;
      }

      for(int i = 0; i < line.length()-1; ++i) //Checks binucleotides
      {

        if (line[i] == 'A' || line [i] == 'a')  //Checks starting with A
        {
          if (line[i+1] == 'A' || line[i+1] == 'a')
            biAA++;
          else if (line[i+1] == 'T' || line[i+1] == 't')
            biAT++;
          else if (line[i+1] == 'G' || line[i+1] == 'g')
            biAG++;
            else if (line[i+1] == 'C' || line[i+1] == 'c')
            biAC++;
        }

        else if (line[i] == 'T' || line[i] == 't') //Check starting with T
        {
          if (line[i+1] == 'A' || line[i+1] == 'a')
            biTA++;
          else if (line[i+1] == 'T' || line[i+1] == 't')
            biTT++;
          else if (line[i+1] == 'G' || line[i+1] == 'g')
            biTG++;
            else if (line[i+1] == 'C' || line[i+1] == 'c')
            biTC++;
        }

        else if (line[i] == 'G' || line[i] == 'g') //Check starting with G
        {
          if (line[i+1] == 'A' || line[i+1] == 'a')
            biGA++;
          else if (line[i+1] == 'T' || line[i+1] == 't')
            biGT++;
          else if (line[i+1] == 'G' || line[i+1] == 'g')
            biGG++;
            else if (line[i+1] == 'C' || line[i+1] == 'c')
            biGC++;
        }

        else if (line[i] == 'C' || line[i] == 'c') //Check starting with C
        {
          if (line[i+1] == 'A' || line[i+1] == 'a')
            biCA++;
          else if (line[i+1] == 'T' || line[i+1] == 't')
            biCT++;
          else if (line[i+1] == 'G' || line[i+1] == 'g')
            biCG++;
            else if (line[i+1] == 'C' || line[i+1] == 'c')
            biCC++;
        }
    }
    lineLength += line.length();
    lineCount++;
  }
  inputStream.close(); // close file
}

inputStream.open(argv[1]);

        if(inputStream.good())
        {
          double tempCount = 0;
          double tempLength = 0;

          while(getline(inputStream, line))
          {
                  tempCount++;
                  tempLength = line.length();
                  varSum += varNum(mean, tempLength);             //Adds a variance numerator
          }
          varLength = varSum / tempCount;                         //Sets the length variance value
          inputStream.close();
        }


        nucCount = lineLength;
        biCount = getSum(lineCount, lineLength);

        ofstream outputStream;
        outputStream.open("yourname.out");

        if(outputStream.good()){

        outputStream << "Name: Bryan Dang" << "\nID: 2295344" << endl;
        outputStream << "Number of lines: " << lineCount << endl;
        outputStream << "Total characters:" << lineLength<<endl;
        outputStream << "Mean: " << mean << endl;
        outputStream << "String length variance: " << varLength << endl;
        outputStream << "Standard deviation of length: " << getStanDev(varLength) << endl;
        outputStream << "Probability of nucleotide: " <<
        "\nA: " << nucA*100/nucCount <<
        "\nT: " << nucT*100/nucCount <<
        "\nG: " << nucG*100/nucCount <<
        "\nC: " << nucC*100/nucCount << endl;
        outputStream << "Probability of binucleotides: " <<
        "\nAA: " << biAA*100/biCount <<
        "\nAT: " << biAT*100/biCount <<
        "\nAG: " << biAG*100/biCount <<
        "\nAC: " << biAC*100/biCount <<
        "\nTA: " << biTA*100/biCount <<
        "\nTT: " << biTT*100/biCount <<
        "\nTG: " << biTG*100/biCount <<
        "\nTC: " << biTC*100/biCount <<
        "\nGA: " << biGA*100/biCount <<
        "\nGT: " << biGT*100/biCount <<
        "\nGG: " << biGG*100/biCount <<
        "\nGC: " << biGC*100/biCount <<
        "\nCA: " << biCA*100/biCount <<
        "\nCT: " << biCT*100/biCount <<
        "\nCG: " << biCG*100/biCount <<
        "\nCC: " << biCC*100/biCount << endl;
        outputStream.close();
        }

        mean = round(mean);

        outputStream.open("yourname.out", ios::app);  //Opens outputstream in append mode.

        int prA = round(getPairProb(countA, nucCount));
        int prT = round(getPairProb(countT, nucCount)) + prA;
        int prG = round(getPairProb(countG, nucCount)) + prT;
        int prC = round(getPairProb(countC, nucCount)) + prG;

        int prbiAA = round(getPairProb(biAA, biCount));
        int prbiAT = round(getPairProb(biAT, biCount)) + prbiAA;
        int prbiAG = round(getPairProb(biAG, biCount)) + prbiAT;
        int prbiAC = round(getPairProb(biAC, biCount)) + prbiAG;
        int prbiTA = round(getPairProb(biTA, biCount)) + prbiAC;
        int prbiTT = round(getPairProb(biTT, biCount)) + prbiTA;
        int prbiTG = round(getPairProb(biTG, biCount)) + prbiTT;
        int prbiTC = round(getPairProb(biTC, biCount)) + prbiTG;
        int prbiGA = round(getPairProb(biGA, biCount)) + prbiTC;
        int prbiGT = round(getPairProb(biGT, biCount)) + prbiGA;
        int prbiGG = round(getPairProb(biGG, biCount)) + prbiGT;
        int prbiGC = round(getPairProb(biGC, biCount)) + prbiGG;
        int prbiCA = round(getPairProb(biCA, biCount)) + prbiGC;
        int prbiCT = round(getPairProb(biCT, biCount)) + prbiCA;
        int prbiCG = round(getPairProb(biCG, biCount)) + prbiCT;
        int prbiCC = round(getPairProb(biCC, biCount)) + prbiCG;

        outputStream << prbiAA << " " << prbiAT << " " << prbiAG << " " << prbiAC << " " << prbiTA << " " << prbiTT << " " << prbiTG << " " << prbiTC << " " << prbiGA << " " << prbiGT << " " << prbiGG << " " << prbiGC << " " << prbiCA << " " << prbiCT << " " << prbiCG << " " << prbiCC << " " << endl;


//Print out random ATCG
        for(int i = 0; i < 1000 ; ++i)
        {
                int r = rand()%100 + 0;
                char last = NULL;
                        if (r < prA && r >= 0)
                                outputStream << "A";
                        else if(prA <=r && r < prT)
                                outputStream << "T";
                        else if(prT <=r && r < prG)
                                outputStream << "G";
                        else if(prG <=r && r < 100)
                                outputStream << "C";
                for(int j = 0; j < mean-1; ++j)
                {
                        if (r < prbiAA){
                                outputStream << "A";
                                last = 'A';
                        }
                        else if(prbiAA <= r && r < prbiAT){
                                outputStream << "T";
                                last = 'T';
                        }
                        else if(prbiAT <= r && r < prbiAG){
                                outputStream << "G";
                                last = 'G';
                        }
                        else if(prbiAG <= r && r < prbiAC){
                                outputStream << "C";
                                last = 'C';
                        }
                        else if(prbiAC <= r && r < prbiTA){
                                outputStream << "A";
                                last = 'A';
                        }
                        else if(prbiTA <= r && r < prbiTT){
                                outputStream << "T";
                                last = 'T';
                        }
                        else if(prbiTT <= r && r < prbiTG){
                                outputStream << "G";
                                last = 'G';
                        }
                        else if(prbiTG <= r && r < prbiTC){
                                outputStream << "C";
                                last = 'C';
                        }
                        else if(prbiTC <= r && r < prbiGA){
                                outputStream << "A";
                                last = 'A';
                        }
                        else if(prbiGA <= r && r < prbiGT){
                                outputStream << "T";
                                last = 'T';
                        }
                        else if(prbiGT <= r && r < prbiGG){
                                outputStream << "G";
                                last = 'G';
                        }
                        else if(prbiGG <= r && r < prbiGC){
                                outputStream << "C";
                                last = 'C';
                        }
                        else if(prbiGC <= r && r < prbiCA){
                                outputStream << "A";
                                last = 'A';
                        }
                        else if(prbiCA <= r && r < prbiCT){
                                outputStream << "T";
                                last = 'T';
                        }
                        else if(prbiCT <= r && r < prbiCG){
                                outputStream << "G";
                                last = 'G';
                        }
                        else if(prbiCG <= r && r < 100){
                                outputStream << "C";
                                last = 'C';
                        }
                        if(last == 'A')
                                r = rand()%prA + 0;
                        else if(last == 'T')
                                r = rand()%(prbiTC-prbiAC) + prbiAC;
                        else if(last == 'G')
                                r = rand()%(prbiGC - prbiTC) + prbiTC;
                        else if(last == 'C')
                                r = rand()%(100 - prbiGC) + prbiGC;
                }
                outputStream << endl;
        }


        outputStream.close();
        return 0;
}



/*
  while(readFile)
  {
    if (letter == '\n')
      lines++;
    else if (letter == ' ')
      words++;
    else
      character++;
    readFile.get(letter);
  }

  cout << "Lines = "<< lines << "\n Words = " << words << "\n Character =" << character << endl;



  //inputFile << "I am writing inside the text. \n";
  //inputFile.close();
  return 0;
  */
}
