/*
    จงหาอายุเฉลี่ยจากข้อมูลของผู้ที่มีรายชื่ออยู่ในไฟล์ พร้อมระบุชื่อของผู้ที่มีอายุมากกว่าค่าเฉลี่ยทุกคน นับจากอายุมากไปยังอายุน้อย พร้อมกับแสดงอายุและเงินเดือนของเขาดังข้อมูลด้านล่างนี้

    ข้อมูลภายในไฟล์ a15-5.txt :
        Name	Age	Salary		Job
        Pong	32	45,000		Programmer
        Som		25	23,000		Support
        Aoy		24	33,250		Advisor
        Ying	26	34,550		Programmer
        Yot		28	50,000		Founder
        Pot		31	24,500		HR
        Vip		25	25,450		Programmer
    Output:
        Average : 27.29 Years
        Pong(32) : 45,000 Bath
        Pot(31) : 24,500 Bath
        Yot(28) : 50,000 Bath
*/

#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 100

typedef struct {
    char name[50];
    int age;
    int salary;
    char job[50];
} Person;

void sortPeopleByAge(Person people[], int count);

int main() {
    FILE *file;
    Person people[MAX_PEOPLE];
    int count = 0, totalAge = 0;
    float averageAge;

    file = fopen("HwF-5file.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file HwF-5file.txt\n");
        return 1;
    }

    char header[200];
    fgets(header, sizeof(header), file);

    while (fscanf(file, "%s %d %d %s", people[count].name, &people[count].age, &people[count].salary, people[count].job) == 4) {
        totalAge += people[count].age;
        count++;
    }
    fclose(file);

    averageAge = (float)totalAge / count;

    printf("Average : %.2f Years\n", averageAge);

    sortPeopleByAge(people, count);

    for (int i = 0; i < count; i++) {
        if (people[i].age > averageAge) {
            printf("%s(%d) : %d Bath\n", people[i].name, people[i].age, people[i].salary);
        }
    }

    return 0;
}

void sortPeopleByAge(Person people[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (people[j].age < people[j + 1].age) {
                Person temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}