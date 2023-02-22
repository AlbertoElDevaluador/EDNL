#include <iostream>
//elimina descendientes de aquellos nodos que su contenido sea mayor o igual, que el de sus ascendientes propios y menor o igual que el
//nodo >= suma_ascendentes && nodo <= descendientes_sum <---- hablamos siempre de contenido.
template <typename T>
void llamada(typename Abin<T>&A)
{
  funcion_rec(A.raiz(), A);
}

template <typename T>
void funcion_rec(typename Abin<T>::nodo n, typename Abin<T> &A)
{
    if(n != typename Abin<T>::NODO_NULO)
    {
        if(A.elemento(n) >= suma_ascendentes(A.padre(n), A) && A.elemento(n) <= (sum_descendientes(n, A) - A.elemento(n)))
           eliminar(n, A);
        else
        {
            funcion_rec(A.hijoIzqdo(n), A);
            funcion_rec(A.hijoDrcho(n), A);
        }
        
    }
}

template <typename T>
void eliminar(typename Abin<T>::nodo n, typename Abin<T>&A)
{
    if(n != typename Abin<T>::NODO_NULO)
    {
        eliminar(A.hijoIzqdo(n), A);
        eliminar(A.hijoDrcho(n), A);

        if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO) A.eliminarhijoIzqdo(n);
        if(A.hijoDrcho(n) != Abin<T>::NODO_NULO) A.eliminarhijoDrcho(n);
    }
}

template <typename T>
int suma_descendientes(typename Abin<T>::nodo n, Abin<T>&A)
{
    if(n == typename Abin<T>::NODO_NULO)
    {
        return 0;
    }else{
        return A.elemento(n) + suma_descendientes(A.hijoIzqdo(n), A) + suma_descendientes(A.hijoDrcho(n), A);
    }
}


template <typename T>
int suma_ascendientes(typename Abin<T>::nodo n, Abin<T>&A)
{
    if(n == typename Abin<T>::NODO_NULO)
    {
        return 0;
    }else{
        return A.elemento(n) + suma_ascendientes(A.padre(n), A);
    }
}


/*
ejercicio  extra: calcular el porcentaje de descendientes propios de un arbol general que sean multiplos de 3
*/

float porcentaje(typename Agen<T>&A)
{
    return (multiplo(A.raiz(), A) * 100) / numero_nodos(A.raiz(), A);
}

template <typename T>
int multiplo(typename Agen<T>::nodo n, tpyename Agen<T>&A)
{
    if(n == typename Agen<T>::NODO_NULO)
    {
        return 0;
    }else{

        int contador = 0;
        if(A.elemento(n) % 3 == 0) contador = 1;

        n = A.hijoIzqdo(n);
        while(n != Agen<T>::NODO_NULO)
        {
            contador = contador + multiplo(n, A);
            n = A.hermDrcho(n);
        }

        return contador;
    }
}

template <typename T>
int numero_nodos(typename Agen<T>::nodo n, tpyename Agen<T>&A)
{
    if(n ==  Agen<T>::NODO_NULO)
    {
        return 0;
    }else{
        int contador = 1;
        n = A.hijoIzqdo(n);
        while(n != Agen<T>::NODO_NULO)
        {   
            contador = contador + multiplo(n, A);
            n = A.hermDrcho(n);
        }

        return contador;
    }
}


