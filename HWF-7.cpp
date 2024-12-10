/*
    จงเขียนโปรแกรมเพื่ออ่านข้อมูลชื่อและวันเดือนปีเกิด (ค.ศ.) และให้แสดงข้อมูลอายุของแต่ละคน พร้อมระบุคนที่อายุมากที่สุด และน้อยที่สุด (คิดอายุหากวันนี้คือวันที่ 21 มิถุนายน พ.ศ. 2561)

    ข้อมูลภายในไฟล์ a15-7.txt :
        No	Name	Birthday
        1	Aoy		1989-06-11
        2	Boy		1998-11-12
        3	Joy		2002-03-15
        4	Toy		1987-05-15
        5	Moy		1923-12-06
        6	Yoy		1994-06-05
        7	Roy		1978-04-09
        8	Woy		1989-03-14
        9	Doy		1989-01-27

    Output:
        Aoy 29 Years, 0 Months
        Boy 19 Years, 7 Months
        Joy 16 Years, 3 Months
        Toy 31 Years, 1 Months
        Moy 94 Years, 6 Months
        Yoy 24 Years, 0 Months
        Roy 40 Years, 2 Months
        Woy 29 Years, 3 Months
        Doy 29 Years, 4 Months

        Max : Moy (94 Years, 6 Months)
        Min : Joy (16 Years, 3 Months)
*/

#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 100

typedef struct {
    char name[50];
    int year, month, day;
    int ageYears, ageMonths;
} Person;

void calculateAge(Person *person, int currentYear, int currentMonth, int currentDay);
void findMaxMin(Person people[], int count, int *maxIndex, int *minIndex);

int main() {
    FILE *file;
    Person people[MAX_PEOPLE];
    int count = 0;

    int currentYear = 2018;
    int currentMonth = 6, currentDay = 21;

    file = fopen("HwF-7file.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file HwF-7file.txt\n");
        return 1;
    }

    char header[200];
    fgets(header, sizeof(header), file);

    while (fscanf(file, "%*d %s %d-%d-%d", people[count].name, &people[count].year, &people[count].month, &people[count].day) == 4) {
        calculateAge(&people[count], currentYear, currentMonth, currentDay);
        count++;
    }
    fclose(file);

    int maxIndex, minIndex;
    findMaxMin(people, count, &maxIndex, &minIndex);

    for (int i = 0; i < count; i++) {
        printf("%s %d Years, %d Months\n", people[i].name, people[i].ageYears, people[i].ageMonths);
    }

    printf("\nMax : %s (%d Years, %d Months)\n", 
           people[maxIndex].name, people[maxIndex].ageYears, people[maxIndex].ageMonths);
    printf("Min : %s (%d Years, %d Months)\n", 
           people[minIndex].name, people[minIndex].ageYears, people[minIndex].ageMonths);

    return 0;
}

void calculateAge(Person *person, int currentYear, int currentMonth, int currentDay) {
    person->ageYears = currentYear - person->year;
    person->ageMonths = currentMonth - person->month;

    if (currentDay < person->day) {
        person->ageMonths--;
    }
    if (person->ageMonths < 0) {
        person->ageYears--;
        person->ageMonths += 12;
    }
}

void findMaxMin(Person people[], int count, int *maxIndex, int *minIndex) {
    *maxIndex = *minIndex = 0;

    for (int i = 1; i < count; i++) {
        if (people[i].ageYears > people[*maxIndex].ageYears || 
            (people[i].ageYears == people[*maxIndex].ageYears && people[i].ageMonths > people[*maxIndex].ageMonths)) {
            *maxIndex = i;
        }
        if (people[i].ageYears < people[*minIndex].ageYears || 
            (people[i].ageYears == people[*minIndex].ageYears && people[i].ageMonths < people[*minIndex].ageMonths)) {
            *minIndex = i;
        }
    }
}