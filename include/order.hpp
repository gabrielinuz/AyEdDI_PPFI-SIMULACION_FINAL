#ifndef ORDER_HPP
#define ORDER_HPP

#include "customer.hpp"
#include "order_detail.hpp"

namespace cosmetic 
{
    const int MAX_DETAILS = 256;

    /**
     * @class Order
     * @brief Administra el cliente (Agregación) y sus renglones.
     * 
     * Cumple con la restricción de usar arreglos dinámicos de puntero simple.
     */
    class Order 
    {
    private:
        int id;
        Customer* customer;       // Puntero simple (Agregación)
        
        /**
         * @brief Puntero simple a un bloque contiguo de memoria.
         * En lugar de usar DetallePedido**, se reserva un array contiguo de objetos
         * usando `new OrderDetail[256]`, evitando punteros dobles.
         */
        OrderDetail* details;     
        
        int detailCount;

    public:
        /**
         * @brief Constructor. Asigna dinámicamente el arreglo de 256 detalles.
         */
        Order();

        /**
         * @brief Destructor. Libera la memoria del arreglo de detalles.
         */
        ~Order();

        /**
         * @brief Configura la metadata del pedido.
         */
        void setup(int _id, Customer* _customer);

        /**
         * @brief Añade un artículo al pedido.
         * 
         * @param article Puntero simple al artículo.
         * @param quantity Cantidad solicitada.
         * @return true Si se agregó correctamente.
         * @return false Si superó el límite de 256.
         */
        bool addArticle(Article* article, int quantity);

        /**
         * @brief Suma todos los subtotales usando un bucle while iterativo.
         * @return Total del pedido.
         */
        double calculateTotal() const;

        /**
         * @brief Formatea la salida completa del ticket.
         */
        void displayOrder() const;

        int getId() const;
    };
}

#endif // ORDER_HPP