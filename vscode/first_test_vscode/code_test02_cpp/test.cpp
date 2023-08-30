// #include <stdio.h>
#include <iostream>

using namespace std;

extern int Add(int x, int y);

int main()
{
    int a = 10;
    int b = 20;
    int sum = Add(a , b);
    // printf("%d",sum);
    cout<<sum;
    return 0;
}