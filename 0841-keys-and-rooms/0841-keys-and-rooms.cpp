class Solution {
public:
    void dfs(int currentRoom,const vector<vector<int>>& rooms,unordered_set<int>& visited){
        visited.insert(currentRoom);
        for(int key:rooms[currentRoom]){
            if(visited.find(key)==visited.end()){
                dfs(key,rooms,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int>visited;
        dfs(0,rooms,visited);
        return visited.size()==rooms.size();
    }
};