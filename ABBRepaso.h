//dados dos arboles binarios de busqueda construir uno nuevo que sea la interseccion de ambos
template <typename T>
Abb<T> funcion(const Abb<T>&A1, const Abb<T>&A2)
{
    assert(!A1.vacio() && !A2.vacio());
    Abb<T> A_int;

    funcion_rec(A1, A2, A_int);

    return A_int;
}

template <typename T>
void funcion(const Abb<T>&A1, const Abb<T>&A2, Abb<T>&A3)
{
    if(!A1.vacio())
    {
        if(!A2.buscar(A1.elemento()).vacio())
        {
            A3.insertar(A1.elemento());

            funcion_rec(A1.izqdo(), A2, A3);
            funcion_rec(A1.drcho(), A2, A3);
        }else{
            funcion_rec(A1.izqdo(), A2, A3);
            funcion_rec(A1.drcho(), A2, A3);
        }
    }
}


/*
 Implementa el operador  para conjuntos definido como A  B = (A  B) - (A  B).
La implementación del operador  debe realizarse utilizando obligatoriamente la
operación , que nos indica si un elemento dado pertenece o no a un conjunto. La
representación del tipo Conjunto debe ser tal que la operación de pertenencia esté en el
caso promedio en O(log n). 
*/

Abb<T> llamada(const Abb<T>&A1, const Abb<T>&A2)
{
    assert(!A1.vacio() && !A2.vacio());

    Abb<T> A3;

    funcion_rec(A1, A2, A3);
}

bool E (const Abb<T>&A, T elemento)
{
    assert(!A.vacio());
    if(!A.buscar(elemento).vacio)
    {
        return true;//si pertenece al conjunto
    }else{
        return false;//no pertenece al conjunto
    }
}

void funcion_rec(const Abb<T>&A1, const Abb<T>&A2, Abb<T>&A3)
{
    if(!A1.vacio() || !A1.vacio())
    {
        if(!A1.vacio() && !A2.vacio())
        {
            if(!E(A2, A1.elemento())) A3.insertar(A1.elemento());
            if(!E(A1, A2.elemento())) A3.insertaR(A2.elemento());

            funcion_rec(A1.izqdo(), A2.izqdo(), A3);
            funcion_rec(A1.drcho(), A2.drcho(), A3);
        }else if(!A1.vacio())
        {
            if(!E(A2, A1.elemento())) A3.insertar(A1.elemento());

            funcion_rec(A1.izqdo(), A2, A3);
            funcion_rec(A1.drcho(), A2, A3);
        }else if(!A2.vacio())
        {
            if(!E(A1, A2.elemento())) A3.insertar(A2.elemento());

            funcion_rec(A1, A2.izqdo(), A3);
            funcion_rec(A1, A2.drcho(), A3);
        }
    }
}

