#include <iostream>
#include "ManageAllCustomers.h"

//Helper Function
int readMenuChoice(){
    while(true)
    {
        std::string line;
        std::getline(std::cin, line);

        try
        {
            //trys to convert player input into int
            int choice = std::stoi(line);
            return choice;
        } 
        catch(...) //Catch any type of exception 
        {
             std::cout << "Please enter a number. \n";
        }
    }
}


//Display All Customer Data




int main(){
    
    ManageAllCustomers customerManager; //Create ManageAllCustomers Object
    bool customerDataLoaded = customerManager.loadCustomerDataFromFile("customerAccountData.csv");
    bool purchaseDataLoaded = customerManager.loadCustomerPurchaseDataFromFile("customerPurchases.csv");

    if (!customerDataLoaded && !purchaseDataLoaded) //If default files do not load correctly give user option to enter file paths
    {
        std::cout << "Could Not load default customer or purchase data files." << std::endl;
        std::cout << "Enter customer data file path? (leave blank to close program): ";
        std::string customerDataFilePath; std::getline(std::cin, customerDataFilePath);
        if (customerDataFilePath.empty()){
            return 0; //Exit program if no file path provided
        }
        std::cout << "Enter purchase data file path? (leave blank to close program): ";
        std::string purchaseDataFilePath; std::getline(std::cin, purchaseDataFilePath);
        if (purchaseDataFilePath.empty()){
            return 0; //Exit program if no file path provided
        }
        customerDataLoaded = customerManager.loadCustomerDataFromFile(customerDataFilePath);
        purchaseDataLoaded = customerManager.loadCustomerPurchaseDataFromFile(purchaseDataFilePath);
    }
    
    int choice;
    while(true)
    {
        std::cout << "\n--- Customer Management Menu ---\n"
                  << "1. Display All Customer Data\n"
                  << "2. Display Sorted Customer Data\n"
                  << "3. Display Total Customer Spend Amount\n"
                  << "4. Insert New Customer\n"
                  << "5. Update Customer Information\n"
                  << "6. Delete Customer\n"
                  << "7. Add New Customer Purchase\n"
                  << "8. Export Customer Data\n"
                  << "9. Display Specific Customer Purchase History\n"
                  << "0. Exit\n"
                  << "Enter your choice: ";
        choice = readMenuChoice();

        switch(choice)
        {
            case 1:
                customerManager.displayAllCustomerData();
                break;
            case 2:
                customerManager.displaySortedCustomerData();
                break;
            case 3:
                customerManager.displayTotalCustomerSpendAmt();
                break;
            case 4:
                customerManager.insertNewCustomer();
                break;
            case 5:
                customerManager.updateCustomerInformation();
                break;
            case 6:
                customerManager.deleteCustomer();
                break;
            case 7:
                customerManager.addNewCustomerPurchase();
                break;
            case 8:
                customerManager.exportCustomerData();
                break;
            case 0:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }




}