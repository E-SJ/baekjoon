#include <iostream>
using namespace std;

int main()
{
    int testnum;
    int group;
    cin >> testnum;
    cin >> group;
    int min = 0, mid, max = 0;
    int* score = new int[testnum];
    for (unsigned i = 0; i < testnum; i++)
    {
        cin >> score[i];
        max+= score[i];
    }
    mid = max / 2;
    int temp, tempgroup;
    while (1)
    {
        temp = 0;
        tempgroup = 0;
        for (unsigned i = 0; i < testnum; i++)
        {
            temp += score[i];
            if (temp >= mid)
            {
                temp = 0;
                tempgroup++;
                if (tempgroup == group)
                    break;
            }
        }
        if (tempgroup == group)
            min = mid + 1;
        else
            max = mid - 1;
        mid = (min + max) / 2;
        if (min > mid || max<mid)
            break;
    }
    cout << mid;
}
