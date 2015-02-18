#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *m = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> m[i];
    }
    for(int i=0;i<n;i++)
    {
        if((i!=0)&&(m[i] == m[i-1]))
        {
            for(int j=i;j<n-1;j++)
            {
                m[j] = m[j+1];
            }
            m[n] = 0;
            n--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << m[i] << ' ';
    }
    delete[] m;
    return 0;
}
