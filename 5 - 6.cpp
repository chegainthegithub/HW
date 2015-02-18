#include <iostream>

using namespace std;

int main()
{
    int n,x,d,u,y;
    cin >> n;
    int *m = new int[n];
    for(int i=0;i<n;i++)
        cin >> m[i];
    cin >> x;
    u = n-1;
    d = 0;
    while(true)
    {
        y = d + (u-d)*(x - m[d])/(m[u] - m[d]);
        if(m[y] = x)
            break;
        if(m[y] > x)
            u = y;
        else if(m[y] < x)
            d = y;
    }
    cout << y;
    delete[] m;
    return 0;
}
