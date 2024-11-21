#include <stdio.h>
#include <string.h>
#include "Product.h"
#include "Storage.h"
#include "General.h"

void initProduct(Product* pProduct , Storage* pStorage)
{
	pProduct->productType = getTypeProduct();
	//printManufacturerByType(pStorage , pProduct->productType);
	int isExist;
	printf("Does your manufacturer exist in the list above?\n");
	printf("Yes - enter 1\nNo - enter 0\n");
	scanf("%d", &isExist);
	if (isExist)
	{
		//printManufacturerByType(pStorage , pProduct->productType);
		printf("Pick a manufacturer\n");
		int manIndex;
		scanf("%d", &manIndex);
	//	pProduct->manufacturer = pStorage->manArray[manIndex - 1];
	}
	//else
	//	initManufacturer(pProduct->manufacturer , pStorage);

	pProduct->nameOfProduct = getStrExactName("Enter the name of your product");
}

eProductType getTypeProduct()
{
	int option;
	printf("\n\n");
	do {
		printf("Please enter one of the following types\n");
		for (int i = 0; i < eNofProductTypes; i++)
			printf("%d for %s\n", i, productTypeStr[i]);
		scanf("%d", &option);
	} while (option < 0 || option >= eNofProductTypes);
	getchar();
	return (eProductType)option;
}

void printProduct(Product* pProduct)
{
	printf("Name of product: %s\nType of product: %s\tManufacturer: %s\t", pProduct->nameOfProduct, productTypeStr[pProduct->productType], pProduct->manufacturer->name);
}

int compareProducts(Product* p1, Product* p2)
{
	
	return strcmp(p1->nameOfProduct,p2->nameOfProduct);
}
