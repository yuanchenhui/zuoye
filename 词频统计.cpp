#include <iostream> 
#include <ctype.h>
#include <algorithm>
#include <string>  

using namespace std;

struct Word                                                          //单词结构体
{
    
    string Str;
    int Count=0;

    void exchange(Word &word)                                        //单词交换，用于排序
    {
        string tStr = word.Str;
        int tCount = word.Count;
        word.Str = Str;
        word.Count = Count;
        Str = tStr;
        Count = tCount;
    }
};


void CalcCount(Word *words, string &newWord, int size)              //词频统计
{
    int i = 0;
    for (; i < size; i++)
    {
        if (words[i].Str == newWord)
        {
            words[i].Count++;
            return;
        }
        else if (words[i].Str == "")
            break;
    }
    words[i].Str = newWord;
    words[i].Count = 1;
}


void SortWordDown(Word * words, int size)                           //根据词频降序排序
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (words[j].Count <  words[j + 1].Count)
            {
                words[j].exchange(words[j + 1]);
            }
        }
    }
}

int main()
{
    Word * words;
    string content;
    cout << "Word is case insensitive, i.e. “file123”, “123FILE” and “File” are considered the same word.";
    getline(cin, content);

     
    int wCount = 1;                                                   //记录单词总数
    for (unsigned int i = 0; i < content.length(); i++)
    {
        if (isalnum(content[i]) == 0)                                 //非字母数字
        {
            wCount++;
        }
    }
    words = new Word[wCount];

    string::size_type offset = content.find(‘ ‘);                     //单词分隔；size_type用以保存string对象的长度
    while (offset != string::npos)
    {
        string wStr = content.substr(0, offset);                      //string.substr()返回一个从指定位置返回指定长度的字符串
        if (wStr.length() < 4)                                        //除去长度小于4的单词
        {
            wCount--;
            content.erase(0, offset + 1);
            offset = content.find(‘ ‘);
            continue;
        }
        content.erase(0, offset + 1);                                 //string.erase()删除从指定位置开始的指定长度的字符
        transform(wStr.begin(), wStr.end(), wStr.begin(), ::tolower); 
        CalcCount(words, wStr, wCount);                               
        offset = content.find(‘ ‘);
    }
    if (content.length() >= 4)
    {
        transform(content.begin(), content.end(), content.begin(), ::tolower);
        CalcCount(words, content, wCount);                           //计算最后一个单词 
    }
    else wCount--;

    for (int i = 0; i < wCount; i++)
    {
        if (words[i].Str == "")
        {
            wCount--;
        }
    }

    SortWordDown(words, wCount);
    cout << "词频统计:" << endl;
    for (int i = 0; i < wCount - 1; i++)
    {
        cout << words[i].Str << "频率:" << words[i].Count << "次" << endl;
    }
    cin.get();
    delete[] words;
    return 0;
}