#include <iostream>

//Para el primer ejercicio vamos a utilizar un Arbol binario de busqueda
//Devuelve un bool true si ha sido eliminado con exito o false si no existe el elemento a eliminar
template <typename int> eliminar(Abb<int>&A, int elemento)
{
    assert(!A.vacio())

    if(!A.buscar(elemento).vacio())
    {
        A.eliminar(elemento);
        return true;

    } else return false;
}

//Arbol ternario, un arbol es ternario si todos sus nodos son hojas o tienen 3 hijos. Dado un arbol arbitrario es 
//ternario o no.-------------------------------------------------------------------------------------------------
template <typename T> bool llamada(const Agen<T>&A)
{
    assert(!A.arbolVacio());
    int num_nodos = 0;
    int num_nodos_ternarios = 0;

    contar_nodos(A.raiz(), A, num_nodos);
    num_nodos_ternarios(A.raiz(), A, num_nodos_ternarios);

    if(num_nodos == num_nodos_ternarios) return true;
    else return false;
}

template <typename T> void contar_nodos(typename Agen<T>::nodo n, const Agen<T>&A, int &cont)
{
    if(n != Agen<T>::NODO_NULO)
    {
        cont++;

        n = A.hijoIzqdo(n);
        while(n != Agen<T>::NODO_NULO)
        {
            contar_nodos(n, A, cont);
            n = A.hermDrcho(n);
        }
    }
}

template <typename T> void ternario(typename Agen<T>::nodo n, const Agen<T>&A, int &num_nodos_ternarios)
{
    if(n != Agen<T>::NODO_NULO)
    {
        if(ternario(n, A)) num_nodos_ternarios++;

        n = A.hijoIzqdo(n);
        while(n != Agen<T>::NODO_NULO)
        {
            contar_nodos(n, A, cont);
            n = A.hermDrcho(n);
        }
    }
}


template <typename T> bool ternario(typename Agen<T>::nodo n, const Agen<T>&A)
{
    if(n != Agen<T>::NODO_NULO)
    {
        if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO) return true;

        int cont_hermanos = 0;
        n = A.hijoIzqdo(n);
        while(n != Agen<T>::NODO_NULO)
        {
            cont_hermanos++;
            n = A.hermDrcho(n);
        }

        if(cont_hermanos == 3) return true;
        else return false;
    }   

}

//Este ejercicio mejorado:
//hace llamada
template <typename T> bool ternario_rec(typename Agen<T>::nodo n, const Agen<T>&A)
{
    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO) return true;
    else
    {   
        bool comprobacion = true;
        int contador = 0;

        n = A.hijoIzqdo(n);
        while(n != Agen<T>::NODO_NULO)
        {
            comprobacion = comprobacion && ternario_rec(n, A);
            cont++;
            n = A.hermDrcho(n);
        }   

        if(cont == 3 && comprobacion) return true;
        else return false;

        //return comprobacion;
    }
}

//EJERCICIOS FCKNING OWNER EL MAS CHUNGO 
template <typname char> void llamada(const Agen<char>&A, int k)
{
    assert(!A.arbolVacio());
    int N = 2^k;
    char Pinturillo[N][N];

    pintar_rec(A.raiz(), A, Pinturillo);
}

template <typename char> void pintar_rec(typename Agen<char>::nodo n, char &Pinturillo[N][N], int N)
{
    if(A.hijoIzqdo(n) == Agen<char>::NODO_NULO)
    {
        M[N][N] = A.elemento(n);
    }else{

        hijo = A.hijoIzqdo(n);
        while(hijo != Agen<char>::NODO_NULO)
        {
            pintar_rec(hijo, Pinturillo, N);
            hijo = A.hermDrcho(hijo);
        }



    }
}
