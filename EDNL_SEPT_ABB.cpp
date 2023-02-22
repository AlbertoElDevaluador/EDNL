// Implementa una nueva operación del TAD Abb que tomando un elemento del mismo
//elimine al completo el subárbol que cuelga de él. 

template <typename int> void llamada(Abb<int>&A, int x)
{
    assert(!A.vacio());

    funcion_rec(A, x);
}

template <typename T> void eliminar(Agen<T> &A, T e)
{
    A.buscar(e)->delete;
}
/*
template <typename int> void funcion_rec (Abb<int>&A, int x)
{
    Abb<int> A2 = A.buscar(x);

    if(!A2.vacio())
    {
        eliminar(A2, A);
    }
}

template <typename int> void eliminar(Abb<int>&A2, Abb<int>&A)
{

    while(!A2.izqdo().vacio())
    {
        A2.eliminar(A2.izqdo().elemento());
    }

    while(!A2.drcho().vacio())
    {
        A2.eliminar(A2.drcho().elemento());
    }
    
}
*/

//Ejercicio 3 ABB, crear arbol con los elementos comunes de los dos arboles 
template <typename T> Abb<T> llamada (const Abb<T>&A1, const Abb<T>&A2)
{
    assert(!A1.vacio() && !A2.vacio());

    Abb<T> Ainterseccion; 

    interseccion_rec(A1, A2, Ainterseccion);

    return Ainterseccion;
}

template <typename T> void interseccion_rec(const Abb<T>&A1, const Abb<T>&A2, Abb<T>&Ainterseccion)
{
    if(!A1.vacio())
    {
        if(!A2.buscar(A1.elemento()).vacio())
        {
            Ainterseccion.insertar(A1.elemento());

            interseccion_rec(A1.izqdo(), A2, Ainterseccion);
            interseccion_rec(A1.drcho(), A2, Ainterseccion);
        }else{
            interseccion_rec(A1.izqdo(), A2, Ainterseccion);
            interseccion_rec(A1.drcho(), A2, Ainterseccion);
        }
    }
}

//Ejercicio 3 Union de dos conjuntos
template <typename T> Abb<T> llamada (const Abb<T>&A1, const Abb<T>&A2)
{
    assert(!A1.vacio() && !A2.vacio());

    Abb<T> Ainterseccion; 

    union_rec(A1, A2, Ainterseccion);

    return Ainterseccion;
}

template <typename T> void union_rec (const Abb<T>&A1, const Abb<T>&A2, Abb<T>&Aunion)
{
    if(!A1.vacio() && !A2.vacio())
    {
        Aunion.insertar(A1.elemento());
        Aunion.insertar(A2.elemento());

        union_rec(A1.izqdo(), A2.izqdo(), Aunion);
        union_rec(A1.drcho(), A2.drcho(), Aunion); 
    }
}

//Ejercicio 5: (A INTERSECCION B) - (A UNION B)
template <typename T> Abb<T> llamada(const Abb<T>&A1, const Abb<T>&A2)
{
    assert(!A1.vacio() && !A2.vacio());
    Abb<T> Aop;
    op(A1, A2, Aop);

    return Aop;
}

template <typename T> bool E(const Abb<T>&A, T& e)
{
    //Esta funcion te determine si un elemento dado pertenece o no a una funcion
    if(!A.buscar(e).vacio())
        return true;
    else 
        return false;
}

template <typename T> void op(const Abb<T>&A1, const Abb<T>&A2, Abb<T>&A)
{
    //esta funcion almacena lo que no pertenece. Es decir, meteremos en el nuevo arbol 
    //los elementos diferentes entre ambos arboles
    //Para ello recorreremos con una misma funcion 
    insertado(A1, A2, A);
    insertado(A2, A1, A);
}

template <typename T> void insertado(const Abb<T>&A1, const Abb<T>&A2, Abb<T>&A)
{
    if(!A1.vacio())
    {
        if(!E(A2, A1.elemento())) A.insertar(A1.elemento());

        insertado(A1.izqdo(), A2, A);
        insertado(A1.drcho(), A2, A);
    }
}


//Ejercicio 2 Ejercicio del equilibrado

