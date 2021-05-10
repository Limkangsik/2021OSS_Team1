#include <stdio.h>
#include "study.h"
#include "manager.h"

int main()
{
    Student st[20];
    Group gr[10];

    int count_st = 0, count_gr = 0;
    int index_st = 0, index_gr = 0;
    int menu;

    while (1)
    {
        menu = selectMenu();

        if (menu == 0)
            break;
        if ((menu != 3) && (count_st == 0))
        {
            printf("=> ������ ����\n");
            continue;
        }
        else if (menu == 3)
        {
            count_st += createStudent(&st[index_st++]);
        }
        else if (menu == 1)
        {

            int islist;
            islist = listStudent(st, index_st);
            if (islist == 0)
                printf("=> ������ ����\n");
        }
        else if (menu == 4)
        {
            int isup;
            int no;
            no = selectStudent(st, index_st);
            if (no > 0)
                isup = updateStudent(&st[no - 1]);
            else if (no == 0)
                continue;
            if (isup == 1)
                printf("\n=> ���� ����\n");
            else
                printf("\n=> ���� ����\n");
        }
        else if (menu == 5)
        {
            int isdel;
            int no, con;
            no = selectStudent(st, index_st);
            if (no > 0)
            {
                printf("������ �����Ͻðڽ��ϱ�? (����:1)");
                scanf("%d", &con);
                if (con == 1)
                {
                    isdel = deleteStudent(&st[no - 1]);
                    if (isdel == 1)
                    {
                        printf("\n=> ���� ����\n");
                        count_st--;
                    }
                    else
                        printf("\n=> ���� ����\n");
                }
                else
                {
                    printf("\n=> ���� ���\n");
                    continue;
                }
            }
        }
        else if (menu == 6)
        {
            count_gr += makeGroup(st, &gr[index_gr++], index_st);
        }
        else if (menu == 2)
        {
            int islist;
            islist = listGroup(gr, index_gr);
            if (islist == 0)
                printf("=> ������ ����\n");
        }
    }
}