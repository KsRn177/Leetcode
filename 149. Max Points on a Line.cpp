class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        if ( points.size() == 0 || points.size() ==1 )
            return points.size();

        int max = 0;
        for ( int  i = 0 ; i < points.size() -1; i++)
        {
            for ( int j = i+1; j < points.size(); j++)
            {
                //y = mx + b
                double x1 = points[i][1];
                double y1 = points[i][0];
                double x2 = points[j][1];
                double y2 = points[j][0];

                int ans = 2;

   
                if ( x1 == x2)
                {
                    for ( int k = 0; k < points.size(); k++)
                    {
                        if ( k!= i && k != j)
                        {
                            if ( points[k][1] == x1)
                                ans ++;
                        }
                    }
                }
                else
                {
                    for ( int k = 0; k < points.size(); k++)
                    {
                        if ( k!= i && k != j)
                        {
                            if ( points[k][0] == 
        ((y1-y2)/(x1-x2)) * points[k][1]-((y1-y2)/(x1-x2)*x1)+y1)
                                ans ++;
                        }
                    }
                }
                if ( ans > max )
                     max = ans;
            }
        }
        return max;
        
    }
};
