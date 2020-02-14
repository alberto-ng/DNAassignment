# include <iostream>
# include <fstream>
# include <cmath>

using namespace std;


int main(int argc, char** argv){
    if (argc > 1){
        ifstream testFile;
        ifstream statFile;
        string currLine;
        char currLetter;
        int sumChar = 0;
        int sumLine = 0;
        int charInLine = 0;
        double differenceSqr = 0.0;
        double sumForVar = 0.0;
        double variance = 0.0;
        double stdDev = 0.0;
        double mean = 0.0;

        testFile.open(argv[1]);
        statFile.open(argv[1]);

        testFile >> currLine;
        while (!testFile.fail()){
            sumLine += 1;
            cout << currLine << endl;
            for (int i = 0; i < currLine.length(); ++i){
                sumChar += 1;
                currLetter = currLine[i];
            }
            testFile >> currLine;
        }

        cout << "\nnumber of char(sum): " << sumChar << endl;
        cout << "number of line: " << sumLine << endl;

        mean = ((double)sumChar)/sumLine;
        cout << "\nMean (sum/lines): " << mean << endl;

        statFile >> currLine;
        while (!statFile.fail()){
            for (int i = 0; i < currLine.length(); ++i){
                charInLine += 1;
            }

            differenceSqr = (charInLine - mean) * (charInLine - mean);
            sumForVar += differenceSqr;
            differenceSqr = 0.0;

            statFile >> currLine;
        }

        variance = sumForVar/sumLine;
        stdDev = sqrt(variance);

        cout << "Variance: " << variance << endl;
        cout << "Standard Deviation: " << stdDev << "\n" << endl;


        testFile.close();
        statFile.close();
    }




}
