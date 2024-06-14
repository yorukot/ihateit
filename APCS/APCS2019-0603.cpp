// So i cant slove this, this only can pass exapmle
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int totalRole = 0, totalLine = 0;
    int answer = 0;
    vector<string> CPlist;
    vector<map<char, bool>> CPlistDuplicate;
    cin >> totalRole >> totalLine;

    for (int i = 0; i < totalLine; i++)
    {
        string temp;
        cin >> temp;
        CPlist.push_back(temp);
        for (char ch : temp)
        {
            map<char, bool> tempMap;
            if (tempMap.find(ch) == tempMap.end())
            {
                tempMap[ch] = true;
            }
            CPlistDuplicate.push_back(tempMap);
        }
    }

    for (int i = 0; i < totalLine; i++)
    {
        for (int x = i; x < totalLine; x++)
        {
            if (CPlistDuplicate[i] != CPlistDuplicate[x])
            {
                answer++;
            }
        }
    }

    cout << answer << endl;

    return 0;
}