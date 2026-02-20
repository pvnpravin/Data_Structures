
#include<iostream>
using namespace std;


class Arithmatic
{
    private:
        int NO1, NO2;

    public:
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
};

int main()
{
    Arithmatic aObj(11,10);

    cout<<aObj.Addition()<<"\n";

    cout<<aObj.Substraction()<<"\n";

    return 0;
}