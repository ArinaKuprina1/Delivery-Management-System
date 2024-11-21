#pragma once
#ifndef __CUSTOMER__
#define __CUSTOMER__


#include "Person.h"
#include "Address.h"
#include "Delivery.h"


typedef struct
{
	Person person;
	Address address;
	Delivery* deliveries;
	int numberOfDeliveries;
	int credits;

	
}Customer;


void		initCustomer(Customer* pCustomer);
void		printCustomer(Customer* pCustomer);
void		addDelivery(Delivery* pDelivery, Customer* pCustomer);
void		changeCredits(Customer* pCustomer, int changeNumber);
void		printAllDeliveriesForCustomer(Customer* pCustomer);
int			changeAddress(Customer* pCustomer, Address* pAddress);

//Person* newCustomer(char* pName, Delivery* pDeliveries, Address* address, int credits, int numberOfDeliveries);

#endif