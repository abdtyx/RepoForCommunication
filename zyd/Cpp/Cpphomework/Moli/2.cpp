#include <bits/stdc++.h>
using namespace std;

typedef struct _word
{
    string word;
    int number = 0;
} Word;

int main()
{
    Word word[200];
    string s = {0};
    int m = 0, t = 0, k = 0;
    int count = 0;
    int i = 0;
    while (getline(cin, s))
    {
        for (; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                count = i;
                for (k = 0; k < m; k++)
                {
                    if (word[k].word == s.substr(t, count - t))
                    {
                        word[k].number++;
                        t = count + 1;
                        i = t;
                        break;
                    }
                }
                if (k == m)
                {
                    word[m].word = s.substr(t, count - t);
                    word[m].number++;
                    m++;
                    t = count + 1;
                    i = t;
                    k = 0;
                }
            }
        }
        i = 0;
        t = 0;
        k = 0;
        count = 0;
    }
    Word minword;
    minword = word[0];
    for (int j = 1; j < m; j++)
    {
        if (minword.number < word[j].number)
        {
            minword = word[j];
        }
        if (minword.number == word[j].number)
        {
            if (minword.word > word[j].word)
            {
                minword = word[j];
            }
        }
    }
    cout << minword.word << " " << minword.number;
}