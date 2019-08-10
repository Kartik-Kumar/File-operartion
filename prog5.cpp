
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;
char name[20], temprrn[5];
fstream fp1, fp2;
int count=0, rrncount=1, r=-1;

class Student{
	public: char fname[15], lname[15], usn[11], branch[5], age[5];
};

Student s[100], t;

void pack(Student t){
	char buffer[100];
	strcpy(buffer, t.fname);
	strcat(buffer, "|");
	strcat(buffer, t.lname);
	strcat(buffer, "|");
	strcat(buffer, t.usn);
	strcat(buffer, "|");
	strcat(buffer, t.branch);
	strcat(buffer, "|");
	strcat(buffer, t.age);
	strcat(buffer, "|");

	int x = strlen(buffer);

	for (int j=0; j<=60-x; j++)
	{
		strcat(buffer, "@");
	}

	fp1.open(name, ios::out|ios::app);
	fp1<<rrncount<<"|"<<buffer<<endl;
	fp1.close();

	fp2.open("index.txt", ios::out|ios::app);
	fp2<<t.usn<<"|"<<rrncount<<"|"<<endl;
	fp2.close();

	rrncount++;
}

void search()
{
	char keyusn[11], buffer1[50], buffer2[100], tempusn[11];

	cout<<"Enter the USN to search for: "<<endl;
	cin>>keyusn;

	fp2.open("index.txt", ios::in);
	while(!fp2.eof())
	{
		fp2.getline(buffer1, 50);
		sscanf(buffer1, "%[^|]|%[^|]|", tempusn, temprrn);
		if(strcmp(keyusn, tempusn)==0)
		{
			r = atoi(temprrn);
			fp1.open(name, ios::in);
			fp1.seekg((r-1)*64, ios::beg);
			fp1.getline(buffer2, 100);
			sscanf(buffer2, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|", temprrn, t.fname, t.lname, t.usn, t.branch, t.age);
			cout<<"First name: "<<t.fname<<endl;
			cout<<"Last name: "<<t.lname<<endl;
			cout<<"USN: "<<t.usn<<endl;
			cout<<"Branch: "<<t.branch<<endl;
			cout<<"Age: "<<t.age<<"\n"<<endl;
			fp1.close();
			fp2.close();
			return;
		}
	}
	cout<<"Record not found!!!"<<endl;
	fp2.close();
}

void del()
{
	if(r==-1)
	{
		return;
	}
	int i=1;
	char buffer[100];
	fp1.open(name, ios::in);
	while(!fp1.eof())
	{
		fp1.getline(buffer, 100);
		sscanf(buffer , "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|", temprrn, s[i].fname, s[i].lname, s[i].usn, s[i].branch, s[i].age);
		i++;
	}
	fp1.close();
	remove(name);
	remove("index.txt");
	fp1.open(name, ios::out);
	fp1.close();
	fp2.open("index.txt", ios::out);
	fp2.close();

	rrncount=1;
	for (int k=1; k<i-1; k++)
	{
		if(k!=r)
		{
			pack(s[k]);
		}
	}
	r=-1;
}

int main(){
	cout<<"Enter the file name: "<<endl;
	cin>>name;
	fp1.open(name, ios::out);
	fp1.close();
	fp2.open("index.txt", ios::out);
	fp2.close();

	while(true){
		int ch;
		cout<<"1.Pack \n2.Search \n3.Delete \n4.Exit "<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;

		switch(ch)
		{
		case 1: cout<<"Enter the First name:"<<endl;
				cin>>t.fname;
				cout<<"Enter the Last name:"<<endl;
				cin>>t.lname;
				cout<<"Enter the USN:"<<endl;
				cin>>t.usn;
				cout<<"Enter the branch:"<<endl;
				cin>>t.branch;
				cout<<"Enter the age:"<<endl;
				cin>>t.age;
				pack(t);
				break;

		case 2: search();
				count=0;
				break;

		case 3: search();
				del();
				break;

		case 4: exit(0);

		}
	}

}
