#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream fo;
    for (int j = 1 ; j <= 12 ; j++)
    {
        vector<int> v;
        int NumOfEle = pow(2,j+9);
        fo.open("InputBolts"+to_string(j)+".txt", ios_base::app);
        for (int i = 1 ; i <= NumOfEle ; i++)
        {
            v.push_back(i);
            fo << i << endl;
        }
        fo.close();
        unsigned seed = 40;
        
        // Shuffling our array
        shuffle(v.begin(), v.end(),default_random_engine(seed));
        fo.open("InputNutsAvg"+to_string(j)+".txt", ios_base::app);
        for (int i = 0 ; i < v.size() ; i++)
            fo << v[i] << endl;
        
        fo.close();
        fo.open("InputNutsWorst"+to_string(j)+".txt", ios_base::app);
        for (int i = NumOfEle ; i > 0 ; i--)
            fo << i << endl;
        
        fo.close();
        cout << j << " file generated!"<< endl;
    }
    return 0;
}

/*THIS FILE IS CREATED BY BRIJESH ROHIT (4birju7)*/
