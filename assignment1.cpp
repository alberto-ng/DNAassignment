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
        int countA = 0;
        int countG = 0;
        int countC = 0;
        int countT = 0;
        double differenceSqr = 0.0;
        double sumForVar = 0.0;
        double mean, variance, stdDev;
        double probA, probG, probC, probT;

        testFile.open(argv[1]);
        statFile.open(argv[1]);

        testFile >> currLine;
        while (!testFile.fail()){
            sumLine += 1;
            cout << currLine << endl;
            for (int i = 0; i < currLine.length(); ++i){
                if (currLine[i] == 'A' || currLine[i] == 'a'){
                    countA += 1;
                }
                else if (currLine[i] == 'T' || currLine[i] == 't'){
                    countT += 1;
                }
                else if (currLine[i] == 'G' || currLine[i] == 'g'){
                    countG += 1;
                }
                else if (currLine[i] == 'C' || currLine[i] == 'c'){
                    countC += 1;
                }

                sumChar += 1;
                currLetter = currLine[i];
            }
            testFile >> currLine;
        }

        cout << "\nnumber of char(sum): " << sumChar << endl;
        cout << "number of line: " << sumLine << endl;

        probA = (((double)countA)/sumChar) * 100;
        probG = (((double)countG)/sumChar) * 100;
        probC = (((double)countC)/sumChar) * 100;
        probT = (((double)countT)/sumChar) * 100;

        cout << "\nProbability of A: " << probA << "%" << endl;
        cout << "Probability of C: " << probC << "%" << endl;
        cout << "Probability of T: " << probT << "%" << endl;
        cout << "Probability of G: " << probG << "%" << endl;


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
