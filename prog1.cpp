#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void reverseStr(string& str)
{
    int n = str.length();


    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
int main() {

	fstream f1,f2;
	char c[20];
	string s;
	int i;
	cout<<"enter the read file name: ";
	cin>>c;
	f1.open(c,ios::out);
	cout<<"enter text to write in file 1: ";
	cin>>s;
	while(s!="$")
	{
		f1<<s<<endl;
		cin>>s;

	}
	f1.close();

	f1.open(c,ios::in);

	cout<<"enter the 2nd file name you want to copy: ";
	cin>>c;
	f2.open(c,ios::out);

	f1>>s;
	reverseStr(s);
	while(!f1.eof()){
	cout<<s<<endl;
	f2<<s<<endl;
	f1>>s;
	reverseStr(s);
}
	f1.close();
	f2.close();
	return 0;
}
