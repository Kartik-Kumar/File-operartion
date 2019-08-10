
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void match(char *f1,char* f2)
{
	char temp1[25],temp2[25];

	fstream fp1,fp2;
	fp1.open(f1,ios::in);
	fp2.open(f2,ios::in);
	fp1.getline(temp1,25,'\n');
	fp2.getline(temp2,25,'\n');
	cout<<"comman names are:"<<endl;
	while(!fp1.eof() && !fp2.eof()){
		int x=strcmp(temp1,temp2);
		if(x==0){
			cout<<temp1<<endl;
			fp1.getline(temp1,25,'\n');
			fp2.getline(temp2,25,'\n');
		}
		else if(x<0)
			fp1.getline(temp1,25,'\n');

		else
			fp2.getline(temp2,25,'\n');
	}
	fp1.close();
	fp2.close();
}

int main() {
	int n,m;
	fstream fp1,fp2;
	char f1[10],f2[10],name[10];
	cout<<"---------"<<endl;
	cout<<"enter the first file name: ";
	cin>>f1;
	cout<<"enter the number of names in file one in ascending: ";
	cin>>n;
	fp1.open(f1,ios::out);
	cout<<"enter the "<<n<<" names: "<<endl;
	for (int i=0;i<n;i++){
		cin>>name;
		fp1<<name<<endl;
	}
	fp1.close();
	cout<<"enter the second file name: ";
	cin>>f2;
	cout<<"enter the number of names in file two in ascending: ";
	cin>>m;
	fp2.open(f2,ios::out);
	cout<<"enter the "<<m<<" names: "<<endl;
	for (int i=0;i<m;i++){
		cin>>name;
		fp2<<name<<endl;
	}
	fp2.close();

	match(f1,f2);

	return 0;
}
