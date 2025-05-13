class Solution {
public:
    string addBinary(string a, string b) 
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans = "";
        char c ='0';
        for ( int i = 0; i < max(a.size(),b.size()); i++)
        {
            if ( i >= a.size() )
            {
                if (b[i] == '1' && c == '0')
                { ans += '1'; c = '0';}
                else if (b[i] == '1' && c == '1')
                { ans += '0'; c = '1';}
                else if (b[i] == '0' && c == '1')
                { ans += '1'; c = '0';}
                else if (b[i] == '0' && c == '0')
                { ans += '0'; c = '0';}

            }
            else if(i >= b.size())
            {
                if (a[i] == '1' && c == '0')
                { ans += '1'; c = '0';}
                else if (a[i] == '1' && c == '1')
                { ans += '0'; c = '1';}
                else if (a[i] == '0' && c == '1')
                { ans += '1'; c = '0';}
                else if (a[i] == '0' && c == '0')
                { ans += '0'; c = '0';}
            }
            else
            {
                if ( a[i] == '1' && b[i] == '1' && c =='1') 
                { ans += '1'; c = '1';}
                else if ( a[i] == '1' && b[i] == '1' && c =='0') 
                { ans += '0'; c = '1';}
                else if ( a[i] == '1' && b[i] == '0' && c =='1') 
                { ans += '0'; c = '1';}
                else if ( a[i] == '1' && b[i] == '0' && c =='0') 
                { ans += '1'; c = '0';}
                else if ( a[i] == '0' && b[i] == '1' && c =='1') 
                { ans += '0'; c = '1';}
                else if ( a[i] == '0' && b[i] == '1' && c =='0') 
                { ans += '1'; c = '0';}
                else if ( a[i] == '0' && b[i] == '0' && c =='1') 
                { ans += '1'; c = '0';}
                else if ( a[i] == '0' && b[i] == '0' && c =='0') 
                { ans += '0'; c = '0';}
            }
        } 

        if ( c == '1')
            ans += '1';
         
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
