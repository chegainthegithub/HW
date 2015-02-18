#include <iostream>

using namespace std;

int main()
{
    int n,k=0;
    cin >> n;
    int *m = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> m[i];
    }
    for(int i=0;i<n;i++)
    {
        if(m[i] == 0)
        {
            k++;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(m[i]!=0)
        {
            k++;
            for(int j=i+1;j<n;j++)
            {
                if(m[j] == m[i])
                {
                    m[j] = 0;
                }
            }
        }
    }
    cout << k;
    delete[] m;
    return 0;
}
