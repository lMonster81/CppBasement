#include<iostream>
using namespace std;

template<typename T>
class SharePtr
{
    private:
      T *ptr;
      int *count;
    public:
    SharePtr(T *newptr):ptr(newptr), count(new int(1))
    {
        cout << (*ptr) << "  number  " << (*count) << endl;
    }
    SharePtr(SharePtr &sp)
    {
        cout << "copy" << endl;
        ptr = sp.ptr;
        count = sp.count;
        (*count)++;
    }
    ~SharePtr()
    {
        Release();
    }
    SharePtr& operator=(const SharePtr &sp)
    {
        if(ptr != sp.ptr)
        {
            Release();
            ptr = sp.ptr;
            count = sp.count;
            (*count)++;
        }
        return *this;
    }
    void Release()
    {
        if(--(*count) == 0)
        {
            cout << (*ptr) << "  remain  " << (*count) << endl;
            delete ptr;
            delete count;
        }
        else
            cout << (*ptr) << "  remain  " << (*count) << endl;
    }

    T& operator *()
    {
        return *ptr;
    }
};

int main()
{
    {
        SharePtr<int> s1(new int(2));
        SharePtr<int> s2 = s1;
        cout << *s1 << endl;
        SharePtr<int> s3 = s1;
        SharePtr<int> s4(new int(3));
        s4 = s1;
    }
    cout << "`````````````````" << endl;
    /*
    {
        SharePtr<string> s1(new string("123123"));
        SharePtr<string> s2 = s1;
        SharePtr<string> s3(s2);
    }
    cout << "!!!!!!!!!!!!!!!!" << endl;
    */
    getchar();
    return 0;
}