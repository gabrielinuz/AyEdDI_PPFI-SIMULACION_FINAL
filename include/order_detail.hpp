#ifndef ORDER_DETAIL_HPP
#define ORDER_DETAIL_HPP

#include "article.hpp"

namespace cosmetic 
{
    /**
     * @class OrderDetail
     * @brief Renglón de compra: relaciona un puntero a Article con una cantidad.
     * 
     * Se utiliza Agregación pura: el puntero simple *article apunta a una
     * dirección de memoria externa (gestionada por CompanyManager). No destruye al artículo.
     */
    class OrderDetail 
    {
    private:
        Article* article; // Puntero simple (sin dobles punteros)
        int quantity;

    public:
        /**
         * @brief Constructor por defecto.
         */
        OrderDetail();

        /**
         * @brief Configura el detalle asignando el puntero al artículo y la cantidad.
         */
        void setup(Article* _article, int _quantity);

        /**
         * @brief Calcula el costo del renglón multiplicando precio por cantidad.
         * @return Subtotal en punto flotante.
         */
        double calculateSubtotal() const;

        /**
         * @brief Muestra el desglose del detalle.
         */
        void displayDetail() const;

        // Getters
        Article* getArticle() const;
        int getQuantity() const;
    };
}

#endif // ORDER_DETAIL_HPP