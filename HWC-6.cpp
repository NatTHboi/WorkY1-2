/*
    ผู้ใช้กรอกชื่อและความสูงของคนในโรงเรียนในห้อง A และห้อง B และเรียงลำดับของคนที่ตัวเล็กที่สุดไปยังตัวใหญ่ที่สุดในแต่ละห้อง และเรียงลำดับของคนทั้งโรงเรียนจากตัวที่ใหญ่ที่สุดมายังตัวเล็กที่สุด

    Test case:
        Room A
        Name : 
            John
        Height (cm) : 
            176.6
        Name : 
            Job
        Height (cm) : 
            177.5
        Name : 
            Aim
        Height (cm) : 
            149.8
        Name : 
            Mon
        Height (cm) : 
            158.9
        Name : 
            Ammy
        Height (cm) : 
            151.0
        Name : 
            A
        Height (cm) : 
            169.7
        Name : 
            -1

        Room B
        Name : 
            Komsam
        Height (cm) : 
            176.1
        Name : 
            Samart
        Height (cm) : 
            165.4
        Name : 
            Sunu
        Height (cm) : 
            168.1
        Name : 
            -1

    Output:
        Room A -> Aim Ammy Mon A John Job
        Room B -> Samart Sunu Komsam
        School -> Job John Komsam A Sunu Samart Mon Ammy Aim
*/

#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 100

struct Person {
    char name[50];
    float height;
};

void sortAscending(Person people[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (people[j].height > people[j + 1].height) {
                Person temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}

void sortDescending(Person people[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (people[j].height < people[j + 1].height) {
                Person temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}

void printRoom(const char* roomName, Person people[], int count) {
    printf("%s ->", roomName);
    for (int i = 0; i < count; i++) {
        printf(" %s", people[i].name);
    }
    printf("\n");
}

int main() {
    Person roomA[MAX_PEOPLE], roomB[MAX_PEOPLE], school[MAX_PEOPLE * 2];
    int countA = 0, countB = 0, totalSchool = 0;

    printf("Room A\n");
    while (1) {
        char name[50];
        float height;

        printf("Name : \n");
        scanf("%s", name);
        if (strcmp(name, "-1") == 0) break;

        printf("Height (cm) : \n");
        scanf("%f", &height);

        strcpy(roomA[countA].name, name);
        roomA[countA].height = height;
        countA++;
    }

    printf("Room B\n");
    while (1) {
        char name[50];
        float height;

        printf("Name : \n");
        scanf("%s", name);
        if (strcmp(name, "-1") == 0) break;

        printf("Height (cm) : \n");
        scanf("%f", &height);

        strcpy(roomB[countB].name, name);
        roomB[countB].height = height;
        countB++;
    }

    sortAscending(roomA, countA);
    sortAscending(roomB, countB);

    for (int i = 0; i < countA; i++) {
        school[totalSchool++] = roomA[i];
    }
    for (int i = 0; i < countB; i++) {
        school[totalSchool++] = roomB[i];
    }

    sortDescending(school, totalSchool);

    printRoom("Room A", roomA, countA);
    printRoom("Room B", roomB, countB);

    printf("School ->");
    for (int i = 0; i < totalSchool; i++) {
        printf(" %s", school[i].name);
    }
    printf("\n");

    return 0;
}
