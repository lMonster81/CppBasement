#include<iostream>
using namespace std;

class A
{
    public:
    int a;
    A():a(1)
    {  
    }
};

class B : public A
{
public:
  int b;
  B()
  {

  }
};

int main()
{
    A a1;
    B b1;
    cout << b1.a << endl;
    cout << b1.b << endl;
    getchar();
    return 0;
}