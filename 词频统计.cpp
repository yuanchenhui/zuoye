#include <iostream> 
#include <ctype.h>
#include <algorithm>
#include <string>  

using namespace std;

struct Word                                                          //���ʽṹ��
{
    
    string Str;
    int Count=0;

    void exchange(Word &word)                                        //���ʽ�������������
    {
        string tStr = word.Str;
        int tCount = word.Count;
        word.Str = Str;
        word.Count = Count;
        Str = tStr;
        Count = tCount;
    }
};


void CalcCount(Word *words, string &newWord, int size)              //��Ƶͳ��
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


void SortWordDown(Word * words, int size)                           //���ݴ�Ƶ��������
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
    cout << "Word is case insensitive, i.e. ��file123��, ��123FILE�� and ��File�� are considered the same word.";
    getline(cin, content);

     
    int wCount = 1;                                                   //��¼��������
    for (unsigned int i = 0; i < content.length(); i++)
    {
        if (isalnum(content[i]) == 0)                                 //����ĸ����
        {
            wCount++;
        }
    }
    words = new Word[wCount];

    string::size_type offset = content.find(�� ��);                     //���ʷָ���size_type���Ա���string����ĳ���
    while (offset != string::npos)
    {
        string wStr = content.substr(0, offset);                      //string.substr()����һ����ָ��λ�÷���ָ�����ȵ��ַ���
        if (wStr.length() < 4)                                        //��ȥ����С��4�ĵ���
        {
            wCount--;
            content.erase(0, offset + 1);
            offset = content.find(�� ��);
            continue;
        }
        content.erase(0, offset + 1);                                 //string.erase()ɾ����ָ��λ�ÿ�ʼ��ָ�����ȵ��ַ�
        transform(wStr.begin(), wStr.end(), wStr.begin(), ::tolower); 
        CalcCount(words, wStr, wCount);                               
        offset = content.find(�� ��);
    }
    if (content.length() >= 4)
    {
        transform(content.begin(), content.end(), content.begin(), ::tolower);
        CalcCount(words, content, wCount);                           //�������һ������ 
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
    cout << "��Ƶͳ��:" << endl;
    for (int i = 0; i < wCount - 1; i++)
    {
        cout << words[i].Str << "Ƶ��:" << words[i].Count << "��" << endl;
    }
    cin.get();
    delete[] words;
    return 0;
}