#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}

int Bingjiling() {
    int n, m;
    //cin >> n >> m;
    n = 5; m = 10;
    vector<vector<int>> data(n);
    for (int i = 0; i < n; i++)
        data[i].resize(2);
    //for (int i = 0; i< n; i++)
    //{
    //    cin >> data[i][0];
    //}
    //for (int i = 0; i<n; i++)
    //{
    //    cin >> data[i][1];
    //}
    data[0][0] = 2; data[0][1] = 3;
    data[1][0] = 4; data[1][1] = 2;
    data[2][0] = 1; data[2][1] = 1;
    data[3][0] = 5; data[3][1] = 5;
    data[4][0] = 3; data[4][1] = 4;

    sort(data.begin(), data.end(), cmp);


    int prise = 0;
    int flag = 0;
    int i = 1;
    for (i = 1;; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (data[j][0] < i)
            {
                prise += (i - data[j][0]) * data[j][1];
            }
        }
        if (prise > m)
            break;
        prise = 0;
    }

    cout << i - 1;



    return 0;
}