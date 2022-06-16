#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

template <typename T, typename W>
W sum(T a, W b) { return a + b; }

struct rec
{
    int val;
    char str[12];
    int *a[2];
};

rec arr1[3];

struct record
{
    char buf[8]; // char array
    char *str;   // string array
    int a[10];   // int array
};
record viele[6]; // record array -->
                 // {record{buf{}, str{}, a{}},
                 // record{buf{}, str{}, a{}},
                 // record{buf{}, str{}, a{}}
                 // record{buf{}, str{}, a{}}
                 // record{buf{}, str{}, a{}}
                 // record{buf{}, str{}, a{}}
//}
/*

• p1 als Zeiger, der auf das vorletzte struct rec in arr zeigt.
• p2 als unveränderliche Zeiger auf das letzte Element von arr. Verwenden Sie nur p1 und nicht arr.
• r3 als unveränderliche Referenz auf das erste Element von arr.
• r4 als Referenz auf das ersten Element des bufs des ersten Elements von arr.

*/

void fun(const int x) { cout << "a"; }
void fun(const char x) { cout << "b"; }
void fun(const int *x) { cout << "c"; }
void fun(const char *x) { cout << "d"; }
struct st
{
    // 1 placeholder
    // char ch; // 1
    short sh; // 2
    int in;   // 4
    // long l;
};

class Noisy
{
public:
    Noisy() { std::cout << "std" << std::endl; }
    Noisy(const Noisy &) { std::cout << "con" << std::endl; }
    Noisy(int i) { std::cout << "coi" << std::endl; }
    Noisy &operator=(const Noisy &)
    {
        std::cout << "ass" << std::endl;
        return *this;
    }
};

class K
{
private:
    char a, b;
    char *c;

public:
    K() : K('a', 'b') {}
    K(char a) : K(a, 'b') {}
    K(char _a, char _b, const char *s = "nothing") : a(_a), b(_b)
    {
        c = new char[strlen(s) + 1];
        strcpy(c, s);
    }
    ~K()
    {
        delete[] c;
    }

    void show()
    {
        cout << a << " " << b << " " << c << endl;
    }
    char aa() const
    {
        return a;
    }
    char &aa()
    {
        return a;
    }
    char bb() const
    {
        return b;
    }
    char &bb()
    {
        return b;
    }
    char *cc() const
    {
        return c;
    }

    char &cc(int pos) const
    {
        return c[pos];
    }
};

int main()

{
    K k1{'a', 'b', "abcdef"};
    K k2{'c', 'd', "abcdef"};
    const K k3{'e', 'f', "abcdef"};
    cout << k1.aa() << k2.aa() << k3.aa() << endl; // ace
    cout << k1.bb() << k2.bb() << k3.bb() << endl; // bdf
    k1.aa() = k2.aa() = k3.aa();
    k1.bb() = k2.bb() = k3.bb();
    cout << k1.aa() << k2.aa() << k3.aa() << endl; // eee
    cout << k1.bb() << k2.bb() << k3.bb() << endl; // fff
    cout << k1.cc() << " " << k2.cc() << " " << k3.cc();
    cout << endl;                                     // abcdef abcdef abcdef
    cout << k1.cc(0) << k2.cc(1) << k3.cc(2) << endl; // abc
    k1.cc(1) = k1.cc(2) = k2.cc(2) = k3.cc(3);
    cout << k1.cc() << " " << k2.cc() << " " << k3.cc();
    cout << endl; // adddef abddef abcdef
    /*
    st s;

    cout << sizeof(s) << endl;


     int a[17] = {0, 100, 200, 300, 400, 500, 120, 700, 8, 900, 10, 11, 12, 13, 14, 15, 16};
     long b[42] = {0};
     char c[20] = {1, 2, 3};
     int i;
     cout << &a[6] << endl;
     cout << &a[2] << endl;
     cout << (&a[6] - &a[2]) << endl;
     cout << (&b[17] - &b[11]) << endl;
     cout << (&c[3] - &c[1]) << endl

     char s[] = "Hello";
     //fun(s);
     //fun(s[0]);
     // fun(s[0] + 65536);
     fun(65536);
     cout << endl;


     record *p1 = &viele[4];
     record *p2 = p1 + 1;
     const record &r3 = viele[0];
     char &r4 = viele[0].buf[0];

     auto p1 = &arr[1];
     cout << "Size of p1:       " << sizeof(p1) << endl;
     cout << "Size of &arr[2]:  " << sizeof(&arr[2]) << endl;
     cout << "Adress of p1:       " << p1 << endl;
     cout << "Adress of &arr[2]:  " << &arr[2] << endl;
     cout << (&arr[2] - p1) << ", ";

     auto p2 = &p1->str[4];
     cout << "Size of p2:                   " << sizeof(p2) << endl;
     cout << "Size of &arr[0].str[6]:         " << sizeof(&arr[0].str[6]) << endl;

     cout << (p2 - &arr[0].str[6]) << endl;
     */
    return 1;
}