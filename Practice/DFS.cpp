#include<iostream>

using namespace std;

//����1������ָ�
//
//6x6�ķ������Ÿ��ӵı��߼����������֡�
//Ҫ���������ֵ���״��ȫ��ͬ��
//�Լ��㣺
//������3�ַַ����ڣ�һ���ж����ֲ�ͬ�ķָ����
//ע�⣺��ת�ԳƵ�����ͬһ�ַָ��
int dir[4][2] = { 0,1, 0,-1, 1,0, -1,0 };	 //����һ����ά�����������������
const int maxn = 7;
int vis[maxn][maxn];
int ans = 0;  							//ansͳ�ƴ���
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
            if (!vis[x1][y1])			//�߼�ȡ��
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
    memset(vis, 0, sizeof(vis));  //vis�����ʼ��0�Ŀ�ݷ���
    vis[3][3] = 1;
    dfs1(3, 3);
    printf("%d\n", ans / 4);

    return 0;
}



//����2��
//������������
//С�����ϲ�������ֻ�ľ��һ����10���ľ��ÿ����ľ����һ�����֣�0~9��
//���ľ����
//ÿ����ľ�ŵ�����������ľ�����棬����һ���������������ľ����С��
//�����4��Ľ������Σ������������еĻ�ľ��
//0
//1 2
//3 4 5
//6 7 8 9	������������Ĵһ���ж����֣�

int visited[10] = { 0 };                            //�鿴��Ԫ���Ƿ񱻷���   ȫ����ֵΪ0
int a[10] = { 0};
int sum = 0;                                      //����ȫ�ֱ���sum�����жԷ�����������ϼ���


int test(int n) {                                //�жϻ�����������
    if (n == 2) {					//��������ľ �ڶ���ʱ
        if (a[0]<a[1] && a[0]<a[2]) {
            return 1;
        }
        return 0;
    }
    else if (n == 5) {				//������ľ ������ʱ
        if (a[1]<a[3] && a[1]<a[4] && a[2]<a[4] && a[2]<a[5]) {
            return 1;
        }
        return 0;
    }
    else if (n == 9) {				//10����ľ ���Ĳ�ʱ
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
        if (!visited[i]) {		//���������visited[i]=0
            visited[i] = 1;		//visited��ֵΪ1 �����Ѿ�����
            a[n] = i;
            if (!test(n)) {		//���test[n]=0  ���ʾ����������
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
