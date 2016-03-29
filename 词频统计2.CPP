#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

struct Word{
	int Count;
	char *p;
	void exchange(Word&word)
	{
		string  tStr=word.Str ;
		int tCount=word.Count ;
		word.Str =Str;
		word.Count =Count;
		Str=tStr;
		Count=tCount;
	}
};
Words test[100];

void lwr(char x[])
{
	int k=0;
	while(x[k]!='\0')
	{
		if(x[k]>='A'&&x[k]<='Z')
			x[k]=x[k]+32;
		k++;
	}
}
int identify(char a[])
{
	int m=(strlen(a)>=4)?1:0;
	int n=(a[0]>='a'&&a[0]<='z')?1:0;
	if(!m||!n)
		return 0;
	else
		while(a)
		{
			for(int i=1;i++)
			{
				if(!(a[i]>='a'&&a[i]<='z')||!(a[i]>='0'&&a[i]<='9'))
					return 0;
				else
					return 1;
			}
		}
}

void SortWordDown(Word*words,int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-1;j++)
		{
			if(words[j].Count<words[j+1].Count )
			{
				words[j].exchange (words[j+1]);
			}
		}
	}
}

int counting(char b[],int num)
{
	for(int j=0;j<num;j++)
	{
		if(!strcmp(b,test[j].p ))
			test[j].Count++;
		else
			return 0;
	}
}

int main(void)
{
	char c[100];
	char *ptr;
	ifstream file("E://A_Tale_of_Two_Cities.txt")
		if(!file)
		{
			cout<<"不能打开文件";
		}
		while(!file.eof ())
		{
			file.getline (c,500);
		}
		file.close ();
		int j=0;
		while(c[j]!='/0'&&c[j+1]!='/0')
		{
			if(c[j]>='A'&&c[j]<='Z')
			{
				c[j]=c[j]-'A'+'a';
				j++;
			}
		}
		cout<<c;
		char *sep="";
		int i=0;
		ptr=strtok(c,"");
		while(ptr!=NULL)
		{
			if(isword(p)!=false)
			{
				if(judge(p,n)!=false)
				{
					w[n].s=*p;
					n++;
				}
			}
			ptr=strtok(NULL,"");
		}
		int t=0;
		cout<<"输入统计出现频数的指定单词:\n";
		char d[500];
		cin>>d;
		int t=0;
		while(!strcmp(test[n].p,d))
		{
			t++;
		}
		cout<<test[n].p<<":"<<test[n].count<<'\n';
		return 0;
}


