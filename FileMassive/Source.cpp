#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void AddElement(vector<int>&v, int num)
{
	v.push_back(num);
}

void check(vector<int>& v)
{
	ifstream fin("massive.txt", ios_base::binary);
	if (!fin.is_open())
	{
		return;
	}
	if (!(bool)v.size())
	{
		for (size_t i = 0; i < 5; i++)
		{
			v.resize(i + 1);
			fin.read((char*)&v[i], sizeof(int));
		}

		fin.close();
	}
	
}

void fWrite(vector<int>& v)
{
	ofstream fout;
	fout.open("massive.txt", ios_base::binary | ios_base::trunc);
	for (size_t i = 0; i < v.size(); i++)
	{
		fout.write((char*)&v[i], sizeof(int));
	}
	fout.close();
}

void main()
{
	vector<int> v;
	check(v);
	int choose, num;
	while (1)
	{
		cout << "1. Add element\n2. Show elements\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Enter the number for vector : \n";
			cin >> num;
			AddElement(v, num);
			fWrite(v);
			break;
		case 2:
			for (size_t i = 0; i < v.size(); i++)
			{
				cout << v[i] << "\t";
			}
			cout << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}