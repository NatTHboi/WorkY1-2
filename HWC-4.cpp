/*
    ผู้บริหารต้องการวิเคราะห์พัฒนาการของพนักงานในบริษัทและศักยภาพของพนักงานจากทักษะที่พัฒนาขึ้นของแต่ละคน ซึ่งแปลงค่าความสามารถของแต่ละคนออกมาเป็นค่า EXP โดยแบ่งอัตราการขึ้นเงินเดือนของแต่ละคนดังนี้
    EXP อยู่ในช่วง 0-1,000 		จะได้รับเงินเดือน x1
	EXP อยู่ในช่วง 1,000-2,000 	จะได้รับเงินเดือน x1.2
	EXP อยู่ในช่วง 2,000-3,000 	จะได้รับเงินเดือน x1.4
	EXP อยู่ในช่วง 3,000-4,000 	จะได้รับเงินเดือน x1.6
	EXP อยู่ในช่วง 4,000-5,000 	จะได้รับเงินเดือน x1.8
	EXP อยู่ในช่วง 5,000 ขึ้นไป	จะได้รับเงินเดือน x2
    โดยผู้บริหารมอบหมายให้ HR เป็นคนกรอกข้อมูลพนักงานในบริษัทและประเมินค่า EXP ของพนักงานแต่ละคน พร้อมสรุปจำนวนคนที่ได้รับเงินเดือนในแต่ละขั้น และระบุคนชื่อคนที่ได้เงินเดือนเยอะที่สุด และคนที่เงินเดือนน้อยที่สุด (หากกรอกเลข -1 ในช่อง Name จะถือเป็นการหยุดโปรแกรมและเตรียมแสดงผล)
    
    Test case:
        Employee 1 Name : 
            Atom
        EXP : 
            2500
        Employee 2 Name : 
            Aom
        EXP : 
            3230
        Employee 3 Name : 
            Aim
        EXP : 
            4560
        Employee 4 Name : 
            Jom
        EXP : 
            5505
        Employee 5 Name : 
            On
        EXP : 
            950
        Employee 6 Name : 
            Oom
        EXP : 
            3500
        Employee 7 Name : 
            Ky
        EXP : 
            2600
        Employee  Name : 
            -1
    Output:
        **** Salary Result ****
        x1.0 count 1
        x1.2 count 0
        x1.4 count 2
        x1.6 count 2
        x1.8 count 1
        x2.0 count 1
        The Employee get x2.0 is Jom
        The Employee get x1.0 is On

    Test case:
        Employee 1 Name : 
            Aey
        EXP : 
            9956
        Employee 2 Name : 
            J
        EXP : 
            4900
        Employee 3 Name : 
            A
        EXP : 
            4560
        Employee 4 Name : 
            Orio
        EXP : 
            200
        Employee 5 Name : 
            Vistra
        EXP : 
            1656
        Employee 6 Name : 
            Oh
        EXP : 
            2300
        Employee  Name : 
            -1
    Output:
        **** Salary Result ****
        x1.0 count 1
        x1.2 count 1
        x1.4 count 1
        x1.6 count 0
        x1.8 count 2
        x2.0 count 1
        The Employee get x2.0 is Aey
        The Employee get x1.0 is Orio
*/

#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    char name[50];
    int exp;
    float salaryMultiplier;
};

int main() {
    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    int salaryCounts[6] = {0};
    Employee highestPaid, lowestPaid;

    highestPaid.salaryMultiplier = 0.0;
    lowestPaid.salaryMultiplier = 100.0;

    while (1) {
        char name[50];
        int exp;

        printf("Employee %d Name: \n", employeeCount + 1);
        scanf("%s", name);
        if (strcmp(name, "-1") == 0) break;

        printf("EXP: \n");
        scanf("%d", &exp);

        float salaryMultiplier;
        if (exp < 1000) salaryMultiplier = 1.0;
        else if (exp < 2000) salaryMultiplier = 1.2;
        else if (exp < 3000) salaryMultiplier = 1.4;
        else if (exp < 4000) salaryMultiplier = 1.6;
        else if (exp < 5000) salaryMultiplier = 1.8;
        else salaryMultiplier = 2.0;

        strcpy(employees[employeeCount].name, name);
        employees[employeeCount].exp = exp;
        employees[employeeCount].salaryMultiplier = salaryMultiplier;
        employeeCount++;

        if (salaryMultiplier == 1.0) salaryCounts[0]++;
        else if (salaryMultiplier == 1.2) salaryCounts[1]++;
        else if (salaryMultiplier == 1.4) salaryCounts[2]++;
        else if (salaryMultiplier == 1.6) salaryCounts[3]++;
        else if (salaryMultiplier == 1.8) salaryCounts[4]++;
        else if (salaryMultiplier == 2.0) salaryCounts[5]++;

        if (salaryMultiplier > highestPaid.salaryMultiplier) {
            highestPaid = employees[employeeCount - 1];
        }
        if (salaryMultiplier < lowestPaid.salaryMultiplier) {
            lowestPaid = employees[employeeCount - 1];
        }
    }

    printf("**** Salary Result ****\n");
    printf("x1.0 count %d\n", salaryCounts[0]);
    printf("x1.2 count %d\n", salaryCounts[1]);
    printf("x1.4 count %d\n", salaryCounts[2]);
    printf("x1.6 count %d\n", salaryCounts[3]);
    printf("x1.8 count %d\n", salaryCounts[4]);
    printf("x2.0 count %d\n", salaryCounts[5]);

    printf("The Employee get x2.0 is %s\n", highestPaid.name);
    printf("The Employee get x1.0 is %s\n", lowestPaid.name);

    return 0;
}