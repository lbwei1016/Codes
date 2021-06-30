#include <bits/stdc++.h>

using namespace std;

char s[11];
const char digits[][10] =
	{"", "", "", "hundred", "thousand", "million", "billion", "trillion"};
const char num[][10] =
	{"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
	 "ten","eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
	 "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

void toRead_2(int d_0, int d_1, int i)
{
    bool flag = false;
	int level = d_0/3;
	if(s[i] == '0' && d_1 != 1)
	{
	    flag = true;
	     d_1--;
	     i++;
	}
    if(d_1 == 1)
    {
        if(s[i] == '0' && !flag)
            printf("zero");
        else
            printf("%s", num[s[i]-'0']);
    }
    else
    {
        if(s[i] == '1')
            printf("%s", num[10+s[i+1]-'0']);
        else
        {
            if(s[i+1] == '0')
                printf("%s", num[18+s[i]-'0']);
            else
                printf("%s-%s", num[18+s[i]-'0'], num[s[i+1]-'0']);
        }
    }

    if(level > 0 && s[i]!='0')
        printf(" %s ", digits[3+level]);

}
void toRead_3(int d_0, int i)
{
	int level = d_0/3;
	for(int j=level; j>0; j--)
	{
	    if(s[i] == '0')
            toRead_2(d_0-3*(level-j+1), 2, i+1);
		else if(s[i+1] == '0')
        {
            if(s[i+2]-'0' == 0)
                printf("%s %s", num[s[i]-'0'], digits[3]);
            else
                printf("%s %s %s", num[s[i]-'0'], digits[3], num[s[i+2]-'0']);
        }
		else if(s[i+1] == '1')
			printf("%s %s %s", num[s[i]-'0'], digits[3], num[10+s[i+2]-'0']);
		else
        {
            if(s[i+2]-'0' == 0)
                printf("%s %s %s", num[s[i]-'0'], digits[3], num[18+s[i+1]-'0']);
            else
                printf("%s %s %s-%s", num[s[i]-'0'], digits[3], num[18+s[i+1]-'0'], num[s[i+2]-'0']);
        }


		if(j > 1 && s[i]!='0')
			printf(" %s ", digits[2+j]);

		i += 3;
	}
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	scanf("%s", s);

	int k = 0;
	if(s[0] == '-')
	{
	    if(s[1] != '0')
            cout << "minus ";
		k = 1;
	}

	int d_0 = strlen(s)-k; //當前位數
	if(d_0%3 == 0)
		toRead_3(d_0, k);
	else
	{
		int d_1 = d_0%3; //剩餘位數
		d_0 -= d_1;

		toRead_2(d_0, d_1, k);
		toRead_3(d_0, d_1+k);
	}
	putchar('\n');


	return 0;
}
