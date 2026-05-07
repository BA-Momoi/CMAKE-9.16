#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int str_num(char __char){
    char arr[10]={'0','1','2','3','4','5','6','7','8','9'};
    for(int i=0;i<=10;i++){
        if(__char==arr[i])
            return i;
    }
    return -1;
}
int main(){
    char *str=(char*)malloc(101*sizeof(char));
    printf("请输入字符串:");
    fgets(str,100,stdin);//应该最多就五十组连续的整数
    int nums_time=0;
    int num_integer=0;
    for(int i=0;i<strlen(str);){
        
        if(str_num(str[i])==-1){
            nums_time=-1;
            i++;
            continue;
        }
        else 
            nums_time=1; 
        if(nums_time==1){
            while(str_num(str[i])!=-1)
                i++;
            num_integer++;
        }
    }   
    int integer=num_integer;
    int *nums=(int*)malloc(num_integer*sizeof(int));
    for(int i=0,j=0;num_integer!=0&&str[i]!='\0';){
        int digit_times=0;
        int digit=0;
        if(str_num(str[i])!=-1){
            while(str_num(str[i])!=-1){
                if(digit==0){
                    nums[j]=str_num(str[i++]);
                    digit++;
                }else{
                   nums[j]*=10;
                   nums[j]+=str_num(str[i++]); 
                }
            }
            j++;
            num_integer--;
        }
        else i++;
    }
    printf("have %d nums\n",integer);
    for(int i=0;i<integer;i++){
        printf("%-3d.%20d\n",i,nums[i]);
    }
    return 0;
}
