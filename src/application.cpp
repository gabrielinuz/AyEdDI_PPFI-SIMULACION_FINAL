#include "application.hpp"
#include <iostream>
#include <limits> // Para el clear() de flujos

namespace cosmetic 
{
    Application::Application() 
    {
        isRunning = true;
        loadDemoData(); // Se auto-carga como en el programa original
    }

    void Application::loadDemoData() 
    {
        manager.loadArticle(101, "Lapiz Labial Matte Ruby", "Labios", 4500.00);
        manager.loadArticle(102, "Serum Facial Vitamina C", "Cuidado Facial", 12800.50);
        manager.loadArticle(103, "Mascara Volumen Pestanas", "Ojos", 7400.00);

        manager.loadCustomer(1, "Mariana Gomez", "34567890", "223-5123456");
        manager.loadCustomer(2, "Laura Benitez", "29876543", "223-4987654");

        Order* p1 = manager.createOrder(1001, 1);
        if (p1 != nullptr) 
        {
            p1->addArticle(manager.findArticleById(101), 2);
            p1->addArticle(manager.findArticleById(102), 1);
        }

        Order* p2 = manager.createOrder(1002, 2);
        if (p2 != nullptr) 
        {
            p2->addArticle(manager.findArticleById(103), 1);
        }
    }

    void Application::run() 
    {
        // Se respeta el requerimiento de usar while para los bucles
        while (isRunning) 
        {
            showMenu();
        }
    }

    void Application::showMenu() 
    {
        std::cout << "\n====================================================================\n";
        std::cout << "  SISTEMA DE GESTION DE PEDIDOS DE COSMETICOS\n";
        std::cout << "====================================================================\n";
        std::cout << " 1. Registrar Articulo\n";
        std::cout << " 2. Registrar Cliente\n";
        std::cout << " 3. Crear Pedido\n";
        std::cout << " 4. Agregar Articulo a Pedido\n";
        std::cout << " 5. Listar Articulos\n";
        std::cout << " 6. Listar Clientes\n";
        std::cout << " 7. Reporte Completo de Pedidos\n";
        std::cout << " 0. Salir\n";
        std::cout << "--------------------------------------------------------------------\n";
        std::cout << " Ingrese opcion: ";

        int opcion;
        std::cin >> opcion;

        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = -1;
        }

        switch (opcion) 
        {
            case 1: actionAddArticle(); break;
            case 2: actionAddCustomer(); break;
            case 3: actionCreateOrder(); break;
            case 4: actionAddArticleToOrder(); break;
            case 5: actionListArticles(); break;
            case 6: actionListCustomers(); break;
            case 7: actionListOrders(); break;
            case 0: isRunning = false; break;
            default: std::cout << " [!] Opcion invalida.\n"; break;
        }
    }

    void Application::actionAddArticle() 
    {
        int id;
        std::string name, cat;
        double price;

        std::cout << "\n-- NUEVO ARTICULO --\nID: ";
        std::cin >> id;
        std::cin.ignore();
        
        std::cout << "Nombre: ";
        std::getline(std::cin, name);
        
        std::cout << "Categoria: ";
        std::getline(std::cin, cat);
        
        std::cout << "Precio Unitario: $";
        std::cin >> price;

        if (manager.loadArticle(id, name, cat, price)) 
        {
            std::cout << " [+] Articulo registrado correctamente.\n";
        } 
        else 
        {
            std::cout << " [-] Error: Capacidad maxima (256) alcanzada.\n";
        }
    }

    void Application::actionAddCustomer() 
    {
        int id;
        std::string name, dni, phone;

        std::cout << "\n-- NUEVO CLIENTE --\nID: ";
        std::cin >> id;
        std::cin.ignore();
        
        std::cout << "Nombre Completo: ";
        std::getline(std::cin, name);
        
        std::cout << "DNI: ";
        std::getline(std::cin, dni);
        
        std::cout << "Telefono: ";
        std::getline(std::cin, phone);

        if (manager.loadCustomer(id, name, dni, phone)) 
        {
            std::cout << " [+] Cliente registrado correctamente.\n";
        } 
        else 
        {
            std::cout << " [-] Error: Capacidad maxima (256) alcanzada.\n";
        }
    }

    void Application::actionCreateOrder() 
    {
        int orderId, customerId;
        
        std::cout << "\n-- CREAR PEDIDO --\nNro de Pedido: ";
        std::cin >> orderId;
        
        std::cout << "ID del Cliente existente: ";
        std::cin >> customerId;

        if (manager.createOrder(orderId, customerId) != nullptr) 
        {
            std::cout << " [+] Pedido #" << orderId << " generado exitosamente.\n";
        } 
        else 
        {
            std::cout << " [-] Error: Cliente no existe o límite de 256 pedidos alcanzado.\n";
        }
    }

    void Application::actionAddArticleToOrder() 
    {
        int orderId, articleId, quantity;
        
        std::cout << "\n-- AGREGAR ITEM A PEDIDO --\nNro de Pedido: ";
        std::cin >> orderId;
        
        Order* order = manager.findOrderById(orderId);
        if (order == nullptr) 
        {
            std::cout << " [-] Error: El pedido no existe.\n";
            return;
        }

        std::cout << "ID del Articulo a agregar: ";
        std::cin >> articleId;
        
        Article* article = manager.findArticleById(articleId);
        if (article == nullptr) 
        {
            std::cout << " [-] Error: El articulo no existe en el catalogo.\n";
            return;
        }

        std::cout << "Cantidad: ";
        std::cin >> quantity;

        if (order->addArticle(article, quantity)) 
        {
            std::cout << " [+] Item agregado al pedido #" << orderId << ".\n";
        } 
        else 
        {
            std::cout << " [-] Error: Limite de ítems en pedido alcanzado (256) o cantidad invalida.\n";
        }
    }

    void Application::actionListArticles() 
    {
        manager.listArticles();
    }

    void Application::actionListCustomers() 
    {
        manager.listCustomers();
    }

    void Application::actionListOrders() 
    {
        manager.showAllOrders();
    }
}