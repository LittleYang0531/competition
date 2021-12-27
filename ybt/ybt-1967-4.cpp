/*===============================================================
本段代码不是模拟填写数字的过程，而是直接根据i和j的值计算(i，j)所在的层k。
然后计算第k层左上角（k,k）位置处的元素值。
接下来呢，要寻到 (i,j)处的值，可以有两种方法：
（1）模拟填数字的过程环绕一圈寻找(i，j)。
（2）根据i，j的值依次计算（k，k）距离（i，j）的几个段的距离即可得到答案。
这里使用第二个方案。
=================================================================*/
#include<stdio.h>
int main()
{
    int n,i,j;
    int k,t;
//    freopen("matrix10.in","r",stdin);
//    freopen("matrix10.txt","w",stdout);
    scanf("%d%d%d",&n,&i,&j);
    //根据i判断（i，j）所在层数k
    t=(n+1)/2;
    if(i<=t)
    {
        if(j<=t)  k=(i<=j?i:j);//（i,j）在左上部分
        else k=(i<(n+1-j)?i:(n+1-j));  //(i,j)在右上部分
    }
    else
    {
        if(j<=t) k=(n+1-i)<j?(n+1-i):j;   //（i,j）在左下部分
        else k=(n+1-i)<(n+1-j)?(n+1-i):(n+1-j);   //（i,j）在右下部分
    }
    //计算第k层左上角坐标为（k，k）的数t
    k--;
    t=n*n-(n-2*k)*(n-2*k)+1;//注意：n-2k表示剥去k层之后剩余部分的行数和列数.(i,j)所在层没被剥掉，故而要先执行k--。
    k++;
    if(i==k) //(i,j)在第k环的上边线
        t=t+(j-k);
    else if(j==k+n-2*(k-1)-1) //(i,j)在环的右边.
        t=t+(n-2*(k-1)-1)+(i-k);
    else if(i==k+n-2*(k-1)-1)//(i,j)在环的下边
        t=t+(n-2*(k-1)-1)+(n-2*(k-1)-1)+((k+n-2*(k-1)-1)-j);
    else t=t+(n-2*(k-1)-1)+(n-2*(k-1)-1)+(n-2*(k-1)-1)+((k+n-2*(k-1)-1)-i);
    printf("%d\n",t);
    return 0;
}
