#ifndef ARTICLE_HPP
#define ARTICLE_HPP

#include <string>

namespace cosmetic 
{
    /**
     * @class Article
     * @brief Representa el producto comercializado (cosmético).
     * 
     * Esta clase encapsula la información de un producto individual.
     * Pertenece al namespace cosmetic para mantener el aislamiento del dominio.
     */
    class Article 
    {
    private:
        int id;
        std::string name;
        std::string category;
        double unitPrice;

    public:
        /**
         * @brief Constructor por defecto. Inicializa el objeto en un estado seguro.
         */
        Article();

        /**
         * @brief Metodo de configuración para inicializar un artículo ya creado en memoria.
         * 
         * @param _id Identificador único.
         * @param _name Nombre del artículo.
         * @param _category Categoría a la que pertenece.
         * @param _price Precio unitario.
         */
        void setup(int _id, const std::string& _name, const std::string& _category, double _price);

        // Getters para acceso a atributos privados encapsulados
        int getId() const;
        std::string getName() const;
        std::string getCategory() const;
        double getUnitPrice() const;

        /**
         * @brief Imprime la información del artículo en la consola.
         */
        void displayInfo() const;
    };
}

#endif // ARTICLE_HPP