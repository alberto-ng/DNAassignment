# include <iostream>
# include <ios>
# include <iomanip>
# include <fstream>
# include <cmath>

using namespace std;


int main(int argc, char** argv){
    if (argc > 1){
        ifstream testFile;
        ifstream statFile;
        string currLine;
        char currLetter;
        char nextLetter;
        int sumChar = 0;
        int sumLine = 0;
        int totalBigram = 0;
        int charInLine = 0;
        int countA = 0;
        int countG = 0;
        int countC = 0;
        int countT = 0;
        int countAA = 0;
        int countAC = 0;
        int countAT = 0;
        int countAG = 0;
        int countCA = 0;
        int countCT = 0;
        int countCG= 0;
        int countCC = 0;
        int countTA = 0;
        int countTC = 0;
        int countTG = 0;
        int countTT = 0;
        int countGA = 0;
        int countGC = 0;
        int countGT = 0;
        int countGG = 0;
        double sumForVar = 0.0;
        double differenceSqr;
        double mean, variance, stdDev;
        double probA, probG, probC, probT;
        double probAA, probAC, probAT, probAG;
        double probCA, probCC, probCT, probCG;
        double probGA, probGC, probGT, probGG;
        double probTA, probTC, probTT, probTG;
        testFile.open(argv[1]);
        statFile.open(argv[1]);

        testFile >> currLine;
        while (!testFile.fail()){
            sumLine += 1;
            cout << currLine << endl;
            for (int i = 0; i < currLine.length(); ++i){
                sumChar += 1;

                currLetter = tolower(currLine[i]);
                if ((i + 1) < currLine.length()){
                    nextLetter = tolower(currLine[i + 1]);
                    totalBigram += 1;
                }
                else {
                    nextLetter = '\0';
                }

                if (currLetter == 'a'){
                    countA += 1;
                    if (currLetter == 'a' && nextLetter == 'a'){
                        countAA += 1;
                    }
                    else if (currLetter == 'a' && nextLetter == 'c'){
                        countAC += 1;
                    }
                    else if (currLetter == 'a' && nextLetter == 't'){
                        countAT += 1;
                    }
                    else if (currLetter == 'a' && nextLetter == 'g'){
                        countAG += 1;
                    }
                }

                else if (currLetter == 't'){
                    countT += 1;
                    if (currLetter == 't' && nextLetter == 'a'){
                        countTA += 1;
                    }
                    else if (currLetter == 't' && nextLetter == 'c'){
                        countTC += 1;
                    }
                    else if (currLetter == 't' && nextLetter == 't'){
                        countTT += 1;
                    }
                    else if (currLetter == 't' && nextLetter == 'g'){
                        countTG += 1;
                    }
                }

                else if (currLetter == 'g'){
                    countG += 1;
                    if (currLetter == 'g' && nextLetter == 'a'){
                        countGA += 1;
                    }
                    else if (currLetter == 'g' && nextLetter == 'c'){
                        countGC += 1;
                    }
                    else if (currLetter == 'g' && nextLetter == 't'){
                        countGT += 1;
                    }
                    else if (currLetter == 'g' && nextLetter == 'g'){
                        countGG += 1;
                    }
                }

                else if (currLetter == 'c'){
                    countC += 1;
                    if (currLetter == 'c' && nextLetter == 'a'){
                        countCA += 1;
                    }
                    else if (currLetter == 'c' && nextLetter == 'c'){
                        countCC += 1;
                    }
                    else if (currLetter == 'c' && nextLetter == 't'){
                        countCT += 1;
                    }
                    else if (currLetter == 'c' && nextLetter == 'g'){
                        countCG += 1;
                    }
                }
            }

            testFile >> currLine;
        }


        cout << "\nnumber of char(sum): " << sumChar << endl;
        cout << "number of line: " << sumLine << endl;

        probA = (((double)countA)/sumChar) * 100;
        probG = (((double)countG)/sumChar) * 100;
        probC = (((double)countC)/sumChar) * 100;
        probT = (((double)countT)/sumChar) * 100;

        probAA = (((double)countAA)/totalBigram) * 100;
        probAG = (((double)countAG)/totalBigram) * 100;
        probAC = (((double)countAC)/totalBigram) * 100;
        probAT = (((double)countAT)/totalBigram) * 100;

        probGA = (((double)countGA)/totalBigram) * 100;
        probGG = (((double)countGG)/totalBigram) * 100;
        probGC = (((double)countGC)/totalBigram) * 100;
        probGT = (((double)countGT)/totalBigram) * 100;

        probCA = (((double)countCA)/totalBigram) * 100;
        probCG = (((double)countCG)/totalBigram) * 100;
        probCC = (((double)countCC)/totalBigram) * 100;
        probCT = (((double)countCT)/totalBigram) * 100;

        probTA = (((double)countTA)/totalBigram) * 100;
        probTG = (((double)countTG)/totalBigram) * 100;
        probTC = (((double)countTC)/totalBigram) * 100;
        probTT = (((double)countTT)/totalBigram) * 100;

        cout << "\nProbability of A: " << fixed << setprecision(2) << probA << "%" << endl;
        cout << "Probability of C: " << fixed << setprecision(2) << probC << "%" << endl;
        cout << "Probability of T: " << fixed << setprecision(2) << probT << "%" << endl;
        cout << "Probability of G: " << fixed << setprecision(2) << probG << "%" << endl;

        cout << "\nProbability of AX bigram: " << fixed << setprecision(2) << probAA +  probAC + probAT + probAG << "%" << endl;
        cout << "Probability of AA: " << fixed << setprecision(2) << probAA << "%" << endl;
        cout << "Probability of AC: " << fixed << setprecision(2) << probAC << "%" << endl;
        cout << "Probability of AT: " << fixed << setprecision(2) << probAT << "%" << endl;
        cout << "Probability of AG: " << fixed << setprecision(2) << probAG << "%" << endl;

        cout << "\nProbability of CX bigram: " << fixed << setprecision(2) << probCA +  probCC + probCT + probCG << "%" << endl;
        cout << "Probability of CA: " << fixed << setprecision(2) << probCA << "%" << endl;
        cout << "Probability of CC: " << fixed << setprecision(2) << probCC << "%" << endl;
        cout << "Probability of CT: " << fixed << setprecision(2) << probCT << "%" << endl;
        cout << "Probability of CG: " << fixed << setprecision(2) << probCG << "%" << endl;

        cout << "\nProbability of TX bigram: " << fixed << setprecision(2) << probTA +  probTC + probTT + probTG << "%" << endl;
        cout << "Probability of TA: " << fixed << setprecision(2) << probTA << "%" << endl;
        cout << "Probability of TC: " << fixed << setprecision(2) << probTC << "%" << endl;
        cout << "Probability of TT: " << fixed << setprecision(2) << probTT << "%" << endl;
        cout << "Probability of TG: " << fixed << setprecision(2) << probTG << "%" << endl;

        cout << "\nProbability of GX bigram: " << fixed << setprecision(2) << probGA +  probGC + probGT + probGG << "%" << endl;
        cout << "Probability of GA: " << fixed << setprecision(2) << probGA << "%" << endl;
        cout << "Probability of GC: " << fixed << setprecision(2) << probGC << "%" << endl;
        cout << "Probability of GT: " << fixed << setprecision(2) << probGT << "%" << endl;
        cout << "Probability of GG: " << fixed << setprecision(2) << probGG << "%" << endl;


        mean = ((double)sumChar)/sumLine;
        cout << "\nMean (sum/lines): " << fixed << setprecision(2) << mean << endl;

        statFile >> currLine;
        while (!statFile.fail()){
            for (int i = 0; i < currLine.length(); ++i){
                charInLine += 1;
            }

            differenceSqr = (charInLine - mean) * (charInLine - mean);
            sumForVar += differenceSqr;
            charInLine = 0;

            statFile >> currLine;
        }

        variance = sumForVar/sumLine;
        stdDev = sqrt(variance);

        cout << "Variance: " << fixed << setprecision(2) << variance << endl;
        cout << "Standard Deviation: " << fixed << setprecision(2) << stdDev << "\n" << endl;


        testFile.close();
        statFile.close();
    }
}
