//方格分割
//暴力破解
#include <iostream>
using namespace std;
void dfs(int line,int column);

int times=0;
int map[7][7]={0};

int main(){
    dfs(3,3);
    cout<<times/4<<endl;//因为一开始（3，3）从四个方向出发，从一个方向深搜的结果与其他方向是相同的，只不过角度不同罢了。
    return 0;
}

void dfs(int line,int column){
    if(map[line][column]==1) return;//深度搜索的时候防止返回原路并且保持图片被一刀切两半
    
    map[6-line][6-column]=1;//对称型切法
    map[line][column]=1;//标记已经切开的路线
    if(line==0||column==0||column==6||line==6){//当与边界相撞的时候，即是一刀切开成功的时候
        times++;
        map[6-line][6-column]=0;
        map[line][column]=0;//回溯
        return ;
    }
    
    dfs(line-1,column);
    dfs(line,column-1);
    dfs(line+1,column);
    dfs(line,column+1);//各种情况
    
    map[6-line][6-column]=0;
    map[line][column]=0;//回溯
}
