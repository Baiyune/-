#include<iostream>
using namespace std;


// -------------------- ������� --------------------
/*
    ����:
        map[i][j]��ʾ����(i,j)��ֵ
        0��ʾ�յ�
        1��ʾ����
        2��ʾ����
    ��: map[3][6] = 1  ��ʾ(3,6)��λ���Ǻ���
*/
int map[19][19];

// ��ʾ��ǰ�غ���  ż����ʾ��������  ������ʾ��������
// ��: flag = 20 ��ʾ��ǰ�ǵ�[20]������  �ɺڷ�����
int flag;
// -------------------- ������� --------------------


// -------------------- service --------------------
/*
    ������: ����
    ����: ��ʼ����Ϸ����
        �����̵�ֵ��ʼ��Ϊ0
        ��ǰ�غ���Ϊ����(flag��Ϊ0)
    ����: void
    ����ֵ: void
*/
void init();

/*
    *�ѵ�1
    ������: ����
    ����: ���ݴ��������(map��Ӧλ��)��flagֵ �ж������Ƿ��ʤ
    ����:
        x: ��ǰ�غ����ӵ�x����
        y: ��ǰ�غ����ӵ�y����
    ����ֵ:
        0��ʾû�л�ʤ
        1��ʾ����ʤ��
        2��ʾ����ʤ��
*/
int isWin(int x, int y);

/*
    ������: ����
    ����: ��ָ��λ������
        ���map[x][y]�ǿյ� ���޸�map[x][y]��ֵ:��Ϊ��Ӧ��ɫ(flag��Ӧ��ɫ)
        ���򲻲���
    ����:
        x: ��ǰ�غ����ӵ�x����
        y: ��ǰ�غ����ӵ�y����
    ����ֵ:
        0��ʾ����ʧ�� (�����Ѿ�����)
        1��ʾ���ӳɹ�

*/
int playerMove(int x, int y);
// -------------------- service --------------------



// -------------------- view --------------------
/*
    ����: չʾѡ��, ��ҿ���������ѡ�������Ϸ, �������û��˳���Ϸ
        ������Ϸ: ������Ϸ���溯��gameView();
        ��������: �����ڴ�...
        �˳���Ϸ: ����exit(0);
*/
void menuView();

/*
    ������: ����
    ����: ����map���� ��ӡ��Ϸ����
    ����: void
    ����ֵ: void
*/
void gameView_ShowMap();

/*
    ������: ����
    ����: ����flag��ֵ  ��ӡ��Ϸʤ������  �û����԰�������ص����˵�
    ����: void
    ����ֵ: void
*/
void winView();

/*
    *�ѵ�2
    ������: ����
    ����: ��Ϸ��������
        ��ʼ����Ϸ����(���ú���init())
        while(1){
            ��ӡ��Ϸ����(���ú���gameView_ShowMap())
            ���������������

            ����(�������Ӻ���playerMove())
                (�������ʧ�� ���¿�ʼѭ��)

            �ж���Ϸ�Ƿ�ʤ��(����ʤ���жϺ���isWin())
                (�����Ϸʤ�� ����ʤ�����溯�� Ȼ�������ǰ����)
            �л����(�޸�flagֵ)
        }
    ����: void
    ����ֵ: void
*/
void gameView();
// -------------------- view --------------------

int main()//�ܵ���
{
    menuView();
    system("pause");
    return 0;
}

void init() //��ʼ����Ϸ����
{
    for (int i = 0; i < 19; i++)//��ͼȫ��Ϊ�յ�
    {
        for (int j = 9; j < 19; j++)
        {
            map[i][j] = 0;
        }
    }
    flag = 0;//��0���غϣ�ż������������
}

int isWin(int x, int y) //�ж�ʤ�����
{
    static int a = 0;//���a���Ϊ�㣬˵��û����Ӯ
    for (int i = 0; i < 19; i++)//���������
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
    for (int i = 0; i < 15; i++)//���������
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
    for (int i = 0; i < 15; i++)//�����ϵ�����б�������,i,j�����ϵ��Ǹ�Ԫ��
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
    for (int i = 0; i < 15; i++)//�����ϵ�����б�����������һ�������ϵ��Ǹ���i��j,ֻ�����Ͻǵ��Ǹ��ķ�Χ
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
    if (a == 0)//û��Ӯ
    {
        return 0;
    }
}

int playerMove(int x, int y) //ִ�����Ӳ���
{
    if (map[x][y] == 0)//�ж��ǿյ�
    {
        if (flag % 2 == 0)
        {
            map[x][y] = 1;//�����
        }
        else
        {
            map[x][y] = 2;//�����
        }
        return 1;
    }
    else//��Ϊ�յ�,������
    {
        return 0;
    }

}

void menuView()//չʾ�˵�
{
    cout << "1��������Ϸ" << endl;
    cout << "2����������" << endl;
    cout << "3���˳���Ϸ" << endl;
    cout << "���������ֽ���ѡ��" << endl;
    int a;//aΪ���������
    while (1)
    {
        cin >> a;
        if ((a != 1) && (a != 2) && (a != 3))//��&&,����||
        {
            cout << "������������������" << endl;
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
                cout << "�����ڴ�......���ٴν���ѡ��" << endl;
                continue;
                break;//���Բ���break�����˸��淶
            case 3:
                exit(0);
                break;//���Բ���break�����˸��淶
            }
        }
    }
}

void gameView_ShowMap() //��ӡ����
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

void winView()//�������ʤ���ˣ��ʹ�ӡʤ������
{
    if(flag%2==0)//���ӻغϵ�ʤ���ˣ�˵���Ǻ���Ӯ�ˣ���Ϊ������flag++�ģ���ʱflag��Ϊż
    {
        cout << "��ϲС����ʤ��" << endl;
    }
    else if (flag%2==1)
    {
        cout << "��ϲ����ʤ��" << endl;
    }
}

void gameView() //��Ϸ��������
{
    init();
    while (1)
    {
        static int x = 0;
        static int y = 0;
        gameView_ShowMap();
        if (flag % 2 == 0)
        {
            cout << "��С��������,��������x��y������0��ʼ����1����С����" << endl;
            cin >> x >> y;
        }
        else if (flag % 2 == 1)
        {
            cout << "���������,��������x��y������0��ʼ����2�������" << endl;
            cin >> x >> y;
        }
        if (playerMove(x, y)==1)//���ǵ���palyerMove��
        {
            cout << "���ӳɹ�" << endl;
            system("pause");
            system("cls");
        }
        else if (playerMove(x, y) == 0)
        {
            cout << "����ʧ��,��λ���������ӣ�����������" << endl;
            system("pause");
            system("cls");
            continue;
        }
        if (isWin(x, y))//Ϊ���������Ӯ��
        {
            gameView_ShowMap();
            winView();
            system("pause");
            exit(0);
        }
        flag++;
    }
}