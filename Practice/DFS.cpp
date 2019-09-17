#include<iostream>

using namespace std;

//例题1：方格分割
//
//6x6的方格，沿着格子的边线剪开成两部分。
//要求这两部分的形状完全相同。
//试计算：
//包括这3种分法在内，一共有多少种不同的分割方法。
//注意：旋转对称的属于同一种分割法。
int dir[4][2] = { 0,1, 0,-1, 1,0, -1,0 };	 //定义一个二维数组来存放搜索方向
const int maxn = 7;
int vis[maxn][maxn];
int ans = 0;  							//ans统计次数
void dfs1(int x, int y)
{
    if (x == 0 || y == 0 || x == 6 || y == 6)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int x1 = x + dir[i][0];
        int y1 = y + dir[i][1];

        int x2 = 6 - x1;
        int y2 = 6 - y1;

        if (x1 >= 0 && y1 >= 0 && x1 <= 6 && y1 <= 6)
        {
            if (!vis[x1][y1])			//逻辑取反
            {
                vis[x1][y1] = vis[x2][y2] = 1;
                dfs1(x1, y1);
                vis[x1][y1] = vis[x2][y2] = 0;
            }
        }
    }
    return;
}


int DFS_test1() {
    memset(vis, 0, sizeof(vis));  //vis数组初始化0的快捷方法
    vis[3][3] = 1;
    dfs1(3, 3);
    printf("%d\n", ans / 4);

    return 0;
}



//例题2：
//【问题描述】
//小明最近喜欢搭数字积木。一共有10块积木，每个积木上有一个数字，0~9。
//搭积木规则：
//每个积木放到其它两个积木的上面，并且一定比下面的两个积木数字小。
//最后搭成4层的金字塔形，必须用完所有的积木。
//0
//1 2
//3 4 5
//6 7 8 9	请你计算这样的搭法一共有多少种？

int visited[10] = { 0 };                            //查看该元素是否被访问   全部赋值为0
int a[10] = { 0};
int sum = 0;                                      //定义全局变量sum来进行对符合条件的组合计数


int test(int n) {                                //判断基本符合条件
    if (n == 2) {					//当三个积木 第二层时
        if (a[0]<a[1] && a[0]<a[2]) {
            return 1;
        }
        return 0;
    }
    else if (n == 5) {				//六个积木 第三层时
        if (a[1]<a[3] && a[1]<a[4] && a[2]<a[4] && a[2]<a[5]) {
            return 1;
        }
        return 0;
    }
    else if (n == 9) {				//10个积木 第四层时
        if (a[3]<a[6] && a[3]<a[7] && a[4]<a[7] && a[4]<a[8] && a[5]<a[8] && a[5]<a[9]) {
            sum++;
            return 1;
        }
        return 0;
    }
    else
        return 1;
}


void dfs2(int n) {
    int i;
    for (i = 0; i<10; i++) {
        if (!visited[i]) {		//如果不对则visited[i]=0
            visited[i] = 1;		//visited赋值为1 代表已经访问
            a[n] = i;
            if (!test(n)) {		//如果test[n]=0  则表示不符合条件
                visited[i] = 0;
                continue;
            }
            dfs2(n + 1);
            visited[i] = 0;
        }
    }
    return;
}


int DFS_test2() {
    dfs2(0);
    printf("%d\n", sum);
    return 0;
}
