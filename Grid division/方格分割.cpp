//方格分割
//暴力破解
#include <iostream>
using namespace std;
void dfs(int line,int column);

int times=0;
int map[9][9]={0};//为什么要9*9，为了让7*7多了一个外表数值为0的框子，以防深度搜索到边框的时候出现错误

int main(){
    dfs(4,4);
    cout<<times/4<<endl;//因为一开始（3，3）从四个方向出发，从一个方向深搜的结果与其他方向是相同的，只不过角度不同罢了。
    return 0;
}

void dfs(int line,int column){
    if(map[line][column]==1) return;//深度搜索的时候防止返回原路并且保持图片被一刀切两半
    
    map[8-line][8-column]=1;//对称型切法
    map[line][column]=1;//标记已经切开的路线
    if(line==1||column==1||column==7||line==7){//当与边界相撞的时候，即是一刀切开成功的时候
        times++;
        map[8-line][8-column]=0;
        map[line][column]=0;//回溯
        return ;
    }
    
    dfs(line-1,column);
    dfs(line,column-1);
    dfs(line+1,column);
    dfs(line,column+1);//各种情况
    
    map[8-line][8-column]=0;
    map[line][column]=0;//回溯
}
