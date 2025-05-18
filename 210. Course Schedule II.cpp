class Solution {
public:
vector < int> path;
    bool dfs(int x, vector<vector<int>>& Pre, vector<bool>& seen, vector<bool>& MARK) {
        if (MARK[x]) return true;  // Already processed
        if (seen[x]) return false; // Cycle detected
        
        seen[x] = true;
        
        for (int neighbor : Pre[x]) {
            if (!dfs(neighbor, Pre, seen, MARK)) {
                return false;
            }
        }
        
        seen[x] = false;
        MARK[x] = true;
        path.insert(path.begin(),x);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<bool> seen(numCourses, false);
        vector<bool> MARK(numCourses, false);
        
        vector<vector<int>> Pre(numCourses);
        
        // Build adjacency list (prerequisite -> course)
        for (const auto& p : prerequisites) {
            Pre[p[1]].push_back(p[0]);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (!MARK[i] && !dfs(i, Pre, seen, MARK) )
                    return vector<int> ();
        }

        return path;
    }
          
};
