class Solution {
public:

    int diff(string a, string b)
    {
        int ans = 0;
        for ( int i = 0; i< a.size(); i++)
        {
            if (a[i] != b[i])
                ans++;

        }
        return ans;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue <string> q;
        q.push(beginWord);

        unordered_map < string, int> map;
        map[beginWord] = 1;

        int L = 0;

        while ( q.size() > 0 )
        {
            int level = q.size();
            for ( int i = 0; i < level; i++)
            {
                if ( q.front() == endWord)
                {
                    return L+1;
                }
                for ( int j = 0; j < wordList.size(); j++)
                {
                    if ( diff(q.front(),wordList[j]) == 1 &&
                    map.find(wordList[j]) == map.end())
                    {
                        q.push(wordList[j]);
                        map[wordList[j]] = 1;
                    }
                }
                q.pop();
            }
            L++;
        }
        return 0;
    }
};
