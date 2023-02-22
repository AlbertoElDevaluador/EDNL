//Ej 1: contar nodos
template <typename T>int contar(typename Abin<T>::nodo n, const Abin<T>&A)
{
    if(n != Abin<T>::NODO_NULO)
    {
        return 1 + contar(A.HijoIzqdo(n), A) + contar(A.HijoDrcho(n), A);
    }else{

        return 0;
    }
}

//Ej 2: contar 
template <typename T> int altura(typename Abin<T>::nodo n, const Abin<T>&A)
{
    if(n != Abin<T>::NODO_NULO)
    {
        return 1 + max(altura(A.HijoIzqdo(n), A), altura(A.HijoDrcho(n), A));
    }else{
        return -1;
    }
}

//Profundidad
template <typename T> int profundidad(typename Abin<T>::nodo n, const Abin<T>&A)
{
    if(n != Abin<T>::NODO_NULO)
    {
        return 1 + profundidad(A.padre(n), A);
    }else
    {
        return -1;
    }
}


//Desequilibrio

 template <typename T>int desequilibrio(typename Abin<T>::nodo n, const Abin<T>&A)
{
    if(n != Abin<T>::NODO_NULO)
    {
        return max(abs(altura(A.HijoIzqdo(n), A) - altura(A.HijoDrcho(n)), desequilibrio(A.HijoIzqdo(n), A)) - desequilibrio(A.HijoDrcho(n), A));
    }else return 0;
}


//Arboles similares
bool llamada_similares(const Abin<T>&A1, const Abin<T>&A2)
{
    return similares(A1.raiz(), A1, A2.raiz(), A2);
}

template <typename T> bool similares(typename Abin<T>::nodo n1, const Abin<T>&A1, typename Abin<T> nodo::n2, const Abin<T>&A2)
{
    if(n1 == Abin<T>::NODO_NULO || n2 == Abin<T>::NODO_NULO)
    {
        if(n1 == Abin<T>::NODO_NULO && n2 == Abin<T>::NODO_NULO)
        {
            return true;
        }else{
            return false;
        }
        
    }else return similares(A1.HijoIzqdo(n1), A1, A2.HijoIzqdo(n2), A2) && similares(similares(A1.HijoDrcho(n1), A1, A2.HijoDrcho(n2)));
}

//Arbol reflejado (simetrico)
void llamada_reflejado(const Abin<T>&A)
{
    A2 = Abin();

    if(A.arbolvacio() == false)
    {
        A2.insertarRaiz(A.elemento(A.raiz())); 

        reflejo(A.raiz(), A, A2.raiz(), A2);
    }
    return A2;
}

template <typename T> void reflejado(typename Abin<T>::nodo n1, const Abin<T>&A1, typename Abin<T> nodo::n2, const Abin<T>&A2)
{
    if(n1 != Abin<T>::NODO_NULO)
    {
        if(A1.HijoIzqdo(n1) != Abin<T>::NODO_NULO)
        {
            A2.insertarHijoDrcho(n2, A1.elemento(A1.HijoIzqdo(n1)));
        }

        if(A2.HijoDrcho(n1) != Abin<T>::NODO_NULO)
        {
            A2.insertarHijoIzqdo(n2, A1.elemento(A1.HijoDrcho(n1)));
        }

        reflejado(A1.HijoIzqdo(n1), A1, A2.HijoDrcho(n2), A2);
        reflejado(A1.HijoDrcho(n1), A1, A2.HijoIzqdo(n2), A2);
    }
}

//Arbol operaciones
struct contenido
{
    char op;
    float num;
}
float resultado_llamada(const Abin<contenido>&A)
{
    assert(!A.arbolVacio());
    return resultado(A.raiz(), A);
}

template <typename T> float resultado(typename Abin<contenido>::nodo n, const Abin<contenido>&A)
{
    if(n != Abin<contenido>::NODO_NULO)
    {
        if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO || A.hijoDrcho(n) != Abin<T>::NODO_NULO)
        {
            swtich(A.elemento(n).op)
            {
                case "+": return resultado(A.hijaIzqdo(n), A) + resultado(A.hijoDrcho(n), A); break;

                case "-": return resultado(A.hijaIzqdo(n), A) - resultado(A.hijoDrcho(n), A); break;

                case "x": return resultado(A.hijaIzqdo(n), A) * resultado(A.hijoDrcho(n), A); break;

                case "/": return resultado(A.hijaIzqdo(n), A) / resultado(A.hijoDrcho(n), A); break; 
            }
        }else{

            return A.elemento(n).num;
        }
    }
}


//Nodos verdes mas ancestros que descendientes----------------------------------------
int nodosverdes_llamada(const Abin<T>&A)
{
    assert(!A.arbolVacio());

    return nodosverdes_rec(A.raiz(), A);
}

template <typename T> int nodosverdes_rec(typename Abin<T>::nodo n, const Abin<T>&A)
{
    if(n != Abin<T>::NODO_NULO)
    {
        if(num_antecesores(n, A) > num_descendientes(n, A) - 1)
        {
            return 1 + nodosverdes_rec(A.hijoIzqdo(n), A) + nodosverdes_rec(A.hijoDrcho(n), A);
        }else{
            return nodosverdes_rec(A.hijoIzqdo(n), A) + nodosverdes_rec(A.hijoDrcho(n), A);
        }
    }else
    {
        return 0;
    }
}

int num_antecesores(typename Abin<T>::nodo n, const Abin<T>&A)
{
    if(n != Abin<T>::NODO_NULO)
    {
        return 1 + num_antecesores(A.padre(n), A);
    }else{
        return -1;
    }
}

int num_descendientes(typename Abin<T>::nodo n, const Abin<T>&A)
{
    if(n != Abin<T>::NODO_NULO)
    {
        return 1 + num_descendientes(A.hijoIzqdo(n), A) + num_descendientes(A.hijoDrcho(n), A);
    }else return 0;
}

//Nodos verdes que tenga tres hijos.----------------------------------------------------------------------
int nodover_llamada(const Abin<T>&A)
{
    assert(!A.arbolVacio());
    return nodoverde_rec(A.raiz(), A);
}

template <typename T> int nodoverde_rec(typename Abin<T>::nodo n, const Abin<T>&A)
{
    if(n != Abin<T>::NODO_NULO)
    {
        if(nodo_verde(n, A) - 1 == 3) return 1 + nodosverdes_rec(A.hijoIzqdo(n), A) + nodosverdes_rec(A.hijoDrcho(n), A);

        else return nodosverdes_rec(A.hijoIzqdo(n), A) + nodosverdes_rec(A.hijoDrcho(n), A);

    }else return 0;
}

int nodo_verde(typename Abin<T> nodo::n, const Abin<T>&A)
{
    if(n != Abin<T>::NODO_NULO)  return 1 + nodo_verde(A.hijoIzqdo(n), A) + nodo_verde(A.hijoDrcho(n), A);
    return 0;
}


//Poda JUANMA---------------------------ELIMINAR POR POSTORDEN--------------------------------------------------------------------------------

Abin<char> poda_juanma_llamada(Abin<char>&A)
{
    assert(!A.arbolVacio());

    //int num_nodos = poda_juanma_contar(A.raiz(), A);
    poda_juanma_poda(A.raiz(), A);

    return A;
}

template <typename char> int poda_juanma_contar(typename Abin<char>::nodo n, Abin<char>&A)
{
    if(n != Abin<char>::NODO_NULO)
    {
        if(A.elemento(n) == "a" || A.elemento(n) == "e" || A.elemento(n) == "i" || A.elemento(n) == "o" || A.elemento(n) == "u")
            return 1 + poda_juanma_contar(A.hijaIzqdo(n), A) + poda_juanma_contar(A.hijoDrcho(n), A);
        else
            return poda_juanma_contar(A.hijaIzqdo(n), A) + poda_juanma_contar(A.hijoDrcho(n), A);
    }else
        return 0;
}

template <typename char> void poda_juanma_poda(typename Abin<char>::nodo n, Abin<char>&A)
{
    if(n != Abin<char>::NODO_NULO)
    {
        if(A.elemento(n) == "a" || A.elemento(n) == "e" || A.elemento(n) == "i" || A.elemento(n) == "o" || A.elemento(n) == "u")
            if(A.hijoIzqd(n) != Abin<char>::NODO_NULO)
            {
                eliminar(A.hijoIzqd(n), A);
                A.eliminarHijoIzqdo(n);

                poda_juanma_poda(A.hijoDrcho(n), A);
            }
        else
        {
            poda_juanma_poda(A.hijoIzqdo(n), A);
            poda_juanma_poda(A.hijoDrcho(n), A);    
        }
            
    }
}

template <typename char> void eliminar(typename Abin<char>::nodo n, Abin<char>&A)
{
    if(n != Abin<char>::NODO_NULO)
    {
        eliminar(A.hijoIzqdo(n), A);
        eliminar(A.hijaIzqdo(n), A);

        if(A.hijoIzqdo(n) != Abin<char>::NODO_NULO) A.eliminarHijoIzqdo(n);
        if(A.hijoDrcho(n) != Abin<char>::NODO_NULO) A.eliminarHijoDrcho(n);
    }
}


//Arboles generales

template <typename T> int grado_llamada(const Agen<T>&A)
{
    assert(!A.arbolVacio())
    int cont = 0;
    return grado_rec(A.raiz(), A);
}

template <typename T> int grado_rec(typename Agen<T>::nodo n, const Agen<T>&A, int cont)
{
    if(n != Agen<T>::NODO_NULO)
    {
        n = A.hijoIzqd(n);
        while(n != Agen<T>::NODO_NULO)
        {
            cont++;
            return rado_llamada(n, A, cont);
            n = A.hermDrcho(n);
        }
    }
}









