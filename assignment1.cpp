# include <iostream>
# include <ios>
# include <iomanip>
# include <fstream>
# include <cmath>

using namespace std;

int main(int argc, char** argv){
    // if statement to check if user put something on command line
    if (argc > 1){
        // initiating/assigning variables that are needed for the program
        ifstream testFile;
        ifstream statFile;
        ofstream outFile;
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
        int countCG = 0;
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

        // open text file twice. One for going through the file, one for stats
        testFile.open(argv[1]);
        statFile.open(argv[1]);

        // opening the file to write to
        outFile.open("albertoNg.txt");

        // store first line to currLine
        testFile >> currLine;

        // while loop to go through the whole txt file until fail
        while (!testFile.fail()){
            // everytime the loop execute means a line exist, so add 1 to sumLine everytime loop runs
            sumLine += 1;

            // showing the current line being analyzed to consel
            outFile << currLine << endl;

            // for loop to store count of letters, each A, C, T, G and as well as each bigram
            for (int i = 0; i < currLine.length(); ++i){
                // each time a loop execute means a letter exist so add 1 to sunChar
                sumChar += 1;

                // turn the currLetter to lower case to make sure upper case and lower case will both be fine
                currLetter = tolower(currLine[i]);

                // if statement to check if the currentLetter is the last letter in the string
                if ((i + 1) < currLine.length()){
                    // if it is not last letter, then make next letter to lower case and store in nextLetter
                    nextLetter = tolower(currLine[i + 1]);
                    // if there is next letter that means count of bigram will increase by 1
                    totalBigram += 1;
                }
                // else statement will execute when currentLetter is the last letter
                else {
                    // store nextLetter to null because there is no nextLetter
                    // reason of this is the if statement bellow check nextLetter to count each bigram
                    // if we do not modify nextLetter, one of the bigram count statement will run even if currLetter is the last letter
                    nextLetter = '\0';
                }

                // if statement to count A
                if (currLetter == 'a'){
                    countA += 1;
                    // if statement to count bigram starting with A
                    if (nextLetter == 'a'){
                        countAA += 1;
                    }
                    else if (nextLetter == 'c'){
                        countAC += 1;
                    }
                    else if (nextLetter == 't'){
                        countAT += 1;
                    }
                    else if (nextLetter == 'g'){
                        countAG += 1;
                    }
                }

                // if statement to count T
                else if (currLetter == 't'){
                    countT += 1;
                    // // if statement to count bigram starting with T
                    if (nextLetter == 'a'){
                        countTA += 1;
                    }
                    else if (nextLetter == 'c'){
                        countTC += 1;
                    }
                    else if (nextLetter == 't'){
                        countTT += 1;
                    }
                    else if (nextLetter == 'g'){
                        countTG += 1;
                    }
                }

                // if statement to count G
                else if (currLetter == 'g'){
                    countG += 1;
                    // if statement to count bigram starting with G
                    if (nextLetter == 'a'){
                        countGA += 1;
                    }
                    else if (nextLetter == 'c'){
                        countGC += 1;
                    }
                    else if (nextLetter == 't'){
                        countGT += 1;
                    }
                    else if (nextLetter == 'g'){
                        countGG += 1;
                    }
                }

                // if statement to count C
                else if (currLetter == 'c'){
                    countC += 1;
                    // if statement to count bigram starting with C
                    if (nextLetter == 'a'){
                        countCA += 1;
                    }
                    else if (nextLetter == 'c'){
                        countCC += 1;
                    }
                    else if (nextLetter == 't'){
                        countCT += 1;
                    }
                    else if (nextLetter == 'g'){
                        countCG += 1;
                    }
                }
            }

            // store next line to currLine
            // if there is no next line, loop conditional will break the loop
            testFile >> currLine;
        }

        // printing sumChar and sumLine to concel
        outFile << "\nnumber of char(sum): " << sumChar << endl;
        outFile << "number of line: " << sumLine << endl;

        // calculating probability of A, G, C, T
        probA = (((double)countA)/sumChar) * 100;
        probG = (((double)countG)/sumChar) * 100;
        probC = (((double)countC)/sumChar) * 100;
        probT = (((double)countT)/sumChar) * 100;

        // calculating probability of bigram starting with A
        probAA = (((double)countAA)/totalBigram) * 100;
        probAG = (((double)countAG)/totalBigram) * 100;
        probAC = (((double)countAC)/totalBigram) * 100;
        probAT = (((double)countAT)/totalBigram) * 100;

        // calculating probability of bigram starting with G
        probGA = (((double)countGA)/totalBigram) * 100;
        probGG = (((double)countGG)/totalBigram) * 100;
        probGC = (((double)countGC)/totalBigram) * 100;
        probGT = (((double)countGT)/totalBigram) * 100;

        // calculating probability of bigram starting with C
        probCA = (((double)countCA)/totalBigram) * 100;
        probCG = (((double)countCG)/totalBigram) * 100;
        probCC = (((double)countCC)/totalBigram) * 100;
        probCT = (((double)countCT)/totalBigram) * 100;

        // calculating probability of bigram starting with T
        probTA = (((double)countTA)/totalBigram) * 100;
        probTG = (((double)countTG)/totalBigram) * 100;
        probTC = (((double)countTC)/totalBigram) * 100;
        probTT = (((double)countTT)/totalBigram) * 100;

        // printing probaility of A, C, T, G in %
        outFile << "\nProbability of A: " << fixed << setprecision(2) << probA << "%" << endl;
        outFile << "Probability of C: " << fixed << setprecision(2) << probC << "%" << endl;
        outFile << "Probability of T: " << fixed << setprecision(2) << probT << "%" << endl;
        outFile << "Probability of G: " << fixed << setprecision(2) << probG << "%" << endl;

        // printing probability of bigram starting with A in %
        outFile << "\nProbability of AX bigram: " << fixed << setprecision(2) << probAA +  probAC + probAT + probAG << "%" << endl;
        outFile << "Probability of AA: " << fixed << setprecision(2) << probAA << "%" << endl;
        outFile << "Probability of AC: " << fixed << setprecision(2) << probAC << "%" << endl;
        outFile << "Probability of AT: " << fixed << setprecision(2) << probAT << "%" << endl;
        outFile << "Probability of AG: " << fixed << setprecision(2) << probAG << "%" << endl;

        // printing probability of bigram starting with C in %
        outFile << "\nProbability of CX bigram: " << fixed << setprecision(2) << probCA +  probCC + probCT + probCG << "%" << endl;
        outFile << "Probability of CA: " << fixed << setprecision(2) << probCA << "%" << endl;
        outFile << "Probability of CC: " << fixed << setprecision(2) << probCC << "%" << endl;
        outFile << "Probability of CT: " << fixed << setprecision(2) << probCT << "%" << endl;
        outFile << "Probability of CG: " << fixed << setprecision(2) << probCG << "%" << endl;

        // printing probability of bigram starting with T in %
        outFile << "\nProbability of TX bigram: " << fixed << setprecision(2) << probTA +  probTC + probTT + probTG << "%" << endl;
        outFile << "Probability of TA: " << fixed << setprecision(2) << probTA << "%" << endl;
        outFile << "Probability of TC: " << fixed << setprecision(2) << probTC << "%" << endl;
        outFile << "Probability of TT: " << fixed << setprecision(2) << probTT << "%" << endl;
        outFile << "Probability of TG: " << fixed << setprecision(2) << probTG << "%" << endl;

        // printing probability of bigram starting with G in %
        outFile << "\nProbability of GX bigram: " << fixed << setprecision(2) << probGA +  probGC + probGT + probGG << "%" << endl;
        outFile << "Probability of GA: " << fixed << setprecision(2) << probGA << "%" << endl;
        outFile << "Probability of GC: " << fixed << setprecision(2) << probGC << "%" << endl;
        outFile << "Probability of GT: " << fixed << setprecision(2) << probGT << "%" << endl;
        outFile << "Probability of GG: " << fixed << setprecision(2) << probGG << "%" << endl;

        // calculating mean and printing to concel
        mean = ((double)sumChar)/sumLine;
        outFile << "\nMean (sum/lines): " << fixed << setprecision(2) << mean << endl;

        // store first line to currLine
        statFile >> currLine;

        // while loop to go through the whole txt file until fail
        while (!statFile.fail()){
            // for loop to get number of char in each line to calculate variance and std deviation
            for (int i = 0; i < currLine.length(); ++i){
                charInLine += 1;
            }

            // calculating (number of char in each line - mean)^2
            differenceSqr = (charInLine - mean) * (charInLine - mean);
            // adding difference squared to sumForVar everytime loop execute to get sum of difference squared
            sumForVar += differenceSqr;
            // setting charInLine back to 0 before the loop execute again to be able to count chars in next line
            charInLine = 0;
            // store next line to currLine
            // if there is no next line, loop conditional will break the loop
            statFile >> currLine;
        }

        // calculating variance and std deviation with information we got from above
        variance = sumForVar/sumLine;
        stdDev = sqrt(variance);

        // printing variance and std deviation in %
        outFile << "Variance: " << fixed << setprecision(2) << variance << endl;
        outFile << "Standard Deviation: " << fixed << setprecision(2) << stdDev << "\n" << endl;

        // closing the two in files
        testFile.close();
        statFile.close();

        // closing the out file
        outFile.close();














    }
}
