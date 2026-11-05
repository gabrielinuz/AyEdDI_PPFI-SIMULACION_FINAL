#include "company_manager.hpp"
#include <iostream>

namespace cosmetic 
{
    /**
     * Construye las entidades en el Heap.
     * Para evitar un desbordamiento de pila (Stack Overflow) provocado al usar arreglos grandes,
     * se inyectan en el heap como arreglos contiguos limitados a 256 elementos vía `new Tipo[MAX_ITEMS]`.
     */
    CompanyManager::CompanyManager() 
    {
        articleCount = 0;
        customerCount = 0;
        orderCount = 0;

        articles = new Article[MAX_ITEMS];
        customers = new Customer[MAX_ITEMS];
        orders = new Order[MAX_ITEMS];
    }

    CompanyManager::~CompanyManager() 
    {
        // Liberación simple de los arreglos contiguos.
        delete[] articles;
        delete[] customers;
        delete[] orders;
    }

    bool CompanyManager::loadArticle(int id, const std::string& name, const std::string& category, double price) 
    {
        if (articleCount >= MAX_ITEMS) 
        {
            return false;
        }
        
        articles[articleCount].setup(id, name, category, price);
        articleCount++;
        
        return true;
    }

    bool CompanyManager::loadCustomer(int id, const std::string& name, const std::string& dni, const std::string& phone) 
    {
        if (customerCount >= MAX_ITEMS) 
        {
            return false;
        }
        
        customers[customerCount].setup(id, name, dni, phone);
        customerCount++;
        
        return true;
    }

    Order* CompanyManager::createOrder(int orderId, int customerId) 
    {
        if (orderCount >= MAX_ITEMS) 
        {
            return nullptr;
        }

        Customer* cli = findCustomerById(customerId);
        if (cli == nullptr) 
        {
            return nullptr;
        }

        orders[orderCount].setup(orderId, cli);
        Order* newOrderPtr = &orders[orderCount]; // Retorna puntero simple del bloque
        orderCount++;
        
        return newOrderPtr;
    }

    Article* CompanyManager::findArticleById(int id) const 
    {
        int i = 0;
        while (i < articleCount) 
        {
            if (articles[i].getId() == id) 
            {
                return &articles[i];
            }
            i++;
        }
        return nullptr;
    }

    Customer* CompanyManager::findCustomerById(int id) const 
    {
        int i = 0;
        while (i < customerCount) 
        {
            if (customers[i].getId() == id) 
            {
                return &customers[i];
            }
            i++;
        }
        return nullptr;
    }

    Order* CompanyManager::findOrderById(int id) const 
    {
        int i = 0;
        while (i < orderCount) 
        {
            if (orders[i].getId() == id) 
            {
                return &orders[i];
            }
            i++;
        }
        return nullptr;
    }

    void CompanyManager::listArticles() const 
    {
        std::cout << "\n------------------ CATALOGO DE ARTICULOS ------------------\n";
        int i = 0;
        while (i < articleCount) 
        {
            articles[i].displayInfo();
            i++;
        }
    }

    void CompanyManager::listCustomers() const 
    {
        std::cout << "\n------------------- CLIENTES REGISTRADOS ------------------\n";
        int i = 0;
        while (i < customerCount) 
        {
            customers[i].displayInfo();
            i++;
        }
    }

    void CompanyManager::showAllOrders() const 
    {
        std::cout << "\n====================================================================\n";
        std::cout << "       REPORTE OFICIAL DE PEDIDOS DE CLIENTES (CONSOLA)             \n";
        std::cout << "====================================================================\n";
        
        if (orderCount == 0) 
        {
            std::cout << " No existen pedidos registrados.\n";
            return;
        }
        
        int i = 0;
        while (i < orderCount) 
        {
            orders[i].displayOrder();
            i++;
        }
    }
}