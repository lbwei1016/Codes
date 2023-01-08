#include <iostream>
#include <map>
#include <string>
#include <iomanip> //setw()

using namespace std;

int main()
{
    map<string, int> m; //m[key] = value; sorted alphabetically by key
    map<string, int>::iterator it;
    m["William"] = 18;
    m["Ruby"] = 17;
    m["Yo"] = 0;
    m.insert(make_pair("Gaga", 999));

    for(it=m.begin(); it!=m.end(); it++)
    {
        cout << setw(8) << it->first << " " << it->second << '\n';
    }
    cout << m["Ruby"] << '\n'; //value can be accessed directly by operator[]

    int r = m.erase("Yo"); //return the number of elements erased
    if(r)
        cout << "\"Yo\" is erased successfully!\n";
    it = m.find("William");
    cout << it->second << '\n';

    auto it = m.begin();
    it = m.erase(it); //return an iterator pointing to the element that follows the erased element 
    //to wipe out all
    m.erase(m.begin(), m.end());
    if(m.empty())
        cout << "map is now empty!\n";

    return 0;
}