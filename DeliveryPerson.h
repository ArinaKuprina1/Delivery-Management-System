#pragma once
#ifndef __DELIVERY_PERSON__
#define __DELIVERY_PERSON__

#include "Person.h"
//#include "DeliveryCompany.h"

#define UPPER_BORDER 72
#define LOWER_BORDER 12

typedef struct
{
	Person* person;
	//DeliveryCompany* pDeliveryComp;
	int* ratingArr;
	int numOfDeliveries;
	int averageRating;
	int deliveryTime;
}DeliveryPerson;

void initDeliveryPerson(DeliveryPerson* pDelPer);
int changeRating(DeliveryPerson* pDelPer, int Rating); // add rating to the array
int addRatingToArray(DeliveryPerson* pDelPer, int Rating);
int calcAverageRating(DeliveryPerson* pDelPer);
void printDeliveryPerson(DeliveryPerson* pDelPer);

#endif // !__DELIVERY_PERSON__
