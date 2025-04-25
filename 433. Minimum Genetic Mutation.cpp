class Solution {
public:


int diff(string a, string b)
{
    int ans = 0;
    for ( int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            ans ++;
    }
    return ans;
}



int minMutation(string startGene, string endGene, vector<string>& bank)
{

    std::vector<std::pair<std::string, int>> temp;
    temp.push_back({startGene,0});

    unordered_map<std::string, int> seen;
    seen.insert({startGene, 1});

    int i = 0;

    while ( i < temp.size())
    {
           
       for ( int j = 0; j < bank.size(); j++)
       {
            if ( (seen.find(bank[j]) == seen.end()) &&
            (diff(temp[i].first ,bank[j]) == 1) )
            {
                if ( bank[j] == endGene )
                    return temp[i].second + 1;
               seen.insert({bank[j], 1});
               temp.push_back( { bank[j],temp[i].second + 1 } );

            }
       }
       i++;
    }

     return -1;

}

};
