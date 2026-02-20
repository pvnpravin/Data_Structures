
#include<iostream>
using namespace std;


class Arithmatic
{
    private:
        int NO1, NO2;

    public:
        Arithmatic(int A, int B);
        int Addition();
        int Substraction();
};


// Errors
/*
program435.cpp:17:12: error: expected unqualified-id before 'int'
 Arithmatic(int A, int B)
            ^~~
program435.cpp:17:12: error: expected ')' before 'int'
program435.cpp: In function 'int Addition()':
program435.cpp:25:12: error: 'NO1' was not declared in this scope
     return NO1+NO2;
            ^~~
program435.cpp:25:16: error: 'NO2' was not declared in this scope
     return NO1+NO2;
                ^~~
program435.cpp: In function 'int Substraction()':
program435.cpp:30:12: error: 'NO1' was not declared in this scope
     return NO1-NO2;
            ^~~
program435.cpp:30:16: error: 'NO2' was not declared in this scope
     return NO1-NO2;

*/   
  
Arithmatic(int A, int B)
{
    this->NO1 = A;
    this->NO2 = B;
}

int Addition()
{
    return NO1+NO2;
}

int Substraction()
{
    return NO1-NO2;
}

int main()
{
    Arithmatic aObj(11,10);

    cout<<aObj.Addition()<<"\n";

    cout<<aObj.Substraction()<<"\n";

    return 0;
}