#pragma once
#ifndef __DELIVERY_COMPANY__
#define __DELIVERY_COMPANY__

#include "DeliveryPerson.h"
#include "Delivery.h"
typedef struct
{
	char* name;
	DeliveryPerson** delPerArray;
	int deliveryPersonCount;
	eRegionType region;
}DeliveryCompany;

void			initDeliveryCompany(DeliveryCompany* delComp);
DeliveryPerson* findDeliveryPerson(DeliveryCompany* delComp);
int				addDeliveryPerson(DeliveryCompany* delComp);
int				removeDeliveryPerson(DeliveryCompany* deComp, DeliveryPerson* pDelPer);
int				compareTwoDeliveryPerson(DeliveryPerson* p1, DeliveryPerson p2);
void			assignDeliveryPersonToDelivery(DeliveryCompany pDelPer, Delivery* pDel);
void			printDeliveryCompany(DeliveryCompany* delComp);

#endif