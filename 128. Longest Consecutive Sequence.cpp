class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        if (nums.size() == 0)
        return 0;
          unordered_set<long int> mymap;
          for ( int i = 0; i< nums.size(); i++)
          {
                mymap.insert(nums[i]);
          }

          long int ans = 1;

        for ( int i = 0; i < nums.size(); i++)
        {
            long int left = nums[i];
            long int right = nums[i];
            while ( mymap.size() != 0 )
            {
                 if ( mymap.find(left-1) == mymap.end() &&
                mymap.find(right+1) == mymap.end() )
                break;
               if(mymap.find(left-1) != mymap.end())
               {
                mymap.erase(left);
                left --;
               }
               if(mymap.find(right+1) != mymap.end())
               {
                mymap.erase(right);
                right ++;
               }
              
            }
            //cout << nums[i] << "_ " << left << "," << right <<endl;
            if ( right - left+1 > ans)
            ans = right -left+1;
        }
        return (ans != 1) ? ans : 1;
           
    }
};
