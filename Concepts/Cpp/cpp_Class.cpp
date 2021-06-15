#include <iostream>

using namespace std;

class Animal
{
    private:
        const int id; 
        //private members can only be accessed through "member functions"
        //const variables must be initialized once declared("id" will be initialized when constructor is called)
    public:
        Animal() : id(0){}; //defined inside class
        Animal(string, int); //only declared
        ~Animal(); //destructor; automatically called at the end of a function
        string name;
        int age;
        void Talk();
        void set_id(int t);
        void display();
    
};
Animal::Animal(string name, int age) : id(0) //define constructor, initializing const int "id" simultaneously
{
    this->name = name;
    this->age = age;
}
Animal::~Animal()
{
    cout << "object destructed\n"; 
}
void Animal::Talk()
{
    cout << this->name + "\n";
}
void Animal::display()
{
    cout << id << endl;
}

int main()
{
    Animal dog, cat("CAT", 10);
    dog.name = "DOG";
    dog.Talk();
    dog.display();
    cat.Talk();
    
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