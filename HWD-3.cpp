/*
    HR ของบริษัทเน็ตเวิร์คทำการกรอกข้อมูลพนักงานลงไปในระบบคำนวณฐานภาษีเพื่อเตรียมส่งยอดภาษีสู่ฝ่ายบัญชี โดยจะหักภาษี ณ ที่จ่าย 7% ของเงินเดือนที่ได้ ให้คุณคำนวณภาษีพนักงานทั้งหมดที่บริษัทของคุณต้องชำระภายในปีนี้ (กรอกเลข -1 ถือเป็นการสิ้นสุดการกรอก และทำการสรุปผลภาษีที่ต้องชำระภายในปีนี้) และสร้างฟังก์ชันที่ระบุคนที่ต้องชำระภาษีเยอะที่สุดในบริษัทมาแสดงในผลสรุปยอดของบริษัทด้วย
    (กำหนดให้ฟังก์ชันที่สร้างขึ้น ห้ามมีการใช้คำสั่ง return แต่สามารถส่งผ่านค่าแบบ pass by reference ได้เท่านั้น)

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

void findMostTaxedEmployee(char names[][50], double taxes[], int count, char *mostTaxedName, double *mostTaxAmount) {
    int maxIndex = 0;
    for (int i = 1; i < count; i++) {
        if (taxes[i] > taxes[maxIndex]) {
            maxIndex = i;
        }
    }
    strcpy(mostTaxedName, names[maxIndex]);
    *mostTaxAmount = taxes[maxIndex];
}

int main() {
    char names[100][50];
    double salaries[100];
    double taxes[100];
    int count = 0;

    double totalSalaryPerMonth = 0, totalSalaryPerYear = 0, totalTax = 0;

    while (1) {
        char name[50];
        double salary;

        printf("Employee %d's Name : \n", count + 1);
        scanf(" %[^\n]", name);

        if (strcmp(name, "-1") == 0) {
            break;
        }

        printf("Salary (Bath/Month) : \n");
        scanf("%lf", &salary);

        strcpy(names[count], name);
        salaries[count] = salary;
        taxes[count] = salary * 12 * 0.07;
        totalSalaryPerMonth += salary;
        totalSalaryPerYear += salary * 12;
        totalTax += taxes[count];
        count++;
    }

    char mostTaxedName[50];
    double mostTaxAmount = 0;
    findMostTaxedEmployee(names, taxes, count, mostTaxedName, &mostTaxAmount);

    printf("\nAll salary per month: %.2lf Bath\n", totalSalaryPerMonth);
    printf("All salary per year: %.2lf Bath\n", totalSalaryPerYear);
    printf("Tax (7%% per year) : %.2lf Bath\n", totalTax);
    printf("Most tax in company : %s (%.2lf Bath per year)\n", mostTaxedName, mostTaxAmount);

    return 0;
}