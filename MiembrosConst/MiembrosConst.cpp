
#if 0
const int valor1 = 3; // Inicialización por copia
const int valor2(4); // Inicialización directa
const int valor3{ 5 }; // Inicialización uniforme (C++11)


class Fecha
{
private:
    int m_dia;
    int m_mes;
    int m_anho;

public:
    Fecha () = default;
    Fecha(int dia, int mes, int anho)
    {
        setFecha(dia, mes, anho);
    }

    void setFecha(int dia, int mes, int anho)
    {
        m_dia = dia;
        m_mes = mes;
        m_anho = anho;
    }

    int getDia() { return m_dia; }
    int getMes() { return m_mes; }
    int getAnho() { return m_anho; }
};


int main()
{

    const Fecha fecha1{}; // inicialización usando constructor default
    const Fecha fecha2(12, 10, 2021); // inicialización usando constructor parametrizado
    const Fecha fecha3{ 12, 10, 2021 }; // inicialización usando constructor parametrizado (C++11)
}


#include <iostream>
class Cualquiera
{
public:
    int m_valor{};

    Cualquiera() : m_valor{ 0 } { }

    void setValor(int valor) { m_valor = valor; }
    int getValor() { return m_valor; }
    
};
int main()

{
    const Cualquiera cualquiera{}; // Llama al constructor predeterminado

    cualquiera.m_valor = 5; // error compilación: vulnera const
    cualquiera.setValor(5); // error compilación: vulnera const
    std::cout << cualquiera.getValor();

    return 0;
}






#include <iostream>
class Cualquiera
{
public:
    int m_valor{};

    Cualquiera() : m_valor{ 0 } { }

    void setValor(int valor) { m_valor = valor; }    
    // Observa que hemos añadido "const" después de los parámetros, pero antes del cuerpo
    int getValor() const { return m_valor; } 
};
int main()

{
    const Cualquiera cualquiera{}; // Llama al constructor predeterminado

    cualquiera.m_valor = 5; // error compilación: vulnera const
    cualquiera.setValor(5); // error compilación: vulnera const
    std::cout << cualquiera.getValor();

    return 0;
}





class Cualquiera
{
public:
    int m_valor{};

    Cualquiera() : m_valor{ 0 } { }

    void resetValor() { m_valor = 0; }
    void setValor(int valor) { m_valor = valor; }

    int getValor() const; // observa que hemos añadido const aquí
};

int Cualquiera::getValor() const // y aquí
{
    return m_valor;
}
#endif

#if 0

class Cualquiera
{
public:
    int m_valor{};
    // error compilación, funciones const no pueden cambiar variables miembro.
    void resetValor() const { m_valor = 0; } 
};




#include <iostream>

class Fecha
{
private:
    int m_dia{};
    int m_mes{};
    int m_anho{};

public:
    Fecha(int dia, int mes, int anho)
    {
        setFecha(dia, mes, anho);
    }

    void setFecha(int dia, int mes, int anho)
    {
        m_dia = dia;
        m_mes = mes;
        m_anho = anho;
    }

     int getDia()  { return m_dia; }
     int getMes()  { return m_mes; }
     int getAnho()  { return m_anho; }
};

// nota: Estamos pasando fecha aquí como referencia const para evitar hacer una copia de fecha
void imprimirFecha(const Fecha& fecha)
{
    std::cout << fecha.getDia() << '/' << fecha.getMes() << '/' << fecha.getAnho() << '\n';
}

int main()
{
    Fecha fecha{ 21, 02, 2022 };
    imprimirFecha(fecha);

    return 0;
}



#include <iostream>
class Fecha
{
private:
    int m_dia{};
    int m_mes{};
    int m_anho{};

public:
    Fecha(int dia, int mes, int anho)
    {
        setFecha(dia, mes, anho);
    }

    void setFecha(int dia, int mes, int anho)
    {
        m_dia = dia;
        m_mes = mes;
        m_anho = anho;
    }
    // Ahora las funciones getDia, getMes y getAnho son const.
    int getDia() const { return m_dia; }
    int getMes() const { return m_mes; }
    int getAnho() const { return m_anho; }
};

// nota: Estamos pasando fecha aquí como referencia const para evitar hacer una copia de fecha
void imprimirFecha(const Fecha& fecha)
{
    std::cout << fecha.getDia() << '/' << fecha.getMes() << '/' << fecha.getAnho() << '\n';
}

int main()
{
    Fecha fecha{ 21, 02, 2022 };
    imprimirFecha(fecha);

    return 0;
}

#endif



#include <string>

class Cualquiera
{
private:
    std::string m_valor{};

public:
    Cualquiera(const std::string& valor = "") : m_valor{ valor } {}
	
    const std::string& getValor() const { return m_valor; } // getValor() para objetos const  (devuelve referencia const)
    std::string& getValor() { return m_valor; } // getValor() para objetos no-const (devuelve referencia no-const)
};


int main()
{
    Cualquiera cualquiera;
    cualquiera.getValor() = "Hola"; // llama a getValor( ) no-const;

    const Cualquiera cualquiera2;
    cualquiera2.getValor(); // llama a getValor( ) const;

    return 0;
}



