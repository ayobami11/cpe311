#ifndef _HEADER_H_
#define _HEADER_H_

struct Pitcher
{
    char Name[40];
    // ERA === earned runs average
    float ERA;
    int InningsPitched;
    float StrikeoutPercentage;
};

void Smokin(Pitcher *);

#endif