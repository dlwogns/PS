#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int fnum;
	cin >> fnum;
	while (fnum--)
	{
		string function1;
		string arrinput;
		int size;
		deque<int>arr;

		cin >> function1;
		cin >> size;
		cin >> arrinput;
		int ii = 0;
		while (arr.size()!=size)
		{
			
			int x = 0;
			while (arrinput[ii] >= 0x30 && arrinput[ii] <= 0x39)
			{
				x *= 10;
				x += int(arrinput[ii] - '0');
				ii++;
			}
			if(x!=0){
				arr.push_back(x);
			}
			ii++;
			
		}
		
		int is = 0;
		bool reverse = 0;
		for (auto e : function1) {
			if (e=='R')
			{
				reverse = !reverse;
					
			}
			else if(e=='D'){
				if (arr.size() == 0)
				{
					is = 1;
					break;
				}
				else if (!reverse)
					arr.pop_front();
				else
					arr.pop_back();
					
			
			}
		}
		if (is==1)
		{
			cout << "error\n";
		}
		else {
			cout << "[";
			while (!arr.empty())
			{
				if (!reverse) {
					auto c = arr.front();
					arr.pop_front();
					cout << c;

				}
				else {
					auto c = arr.back();
					arr.pop_back();
					cout << c;

				}
				if (!arr.empty())
					cout << ",";
			}
			cout << "]\n";
		}
	}

}