#include <iostream>

using namespace std;

int main()
{
    int n,mx=0,k=1;
    cin >> n;
    int *m = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> m[i];
    }
    for(int i=1;i<n;i++)
    {
        if(m[mx]<m[i])
        {
            mx = i;
        }
        //cout << mx << i << endl;
    }
    //cout << mx << endl;
    //cin >> k;
    bool flag;
    while(k<m[mx])
    {
        flag = 1;
        for(int i=0;i<n;i++)
        {
            if(m[i] == k)
            {
                flag = 0;
            }
        }
        if(flag == 1)
        {
            cout << k << ' ';
        }
        k++;
    }
    delete[] m;
    return 0;
}
