#include <stdio.h>
#include "Customer.h"

//Person* newCustomer(char* pName, Delivery* pDeliveries, Address* address, int credits, int numberOfDeliveries)
//{
//    Customer* pCustomer;
//    Person* pPerson;
//    pCustomer = newPerson(pName);
//    return nullptr;
//}

void initCustomer(Customer* pCustomer)
{
	initPerson(&pCustomer->person);
	initAddress(&pCustomer->address);
	pCustomer->deliveries = NULL;
	pCustomer->numberOfDeliveries = 0;
	
	int tempCredits;
	do
	{
		printf("Enter how many credits you want to deposit\n");
		scanf("%d", &tempCredits)
	} while (tempCredits <= 0);

	pCustomer->credits = tempCredits;
}

void printCustomer(Customer* pCustomer)
{
	printPerson(&pCustomer->person);
	printAddress(&pCustomer->address);
	printAllDeliveriesForCustomer(pCustomer);
	printf("Number Of Deliveries: %d\n", pCustomer->numberOfDeliveries);
	printf("Credits Available: %d\n", pCustomer->credits);
}

void addDelivery(Delivery* pDelivery, Customer* pCustomer)
{
	
}

void changeCredits(Customer* pCustomer, int changeNumber)
{
	pCustomer->credits += changeNumber;
	
}

void printAllDeliveriesForCustomer(Customer* pCustomer)
{
	for (int i = 0; i < pCustomer->numberOfDeliveries; i++)
	{
		printDelivery(&pCustomer->deliveries[i]);
	}
}

int changeAddress(Customer* pCustomer, Address* pAddress)
{
	pCustomer->address = *pAddress;
}
