Delivery Management System
Overview
The Delivery Management System is designed to manage and streamline the logistics of product deliveries. It handles information about manufacturers, products, customers, delivery personnel, and delivery companies, ensuring efficient assignment and tracking of deliveries.

Features
Classes and Responsibilities:
Product

Attributes: Manufacturer, TypeProduct, name
Methods: initProduct, printProduct
Person

Attributes: name
Methods: initPerson, printPerson
DeliveryPerson (inherits from Person)

Attributes: DeliveryCompany, rating, numOfDeliveries, averageRating
Methods: initDeliveryPerson, printDeliveryPerson, changeRating, calculateAverageRating
Customer (inherits from Person)

Attributes: Address
Methods: initCustomer, printCustomer
DeliveryCompany

Attributes: DeliveryPerson, baseRegion
Methods: findDeliveryPerson, addDeliveryPerson, removeDeliveryPerson, compareDeliveryPersonsByRating, assignDeliveryPersonToDelivery, initCompany, printCompany
Manufacturer

Attributes: name, id
Methods: initManufacturer, printManufacturer
Storage

Attributes: Product, Delivery, DeliveryCompany
Methods: initStorage, addDeliveryToStorage, compareDeliveryCompaniesByRegion, addDeliveryCompanyToStorage, removeDeliveryCompanyFromStorage, addProductToStorage, removeProductFromStorage, assignDeliveryCompany, printStorage
Delivery

Attributes: Customer, Product, DeliveryDate, DeliveryCompany, isDelivered
Methods: initDelivery, changeDeliveryDate, changeProduct, addProduct, removeProduct, returnRatingWhenDelivered, printDelivery
Date

Attributes: day, month, year
Methods: initDate, printDate
Address

Attributes: region, city, streetName, homeNumber
Methods: initAddress, printAddress
How to Use
Setup:

Clone or download the project repository.
Ensure you have the necessary environment to run the code (e.g., Python, Java, or any other specified language).
Initialize Classes:

Use the init methods of the classes to initialize their respective objects.
Manage Deliveries:

Add products, assign delivery companies, and track deliveries using the methods provided in Storage and DeliveryCompany.
Print Data:

Use the print methods in each class to display details about entities such as products, deliveries, and personnel.

Future Improvements
Add a graphical user interface (GUI) or web-based frontend for easier interaction.
Implement real-time tracking of deliveries.
Integrate analytics to evaluate company performance and customer satisfaction.

Author
Arina Kuprina
Shay Gelbart 



