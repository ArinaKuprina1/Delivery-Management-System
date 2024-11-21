#ifndef PRODUCT
#define PRODUCT

#include "Manufacturer.h"

typedef enum {
	eToys, eBooks , eElectronics, eSports, eFurniture, eClothing, eBeauty, eNofProductTypes
} eProductType;

static const char* productTypeStr[eNofProductTypes]
= { "Toys", "Books", "Electronics", "Sports", "Furniture" , "Clothing", "Beauty"};


typedef struct
{
	Manufacturer* manufacturer;
	eProductType productType;
	char* nameOfProduct;
}Product;

void initProduct(Product* pProduct, Storage* pStorage); // Corrected function signature with Storage parameter
eProductType getTypeProduct();
void printProduct(Product* pProduct);
int compareProducts(Product* p1, Product* p2);

#endif
