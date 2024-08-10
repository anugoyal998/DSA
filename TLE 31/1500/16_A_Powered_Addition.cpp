#include <iostream>
using namespace std;
int t, n, mx, md, c, x;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n, mx = -1e9, md = x = 0;
        while (n--)
            cin >> c, mx = max(mx, c), md = max(md, mx - c);
        while (md)
            md /= 2, x++;
        cout << x << endl;
    }
}
