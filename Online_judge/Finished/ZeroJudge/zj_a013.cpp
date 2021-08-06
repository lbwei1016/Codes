#include <bits/stdc++.h>

using namespace std;

typedef struct 
{
    char c;
    int num;
}NUM;
int convert(string a, NUM rome[])
{
    int left = 0, n1 = 0;
    for(int i=0; i<a.size(); i++) //number converting
    {
        for(int j=0; j<7; j++)
        {
            if(a[i] == rome[j].c)
            {
                if(rome[j].num <= left || left == 0) //normal: X+V+I+I = XVII -- descending
                {
                    n1 += left;
                    left = rome[j].num;
                }
                else
                {
                    n1 -= left;
                    left = rome[j].num; 
                }
                break;
            }
        }
    }
    return (n1+left);
}
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    NUM rome[7];
    rome[0] = {.c = 'I', .num = 1},
    rome[1] = {.c = 'V', .num = 5},
    rome[2] = {.c = 'X', .num = 10},
    rome[3] = {.c = 'L', .num = 50},
    rome[4] = {.c = 'C', .num = 100},
    rome[5] = {.c = 'D', .num = 500},
    rome[6] = {.c = 'M', .num = 1000};
    string a, b;
    while(cin >> a)
    {
        if(a == "#")
            break;
        cin >> b;
        if(a == b)
        {
            cout << "ZERO\n";
            continue;
        }
        int n1 = convert(a, rome),
            n2 = convert(b, rome);

        int res = abs(n1-n2); //1998

        int digits[5];
        stack<char> output;
        for(int &i : digits) //initiallize
            i = -1;
        for(int i=0; res > 0; i++, res/=10)
        {
            digits[i] = res%10; //8 9 9 1
        }
        for(int i=0, j=1; digits[i]!=-1; i++, j+=2) //j may exceed limits, but inputs are < 4000
        {
            int di = digits[i] % 5;
            int five = digits[i] / 5;
            if(!five)
            {
               if(di < 4)
                {
                    for(int k=0; k<di; k++)
                        output.push(rome[j-1].c);
                }
                else
                {
                    output.push(rome[j].c);
                    output.push(rome[j-1].c);
                }
            }
            else
            {
                if(di < 4)
                {
                    for(int k=0; k<di; k++)
                        output.push(rome[j-1].c);
                    output.push(rome[j].c);
                }
                else
                {
                    output.push(rome[j+1].c);
                    output.push(rome[j-1].c);
                }
            }
                
        }   

        while(output.size())
        {
            char temp = output.top(); output.pop();
            cout << temp;
        }
        cout << '\n';
    }
        
    return 0;
}
/*

羅馬數字	數目
I	1
V	5
X	10
L	50
C	100
D	500
M	1,000
*/