#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stuName[20][30];
int presentAttendance[20] = {0};
int absentAttendance[20] = {0};
int indexNumber = 0;
void checkAttendance()
{
    int i;
    printf("\n   Total Present | Total Absent \n ");
    for (i = 0; i < indexNumber; i++)
    {
        printf("%s", stuName[i]);
        printf("        %d        %d\n", presentAttendance[i], absentAttendance[i]);
    }
}
void addStudent()
{
    int i, num, add;
    if (indexNumber == 0)
    {
        printf("Enter how many student you want to add:");
        fflush(stdin);
        scanf("%d", &num);
        for (i = 0; i < num; i++)
        {
            printf("\n Enter %d student name to add in attendance ragister:", i + 1);
            fflush(stdin);
            gets(stuName[i]);
            indexNumber++;
        }
    }
    else
    {
        printf("Enter how many student you want to add:");
        fflush(stdin);
        scanf("%d", &num);
        add = indexNumber + num;
        for (i + indexNumber; i < add; i++)
        {
            printf("\n Enter %d student name to add in attendance ragister:", i + 1);
            fflush(stdin);
            gets(stuName[i]);
            indexNumber++;
        }
    }
}
void removeStudent()
{
    char name[30];
    printf("Enter student name  to remove:");
    fflush(stdin);
    gets(name);
    for (int i = 0; i < indexNumber; i++)
    {
        if (strcmp(name, stuName[i]) == 0)
        {
            for (int j = i; j < indexNumber; j++)
            {
                strcpy(stuName[j], stuName[j + 1]);
                presentAttendance[i] = presentAttendance[i + 1];
                absentAttendance[i] = absentAttendance[i + 1];
            }
            indexNumber--;
            printf("\n%s student is removed \n", name);
            break;
        }
        else if (i==indexNumber-1)
        {
            printf("This name is not exist \n");
        }
    }
}
void takeAttendance()
{
    int i;
    char ch;
    printf("\n Enter y for present and N for absent\n");
    for (i = 0; i < indexNumber; i++)
    {
    repeate:
        printf("%d. %s is present:", i + 1, stuName[i]);
        fflush(stdin);
        scanf("%c", &ch);
        if (ch == 'y' || ch == 'Y')
        {
            presentAttendance[i] += 1;
        }
        else if (ch == 'n' || ch == 'N')
        {
            absentAttendance[i] += 1;
        }
        else
        {
            printf("Invalid character try again \n");
            goto repeate;
        }
    }
}
void main()
{
    int choose;
    do
    {
        printf("\n******Main Menu******\n");
        printf("Enter 1 for add student\n");
        printf("Enter 2 for take attendance\n");
        printf("Enter 3 for check attendance\n");
        printf("Enter 4 for remove student\n");
        printf("Enter 5 for exit\n");
        printf("Please choose any menu:");
        fflush(stdin);
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            addStudent();
            break;
        case 2:
            takeAttendance();
            break;
        case 3:
            checkAttendance();
            break;
        case 4:
            removeStudent();
            break;
        case 5:
            exit(0);
            break;
        }
    } while (choose!=5);

}
