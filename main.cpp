#include <iostream>
using namespace std;
bool isrui(int );
int week(int );
int day(int month,int year);
int main(){
    int year,line;
    int date[12][42]={0};
    cin>>year>>line;
    for(int m=0,start=week(year);m<12;m++){
        for(int i=(start+=day(m,year))%7,sq=1;sq<=day(m+1,year);){
            date[m][i++]=sq++;
        }
    }
    for(int i=1;i<=12;i+=line){
        for(int n=0;(12-i>line)?(n<line):(n<12-i+1);n++){
            printf("%4s%4s%4s%4s%4s%4s%4s","SUN","MON","TU","WE","TH","FR","ST");
            cout<<"  ";
        }
        cout<<endl;
        for(int l=0;l<6;l++){
            for(int n=1;n<=line;n++){
                for(int j=0;j<7;j++){
                    if(i-1+n-1>11) break;
                    if(date[i-1+n-1][j+7*l]==0)
                        printf("%4s"," ");
                    else
                        printf("%4d",date[i-1+n-1][j+7*l]);
                }
                cout<<"  ";
            }
            cout<<endl;
        }
    }
    return 0;
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
int week (int year){
    return (((year-1)*365)+((year-1)/4)-((year-1)/100)+((year-1)/400+1))%7;
}
bool isrui(int year){
    if ((year%4==0&&year%100!=0)||year%400==0){
        return true;
    }
    else{
        return false;
    }
}
