#include <iostream>
#include <tuple>
using namespace std;

int main() {
    // below both are good
    // tuple<string, int, char> member{"William", 19, 'A'};
    tuple<string, int, char> member("William", 19, 'A');
    cout << get<0>(member) << '\n';

    string name;
    int age;
    char blood_type;
    // decompose a tuple and assign its elements to variables
    tie(name, age, blood_type) = member; 
    cout << name+'\n';    

    age = 21;
    blood_type = 'B';
    // compose a tuple with variabless
    member = tie(name, age, blood_type);
    cout << "now the age is: " << get<1>(member) << '\n';
    return 0;
}