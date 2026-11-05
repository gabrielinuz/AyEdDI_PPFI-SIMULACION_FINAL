#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "company_manager.hpp"

namespace cosmetic 
{
    /**
     * @class Application
     * @brief Encapsula el ciclo de vida del programa y la interfaz de usuario interactiva (Menú).
     * 
     * Aísla por completo la entrada/salida y la lógica de inicialización para
     * dejar un archivo main.cpp completamente limpio.
     */
    class Application 
    {
    private:
        CompanyManager manager; // Instancia de nuestra lógica de negocio principal
        bool isRunning;

        // Métodos privados para cada acción del menú
        void showMenu();
        void actionAddArticle();
        void actionAddCustomer();
        void actionCreateOrder();
        void actionAddArticleToOrder();
        void actionListArticles();
        void actionListCustomers();
        void actionListOrders();
        
        /**
         * @brief Carga datos quemados (mock) para probar el sistema rápidamente.
         */
        void loadDemoData();

    public:
        Application();
        
        /**
         * @brief Método que inicia el bucle while principal del software.
         */
        void run();
    };
}

#endif // APPLICATION_HPP