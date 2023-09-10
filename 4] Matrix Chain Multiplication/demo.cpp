#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int x;
    int ans;

    while(true)
    {
        cout << "\nNumber         : ";
        cin >> x;

        ans = log2(x);
        cout << "Log            : " << ans << endl;
        cout << "Accurate Value : " << log2(x) << endl;
    }
}