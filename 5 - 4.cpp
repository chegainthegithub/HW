#include <iostream>

using namespace std;

int main()
{
    int n,x;
    cin >> n;
    int *m = new int[n],k = n/2;
    for(int i=0;i<n;i++)
    {
        cin >> m[i];
    }
    while(k>=1)
    {
        for(int i=0;i<k;i++)
        // i - номер "группы"
        {
            for(int j=0;j<n/k;j++)
            // j - номер элемента "группы"
            {
                l = j;
                while((m[j*k+i]<m[j*k+i-1])&&(l>0))
                {
                    x = m[j*k+i];
                    m[j*k+i] = m[j*k+i-1];
                    m[j*k+i-1] = x;
                    j*k+i--;
                }
            }
        }
        k /= 2;
    }
    for(int i=0;i<n;i++)
    {
        cout << m[i] << ' ';
    }
    delete[] m;
    return 0;
}
