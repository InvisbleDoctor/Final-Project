#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "AllPurchases.h"

#ifndef ALLCUSTOMERS_H
#define ALLCUSTOMERS_H


void printTestMessage();


class AllCustomers {
    std::string m_firstName;
    std::string m_lastName;
    std::string m_streetAddress;
    std::string m_city;
    std::string m_state;
    std::string m_zipCode;
    std::string m_phoneNumber;
    std::vector<AllPurchases> customerPurchaseHistory;

protected:
    int m_accountNumber;

public:
    //Constructors 
    AllCustomers(); //Defualt constructor
    AllCustomers(const std::string& firstName, const std::string& lastName, const int& accountNumber, 
    const std::string& streetAddress, const std::string& city, const std::string& state, 
    const std::string& zipCode, const std::string& phoneNumber); //Parameterized constructor

    //Copy constructor
    AllCustomers(const AllCustomers& other);

    //Overloaded Assignment Operator
    AllCustomers& operator=(const AllCustomers& rhs);

    //Customer Management
    void printCustomerData() const;
    void addPurchaseToHistory(const AllPurchases& newPurchase){
        customerPurchaseHistory.push_back(newPurchase);
    }
    void printPurchaseHistory() const;
    //Getter's
    int getAccountNumber() const {return m_accountNumber;}
    std::string getFirstName() const {return m_firstName;}
    std::string getLastName() const {return m_lastName;}
    std::string getStreetAddress() const {return m_streetAddress;}
    std::string getCity() const {return m_city;}
    std::string getState() const {return m_state;}
    std::string getZipCode() const {return m_zipCode;}
    std::string getPhoneNumber() const {return m_phoneNumber;}
    std::vector<AllPurchases> getPurchaseHistory() const {return customerPurchaseHistory;}
    
    

    //Setters
    void setAccountNumber(const int accountNumberVal) {m_accountNumber = accountNumberVal;}
    void setFirstName(const std::string firstNameVal) {m_firstName = firstNameVal;}
    void setLastName(const std::string lastNameVal) {m_lastName = lastNameVal;}
    void setStreetAddress(const std::string streetAdressVal) {m_streetAddress = streetAdressVal;}
    void setCity(const std::string cityVal) {m_city = cityVal;}
    void setState(const std::string stateVal) {m_state = stateVal;}
    void setZipCode(const std::string zipCodeVal) {m_zipCode = zipCodeVal;}
    void setPhoneNumber(const std::string phoneNumberVal) {m_phoneNumber = phoneNumberVal;}
    


    
    
    
    //Destructor
    ~AllCustomers(){}


};

#endif // ALLCUSTOMERS_H