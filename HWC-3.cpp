/*
    ผู้ใช้กรอกข้อมูลพนักงานในบริษัท โดยจะกรอกข้อมูล ชื่อ, เงินเดือน, อายุการทำงาน ของแต่ละคน โดยเมื่อผู้ใช้กรอกตัว n จะถือเป็นการหยุดโปรแกรมและทำการแสดงข้อมูลเงินเดือนเฉลี่ยของพนักงานในบริษัท และเงินเดือนของทุกคนรวมกันที่ผู้บริหารต้องจ่าย และแสดงคนที่อายุงานเยอะที่สุดพร้อมระบุ ชื่อ เงินเดือน และอายุงาน ของคนๆ นั้น
    
    Test case:
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Yorn
        Salary (Bath/Month) : 
            15000
        Duration (Year) : 
            4
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Van
        Salary (Bath/Month) : 
            14550
        Duration (Year) : 
            2
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Thane
        Salary (Bath/Month) : 
            22500
        Duration (Year) : 
            8
        Do you want to Enter Employee Information? (y/n) : 
            n
    Output:
        Average of Salary : 17,350.00 Bath
        Payment of every month : 52,050.00 Bath
        ----------------------------------------
        ** Most duration in this business **
        Name : Thane (8 Years)
        Salary : 22,500.00 Bath

*/

//TODO: #21 output money should in decimal format (eg. 120,200,340.42).

#include <stdio.h>
#include <string.h>

struct Employee {
    char Name[50];
    float Salary;
    int Duration;
};

void formatNumber(char *formatted, double number) {
    sprintf(formatted, "%.2f", number);
    int len = strlen(formatted);
    int insert_pos = len - 6;

    while (insert_pos > 0 && formatted[insert_pos - 1] != '-') {
        memmove(formatted + insert_pos + 1, formatted + insert_pos, len - insert_pos + 1);
        formatted[insert_pos] = ',';
        insert_pos -= 3;
        len++;
    }
}

int main() {
    struct Employee employees[100];
    int count = 0;
    char choice;
    float totalSalary = 0;
    struct Employee mostExperienced = {"", 0, 0};

    do {
        printf("Do you want to Enter Employee Information? (y/n) : ");
        scanf(" %c", &choice);

        if (choice == 'y') {
            printf("----\n");
            printf("Employee Name : ");
            scanf("%s", employees[count].Name);
            printf("Salary (Bath/Month) : ");
            scanf("%f", &employees[count].Salary);
            printf("Duration (Year) : ");
            scanf("%d", &employees[count].Duration);

            totalSalary += employees[count].Salary;

            if (employees[count].Duration > mostExperienced.Duration) {
                mostExperienced = employees[count];
            }

            count++;
        }
    } while (choice != 'n');

    float averageSalary = (count > 0) ? totalSalary / count : 0;

    char formattedTotalSalary[50], formattedAverageSalary[50], formattedMostSalary[50];
    formatNumber(formattedTotalSalary, totalSalary);
    formatNumber(formattedAverageSalary, averageSalary);
    formatNumber(formattedMostSalary, mostExperienced.Salary);

    printf("\nAverage of Salary : %s Bath\n", formattedAverageSalary);
    printf("Payment of every month : %s Bath\n", formattedTotalSalary);
    printf("----------------------------------------\n");
    if (count > 0) {
        printf("** Most duration in this business **\n");
        printf("Name : %s (%d Years)\n", mostExperienced.Name, mostExperienced.Duration);
        printf("Salary : %s Bath\n", formattedMostSalary);
    } else {
        printf("No employee data entered.\n");
    }

    return 0;
}