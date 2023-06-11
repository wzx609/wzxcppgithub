#include<bits/stdc++.h>
using namespace std;
int main()
{

	puts(setlocale(LC_CTYPE, "")); 
	wifstream in("test1.txt");
	wofstream out("10-10"); 
	wstring line; 
	map<wchar_t,int>counter;
	
	
	while(getline(in,line))
	{
		for(int i=0;i<line.length();++i)
		{
			counter[line[i]]++; 
		}
	}
	map<wchar_t,int>::iterator itor;
	int i=1;
	for(itor=counter.begin();itor!=counter.end();++itor,++i)
	{
		out<<itor->first<<"\t"<<itor->second<<"\t";
		if(i%4==0){
			out<<endl;
		}
	}
	in.close();
	out.close(); 
	
	return 0;
}