#include<iostream>
using namespace std;
 
const int N = 505;
 
struct option
{
    char a[5], b[5];        //a表示喜欢的动物。b表示不喜欢的动物
};
 
int maze[N][N];
option cat[N], dog[N];
int isvisit[N];
int match[N];
int c, d, v;
int cnt_cat, cnt_dog;
 
bool find (int u)                        //匈牙利算法
{
    for (int i = 0; i < cnt_dog; i++)
        if (maze[u][i] && !isvisit[i])
        {
            isvisit[i] = true;
            if (match[i] == -1 || find(match[i]))
            {
                match[i] = u;
                return true;
            }
        }
 
    return false;
}
 
int main()
{
    int cases;
    char a[5];
    char b[5];
 
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d%d%d", &c, &d, &v);
        cnt_cat = 0;
        cnt_dog = 0;
        for (int i = 0; i < v; i++)  
        {
            scanf("%s%s", a, b);
     
            if (a[0] == 'C')
            {
                strcpy(cat[cnt_cat].a, a);
                strcpy(cat[cnt_cat].b, b);
                cnt_cat++;                        //统计喜欢猫人数
            }
            else
            {
                strcpy(dog[cnt_dog].a, a);
                strcpy(dog[cnt_dog].b, b);
                cnt_dog++;
            }       
        }
 
        memset(maze, false, sizeof(maze));
        for (int i = 0; i < cnt_cat; i++)
            for (int j = 0; j < cnt_dog; j++)        
                if (strcmp(cat[i].a, dog[j].b) == 0 || strcmp(cat[i].b, dog[j].a) == 0)             
                    maze[i][j] = true;
                 
        int ans = 0;
        memset(match, -1, sizeof(match));
        for (int i = 0; i < cnt_cat; i++)
        {
            memset(isvisit, false, sizeof(isvisit));
            if (find(i))
                ans++;
        }
 
        printf("%d\n", v-ans);
    }
    return 0;
}
