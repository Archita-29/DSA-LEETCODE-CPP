class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].size();
        int startX=-1,startY=-1;
        vector<pair<int,int>>litter;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(classroom[r][c]=='S'){
                    startX=r;
                    startY=c;
                }else if(classroom[r][c]=='L'){
                    litter.push_back({r,c});
                }
            }
        }
        int totalLitter=litter.size();
        int fullMask=(1<<totalLitter)-1;
        if(totalLitter==0) return 0;
        vector<vector<vector<int>>> bestEnergy(m,vector<vector<int>>(n,vector<int>(1<<totalLitter,-1)));
        queue<tuple<int,int,int,int,int>>q;
        q.push({startX,startY,0,energy,0});
        bestEnergy[startX][startY][0]=energy;
        int directions[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            auto[r,c,mask,curEnergy,steps]=q.front();
            q.pop();

            if(mask==fullMask){
                return steps;
            }
            for(auto& dir:directions){
                int nr=r+dir[0];
                int nc=c+dir[1];
                if(nr>=0 && nr<m && nc>=0 && nc<n && classroom[nr][nc]!='X'){
                    int nextEnergy=curEnergy-1;
                    if(nextEnergy<0) continue;
                    int nextMask=mask;
                    char cell=classroom[nr][nc];
                    if(cell=='R'){
                        nextEnergy=energy;
                    }
                    else if(cell='L'){
                        for(int i=0;i<totalLitter;i++){
                            if(litter[i].first==nr && litter[i].second==nc){
                                nextMask |= (1<<i);
                                break;
                            }
                        }
                    }
                    if(nextEnergy>bestEnergy[nr][nc][nextMask]){
                        bestEnergy[nr][nc][nextMask]=nextEnergy;
                        q.push({nr,nc,nextMask,nextEnergy,steps+1});
                    }
                }
            }
        }
        return -1;
    }
};