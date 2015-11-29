#‎include‬<iostream>
#include <math.h>
#include "dbc.h"
#include <string>
# define max 100

using namespace std;

class Dictionary
{
private :
string key[max];
string value[max];
int counter;
public:
Dictionary()
{
INVARIANT0(count()>=0);
for(int i=0;i<max;i++)
{
key[i] ="";
value[i]="";
counter=0;
INVARIANT0(count()>=0);
}

}
bool exists(string k)
{INVARIANT0(count()>=0);
int i=0;
while (i<max)

{ if (key[i]==k)
{
return 1;}
else i++;
}
return 0 ;
INVARIANT0(count()>=0);

}

int count ()
{ INVARIANT0(count()>=0);
return counter;
INVARIANT0(count()>=0);

}
void add(string k,string v)
{INVARIANT0(count()>=0);
REQUIRE0(exists(k)==0&&k!="");

int i=0;
int c=count();
while (i<max)

{ if (key[i]=="")
{key[i]=k;
value[i]=v;
counter++;
break;

}
else i++;
}

ENSURE0(exists(k)&&get_value(k)==v&&count()==c+1);
INVARIANT0(count()>=0);
}
string get_value(string k)
{
INVARIANT0(count()>=0);
int i=0;
while (i<max)

{ if (key[i]==k)
{
return value[i];}
else i++;
}
return "" ;

INVARIANT0(count()>=0);
}

void del(string k){
INVARIANT0(count()>=0);
REQUIRE0(exists(k));
int i=0;
int c=count();
while (i<max)

{ if (key[i]==k)
{
key[i]="";
value[i]="";
counter--;
break;
}

else i++;
}
ENSURE0(get_value(k)==""&&exists(k)==0&&count()==c-1);
INVARIANT0(count()>=0);
}
void change (string k,string v)
{ INVARIANT0(count()>=0);
REQUIRE0(exists(k));
int i=0;
int c=count();
while (i<max)

{ if (key[i]==k)
{

value[i]=v;
break;
}

else i++;
}
ENSURE0(get_value(k)==v&&exists(k)&&count()==c);
INVARIANT0(count()>=0);
}

};

void main()
{

Dictionary d;


}