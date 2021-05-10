#include "manager.h"
#include <stdio.h>
#include <string.h>

int listStudent(Student *s, int count)
{
    int i;
    printf("No.\t �̸�\t�й�\t\t�г�\t����\n");
    for (i = 0; i < count; i++)
    {
        if (s[i].year == -1)
            continue;
        printf("%d\t", i + 1);
        readStudent(s[i]);
    }
    if (i == 0)
        return 0;
    return 1;
}

int selectStudent(Student *s, int count)
{
    int no;
    listStudent(s, count);
    printf("�л� ��Ϲ�ȣ(���:0) : ");
    scanf("%d", &no);
    getchar();
    return no;
}

int makeGroup(Student *s, Group *g, int count)
{

    char targetsub[10];
    printf("�׷��� ������ ����(ex. ������ ����) : ");
    scanf("%[^\n]", targetsub);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (strstr(s[i].sub, targetsub))
            {
                strcpy(g->group_mem[j], s[j].id);
                strcpy(g->sub, targetsub);
                g->group_num = i + 1;
                g->st_num = j + 1;
            }
            else
                return 1;
        }
        printf("��� �� : %d", g[i].st_num);
        printf("�׷� �� : %d", g[i].group_num);
    }

    return 1;
}
int listGroup(Group *g, int count)
{
    int i;
    printf("�����\t�׷� ��ȣ\t�׷��\n");
    for (i = 0; i < count; i++)
    {
        readGroup(g[i]);
    }
    if (i == 0)
        return 0;
    return 1;
}
