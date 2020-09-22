#include <cstdio>

using namespace std;

int add(int a, int b)  
{ 
    int s = a ^ b; 
    int overflow = a & b;
  
    if (overflow == 0) return s; 
    else return add(s, overflow << 1); 
}

int main()
{
    int a, b;

    // I prefer to use scanf/printf rather than cin/cout as they're much faster than the latter ones.
    scanf("%d %d", &a, &b);
    printf("%d", add(a, b));

    return 0;
}