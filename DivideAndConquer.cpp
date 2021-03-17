#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int pivot, int start, int end)
{
    int i = start;
    for (int j = start ; j < end ; j++)
    {
        if (a[j] < pivot)
        {
            swap(a[i], a[j]);
            i++;
        }
        else if (a[j] == pivot)
        {
            swap(a[j], a[end]);
            j--;
        }
    }
    swap(a[i], a[end]);
    return i;
}

void nutBoltMatch(vector<int> &nuts, vector<int> &bolts, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(nuts, bolts[end], start, end);
        partition(bolts, nuts[pivot], start, end);
        nutBoltMatch(nuts, bolts, start, pivot - 1);
        nutBoltMatch(nuts, bolts, pivot + 1, end);
    }
}

int main()
{
    int NumOfEle, temp;
    cout << "PLEASE ENTER THE NUMBER OF BOLTS AND NUTS PAIRS : ";
    cin >> NumOfEle;
    
    vector<int> nuts, bolts;
    cout << "PLEASE ENTER SIZES OF ALL N NUTS : ";
    for (int i = 0 ; i < NumOfEle ; i++)
    {
        cin >> temp;
        nuts.push_back(temp);
    }
    
    cout << "PLEASE ENTER SIZES OF ALL N BOLTS : ";
    for (int i = 0 ; i < NumOfEle ; i++)
    {
        cin >> temp;
        bolts.push_back(temp);
    }
    
    nutBoltMatch(nuts, bolts, 0, NumOfEle-1);
    
    cout << "NUTS  : " ;
    for (auto x : nuts)
        cout << x << ' ';
    
    cout << endl << "BOLTS : ";
    for (auto x : bolts)
        cout << x << ' ';
    
    cout << endl;
    return 0;
}
