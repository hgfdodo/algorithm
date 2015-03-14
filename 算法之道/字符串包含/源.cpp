/*
author: Guangfu he
mail:hgfdodo@gmail.com
*/


#include <iostream>
#include <string>
using namespace std;

/*
挨个比较
时间复杂度O(m*n)
*/
bool method1(string a, string b)
{
	int la = a.length();
	int lb = b.length();

	bool flag = true;

	for (int j = 0; j < lb; j++)
	{
		bool tmp = false;
		for (int i = 0; i < la; i++)
		{
			if (b[j] == a[i])
			{
				tmp = true;
				break;
			}
		}
		if (tmp == false)
		{
			flag = false;
			break;
		}

	}

	return flag;
}

/*
使用hash的方法，时间复杂度O(m+n)
*/
bool method2(string a,string b)
{
	bool flag=true;
	int ku[26];
	memset(&ku, 0, 26 * sizeof(int));
	int la = a.length();
	int lb = b.length();

	for (int i = 0; i < la; i++)
	{
		ku[a[i] - 'a'] = 1;
	}
	for (int j = 0; j < lb; j++)
	{
		int tmp = b[j] - 'a';
		if (ku[tmp] == 0)
		{
			flag = false;
			break;
		}
	}


	return flag;
}

int main()
{
	string a = "abcdefg";
	string b = "cde";
	cout << method2(a, b) << endl;
	cin >> a;
	return 0;
}