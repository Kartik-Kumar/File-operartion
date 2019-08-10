#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
fstream fp1,fp2,fp3;
int rrn=1;
int r=-1;
char buffer1[100],buffer2[100];

int i;
class student
{   public:
	char fname[20];
	char lname[20];
	char usn[20];
	char branch[10];
	char sem[10];
};
student s[100],t;


void pack(student t)
{
	char buffer[100];
	strcpy(buffer,t.fname);
	strcat(buffer,"|");
	strcat(buffer,t.lname);
	strcat(buffer,"|");
	strcat(buffer,t.usn);
	strcat(buffer,"|");
	strcat(buffer,t.branch);
	strcat(buffer,"|");
	strcat(buffer,t.sem);
	strcat(buffer,"|");

int x=strlen(buffer);
for(int j=0;j<=60-x;j++)
{
	strcat(buffer,"@");
}
fp1.open("std.txt",ios::out|ios::app);
fp1<<rrn<<"|"<<buffer<<endl;
fp2.open("index.txt",ios::out|ios::app);
fp2<<t.usn<<"|"<<rrn<<"|"<<endl;
rrn++;


fp3.open("secondary.txt",ios::out|ios::app);
fp3<<t.fname<<"|"<<t.usn<<"|"<<endl;
fp1.close();
fp2.close();
fp3.close();

}

void search(char *keyusn)
{
	char temprrn[10],tempusn[10];

	fp2.open("index.txt",ios::in);
	while(!fp2.eof())
	{
		fp2.getline(buffer1,100);
		sscanf(buffer1,"%[^|]|%[^|]|",tempusn,temprrn);


		if(strcmp(keyusn,tempusn)==0)
		{
			r=atoi(temprrn);
			fp1.open("std.txt",ios::in);
			fp1.seekg((r-1)*64,ios::beg);



		fp1.getline(buffer2,100);
		sscanf(buffer2,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",temprrn,t.fname,t.lname,t.usn,t.sem,t.branch);
		cout<<"details are"<<endl;
		cout<<"name is:"<<t.fname<<endl<<"last name:"<<t.lname<<endl<<"usn:"<<t.usn<<endl<<"sem is:"<<t.sem<<endl<<"bramnch:"<<t.branch<<endl;

		fp1.close();
		fp2.close();

		return;
		}
    }

		cout<<"not found";
		fp2.close();
}
 void Del()
{  char temprrn[10];
	if(r==-1)
		return;

	int i=1;
	fp1.open("std.txt",ios::in);
      while(!fp1.eof())
      {
       fp1.getline(buffer1,100);
       sscanf(buffer1,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",temprrn,s[i].fname,s[i].lname,s[i].usn,s[i].sem,s[i].branch);
     i++;
      }
      fp1.close();
      remove("std.txt");
      remove("index.txt");
      rrn=1;
      for(int k=1;k<i-1;k++)
      {
    	  if(k!=r)
    		  pack(s[k]);
      }
}

void searchbyname()
{
	int flag=0;
	char keyname[50],buffer3[50],tempname[50],tempusn[20];
	fp3.open("secondary.txt",ios::in);
	cout<<"enter the name to be searchred for"<<endl;
	cin>>keyname;
	while(!fp3.eof())
	{
		fp3.getline(buffer3,100);
		sscanf(buffer3,"%[^|]|%[^|]|",tempname,tempusn);
		if(strcmp(keyname,tempname)==0)
			{
			search(tempusn);
			flag=1;
			}
		strcat(tempname," ");
	}
	if(flag==0)
		cout<<"no record found"<<endl;
	fp3.close();
}
int main() {

	 int n;
		char name[20],str[20];
		cout<<"enter the filename";


		fp1.open("std.txt",ios::out);
		fp1.close();
		fp2.open("index.txt",ios::out);
		fp2.close();
		fp3.open("secondary.txt",ios::out);
		fp3.close();

		while(true)

		{ 	cout<<"1.add \n 2.search\n 3.delete \n 4.exit\n ";
			int choice;
		    cout<<"enter your choice";
		    cin>>choice;
		    switch(choice)
		    {
				case 1:

					cout<<"enter the first name of the student";
					cin>>t.fname;
					cout<<"enter the last name of the student";
			        cin>>t.lname;
			        cout<<"enter the usn of the student";
			       	cin>>t.usn;
			       	cout<<"enter the branch of the student";
			       	cin>>t.branch;
			       	cout<<"enter the sem of the student";
			       	cin>>t.sem;
	                pack(t);
					break;
				case 2:
					cout<<"search-"<<endl;
					searchbyname();

					break;
				case 3:

					Del();
					break;


				case 4:


	                exit(0);
					break;

				default:
					cout<<"invalid";
		    }

		}
	return 0;
}
