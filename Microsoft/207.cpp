class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        
         vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);
        
        for(auto edge: prerequisites){
            degree[edge[0]]++;
            graph[edge[1]].push_back(edge[0]);
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; i++)
            if(degree[i] == 0)
                q.push(i);
        
        while(!q.empty()){
            int e = q.front();
            q.pop();
            numCourses--;
            for(int i: graph[e])
                if(--degree[i] == 0)
                    q.push(i);
        }
        return numCourses == 0;
    }
};
