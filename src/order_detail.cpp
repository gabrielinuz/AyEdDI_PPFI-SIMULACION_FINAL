#include "order_detail.hpp"
#include <iostream>
#include <iomanip>

namespace cosmetic 
{
    OrderDetail::OrderDetail() 
    {
        article = nullptr;
        quantity = 0;
    }

    void OrderDetail::setup(Article* _article, int _quantity) 
    {
        article = _article;
        quantity = _quantity;
    }

    double OrderDetail::calculateSubtotal() const 
    {
        if (article != nullptr) 
        {
            return article->getUnitPrice() * quantity;
        }
        return 0.0;
    }

    void OrderDetail::displayDetail() const 
    {
        if (article != nullptr) 
        {
            std::cout << "    - " << std::left << std::setw(25) << article->getName()
                      << " Cant: " << std::setw(3) << quantity
                      << " ($" << std::fixed << std::setprecision(2) << article->getUnitPrice() << " c/u)"
                      << " -> Subtotal: $" << calculateSubtotal() << "\n";
        }
    }

    Article* OrderDetail::getArticle() const 
    { 
        return article; 
    }
    
    int OrderDetail::getQuantity() const 
    { 
        return quantity; 
    }
}