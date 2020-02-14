# include <iostream>
# include <fstream>

using namespace std;


int main(int argc, char** argv){
    if (argc > 1){
        ifstream testFile;
        string currLine;
        char currLetter;
        int sum = 0;

        testFile.open(argv[1]);


        testFile >> currLine;
        while (!testFile.fail()){
            cout << currLine << endl;
            for (int i = 0; i < currLine.length(); ++i){
                sum += 1;
                currLetter = currLine[i];
            }
            testFile >> currLine;
        }

        cout << sum << endl;

        testFile.close();
    }




}
