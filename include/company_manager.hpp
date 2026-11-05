#ifndef COMPANY_MANAGER_HPP
#define COMPANY_MANAGER_HPP

#include "article.hpp"
#include "customer.hpp"
#include "order.hpp"

namespace cosmetic 
{
    const int MAX_ITEMS = 256;

    /**
     * @class CompanyManager
     * @brief Controlador principal del sistema. 
     * 
     * Gestiona la memoria del sistema utilizando arreglos de tamaño fijo de 256 ítems
     * reservados dinámicamente en el Heap con un puntero simple, eludiendo la STL.
     */
    class CompanyManager 
    {
    private:
        Article* articles;    // Puntero simple a arreglo de objetos Article
        int articleCount;

        Customer* customers;  // Puntero simple a arreglo de objetos Customer
        int customerCount;

        Order* orders;        // Puntero simple a arreglo de objetos Order
        int orderCount;

    public:
        /**
         * @brief Constructor. Instancia los tres bloques de 256 elementos en el Heap.
         */
        CompanyManager();

        /**
         * @brief Destructor. Destruye los bloques contiguos limpiando la RAM (delete[]).
         */
        ~CompanyManager();

        bool loadArticle(int id, const std::string& name, const std::string& category, double price);
        bool loadCustomer(int id, const std::string& name, const std::string& dni, const std::string& phone);
        Order* createOrder(int orderId, int customerId);

        Article* findArticleById(int id) const;
        Customer* findCustomerById(int id) const;
        Order* findOrderById(int id) const;

        void listArticles() const;
        void listCustomers() const;
        void showAllOrders() const;
    };
}

#endif // COMPANY_MANAGER_HPP