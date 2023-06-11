#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream infile;
	infile.open("test.txt");
	ofstream outfile;
	outfile.open("test2.txt",ios::out);
	int num_line=1;	
	char buffer[256]; 
	while(!infile.eof()){

		if (!infile.getline(buffer, sizeof(buffer))){

			break;
		}
		while(infile.getline(buffer,256))
	    {
	    	outfile.width(10); 
	        outfile << num_line++ << ". ";
	        outfile << buffer <<endl;
	    }
	}
	infile.close();
	outfile.close();
	cout<<"操作成功，程序结束！\n";
	return 0; 
}