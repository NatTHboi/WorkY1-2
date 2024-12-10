/*
    จงเขียนโปรแกรมเพื่อหาข้อมูลจากไฟล์เพื่อคำนวณหาเงินเดือนของสายอาชีพที่มีซ้ำกันในไฟล์ เพื่อหาว่าในสายอาชีพนั้นใครได้เงินเดือนเยอะที่สุด และระบุค่าเฉลี่ยของเงินเดือนทั้งบริษัทว่ามีเท่าไหร่

    ข้อมูลภายในไฟล์ a15-6.txt :
        Name    Age	Salary		Job
        Pong	32	45,000		Programmer
        Som		25	23,000		Support
        Aoy		24	33,250		Support
        Ying	26	34,550		Programmer
        Yot		28	50,000		Founder
        Pot		31	24,500		HR
        Vip		25	25,450		Programmer

    Output:
        Programmer: Pong(32 yrs) 45,000.00 Bath
        Support: Aoy(24 yrs) 33,250.00 Bath
        Average Salary: 33,678.57 Bath
*/

#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 100

typedef struct {
    char name[50];
    int age;
    float salary;
    char job[50];
} Person;

typedef struct {
    char job[50];
    char name[50];
    int age;
    float maxSalary;
} JobHighest;

void findHighestInJobs(Person people[], int count, JobHighest highestJobs[], int *jobCount, float *averageSalary);

int main() {
    FILE *file;
    Person people[MAX_PEOPLE];
    JobHighest highestJobs[MAX_PEOPLE];
    int count = 0, jobCount = 0;
    float averageSalary;

    file = fopen("HwF-6file.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file HwF-6file.txt\n");
        return 1;
    }

    char header[200];
    fgets(header, sizeof(header), file);

    while (fscanf(file, "%s %d %f %s", people[count].name, &people[count].age, &people[count].salary, people[count].job) == 4) {
        count++;
    }
    fclose(file);

    findHighestInJobs(people, count, highestJobs, &jobCount, &averageSalary);

    for (int i = 0; i < jobCount; i++) {
        printf("%s: %s(%d yrs) %.2f Bath\n", 
               highestJobs[i].job, 
               highestJobs[i].name, 
               highestJobs[i].age, 
               highestJobs[i].maxSalary);
    }

    printf("Average Salary: %.2f Bath\n", averageSalary);

    return 0;
}

void findHighestInJobs(Person people[], int count, JobHighest highestJobs[], int *jobCount, float *averageSalary) {
    float totalSalary = 0;
    int uniqueJobs = 0;

    for (int i = 0; i < count; i++) {
        totalSalary += people[i].salary;

        int jobIndex = -1;
        for (int j = 0; j < uniqueJobs; j++) {
            if (strcmp(highestJobs[j].job, people[i].job) == 0) {
                jobIndex = j;
                break;
            }
        }

        if (jobIndex == -1) {
            strcpy(highestJobs[uniqueJobs].job, people[i].job);
            strcpy(highestJobs[uniqueJobs].name, people[i].name);
            highestJobs[uniqueJobs].age = people[i].age;
            highestJobs[uniqueJobs].maxSalary = people[i].salary;
            uniqueJobs++;
        } else {
            if (people[i].salary > highestJobs[jobIndex].maxSalary) {
                strcpy(highestJobs[jobIndex].name, people[i].name);
                highestJobs[jobIndex].age = people[i].age;
                highestJobs[jobIndex].maxSalary = people[i].salary;
            }
        }
    }

    *jobCount = uniqueJobs;
    *averageSalary = totalSalary / count;
}