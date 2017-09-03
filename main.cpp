#include <iostream>
using namespace std;
void dfs(int line,int column);

int times=0;
int map[9][9]={0};

int main(){
    dfs(4,4);
    cout<<times/4<<endl;
    return 0;
}

void dfs(int line,int column){
    if(map[line][column]==1) return;
    
    map[8-line][8-column]=1;
    map[line][column]=1;
    if(line==1||column==1||column==7||line==7){
        times++;
        map[8-line][8-column]=0;
        map[line][column]=0;
        return ;
    }
    
    dfs(line-1,column);
    dfs(line,column-1);
    dfs(line+1,column);
    dfs(line,column+1);
    
    map[8-line][8-column]=0;
    map[line][column]=0;
}
