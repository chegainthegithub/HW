#include <iostream>

using namespace std;

int main()
{
    int n,x,u,d,k;
    cin >> n;
    int *m = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> m[i];
    }
    for(int i=1;i<n;i++)
    {
        u = i;
        d = 0;
        while((u-d) > 1)
        {
            if(m[i] >= m[(u+d)/2])
            {
                d = (u+d)/2;
            }
            else
            {
                u = (u+d)/2;
            }
        }
        k = i;
        while(k>u)
        {
            x = m[k];
            m[k] = m[k-1];
            m[k-1] = x;
            k--;
        }
        if(m[k]<m[k-1])
        {
            x = m[k];
            m[k] = m[k-1];
            m[k-1] = x;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << m[i] << ' ';
    }
    delete[] m;
    return 0;
}
