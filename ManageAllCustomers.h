#ifndef ManageAllCustomers_h
#define ManageAllCustomers_h

#include "AllCustomers.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm> 
#include <cctype>



//Helper Functions
    inline bool isValidName(const std::string input){
        if(input.empty()) return false;
        for(char c : input){
            if(!std::isalpha(c) && c != ' ' && c != '-') return false; //Allows letters, spaces, and hyphens rejects numbers
        }
        return true;
    }

    inline bool isValidPhoneNumber(const std::string& input){
        if(input.length() != 10) return false; //Must be exactly 10 digits
        for(char c : input){
            if(!std::isdigit(c)) return false; //Must be all digits
        }
        return true;
    }

    inline bool isValidZipCode(const std::string& input){
        if(input.length() != 5) return false; //Must be exactly 5 digits
        for(char c : input){
            if(!std::isdigit(c)) return false; //Must be all digits
        }
        return true;
    }

    inline bool isValidState(const std::string& input){
        if(input.empty()) return false;
        if(input.length() != 2) return false; //State must be 2 letter abbreviation
        for(char c : input){
            if(!std::isalpha(c)) return false; //Only allows letters
        }
        return true;
    }

    inline int readMenuChoice(){
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


class ManageAllCustomers
{
    std::vector<AllCustomers> defaultCustomerDataBase;
public:
    bool loadCustomerDataFromFile(const std::string& filename);
    bool loadCustomerPurchaseDataFromFile(const std::string& filename);
    void displayAllCustomerData();
    void displayAllCustomerData(const std::vector<AllCustomers>& customers); //Overloaded to display passed in vector
    void displaySortedCustomerData(); //sort by name 
    void displayTotalCustomerSpendAmt();
    void insertNewCustomer(); //Add Multiple Customers give option recursive 

    void updateCustomerInformation();
    void deleteCustomer();

    void addNewCustomerPurchase(); //ADD more than one purchase give recursive option
    void exportCustomerData(); //Give option to write over existing file or export to new file
    
    void displaySpecificCustomerAccountAndPurchaseHistory();
    int customerManageMenuApp();
    

};

#endif // ManageAllCustomers_h   //Main Menu Application Loop