#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

struct Word{      //����ṹ��
    int Count;//������
     Word() : Str(""), Count(0) {}  
    string Str; //�ַ���
    char *p;
};


void exchange(Word &word)  //���������ڽ������ʣ����򵥴ʣ�    
{  
    string      tStr = word.Str;  
    int     tCount = word.Count;  
    word.Str   = Str;  
    word.Count   = Count;  
    Str        =tStr;  
    Count        = tCount;  
}  

Words test[100];

void lwr(char x[])     //��дתСд
{   int k = 0;
    while (x[k] != '\0')
    {
        if (x[k] >= 'A'&&x[k] <= 'Z')
            x[k] = x[k] + 32;
        k++;
    }
}

int identify(char a[])    //�ж��Ƿ���ϵ��ʵĶ���
{   int m=(strlen(a)>=4)?1:0;
    int n=(a[0]>='a'&&a[0]<='z')?1:0;
    if(!m||!n)
        return 0;
    else
        while(a)
        {   for(int i=1;;i++)
           {  
               if(!(a[i]>='a'&&a[i]<='z')||!(a[i]>='0'&&a[i]<='9'))
                        return 0;
               else
                        return 1;
           }
        }
}

void SortWordDown(Word * words, int size)  //�Ե��ʳ���Ƶ�ʽ������е��ʣ�words �������飬size ��������
{  
    for(int i=0;i<size;i++)  
    {
        for(int j=0;j <size-1;j++)  
        { 
            if(words[j].Count<words[j+1].Count)  
            {  
                words[j].exchange(words[j+1]);  
            }  
        }  
    }  
}  

int counting(char b[],int num)    //�Գ��ִ�������
{   for(int j=0;j<num;j++)
    {

        if(!strcmp(b,test[j].p))
             test[j].count++;
        else
            return 0;
    }
}


int main( void )
{
    char result[500];

    char *ptr;
    ifstream file( "E://A_Tale_of_Two_Cities.txt" ); /* ��ȡ */
    if ( !file )
    {
        cout << "���ܴ��ļ�";
    }
    while ( !file.eof() )
    {
        file.getline( result, 500 );
    }
    file.close();
    int j = 0; /* ��дתСд */
    while ( result[j] != '/0' && result[j + 1] != '/0' )
    {
        if ( result[j] >= 'A' && result[j] <= 'Z' )
        {
            result[j] = result[j] - 'A' + 'a';
            j++;
        }
    }
    cout << result;
    char *sep = " ";

    int i = 0;
    ptr = strtok( result, " " );            /* ����strtok�������ָ�result�ַ����еĵ��� */
    while ( ptr != NULL )
    {
        if ( isword( p ) != false )
        {
            if ( judge( p, n ) != false )
            {
                w[n].s = *p;    /* ��ֵ������ */
                n++;
            }
        }
        ptr = strtok( NULL, " " );
    }
    int t = 0;
    ofstream outfile;                       /* ����ļ���result1 */
    outfile.open( "Result1.txt" )
    SortWordDown( w, count );
    while ( w[t].s )                        /* ���ͳ�ƽ�� */
    {
        if ( strlen( w[t].s ) >= 4 )
        {
            outfile << w[t].s << "��" << w[t].count << '\n';
            t++;
        }
    }
    return(0);
}