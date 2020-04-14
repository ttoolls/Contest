#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;


struct Pallet
{
	int m_w;
	int m_h;
};

bool ComparePalletes(const Pallet& p1, const Pallet& p2)
{
	bool res = false;
	if (p1.m_w == p2.m_w)
		return p1.m_h > p2.m_h;
	else return p1.m_w > p2.m_w;
}



void PrintPalletes(vector<Pallet> palletes)
{
	for (const auto& i : palletes)
	{
		cout << i.m_h << ' ' << i.m_w << endl;
	}
}

int RunPalletes()
{
	int n;
	cin >> n;	
	vector<Pallet> palletes;
	for (int i = 0; i < n; i++)
	{
		int w, h, tmp;
		cin >> w >> h;
		if (h > w)
		{
			tmp = w;
			w = h;
			h = tmp;
		}
		palletes.push_back({ w,h });
	}
	sort(palletes.begin(), palletes.end(), ComparePalletes);	
	
	if (n == 0)
	{
		cout << n;
		return 0;
	}

	int count = 0;	
	int tmp = 0;	
	int same = 1;
	for (int j = tmp+1; j<n; j++)
	{		
		if (palletes[tmp].m_w == palletes[j].m_w && palletes[tmp].m_h == palletes[j].m_h)
		{	
			same ++;
			for (int i = j; i<n; i++)
			{
				if (palletes[tmp].m_w == palletes[i].m_w && palletes[tmp].m_h == palletes[i].m_h)
				{
					same++;
					j=i;
				}
			}
			tmp == j;						
		}
		if (palletes[j].m_h < palletes[tmp].m_h)
		{
			count++;
			tmp = j;
		}			
	}
	cout << count-same;
	return 0;
}