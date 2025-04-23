class Solution {
public:

vector <string> ANS;

   string back_track(string digits,int start,string ans)
  {
      
     // cout << start <<" - "<<digits[start] << " " << ans << endl;
      if ( start >= digits.size() && ans != "")
      {
        ANS.push_back(ans);
          return ans;
      }
      
      if(digits[start] == '1')
      {
          back_track(digits, start+1, ans);
      }
      if ( digits[start] == '2')
      {
          back_track(digits , start+1, (ans +'a') );
          back_track(digits , start+1, (ans +'b') );
          back_track(digits , start+1, (ans +'c') );
      }
      if ( digits[start] == '3')
      {
          back_track(digits , start+1, (ans + 'd') );
          back_track(digits , start+1, (ans + 'e') );
          back_track(digits , start+1, (ans + 'f') );
      }
      if ( digits[start] == '4')
      {
          back_track(digits , start+1, (ans + 'g') );
          back_track(digits , start+1, (ans + 'h') );
          back_track(digits , start+1, (ans + 'i') );
      }
      if ( digits[start] == '5')
      {
          back_track(digits , start+1, (ans + 'j') );
          back_track(digits , start+1, (ans + 'k') );
          back_track(digits , start+1, (ans + 'l') );
      }
      if ( digits[start] == '6')
      {
          back_track(digits , start+1, (ans + 'm') );
          back_track(digits , start+1, (ans + 'n') );
          back_track(digits , start+1, (ans + 'o') );
      }
      if ( digits[start] == '7')
      {
          back_track(digits , start+1, (ans + 'p') );
          back_track(digits , start+1, (ans + 'q') );
          back_track(digits , start+1, (ans + 'r') );
          back_track(digits , start+1, (ans + 's') );
      }
      if ( digits[start] == '8')
      {
          back_track(digits , start+1, (ans + 't') );
          back_track(digits , start+1, (ans + 'u') );
          back_track(digits , start+1, (ans + 'v') );
      }
      if ( digits[start] == '9')
      {
          back_track(digits , start+1, (ans + 'w') );
          back_track(digits , start+1, (ans + 'x') );
          back_track(digits , start+1, (ans + 'y') );
          back_track(digits , start+1, (ans + 'z') );
      }
      return ans;
  }
    vector<string> letterCombinations(string digits)
    {
        back_track(digits,0,"");
        return ANS;
    }
};
