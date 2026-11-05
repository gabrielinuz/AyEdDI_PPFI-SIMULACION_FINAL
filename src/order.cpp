#include "order.hpp"
#include <iostream>
#include <iomanip>

namespace cosmetic 
{
    /**
     * En el constructor asignamos mediante `new` un bloque de 256 objetos OrderDetail.
     * Al usar objetos contiguos (no punteros), cumplimos estrictamente con 
     * las reglas de optimización de puntero simple de tamaño fijo estipuladas.
     */
    Order::Order() 
    {
        id = 0;
        customer = nullptr;
        details = new OrderDetail[MAX_DETAILS];
        detailCount = 0;
    }

    Order::~Order() 
    {
        if (details != nullptr) 
        {
            delete[] details;
            details = nullptr;
        }
        customer = nullptr; // Agregación: Cliente sobrevive a la destrucción del pedido
    }

    void Order::setup(int _id, Customer* _customer) 
    {
        id = _id;
        customer = _customer;
        detailCount = 0; // Se reinicia en caso de reciclar el objeto
    }

    bool Order::addArticle(Article* article, int quantity) 
    {
        if (article == nullptr || quantity <= 0) 
        {
            return false;
        }
        
        if (detailCount >= MAX_DETAILS) 
        {
            return false;
        }

        // Llamamos al método setup sobre el objeto ya instanciado en el arreglo.
        details[detailCount].setup(article, quantity);
        detailCount++;
        
        return true;
    }

    double Order::calculateTotal() const 
    {
        double total = 0.0;
        int i = 0;
        
        // Uso estricto de While para optimizar iteraciones
        while (i < detailCount) 
        {
            total += details[i].calculateSubtotal();
            i++;
        }
        
        return total;
    }

    int Order::getId() const 
    { 
        return id; 
    }

    void Order::displayOrder() const 
    {
        std::cout << "\n====================================================================\n";
        std::cout << " PEDIDO NRO: #" << id << "\n";
        std::cout << "--------------------------------------------------------------------\n";
        std::cout << " CLIENTE ASIGNADO:\n";
        
        if (customer != nullptr) 
        {
            std::cout << "   Nombre: " << customer->getFullName() 
                      << " | DNI: " << customer->getDni() 
                      << " | Tel: " << customer->getPhone() << "\n";
        } 
        else 
        {
            std::cout << "   [Sin cliente asignado]\n";
        }
        
        std::cout << "--------------------------------------------------------------------\n";
        std::cout << " ARTICULOS SOLICITADOS:\n";
        
        if (detailCount == 0) 
        {
            std::cout << "    (Sin articulos cargados)\n";
        } 
        else 
        {
            int i = 0;
            // Recorrido obligatorio en formato While
            while (i < detailCount) 
            {
                details[i].displayDetail();
                i++;
            }
        }
        
        std::cout << "--------------------------------------------------------------------\n";
        std::cout << " TOTAL FACTURADO: $" << std::fixed << std::setprecision(2) << calculateTotal() << "\n";
        std::cout << "====================================================================\n";
    }
}