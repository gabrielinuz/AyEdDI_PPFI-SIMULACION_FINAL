#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>

namespace cosmetic 
{
    /**
     * @class Customer
     * @brief Entidad del dominio de negocio que realiza los pedidos.
     */
    class Customer 
    {
    private:
        int id;
        std::string fullName;
        std::string dni;
        std::string phone;

    public:
        /**
         * @brief Constructor por defecto.
         */
        Customer();

        /**
         * @brief Configura los datos del cliente post-instanciación.
         * 
         * @param _id Identificador único.
         * @param _name Nombre completo.
         * @param _dni Documento de identidad.
         * @param _phone Número telefónico.
         */
        void setup(int _id, const std::string& _name, const std::string& _dni, const std::string& _phone);

        // Getters
        int getId() const;
        std::string getFullName() const;
        std::string getDni() const;
        std::string getPhone() const;

        /**
         * @brief Muestra la información del cliente por pantalla.
         */
        void displayInfo() const;
    };
}

#endif // CUSTOMER_HPP