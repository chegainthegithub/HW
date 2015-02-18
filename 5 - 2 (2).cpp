#include <iostream>

using namespace std;

int main()
{
    int n,x,k;
    cin >> n;
    int *m = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> m[i];
    }
    for(int i=1;i<n;i++)
    {
        k=i;
        while((m[k]<m[k-1])&&(k>0))
        {
            x = m[k];
            m[k] = m[k-1];
            m[k-1] = x;
            k--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << m[i] << ' ';
    }
    delete[] m;
    return 0;
}
