#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Student
{
public :
	char fname[20];
	char lname[20];
	char usn[10];
	char dep[5];
	char sem[3];
};
Student s[100];
Student t;
fstream f1;
char c[20];
int count,src_index;
void input()
{
	cout<<"enter the name: ";
	cin>>t.fname;
	cout<<"enter the last name: ";
	cin>>t.lname;
	cout<< "enter the usn: ";
	cin>>t.usn;
	cout<<"enter the deptment: ";
	cin>>t.dep;
	cout<<"enter the sem: ";
	cin>>t.sem;
}
void display()
{

	for(int i=0;i<count-1;i++)
	{
	cout<<"name:"<<s[i].fname<<endl;
	cout<<"lastname:"<<s[i].lname<<endl;
	cout<<"usn:"<<s[i].usn<<endl;
	cout<<"department:"<<s[i].dep<<endl;
	cout<<"sem:"<<s[i].sem<<endl;
	}
}

void pack(Student z)
{
	char buffer[100];

	strcpy(buffer,z.fname);
	strcat(buffer,"|");
	strcat(buffer,z.lname);
	strcat(buffer,"|");
	strcat(buffer,z.usn);
	strcat(buffer,"|");
	strcat(buffer,z.dep);
	strcat(buffer,"|");
	strcat(buffer,z.sem);
	strcat(buffer,"|");



	f1.open(c,ios ::out|ios::app);
	f1<<buffer<<endl;
	f1.close();
}

void unpack()

{
	char buf[100];
	int i=0;
	f1.open(c,ios::in);
	while(!f1.eof())
	{
		f1.getline(buf,80);
		sscanf(buf,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",s[i].fname,s[i].lname,s[i].usn,s[i].dep,s[i].sem);
		i++;


	}
	count=i;
	f1.close();
}
void modify()
{
	if (src_index==-1)
		return;
	int i=src_index;
	cout<<"enter the new file name :";
	cin>>c;

	cout<<"enter the name: ";
	cin>>s[i].fname;
	cout<<"enter the last name: ";
	cin>>s[i].lname;
	cout<<"enter the deptment: ";
	cin>>s[i].dep;
	cout<<"enter the sem: ";
	cin>>s[i].sem;
	f1.open(c,ios::out);f1.close();
	for(int j=0;j<count;j++){
		pack(s[j]);
	}

}
void search()
{
	src_index=-1;
	char key_usn[15];
	cout<<"enter the key usn to search: ";
	cin>>key_usn;
	for(int i =0;i<count;i++){
		if (strcmp(key_usn,s[i].usn)==0){
			cout<<"value found at position "<< i <<endl;
			cout<<"name:"<<s[i].fname<<endl;
			cout<<"lastname:"<<s[i].lname<<endl;
			cout<<"usn:"<<s[i].usn<<endl;
			cout<<"department:"<<s[i].dep<<endl;
			cout<<"sem:"<<s[i].sem<<endl;
			src_index= i;
			return ;
		}

	}
	cout<<"value not found opsssssssss"<<endl;
}

int main()
{

	int choice;

	cout<<"enter the filename: ";
	cin>>c;
	f1.open(c,ios::out);
	f1.close();

	cout<<"----------------------------------------"<<endl;
	while(true)
	{
		cout<<"-------------------------------------"<<endl;
		cout<<"1.pack\n" <<"2.unpack\n"<<"3.modify\n"<<"4.search\n"<<"5.exit"<<endl;
		cout<<"enter your choice"<<endl;

		cin>>choice;
		switch (choice)
		{
		case 1:input();
			   pack(t);
			break;
		case 2:unpack();display();
			break;
		case 3:unpack();search();modify();
			break;
		case 4:unpack(); search();
			break;
		default :
			exit(0);

		}

	}
	return 0;
}
