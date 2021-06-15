//unknown reason for WA
#include <bits/stdc++.h>

using namespace std;

vector<int> pile, sorted, ans;

void flip(int pos)
{
    vector<int> temp;
    for(int i=0; i<pos-1; i++)
    {
        int k = pile.back();
        temp.push_back(k);
        pile.pop_back();
    }
    reverse(pile.begin(), pile.end());
    while(temp.size())
    {
        int k = temp.back();
        pile.push_back(k);
        temp.pop_back();
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    vector<vector<int> > input, answer;

    while(getline(cin, s))
    {
        pile.clear();
        sorted.clear();
        ans.clear();

        stringstream ss; //#include <sstream>
        ss << s; //convert string with space into separate numbers
        int num = 0;
        while(ss >> num)
            pile.push_back(num);

        input.push_back(pile);
        
        
        sorted = pile;
        sort(sorted.begin(), sorted.end());
        ans = sorted;

        vector<int> procedure;
        int sz = pile.size();
        for(int i=0, end_pos=sz-1; i<sz;)
        {
            if(pile == ans)
                 break;
            int max = (sorted[sorted.size()-1]);
            if(pile[0] == max)
            {
                sorted.pop_back();
                int p = sz - end_pos;
                flip(p);
                procedure.push_back(p);
                end_pos--;
            }
            else if(pile[end_pos] == max)
            {
                sorted.pop_back();
                end_pos--;
            }
            else if(pile[i] == max && i!=end_pos)
            {
                int p = sz - i;
                flip(p);
                procedure.push_back(p);
                i = 0;
            }
            else
                i++;
        }
        answer.push_back(procedure);
    }

    for(int i=0; i<input.size(); i++)
    {
        for(int j=0; j<input[i].size(); j++)
        {
            if(j < input[i].size()-1)
                cout << input[i][j] << ' ';
            else
                cout << input[i][j];
        }
        cout << '\n';
        for(int j=0; j<answer[i].size(); j++)
        {
            //if(j < answer[i].size()-1)
                cout << answer[i][j] << ' ';
            // else
            //     cout << answer[i][j];
        }
        if(i < input.size()-1)
            cout << "0\n";
        else
            cout << '0';
    }
    return 0;
}