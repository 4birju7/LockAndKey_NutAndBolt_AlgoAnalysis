#include <bits/stdc++.h>
using namespace std;

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
    
    //MatchPairing
    for (int i = 0 ; i < NumOfEle ; i++)
    {
        bool PairFound = false;
        for (int j = i ; j < NumOfEle ; j++)
        {
            if (nuts[i] == bolts[j])
            {
                swap(bolts[i],bolts[j]);
                PairFound = true;
            }
        }
        //checking if all pairs are matched.
        if(!PairFound)
        {
            cout << "ERROR!" << endl;
            cout << "NO PAIR FOUND, ERROR IN INPUTS. PLEASE RE-RUN THE PROGRAM!" << endl;
            return 0;
        }
    }
    
    cout << "NUTS  : " ;
    for(auto x:nuts)
        cout << x << ' ';
    
    cout << endl << "BOLTS : ";
    for(auto x:bolts)
        cout << x << ' ';
    
    cout << endl;
    return 0;
}
