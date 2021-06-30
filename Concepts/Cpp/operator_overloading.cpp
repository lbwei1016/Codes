#include <iostream>

using namespace std;

int main() {
    
    return 0;
}
/*
    運算子函式有兩種實作方式
        1. 成員函式(Member functions)
        ? 使用this來取得主要運算元
        ? 其餘運算元位於參數列上
        ? 最左邊的物件型態必須跟運算子的類別相同
        ? 如:Date1+Date2, 則Date1的operator+(Date2)函式被呼叫

        2. 非成員函式(Non member functions)
        ? 每個運算元皆位於參數列上
        ? 最左邊的物件型態可以跟運算元的類別不同
        ? 如要存取private或protected資料成員,則必須是friend
        ? 如:Date1+Date2, 則operator+(Date1, Date2)函式被呼叫
*/