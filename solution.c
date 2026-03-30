#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[101];
    int score;
} Student;

static int cmp_mode0(const void *a, const void *b) {
    const Student *sa = (const Student *)a;
    const Student *sb = (const Student *)b;
    return sa->id - sb->id;
}

static int cmp_mode1(const void *a, const void *b) {
    const Student *sa = (const Student *)a;
    const Student *sb = (const Student *)b;
    int cmp = strcmp(sa->name, sb->name);
    if (cmp != 0) return cmp;
    return sa->id - sb->id;
}

static int cmp_mode2(const void *a, const void *b) {
    const Student *sa = (const Student *)a;
    const Student *sb = (const Student *)b;
    if (sa->score != sb->score) return sb->score - sa->score;
    return sa->id - sb->id;
}

void Solution(void) {
    int n;
    scanf("%d", &n);

    Student students[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &students[i].id, students[i].name, &students[i].score);
    }

    int mode;
    scanf("%d", &mode);

    if (mode == 0) {
        qsort(students, n, sizeof(Student), cmp_mode0);
    } else if (mode == 1) {
        qsort(students, n, sizeof(Student), cmp_mode1);
    } else {
        qsort(students, n, sizeof(Student), cmp_mode2);
    }

    for (int i = 0; i < n; i++) {
        printf("%d %s %d\n", students[i].id, students[i].name, students[i].score);
    }
}

int main(void) {
    Solution();
    return 0;
}
