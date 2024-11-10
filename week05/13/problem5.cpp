#include <iostream>
#include <vector>
using namespace std;

int add123(int a)
{
    if(a==1|| a==2)
    {
        return a;
    }
    if(a==3)
    {
        return 4;
    }

    return add123(a-1)+add123(a-2)+add123(a-3);
}

int main()
{
    int n;

    cin >> n;
    
    
    for(int i=0; i<n; i++){
        int num;
        cin >> num;

        cout << add123(num) << endl;
    }
    
    return 0;
}
