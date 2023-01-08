#include <iostream>
#include <fstream>

using namespace std;

int main() {

    // file.open(filiname, mode)
    // default: ios::out | ios::in, which means both "in" and "out" are available
    ofstream out;
    fstream file("test1.txt", ios::out); 
    ifstream in; 
    string line;

    if(!file || !out) {
        cerr << "Can't open file\n";
        exit(1);
    }
    else 
        cout << "File open successfully\n";

    //Text file --output
    file << "This is my test file\n";
    file << "Glad to see you!\n";
    file.close();

    //Text file --input
    in.open("test1.txt"); //default: ios::in    
    // while(in >> line) {
    //     cout << line + "\n";
    // }
    while(getline(in, line)) {
        cout << line + "\n";
    }
    in.close();

/*---------------------------------------------------------------------------*/

    /*
        Binary file --input, output:
            Copy the content of "test1.txt" to "test2.txt"
    */
    streampos size;
    char *str;
        /*
            ios::ate: Set the initial position at the end of the file.
        */
    in.open("test1.txt", ios::in | ios::binary | ios::ate); 
    size = in.tellg(); //Getting the current read position, returning type "streampos"
    str = new char[size];
    in.seekg(0, ios::beg); //Changing the current read position；ios::beg: beginning
    in.read(str, size); //file.read(buffer, characters)
    in.close();

    out.open("test2.txt", ios::out | ios::binary);
    out.write(str, size);
    out.close();

    if(!in.is_open()) {
        in.open("test2.txt");
        while(getline(in, line)) {
            cout << line + "\n";
        }
        //Returns true if a file open for reading has reached the end.
        cout << in.eof() << '\n'; 
        in.close();
    }

    return 0;
}