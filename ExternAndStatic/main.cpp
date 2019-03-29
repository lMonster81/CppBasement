#include<iostream>
using namespace  std;

class Test
{
private:
  int a = 1;
  char b = 'b';

public:
    Test()
    {

    }
    ~Test(){}
    int geta()
    {
        return a;
    }
    char getb()
    {
        return b;
    }
};


int main()
{
    Test a;
    cout << a.geta() << endl;
    cout << a.getb() << endl;
    getchar();
    return 0;
}