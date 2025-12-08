#ifndef ManageAllCustomers_h
#define ManageAllCustomers_h

#include "AllCustomers.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm> 
#include <cctype>


class ManageAllCustomers
{
    std::vector<AllCustomers> defaultCustomerDataBase;
public:
    bool loadCustomerDataFromFile(const std::string& filename);
    bool loadCustomerPurchaseDataFromFile(const std::string& filename);
    void displayAllCustomerData();
    void displaySortedCustomerData(); //sort by name 
    void displayTotalCustomerSpendAmt();
    void insertNewCustomer(); //Add Multiple Customers give option recursive 

    void updateCustomerInformation();
    void deleteCustomer();

    void addNewCustomerPurchase(); //ADD more than one purchase give recursive option
    void exportCustomerData(); //Give option to write over existing file or export to new file
    



};



#endif