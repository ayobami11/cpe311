// for strcpy function
#include <string.h>

#include "header.h"

void Smokin(Pitcher *person)
{

    strcpy(person->Name, "Smokin' Joe Green");
    person->ERA = 1.2;
    person->InningsPitched = 55;
    person->StrikeoutPercentage = 0.25;
}