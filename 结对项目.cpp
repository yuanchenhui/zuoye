#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

struct Word{      //定义结构体
    int Count;//计数器
     Word() : Str(""), Count(0) {}  
    string Str; //字符串
    char *p;
};


void exchange(Word &word)  //函数，用于交换单词（排序单词）    
{  
    string      tStr = word.Str;  
    int     tCount = word.Count;  
    word.Str   = Str;  
    word.Count   = Count;  
    Str        =tStr;  
    Count        = tCount;  
}  

Words test[100];

void lwr(char x[])     //大写转小写
{   int k = 0;
    while (x[k] != '\0')
    {
        if (x[k] >= 'A'&&x[k] <= 'Z')
            x[k] = x[k] + 32;
        k++;
    }
}

int identify(char a[])    //判断是否符合单词的定义
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

void SortWordDown(Word * words, int size)  //以单词出现频率降序排列单词，words 单词数组，size 单词数量
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

int counting(char b[],int num)    //对出现次数计数
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
    ifstream file( "E://A_Tale_of_Two_Cities.txt" ); /* 读取 */
    if ( !file )
    {
        cout << "不能打开文件";
    }
    while ( !file.eof() )
    {
        file.getline( result, 500 );
    }
    file.close();
    int j = 0; /* 大写转小写 */
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
    ptr = strtok( result, " " );            /* 利用strtok函数来分割result字符串中的单词 */
    while ( ptr != NULL )
    {
        if ( isword( p ) != false )
        {
            if ( judge( p, n ) != false )
            {
                w[n].s = *p;    /* 赋值给数组 */
                n++;
            }
        }
        ptr = strtok( NULL, " " );
    }
    int t = 0;
    ofstream outfile;                       /* 输出文件到result1 */
    outfile.open( "Result1.txt" )
    SortWordDown( w, count );
    while ( w[t].s )                        /* 输出统计结果 */
    {
        if ( strlen( w[t].s ) >= 4 )
        {
            outfile << w[t].s << "：" << w[t].count << '\n';
            t++;
        }
    }
    return(0);
}