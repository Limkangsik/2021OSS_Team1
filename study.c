#include <stdio.h>

typedef struct
{
    char name[20]; //student name
    char id[10];   //student ID
    char sub[20];
    int year;
    int groubNumber;
} Student;

int selectMenu()
{
    int menu;

    printf("\n*****Study Together*****\n");
    printf("1. �л� ��ȸ�ϱ�       *\n");
    printf("2. �׷� ��ȸ�ϱ�       *\n");
    printf("3. �л� �߰��ϱ�       *\n");
    printf("4. �л� �����ϱ�       *\n");
    printf("5. �л� �����ϱ�       *\n");
    printf("6. �׷� �����ϱ�       *\n");
    printf("7. �л� �˻��ϱ�       *\n");
    printf("8. �׷� �˻��ϱ�       *\n");
    printf("9. �׷� �����ϱ�       *\n");
    printf("0. ���α׷� ����       *\n");
    printf("************************\n");
    printf("\n=> �޴��� ���ÿ� : ");
    scanf("%d", &menu);

    return menu;
}

int createStudent(Student *s)
{
    printf("�л� �̸�(ex. ȫ�浿) : ");
    scanf("%s", s->name);
    printf("�й� (ex. 21700***) : ");
    scanf("%s", s->id);
    printf("�г� : ");
    scanf("%d", &s->year);
    getchar();
    printf("��� ���� (ex. ������ ����) :");
    scanf("%[^\n]", s->sub);

    return 1;
}

void readStudent(Student s)
{
    printf("%s\t%s\t%d\t%s\n", s.name, s.id, s.year, s.sub);
}

int updateStudent(Student *s)
{
    printf("�л� �̸�(ex. ȫ�浿) : ");
    scanf("%s", s->name);
    printf("�й� (ex. 21700***) : ");
    scanf("%s", s->id);
    printf("�г� : ");
    scanf("%d", &s->year);
    getchar();
    printf("��� ���� (ex. ������ ����) : ");
    scanf("%[^\n]", s->sub);

    return 1;
}

int deleteStudent(Student *s)
{
    s->year = -1;

    return 1;
}

int createGroup(Student s[])
{   
    int stack = 1;
    int setG = 1;
    char targetSub[20];
    printf("�׷��� ������ ����(ex. ������ ����) : ");
    scanf("%s", &targetSub);
    int size = sizeof(s);
    for(int i = 0; i < s; i++){
        if(s[i].sub == targetSub){
            if(stack%4 == 0) setG++;
            s[i].groubNumber = setG;
            stack++;
        }
    }

    return 1;
}

void readGroup(Student s[])
{
    int gn = 10;
    int size = sizeof(s);
    char targetsub[20];

    printf("�ҷ��� �׷츮��Ʈ�� ����(ex. ������ ����");
    scanf("%s", &targetsub);

    for(int i = 1; i < gn; i++){
        printf("Group %d\n", i);
        for(int j = 0; j < size; j++){
            if(s[j].sub == targetsub && s[j].groubNumber == i) printf("%d %s\t",s[j].id, s[j].name);
        }
        printf("\n");
    }    
}