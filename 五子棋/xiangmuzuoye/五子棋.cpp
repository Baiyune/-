#include<iostream>
using namespace std;


// -------------------- 数据设计 --------------------
/*
    棋盘:
        map[i][j]表示坐标(i,j)的值
        0表示空地
        1表示黑子
        2表示白子
    如: map[3][6] = 1  表示(3,6)的位置是黑子
*/
int map[19][19];

// 表示当前回合数  偶数表示黑棋落子  奇数表示白棋落子
// 如: flag = 20 表示当前是第[20]次落子  由黑方落子
int flag;
// -------------------- 数据设计 --------------------


// -------------------- service --------------------
/*
    负责人: 张三
    功能: 初始化游戏数据
        将棋盘的值初始化为0
        当前回合设为黑棋(flag设为0)
    参数: void
    返回值: void
*/
void init();

/*
    *难点1
    负责人: 张三
    功能: 根据传入的坐标(map对应位置)和flag值 判断落点后是否获胜
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示没有获胜
        1表示黑子胜利
        2表示白子胜利
*/
int isWin(int x, int y);

/*
    负责人: 张三
    功能: 在指定位置落子
        如果map[x][y]是空地 则修改map[x][y]的值:改为相应颜色(flag对应颜色)
        否则不操作
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示落子失败 (棋盘已经有子)
        1表示落子成功

*/
int playerMove(int x, int y);
// -------------------- service --------------------



// -------------------- view --------------------
/*
    功能: 展示选项, 玩家可以在这里选择进入游戏, 进入设置或退出游戏
        进入游戏: 调用游戏界面函数gameView();
        进入设置: 敬请期待...
        退出游戏: 调用exit(0);
*/
void menuView();

/*
    负责人: 张三
    功能: 根据map数组 打印游戏棋盘
    参数: void
    返回值: void
*/
void gameView_ShowMap();

/*
    负责人: 张三
    功能: 根据flag的值  打印游戏胜利界面  用户可以按任意键回到主菜单
    参数: void
    返回值: void
*/
void winView();

/*
    *难点2
    负责人: 张三
    功能: 游戏界面整合
        初始化游戏数据(调用函数init())
        while(1){
            打印游戏界面(调用函数gameView_ShowMap())
            接收玩家坐标输入

            落子(调用落子函数playerMove())
                (如果落子失败 重新开始循环)

            判断游戏是否胜利(调用胜利判断函数isWin())
                (如果游戏胜利 调用胜利界面函数 然后结束当前界面)
            切换玩家(修改flag值)
        }
    参数: void
    返回值: void
*/
void gameView();
// -------------------- view --------------------

int main()//总调用
{
    menuView();
    system("pause");
    return 0;
}

void init() //初始化游戏数据
{
    for (int i = 0; i < 19; i++)//地图全设为空地
    {
        for (int j = 9; j < 19; j++)
        {
            map[i][j] = 0;
        }
    }
    flag = 0;//第0个回合，偶数，黑子落棋
}

int isWin(int x, int y) //判断胜利与否
{
    static int a = 0;//如果a最后为零，说明没有人赢
    for (int i = 0; i < 19; i++)//横着连五个
    {
        for (int j = 0; j < 15; j++)
        {
            if (map[i][j] == 1 && map[i][j + 1] == 1&& map[i][j + 2] == 1&& map[i][j + 3] == 1&& map[i][j + 4] == 1)
            {
                return 1;
                a = 1;
            }
            else if (map[i][j] == 2 && map[i][j + 1] == 2 && map[i][j + 2] == 2 && map[i][j + 3] == 2 && map[i][j + 4] == 2)
            {
                return 2;
                a = 2;
            }
        }
    }
    for (int i = 0; i < 15; i++)//竖着连五个
    {
        for (int j = 0; j < 19; j++)
        {
            if (map[i][j] == 1 && map[i+1][j] == 1 && map[i+2][j ] == 1 && map[i+3][j] == 1 && map[i+4][j ] == 1)
            {
                return 1;
                a = 1;
            }
            else if (map[i][j] == 2 && map[i+1][j] == 2 && map[i+2][j] == 2 && map[i+3][j] == 2 && map[i+4][j] == 2)
            {
                return 2;
                a = 2;
            }
        }
    }
    for (int i = 0; i < 15; i++)//从左上到右下斜着连五个,i,j是左上的那个元素
    {
        for (int j = 0; j < 15; j++)
        {
            if (map[i][j] == 1 && map[i+1][j +1] == 1 && map[i+2][j +2] == 1 && map[i+3][j + 3] == 1 && map[i+4][j + 4] == 1)
            {
                return 1;
                a = 1;
            }
            else if (map[i][j] == 2 && map[i+1][j + 1] == 2 && map[i+2][j + 2] == 2 && map[i+3][j + 3] == 2 && map[i+4][j + 4] == 2)
            {
                return 2;
                a = 2;
            }
        }
    }
    for (int i = 0; i < 15; i++)//从右上到左下斜着连五个，第一个是右上的那个的i，j,只看右上角的那个的范围
    {
        for (int j = 4; j < 19; j++)
        {
            if (map[i][j] == 1 && map[i+1][j - 1] == 1 && map[i + 2][j - 2] == 1 && map[i + 3][j -3] == 1 && map[i + 4][j -4] == 1)
            {
                return 1;
                a = 1;
            }
            else if (map[i][j] == 2 && map[i + 1][j - 1] == 2 && map[i + 2][j -2] == 2 && map[i + 3][j - 3] == 2 && map[i + 4][j - 4] == 2)
            {
                return 2;
                a = 2;
            }
        }
    }
    if (a == 0)//没人赢
    {
        return 0;
    }
}

int playerMove(int x, int y) //执行落子操作
{
    if (map[x][y] == 0)//判断是空地
    {
        if (flag % 2 == 0)
        {
            map[x][y] = 1;//落黑子
        }
        else
        {
            map[x][y] = 2;//落白子
        }
        return 1;
    }
    else//不为空地,有子了
    {
        return 0;
    }

}

void menuView()//展示菜单
{
    cout << "1、进入游戏" << endl;
    cout << "2、进入设置" << endl;
    cout << "3、退出游戏" << endl;
    cout << "请输入数字进行选择" << endl;
    int a;//a为输入的数字
    while (1)
    {
        cin >> a;
        if ((a != 1) && (a != 2) && (a != 3))//用&&,不是||
        {
            cout << "输入有误，请重新输入" << endl;
            continue;
        }
        else
        {
            switch (a)
            {
            case 1:
                gameView();
                break;
            case 2:
                cout << "敬请期待......请再次进行选择" << endl;
                continue;
                break;//可以不加break，加了更规范
            case 3:
                exit(0);
                break;//可以不加break，加了更规范
            }
        }
    }
}

void gameView_ShowMap() //打印棋盘
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void winView()//如果有人胜利了，就打印胜利界面
{
    if(flag%2==0)//黑子回合的胜利了，说明是黑子赢了，因为是最后才flag++的，此时flag仍为偶
    {
        cout << "恭喜小黑子胜利" << endl;
    }
    else if (flag%2==1)
    {
        cout << "恭喜白子胜利" << endl;
    }
}

void gameView() //游戏界面整合
{
    init();
    while (1)
    {
        static int x = 0;
        static int y = 0;
        gameView_ShowMap();
        if (flag % 2 == 0)
        {
            cout << "请小黑子落棋,输入坐标x、y（均从0开始），1代表小黑子" << endl;
            cin >> x >> y;
        }
        else if (flag % 2 == 1)
        {
            cout << "请白子落棋,输入坐标x、y（均从0开始），2代表白子" << endl;
            cin >> x >> y;
        }
        if (playerMove(x, y)==1)//算是调用palyerMove了
        {
            cout << "落子成功" << endl;
            system("pause");
            system("cls");
        }
        else if (playerMove(x, y) == 0)
        {
            cout << "落子失败,此位置已有棋子，请重新落子" << endl;
            system("pause");
            system("cls");
            continue;
        }
        if (isWin(x, y))//为真代表有人赢了
        {
            gameView_ShowMap();
            winView();
            system("pause");
            exit(0);
        }
        flag++;
    }
}