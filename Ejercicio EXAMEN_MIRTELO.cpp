#include <iostream>

//PArcial 1 EDNL 2022

template <typename T>
int contar_nodos_verdes(typename Abin<T>::nodo n, const Agen<T>&A)
{
    if(n != Agen<T>::NODO_NULO)
    {
        if(nodo_verde(A.hijoIzqdo(n), A, A.hijoDrcho(n)) && A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO)
        {
            return 2 + contar_nodos_verdes(A.hijoIzqdo(n), A) + contar_nodos_verdes(A.hijoDrcho(n), A);
        }else return contar_nodos_verdes(A.hijoIzqdo(n), A) + contar_nodos_verdes(A.hijoDrcho(n));

    }else return 0;
}

bool nodo_verde(typename Abin<T>::nodo n1, const Agen<T>&A, typename Abin<T>::nodo n2)
{
    if(n1 == Abin<T>::NODO_NULO && n2 == Abin<T>::NODO_NULO)
    {
        return true;
    }else{

        if(n1 != Abin<T>::NODO_NULO && n2 != Abin<T>::NODO_NULO)
        {
            if(A.elemento(n1) == A.elemento(n2)) return nodo_verde(A.hijoIzqdo(n1), A, A.hijoDrcho(n2)) && nodo_verde(A.hijoDrcho(n1), A, A.hijoIzqdo(n2)); 
            else return false;
        }else return false;
    }
}

//Devolver el número de nodos "nostálgicos" de un árbol.
//Un nodo nostálgico sería aquel que tiene más pasado que futuro, es decir, que tiene más antecesores propios que descendientes propios.
int llamada(const Agen<T>&A)
{
    if(!A.arbolVacio()) return contar_nodos(A.raiz(), A);
    else return 0;
}

template <typename T>
int contar_nodos(typename Abin<T>::nodo n, const Abin<T>&A)
{
    if(n == Abin<T>::NODO_NULO) return 0;
    else{

        if(num_antecesores(n, A) > num_descendientes(n, A) - 1)
        {
            return 1 + contar_nodos(A.hijoIzqdo(n), A) + contar_nodos(A.hijoDrcho(n), A);
        }else{
            return contar_nodos(A.hijoIzqdo(n), A) + contar_nodos(A.hijoDrcho(n), A);
        }

    }
}

template <typename T>
int num_antecesores(typename Abin<T>::nodo n, const Abin<T>&A)
{
    if(n == Abin<T>::NODO_NULO) return -1;
    else{
        return 1 + num_antecesores(A.padre(n), A);
    }
}

template <typename T>
int num_descendientes(typename Abin<T>::nodo n, const Abin<T>&A)
{
    if(n == Abin<T>::NODO_NULO) return 0;
    else{
        return 1 + num_descendientes(A.hijoIzqdo(n), A) + num_descendientes(A.hijoDrcho(n), A);
    }
}

//Calcular la densidad de un arbol
//La densidad es el grado maximo de un arbol entre el numero de nodos hojas del arbol
template <typename T>
float llamada(const Agen<T>&A)
{
    if(!A.arbolVacio()) return grado(A.raiz(), A) / num_nodos_hojas(A.raiz(), A);
    else return 0;
}

template <typename T>
int grado(typename Agen<T>::nodo n, const Agen<T>&A)
{
    if(n == Agen<T>::NODO_NULO) return 0;
    else{
        int contador = 0;

        Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO)
        {
            contador++;
            hijo = A.hermDrcho(hijo);
        }

        n = A.hijoIzqdo(n);
        while(n != Agen<T>::NODO_NULO)
        {
            contador = max(contador, grado(n, A));
            n = A.hermDrcho(n);
        }

        return contador;
    }
}

template <typename T>
int num_nodos_hoja(typename Agen<T>::nodo n, const Agen<T>&A)
{
    if(n == Agen<T>::NODO_NULO) return 0;
    else{
            int var = 0;
            if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO) var = 1;

            n = A.hijoIzqdo(n);
            while(n != Agen<T>::NODO_NULO)
            {
                var = var + num_nodos_hoja(n, A);
                n = A.hermDrcho(n);
            }

            return var;
        }
}


/*
Ejercicio examen
*/

template <typename bool>
int num_reb_llamada(const Abin<bool>&A)
{
    return funcion_rec(A.raiz(), A);
}

template <typename bool>
int funcion_rec(typename Abin<bool>::nodo n, const Abin<bool>&A)
{
    if(n == Abin<bool>::NODO_NULO)
    {
        return 0;
    }else{

        swtich(A.elemento(n))
        {
            case true: if(num_false(A.padre(n), A) > num_true(A.padre(n), A))
            {
                return 1 + funcion_rec(A.hijoIzqdo(), A) + funcion_rec(A.hijoDrcho(n), A);
            }else{
                return funcion_rec(A.hijoIzqdo(), A) + funcion_rec(A.hijoDrcho(n), A);
            } break;

            case false: if(num_true(A.padre(n), A) > num_false(A.padre(n), A))
            {
                return 1 + funcion_rec(A.hijoIzqdo(), A) + funcion_rec(A.hijoDrcho(n), A); 
            }else{
                return funcion_rec(A.hijoIzqdo(), A) + funcion_rec(A.hijoDrcho(n), A);
            } break;
        }
    }
}

template <typename bool>
int num_true(typename Abin<bool>::nodo n, const Abin<bool>&A)
{
    if(n == Abin<bool>::NODO_NULO)
    {
        return 0;
    }else
    {
        if(A.elemento(n) == true)
        {
            return 1 + num_true(A.padre(n), A);

        }else return num_true(A.padre(n), A);
    }
}

template <typename bool>
int num_false(typename Abin<bool>::nodo n, const Abin<bool>&A)
{
    if(n == Abin<bool>::NODO_NULO)
    {
        return 0;
    }else
    {
        if(A.elemento(n) == false)
        {
            return 1 + num_false(A.padre(n), A);
            
        }else return num_false(A.padre(n), A);
    }
}


/*
Abuelete mas ancestros que descendientes
*/

template <typename bool>
int num_reb_llamada(const Abin<bool>&A)
{
    return funcion_rec(A.raiz(), A);
}

template <typename bool>
int funcion_rec(typename Abin<bool>::nodo n, const Abin<bool>&A)
{/*
    if(n == Abin<bool>::NODO_NULO)
    {
        return 0;
    }else{

        if(abuelete(n, A)) return 1 + funcion_rec(A.hijoIzqdo(n), A) + funcion_rec(A.hijoDrcho(n), A);
        else return funcion_rec(A.hijoIzqdo(n), A) + funcion_rec(A.hijoDrcho(n), A);
    }
    */
    if(n == Abin<bool>::NODO_NULO)
    {
        return 0;
    }else{

        if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO || A.hijoDrcho(n) == Abin<T>::NODO_NULO)
        {
            return funcion_rec(A.hijoIzqdo(n), A) + funcion_rec(A.hijoDrcho(n), A);
        }else{
            if(num_nietos(A.hijoIzqdo(n), A.hijoDrcho(n), A) == 3) return 1 + funcion_rec(A.hijoIzqdo(n), A) + funcion_rec(A.hijoDrcho(n), A);
            else return funcion_rec(A.hijoIzqdo(n), A) + funcion_rec(A.hijoDrcho(n), A);
        }
    }
}

int abuelete (typename Abin<T>::nodo n1, typename Abin<T>::nodo n2, const Abin<T>&A)
{
    int cont = 0;
    if(A.hijoIzqdo(n1) != Abin<T>::NODO_NULO) cont++;
    if(A.hijoDrcho(n1) != Abin<T>::NODO_NULO) cont++;
    if(A.hijoIzqdo(n2) != Abin<T>::NODO_NULO) cont++;
    if(A.hijoDrcho(n2) != Abin<T>::NODO_NULO) cont++;

    return cont;
}
/*
bool abuelete (typename Abin<T>::nodo n, const Abin<T>&A)
{
    if(A.hijoIzqdo(n) == typename Abin<T>::NODO_NULO || A.hijoDrcho(n) == typename Abin<T>::NODO_NULO)
    {
        return false;
    }else{
        if(A.hijoIzqdo(A.hijoIzqdo(n)) != Abin<bool>::NODO_NULO && A.hijoDrcho(A.hijoIzqdo(n)) != Abin<bool>::NODO_NULO && A.hijoIzqdo(A.hijoDrcho(n)) != Abin<bool>::NODO_NULO && A.hijoDrcho(A.hijoIzqdo(n)) == Abin<bool>::NODO_NULO
        || A.hijoIzqdo(A.hijoIzqdo(n)) != Abin<bool>::NODO_NULO && A.hijoDrcho(A.hijoIzqdo(n)) != Abin<bool>::NODO_NULO && A.hijoIzqdo(A.hijoDrcho(n)) == Abin<bool>::NODO_NULO && A.hijoDrcho(A.hijoIzqdo(n)) != Abin<bool>::NODO_NULO
        || A.hijoIzqdo(A.hijoIzqdo(n)) == Abin<bool>::NODO_NULO && A.hijoDrcho(A.hijoIzqdo(n)) != Abin<bool>::NODO_NULO && A.hijoIzqdo(A.hijoDrcho(n)) == Abin<bool>::NODO_NULO && A.hijoDrcho(A.hijoIzqdo(n)) == Abin<bool>::NODO_NULO)
        {
            return true;
        }else return false;
    }
}
*/








