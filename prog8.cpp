//============================================================================
// Name        : prog8.cpp
// Author      : kartik kumar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
fstream fp[8];
char name[20][30];
void sort(int n){
	char t[30];
	for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(strcmp(name[j-1], name[j])>0)
				{
					strcpy(t, name[j-1]);
					strcpy(name[j-1], name[j]);
					strcpy(name[j], t);
				}
			}
		}
}
void merge_file(char *f1,char *f2, char *f3){
	fstream fp1,fp2,fp3;
	fp1.open(f1,ios::in);
	fp2.open(f2,ios::in);
	fp3.open(f3,ios::out);

	int k=0;
	while(!fp1.eof())
	{
		fp1.getline(name[k],20);
		k++;
	}
	k--;
	while(!fp2.eof())
		{
			fp2.getline(name[k],20);
			k++;
		}
	k--;
	sort(k);
	for(int i=0;i<k;i++)
		fp3<<name[i]<<"\n";

}
void kmerge(){
	merge_file("1.txt","2.txt","11.txt");
	merge_file("3.txt","4.txt","22.txt");
	merge_file("5.txt","6.txt","33.txt");
	merge_file("7.txt","8.txt","44.txt");
	merge_file("11.txt","22.txt","111.txt");
	merge_file("33.txt","44.txt","222.txt");
	merge_file("111.txt","222.txt","final.txt");
}

int main() {

	int n;
	char file[8][10]={"1.txt","2.txt","3.txt","4.txt","5.txt","6.txt","7.txt","8.txt"};
	char name[10];
	cout<<"enter the no of name: ";
	cin>>n;
	for (int i=0;i<8;i++){
		fp[i].open(file[i],ios::out);
	}
	cout<<"entyer the n names "<<endl;
	for(int i=0;i<n;i++){
		cin>>name;
		fp[i%8]<<name<<endl;
	}
	for (int i=0;i<8;i++){
			fp[i].close();
		}

	kmerge();
	return 0;
}
