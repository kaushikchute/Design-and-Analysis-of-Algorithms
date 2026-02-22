#include <iostream>
using namespace std;

int main()
{
    // Array of Indian currency denominations (ascending order)
    int array[11] = {1,2,5,10,20,50,100,200,500,1000,2000};
    
    int x;
    cout << "Enter the value of X (amount to be made): " << endl;
    cin >> x;

    // temp stores the remaining amount to be formed
    int temp = x;

    cout << "For making " << x << " we need the coins: " << endl;

    // Traverse from largest denomination to smallest
    for(int i = 10; i >= 0; i--)
    {
        // Keep taking the current coin while it fits in remaining amount
        while(temp >= array[i])
        {
            cout << array[i] << " ";
            temp -= array[i];   // Reduce remaining amount
        }
    }

    return 0;
}