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
        string newLine;
        string word;
        string fileName;
        string first = "yes";
        char currLetter;
        char nextLetter;
        int sumChar;
        int sumLine;
        int totalBigram;
        int charInLine;
        int countA;
        int countG;
        int countC;
        int countT;
        int countAA;
        int countAC;
        int countAT;
        int countAG;
        int countCA;
        int countCT;
        int countCG;
        int countCC;
        int countTA;
        int countTC;
        int countTG;
        int countTT;
        int countGA;
        int countGC;
        int countGT;
        int countGG;
        double sumForVar;
        double pi = 3.14159;
        double differenceSqr;
        double mean, variance, stdDev;
        double probA, probG, probC, probT;
        double probAA, probAC, probAT, probAG;
        double probCA, probCC, probCT, probCG;
        double probGA, probGC, probGT, probGG;
        double probTA, probTC, probTT, probTG;
        double a, b, c, d, random;


        // opening the file to write to
        outFile.open("albertoNg.out");

        // header
        outFile << "Name: Alberto Ng" << "\nStudent ID: 2298866" << "\nCPSC350-02\n" << endl;

        // check if user wants to quit
        while (word != "q"){
            // resetting all the variables before program run on new file
            countA = 0;
            countG = 0;
            countC = 0;
            countT = 0;
            countAA = 0;
            countAC = 0;
            countAT = 0;
            countAG = 0;
            countCA = 0;
            countCT = 0;
            countCG = 0;
            countCC = 0;
            countTA = 0;
            countTC = 0;
            countTG = 0;
            countTT = 0;
            countGA = 0;
            countGC = 0;
            countGT = 0;
            countGG = 0;
            sumChar = 0;
            sumLine = 0;
            totalBigram = 0;
            charInLine = 0;
            sumForVar = 0.0;

            // check if it is the first time this program is run
            if (first == "yes"){
                // open text file twice. One for going through the file, one for stats
                testFile.open(argv[1]);
                statFile.open(argv[1]);

                // setting fileName to what user put
                fileName = argv[1];

                // check if the file can be opened
                if (testFile.fail()){
                    // while fail, kept prompting unil user quits or enter a valid file
                    while (testFile.fail()){
                        cout << "\nFailed.\n1. Enter q to quit. \n2. Enter next .txt file \n\"EXAMPLE: dna.txt\"" << endl;
                        cin >> word;

                        // exit out of while(testFile.fail()) loop if user wants to quit
                        if (word == "q"){
                            break;
                        }

                        // kept trying to open file until success
                        testFile.open(word);
                        statFile.open(word);
                    }

                    // exit out of while(word != "q") loop if user wants to quit
                    if (word == "q"){
                        break;
                    }

                    // print out the current file to the .out file
                    outFile << "\nCURRENT FILE: " << word << "\n" << endl;
                }
                // print out the current file to the .out file if the file can be opened
                else {
                    outFile << "\nCURRENT FILE: " << argv[1] << "\n" << endl;
                }
                // letting the program know it is no longer the first time
                first = "no";
            }
            // else statement will execute when not the first time
            else{
                // open text file twice. One for going through the file, one for stats
                testFile.open(word);
                statFile.open(word);

                // while fail, kept prompting unil user quits or enter a valid file
                while (testFile.fail()){
                    cout << "\nFailed.\n1. Enter q to quit. \n2. Enter next .txt file \n\"EXAMPLE: dna.txt\"" << endl;
                    cin >> word;

                    // if user wants to quit, exit out of while (testFile.fail()) loop
                    if (word == "q"){
                        break;
                    }

                    testFile.open(word);
                    statFile.open(word);
                }

                // exit out of while(word != "q") loop if user wants to quit
                if (word == "q"){
                    break;
                }

                // setting fileName to user input word
                fileName = word;
                // printing current file
                outFile << "\nCURRENT FILE: " << word << "\n" << endl;
            }

            // store first line to currLine
            testFile >> currLine;

            // while loop to go through the whole txt file until fail
            while (!testFile.eof()){
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


            // to print 1000 lines
            for (int i = 0; i < 1000; ++i){
                // resetting newLine every time loop execute
                newLine = "";

                // getting 2 random number
                a = ((double)rand()/RAND_MAX);
                b = ((double)rand()/RAND_MAX);

                // getting c and d with equation given
                c = (sqrt((-2) * log(a))) * (cos(2 * pi * b));
                d = (stdDev * c) + mean;

                // if statement to get d to a whole number if the value in decimal is above 0.5
                if (remainder(d, 1) > 0.5){
                    d += (1 - remainder(d, 1));
                }
                // else statement to get d to a whole number if the value in decimal is below 0.5
                else {
                    d -= remainder(d, 1);
                }

                // for loop saving char to newLine
                for (int i = 0; i < d; ++i){
                    // getting a random number
                    random = ((double)rand()/RAND_MAX) * 100;

                    // if random falls between (probA + probC + probG) to 1, add T to newLine
                    if (random <= (probA + probC + probG + probT) && random > (probA + probC + probG)){
                        newLine += "T";
                    }
                    // if random falls between (probA + probC) to (probA + probC + probG), add G to newLine
                    else if (random <= (probA + probC + probG) && random > (probA + probC)){
                        newLine += "G";
                    }
                    // if random falls between (probA) to (probA + probC), add C to newLine
                    else if (random <= (probA + probC) && random > (probA)){
                        newLine += "C";
                    }
                    // if random falls between 0 to (probA), add A to newLine
                    else {
                        newLine += "A";
                    }
                }

                // print newLine to outFile
                outFile << newLine << endl;
            }

            // promt user with options
            cout << "\nEnd of file. \n1. Enter q if done. \n2. Enter next .txt file \n\"EXAMPLE: dna.txt\"" << endl;
            cin >> word;
        }
        // closing the out file
        outFile.close();
    }
}
