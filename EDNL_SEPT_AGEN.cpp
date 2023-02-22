//Ejercicio 2: Implementa un subprograma que dados un arbol y un nodo dentro de dicho arbol determine
//la profundidad de este nodo en el arbol. 
template <typename T> int funcion_rec(typename Agen<T>::nodo n, const Agen<T>&A)
{
    if(n != Agen<T>::NODO_NULO)
    {
        return 1 + funcion_rec(A.padre(n), A);
    }else return -1;
} 

//Ejercicio 4: Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice
//la poda de A a partir de x. Se asume que no hay elementos repetidos en A.
template <typename int> Agen<int> llamada(Agen<int>&A, int x)
{
    assert(!A.arbolVacio());

    poda_rec(A.raiz(), A, x);
} 

template <typename int> void poda_rec(typename Agen<int>::nodo n, Agen<int>&A, int x)
{
    if(n != Agen<int>::NODO_NULO)
    {
        if(A.elemento(n) == x) eliminar(n, A);
        else
        {
            n = A.hijoIzqdo(n);

            while(n != Agen<int>::NODO_NULO)
            {
                poda_rec(n, A, x);
                n = A.hermDrcho(n);
            }
        }
    }
}

template <typename int> void eliminar(typename Agen<int>::nodo n, Agen<int>&A)
{
    if(n != Agen<int>::NODO_NULO)
    {
        typename Agen<int>::nodo hijo = A.hijoIzqdo(n);

        while(hijo != Agen<int>::NODO_NULO)
        {
            eliminar(hijo, A);
            hijo = A.hermDrcho(hijo);
        }

        if(A.hijoIzqdo(n) != Agen<int>::NODO_NULO)
        {
            while(A.hijoIzqdo(n) != Agen<int>::NODO_NULO)
            {
                A.eliminarHijoIzqdo(n);
            }
        }
    }
}

//Arboles generales ejercicio de examen: una funcion que me dan el arbol genelogico, el nodo muerto, y tienes que dividir la riqueza entre
//tus descendientes. No sabemos que se almacena.

struct contenido{
    int riqueza;
    bool estado;
}

template <typename contenido>
void llamada(Agen<contenido>&A)
{
    assert(!A.arbolVacio());

    herencias_rec(A.raiz(), A);
}

template <typename contenido>
void herencias_rec(typename Agen<contenido>::nodo n, Agen<contenido>&A)
{
    if(n !=  Agen<contenido>::NODO_NULO)
    {
        if(tiene_descendencia_viva(n, A))//procesar
        {
            //ahora contaremos el numero de hijos que tiene el nodo para saber como repartir el dinero.
            int cont = 0;
            Agen<contenido>::nodo nodo_aux = A.hijoIzqdo(n);

            while(nodo_aux != Agen<contenido>::NODO_NULO)//contamos el numero de hijos
            {
                if(l.elemento(nodo_aux).estado == false)//comprobamos que no sean hijos muertos
                {
                    if(tiene_descendencia_viva(nodo_aux, A) == true) cont++;//si son hijos muertos comprobaremos que estos tienen descendencia para contarlos en la herencia
                }else cont++;
                
                nodo_aux = A.hermDrcho(nodo_aux);
            }//orden n

            if(cont > 0)
            {
                repartir_herencia(n, A, cont, A.elemento(n).riqueza);//repartimos la herencia, porque tiene hijos;
                A.elemento(n).riqueza = 0;
            }
            else A.elemento(n).riqueza = 0;//si el numero de hijos es superior a 0 repartimos, sino se lo damos al estado;
        }

        n = A.hijoIzqdo(n);

        while(n != Agen<contenido>::NODO_NULO)//continuamos iterando en preorden
        {
            herencias_rec(n, A);
            n = A.hermDrcho(n);
        }
    }
}

template <typename contenido>
void repartir_herencia(typename Agen<contenido>::nodo n, Agen<contenido>&A, int numero_hijos, int riqueza)
{
    n = A.hijoIzqdo(n);

    while(n != Agen<contenido>::NODO_NULO)
    {
        if(tiene_descendencia_viva(n, A)) A.elemento(n).riqueza = A.elemento(n).riqueza + (riqueza/numero_hijos);

        n = A.hermDrcho(n);
    }
}

template <typename contenido>
bool tiene_descendencia_viva(typename Agen<contenido>::nodo n, Agen<contenido>&A)
{
    if(n != Agen<contenido>::NODO_NULO)
    {
        bool descendencia = false;

        n = A.hijoIzqdo(n);
        while(n != Agen<contenido>::NODO_NULO && descendencia == false)
        {
            if(A.elemento(n).estado == true) descendencia == true;
            else
            {
                descendencia = tiene_descendencia_viva(n, A);
                n = A.hermDrcho(n);
            }
        }

        return descendencia;
    }else return false;
}
