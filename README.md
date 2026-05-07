# 输入一个字符窜，将123放入a\[0]456放入a\[1]，统计其整数个数并输出
## 使用fgets函数输入字符串
 ```C
* 统计字符串内的整数个数 *
* int nums_time=0;//标记i坐标的str是否为需要的数
    int num_integer=0;
    for(int i=0;i<strlen(str);){
        
        if(str_num(str[i])==-1){
            nums_time=-1;
            i++;
            continue;//不符合需要的整数直接下一循环
        }
        else 
            nums_time=1; //符合边赋值将nums_time赋值为1
        if(nums_time==1){
            while(str_num(str[i])!=-1)//循环至整数结束
                i++;
            num_integer++;//整数个数加一
        }
    } *   
```
 ```C
 * 将字符串写入整数 *
 * int integer=num_integer;//将整数个数记录；
    int *nums=(int*)malloc(num_integer*sizeof(int));//根据整数个数分配整数空间
    for(int i=0,j=0;num_integer!=0&&str[i]!='\0';){//循环条件
        int digit=0;//判断是否为整数的第一位
        if(str_num(str[i])!=-1){
            while(str_num(str[i])!=-1){
                if(digit==0){//第一位数便直接加上
                    nums[j]=str_num(str[i++]);
                    digit++;
                }else{//不是第一位便将数乘十比如'5'+'4'就是50+4
                   nums[j]*=10;
                   nums[j]+=str_num(str[i++]); 
                }
            }
            j++;//循环结束到下一个整数
            num_integer--;//剩余整数
        }
        else i++;//如果不符合就下一个
    }
    *
 ```
 #### 最后输出只需要设定输出整数数组范围最大小于integer便可 ####
