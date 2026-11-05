#include "customer.hpp"
#include <iostream>
#include <iomanip>

namespace cosmetic 
{
    Customer::Customer() 
    {
        id = 0;
        fullName = "";
        dni = "";
        phone = "";
    }

    void Customer::setup(int _id, const std::string& _name, const std::string& _dni, const std::string& _phone) 
    {
        id = _id;
        fullName = _name;
        dni = _dni;
        phone = _phone;
    }

    int Customer::getId() const 
    { 
        return id; 
    }
    
    std::string Customer::getFullName() const 
    { 
        return fullName; 
    }
    
    std::string Customer::getDni() const 
    { 
        return dni; 
    }
    
    std::string Customer::getPhone() const 
    { 
        return phone; 
    }

    void Customer::displayInfo() const 
    {
        std::cout << "  [Cliente #" << id << "] " 
                  << std::left << std::setw(20) << fullName 
                  << " | DNI: " << std::setw(10) << dni 
                  << " | Tel: " << phone << "\n";
    }
}