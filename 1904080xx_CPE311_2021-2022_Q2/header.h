#ifndef QUESTION_2_H
#define QUESTION_2_H

struct Student
{
    char Name[40];
    int Score1;
    int Score2;
    int Score3;
    int Score4;
    float AvgScore;
};

void ReadStudentInfo(Student[3]);
void CalcAverage(Student[3]);
void WriteAvgScore(Student[3]);

#endif