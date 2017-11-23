#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<fstream>
#include<stdio.h>
using namespace std;
int s_no=1;
int c=1;
void key();
void set_reminder();
void see_reminder();
void set_diary();
void see_diary();
void m_print(int t);
void date();
void a_handle(char t);
int checkd(string check);
int checkp(string u,string p);
void fullscreen();
void basic();
int x[3];
struct reminder_var
{ int choice;
string title;
string priority;
string description;
}r;
class design
{ int a,b;
public:
	void cur_pos(short x,short y);
	void color(int a);
	void border(char ch);
friend class start;
};
class start
{public:
  int m_choice; 

	void option();
}j;
struct date
{ string t_date;
string rs_date;
string dv_date;

}d,e;


int main()
{ string p,u;
//struct date t;
class design d;
class start j;
int a;
fullscreen();

cout<<"please drag the title bar  of the output screen to the top of the window to make it full screen,then\n";
system("pause");
d.color(1);
system("cls");
do
{ cout<<"username(lovely)\npassword(1-9)\n";
d.cur_pos(30,0);
cin>>u;
d.cur_pos(30,1);
cin>>p;
a=checkp(u,p);
} while(a!=1);

system("cls");
date();
system("cls");
basic();
}
void design::cur_pos(short x,short y)
{
COORD coord = {x, y};
SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), coord );
}
void design::color(int a)
{ if(a==1)
system("color 1a");
else
{ system("color 2a");
}
}
int checkp(string u,string p)
{ 
class design d;
if(u=="lovely"&&p=="123456789")
 { cout<<"credentials matched\n";
 d.color(1);
 getch();
  return 1;
}
else 
{ d.color(0);
cout<<"credentials wrong\n";
cout<<"try again\n";
getch();
system("cls");
return 0;
}
}
void design::border(char ch)
{ 
switch(ch)
{
 case 'b':
 	cur_pos(0,0);
 for(a=0;a<167;a++)
cout<<"*";
cur_pos(0,1);
for(a=0;a<56;a++)
{ cout<<"*\n";
}
cur_pos(167,0);
for(a=0;a<56;a++)
{ cout<<"*";
cur_pos(167,a);
}
cur_pos(1,56);
for(a=1;a<167;a++)
{ cout<<"*";
cur_pos(a,56);
}
cur_pos(1,1);
break;
default:cur_pos(0,0);
}
}
void start:: option()
{ 
system("color 2c");
class design s;
int a;
s.border('b');
cout<<" enter ur choice\n";

::c=1;
m_print(::c);
key();
j.m_choice=::c;
cout<<j.m_choice;
getch();
}
void key()
{
int ch;
do
{
	
	cout<<flush;
ch=getch(); 

if ( ch==0xE0||ch==0)
{ 
ch=getch();

if(ch==72)
{a_handle('u');
}
else if(ch==80)
{ a_handle('d');
}
}
} while(ch!=' ');


}
void a_handle(char t)
{int *p=&c;
if(t=='u')
{if(::c==1)
   ::c=5;
   else  ::c--;
    m_print(::c);
    
             }
  if(t=='d')
  {if(::c==5)
     ::c=1;
    else  ::c++;
    	m_print (::c);
	}
}

void fullscreen()
{ system("mode 650");
}
void set_reminder()
{ design d;
system("cls");
start s;
int a;
struct reminder_var r;
system("color 4c");
fstream file("reminder.txt");
if(file.fail())
{ cout<<"file not found\n";
getch();
cout<<"program will automatically make the file\n";
ofstream o("reminder.txt");
o.close();
}
file.close();
fstream r_set("reminder.txt");
r_set.seekp(0,ios::end);
do
{
	cout<<"enter the date for which reminder is to be set\n";
cin>>e.rs_date;
a=checkd(e.rs_date);
}while(a!=1);

cout<<"priority";
cout<<"1.High\t2.Medium\t3.Low\n";
cout<<"\nTitle=\n";
cout<<"\n Description=\n";
d.cur_pos(0,1);
cin>>r.choice;
switch(r.choice)
{ case 1:r.priority="High";
break;
case 2:r.priority="Medium";
break;
case 3:r.priority="Low";
break;
default:d.cur_pos(0,7);
cout<<"Wrong input\nriority will be treated as medium\n";
r.priority="Medium";
}
d.cur_pos(0,3);
cin.ignore();
getline(cin,r.title);
d.cur_pos(0,5);
cin.ignore();
getline(cin,r.description);
cout<<"reminder set\n";
r_set<<e.rs_date<<"\t"<<r.priority<<"\t"<<r.title<<"\t"<<r.description<<"\n";
r_set.close();
getch();
system("cls");
cout<<"\nwant to continue\n";
cout<<"1.Yes\n2.No\n";
cin>>a;
if(a==1)
{system("cls");
	basic();
}
}
void date()
{ system("cls");
system("color 5a");
cout<<"enter today's date(dd/mm/yy)\n";
cin>>d.t_date;
int a,b;
x[0]=(((int)d.t_date[0]-48)*10)+(int)d.t_date[1]-48;
x[1]=(((int)d.t_date[3]-48)*10)+(int)d.t_date[4]-48;
x[2]=(((int)d.t_date[6]-48)*10)+(int)d.t_date[7]-48;
getch();
if(d.t_date[2]!='/'||d.t_date[5]!='/')
{system("cls");
date();
}
}
int  checkd(string date)
{ int y[3];
system("cls");
y[0]=(((int)e.rs_date[0]-48)*10)+(int)e.rs_date[1]-48;
y[1]=(((int)e.rs_date[3]-48)*10)+(int)e.rs_date[4]-48;
y[2]=(((int)e.rs_date[6]-48)*10)+(int)e.rs_date[7]-48;
if(x[2]>y[2])
{ cout<<"entered date has passed or date format is invalid\n";
return 0;}
else if(x[2]==y[2])
{if(x[1]>y[1])
{
cout<<"either date format is invalid or entered date has passed";
return 0;}
else if(x[1]==y[1])
{ if(x[0]>y[0])
{cout<<"date format is invalid or entered date has passed";
return 0;}
else 
return 1;
}
else return 1;

}
else 
return 1;
}
void see_reminder()
{ int a;
design e;      
system("color aa");
ifstream r_view("reminder.txt");
if(r_view.fail())
{ cout<<"reading file does not exist\n";
cout<<"please make the file first\n";
getch();
basic();
}
string date,priority,title,description;
string s,t;
int c=0;

string date1,priority1,title1,description1;
r_view>>date1;
getch();
cout<<"reminders for today\n";
cout<<"date";
e.cur_pos(30,1);
cout<<"priority";
e.cur_pos(60,1);
cout<<"  title";
e.cur_pos(80,1);
cout<<" description\n";
int b=2;
while(r_view)
{ if(date1==d.t_date)
{cout<<date1;
 r_view>>priority1;
 e.cur_pos(30,b);
 cout<<priority1;
 e.cur_pos(60,b);
 r_view>>title1;
 cout<<title1;
 e.cur_pos(80,b);
getline(r_view,description1);
 cout<<description1<"\n";
c++;
b++;
}
r_view>>date1;
}
if(c==0)
{getch();
system("color 5c");
while(!getch())
{ system("color 4a");
system("color 1a");
cout<<" \nNo reminder for today\n";
}
}
r_view.close();
cout<<"\nwant to see all the reminders\n1.Yes\n2.No\n";
cin>>a;
 b=1;

if(a==1)
{
system("cls");
ifstream ra_view("reminder.txt");
cout<<"date";
e.cur_pos(30,0);
cout<<"priority";
e.cur_pos(60,0);
cout<<"  title";
e.cur_pos(80,0);
cout<<"Description=\n";

do
{ ra_view>>date;
cout<<date;
e.cur_pos(30,b);
ra_view>>priority;
cout<<priority;
e.cur_pos(60,b);
getline(ra_view,title);
cout<<title;
e.cur_pos(80,b);
getline(ra_view,description);
cout<<description<<"\n";
b++;
}while(ra_view);
e.cur_pos(0,b-1);
cout<<"                                                                                                                                    \n";
ra_view.close();
}

getch();
cout<<"want to continue\n";
cout<<"1.Yes\n2.No\n";
cin.ignore();
cin>>a;
if(a==1)
{system("cls");
	basic();
}
}

void basic()
{ int a;
class start j;

j.option();
system("cls");
switch(::c)
{ case 1:set_reminder();
break;
case 2:see_reminder();
break;
case 3:set_diary();
break;
case 4:see_diary();
break;
case 5:cout<<"ok then see u later\n";
exit(0);
}
}


void m_print(int t)
{system("cls");
cout<<"enter your choice(press SPACEBAR when done)\n"; 
if(t==1)
{//system("cls");
 cout<<"->set reminder\n  see reminder\n  make daily diary\n  see daily diary\n  quit\n";
}
 if(t==2)
{
//system("cls");
  cout<<"  set reminder\n->see reminder\n  make daily diary\n  see daily diary\n  quit\n";  

}
 if(t==3)
{//system("cls");
cout<<"  set reminder\n  see reminder\n->make daily diary\n  see daily diary\n  quit\n";
}
if(t==4)
{ //system("cls");
cout<<"  set reminder\n  see reminder\n  make daily diary\n->see daily diary\n  quit\n";
}
if(t==5)
{ //system("cls");
cout<<"  set reminder\n  see reminder\n  make daily diary\n  see daily diary\n->quit\n";
}
}



void set_diary()
{ int a; 
fstream file("p_diary.txt");
if(file.fail())
{ cout<<"file does not exist\n";
getch();
cout<<"program will autmatically create the file\n";
ofstream make("p_diary.txt");
make.close();
}
char ch;
file.close();
fstream s_dir("p_diary.txt");

s_dir.seekp(0,ios::end);
s_dir<<"\n";
ch=getchar();
s_dir<<d.t_date<<"\n";
while(ch!='#')
{ s_dir<<ch;
ch=getchar();
}
s_dir<<"#\n";
s_dir.close();
cout<<"want to continute\n1.Yes2.No\n";
cin.ignore();
cin>>a;
if(a==1)
{ system("cls");
basic();}
else 
exit(0);
}



void see_diary()
{ifstream d_read("p_diary.txt");
int a;
string p,date;
if(d_read.fail())
{ cout<<"no diary exist\n";
cout<<"please make the diary";
getch();
basic();
}int l;
char ch;
cout<<"please enter your viewing choice\n";
cout<<"1.Fixed date\n2.All diaries\n";
cin>>a;
if(a==1)
{cout<<"enter the date for which the diary is to be read(dd/mm/yy)\n";
cin>> date;
ifstream s_read("p_diary.txt");
ifstream p_read("p_diary.txt");
s_read>>p;
int c=0;
while(s_read)
{ if(p==date)
{ 
l=s_read.tellg();
c=1;
break;
}
s_read>>p;
}
if(c==1)
{
s_read.close();
p_read.seekg(l-2);
p_read>>ch;
while(ch!='#')
{cout<<ch;
ch=p_read.get();
}
p_read.close();
}
else {
cout<<"reminder for given date does not exist\n";
system("color 3f");
}
}
else
{
string s;
 while ( getline (d_read,s) )
    {
      cout << s << '\n';
    }
d_read.close();}
getch();
cout<<"\nwant to continute\n1.Yes2.No\n";
cin>>a;
if(a==1)
{ system("cls");
basic();}
else 
exit(0);
}

