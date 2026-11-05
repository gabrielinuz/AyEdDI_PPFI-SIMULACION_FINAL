#include "article.hpp"
#include <iostream>
#include <iomanip>

namespace cosmetic 
{
    Article::Article() 
    {
        id = 0;
        name = "";
        category = "";
        unitPrice = 0.0;
    }

    void Article::setup(int _id, const std::string& _name, const std::string& _category, double _price) 
    {
        id = _id;
        name = _name;
        category = _category;
        unitPrice = _price;
    }

    int Article::getId() const 
    { 
        return id; 
    }
    
    std::string Article::getName() const 
    { 
        return name; 
    }
    
    std::string Article::getCategory() const 
    { 
        return category; 
    }
    
    double Article::getUnitPrice() const 
    { 
        return unitPrice; 
    }

    void Article::displayInfo() const 
    {
        std::cout << "  [ID " << std::setw(3) << id << "] " 
                  << std::left << std::setw(26) << name 
                  << " (" << std::setw(15) << category << ") - $" 
                  << std::fixed << std::setprecision(2) << unitPrice << "\n";
    }
}