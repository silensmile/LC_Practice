#include<iostream>
#include<algorithm>

using namespace std;

int Huakuai() {
	int n, k, i = 0;
	int data[150000];
	//cin >> n >> k;
	//for(;i<n;i++)
	//{
	//	cin >> data[i];
	//}
	n = 7; k = 3;
	data[0] = 1;
	data[1] = 2;
	data[2] = 6;
	data[3] = 1;
	data[4] = 1;
	data[5] = 7;
	data[6] = 1;

	int sum = 0, summin = 0, indexmin = 1;
	int j = 0;
	for (j = 0; j < k; j++)
	{
		summin += data[j];
	}

	for (i = 0; i < n - j; i++)
	{
		for (j = 0; j < k; j++)
		{
			sum += data[i + j];
		}
		if (sum < summin)
		{
			summin = sum;
			indexmin = i;
		}
		sum = 0;
	}
	cout << indexmin + 1;
	
    return 0;
}