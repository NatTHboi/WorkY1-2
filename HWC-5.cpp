/*
    HR ของบริษัทเน็ตเวิร์คทำการกรอกข้อมูลพนักงานลงไปในระบบคำนวณฐานภาษีเพื่อเตรียมส่งยอดภาษีสู่ฝ่ายบัญชี โดยจะหักภาษี ณ ที่จ่าย 7% ของเงินเดือนที่ได้ ให้คุณคำนวณภาษีพนักงานทั้งหมดที่บริษัทของคุณต้องชำระภายในปีนี้ (กรอกเลข -1 ถือเป็นการสิ้นสุดการกรอก และทำการสรุปผลภาษีที่ต้องชำระภายในปีนี้) และสร้างฟังก์ชันที่ระบุคนที่ต้องชำระภาษีเยอะที่สุดในบริษัทมาแสดงในผลสรุปยอดของบริษัทด้วย

    Test case:
        Employee 1's Name : 
            Omar
        Sarary (Bath/Month) : 
            12750
        Employee 2's Name : 
            Alice
        Sarary (Bath/Month) : 
            15900
        Employee 3's Name : 
            Max
        Sarary (Bath/Month) : 
            19860
        Employee 4's Name : 
            -1
    Output:
        All salary per month: 48,510.00 Bath
        All salary per year: 582,120.00 Bath
        Tax (7% per year) : 40,748.40 Bath
        Most tax in company : Max (16,682.40 Bath per year)

    Test case:
        Employee 1's Name : 
            John
        Sarary (Bath/Month) : 
            15780
        Employee 2's Name : 
            Oven
        Sarary (Bath/Month) : 
            16890
        Employee 3's Name : 
            May
        Sarary (Bath/Month) : 
            17870
        Employee 4's Name : 
            Bill
        Sarary (Bath/Month) : 
            22100
        Employee 5's Name : 
            -1
    Output:
        All salary per month: 72,640.00 Bath
        All salary per year: 871,680.00 Bath
        Tax (7% per year) : 61,017.60 Bath
        Most tax in company : Bill (18,564.00 Bath per year)
*/

#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    char name[50];
    float salary;
};

Employee findHighestTax(Employee employees[], int count) {
    Employee highestTaxEmployee = employees[0];
    float highestTax = employees[0].salary * 12 * 0.07;

    for (int i = 1; i < count; i++) {
        float currentTax = employees[i].salary * 12 * 0.07;
        if (currentTax > highestTax) {
            highestTax = currentTax;
            highestTaxEmployee = employees[i];
        }
    }
    return highestTaxEmployee;
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    float totalMonthlySalary = 0.0;

    while (1) {
        char name[50];
        float salary;

        printf("Employee %d's Name: \n", employeeCount + 1);
        scanf("%s", name);
        if (strcmp(name, "-1") == 0) break;

        printf("Salary (Bath/Month): \n");
        scanf("%f", &salary);

        strcpy(employees[employeeCount].name, name);
        employees[employeeCount].salary = salary;
        employeeCount++;

        totalMonthlySalary += salary;
    }

    float totalAnnualSalary = totalMonthlySalary * 12;
    float totalTax = totalAnnualSalary * 0.07;

    Employee highestTaxEmployee = findHighestTax(employees, employeeCount);
    float highestTax = highestTaxEmployee.salary * 12 * 0.07;

    printf("All salary per month: %.2f Bath\n", totalMonthlySalary);
    printf("All salary per year: %.2f Bath\n", totalAnnualSalary);
    printf("Tax (7%% per year) : %.2f Bath\n", totalTax);
    printf("Most tax in company : %s (%.2f Bath per year)\n", highestTaxEmployee.name, highestTax);

    return 0;
}
