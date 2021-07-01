#include <iostream>
using namespace std;

int main()
{
    long long int city_num;
    cin >> city_num;
    long long int*length = new long long int[city_num - 1];
    long long int*price = new long long int[city_num];
    long long int result = 0;
    for (unsigned i = 0; i < city_num - 1; i++)
        cin >> length[i];
    for (unsigned i = 0; i < city_num; i++)
        cin >> price[i];
    long long int* best_price = new long long int[city_num];
    best_price[0] = price[0];
    for (unsigned i = 1; i < city_num; i++)
    {
        best_price[i] = min(best_price[i - 1], price[i]);
    }
    for (unsigned i = 0; i < city_num-1; i++)
    {
        result += (best_price[i] * length[i]);
    }
    delete[] length;
    delete[] price;
    delete[] best_price;
    cout << result;
}
