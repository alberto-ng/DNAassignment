# include <iostream>
# include <fstream>

using namespace std;


int main(int argc, char** argv){
    if (argc > 1){
        ifstream testFile;
        char letter1;

        testFile.open(argv[1]);


        testFile >> letter1;
        while (!testFile.fail()){
            cout << letter1 << endl;
            testFile >> letter1;
        }

        testFile.close();
    }




}
