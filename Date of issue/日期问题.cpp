//日期问题
//思路一定要骚
//代码越高大上说明你越智障
//相反越低级说明你越牛掰
//简单才是王道
#include<iostream>
using namespace std;
int day(int month,int year);
bool isrui(int year);//这两个包用于给其他包用

//剩下的包只给main函数用
bool isyear(int year){
    if(year<=2059&&year>=1960){
        return true;
    }
    else{
        return false;
    }
}
bool ismonth(int month){
    if(month<=12&&month>=1){
        return true;
    }
    else{
        return false;
    }
}
bool isday(int year,int month,int yourday){
        if(yourday>day(month,year)||yourday==0){
            return false;
        }
        else
            return true;
}
bool isrui(int year){
    if ((year%4==0&&year%100!=0)||year%400==0){
        return true;
    }
    else{
        return false;
    }
}
int day(int month,int year){
    if(month==0){
        return 0;
    }
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
        return 31;
    }
    else if(month==2&&isrui(year)){
        return 29;
    }
    else if(month==2&&!isrui(year)){
        return 28;
    }
    else{
        return 30;
    }
}
void jazzi(int A,int B,int C){//核心函数
    if(A<60)
        A+=2000;
    else if(A>=60)
        A+=1900;
    if(isyear(A)){
        if(ismonth(B)){
            if(isday(A, B, C)){
                printf("%d-%02d-%02d\n",A,B,C);
            }
        }
    }
}
int main(){
    int A,B,C;
    scanf("%d/%d/%d",&A,&B,&C);
    jazzi(A,B,C);
    jazzi(C,A,B);
    jazzi(C,B,A);
}
