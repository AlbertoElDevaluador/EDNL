//Ej 1 de las dos maneras

int contar (typename Abin<T> nodo::n, const Abin<T>&A)
{
    if(n != Abin<T>::NODO_NULO)
    {
        return 1 + contar(A.HijoIzqd(n), A) + contar(A.HijoDrcho(n), A);
    }else{
        return 0;
    }
}

//Manera 2
static int cont = 0;

void contar (typename Abin<T> nodo::n, const Abin<T>&A, int cont)
{
    if(n == A.raiz(n)) cont = 0;
    
    if(n != Abin<T>::NODO_NULO)
    {
        cont++;
        contar(A.HijoIzqdo(n), A, cont);
        contar(A.HijoDrcho(n), A, cont);
    }
}



//Ejercicio 2 Altura
int altura(typename Abin<T> nodo::n, const Abin<T> &A)
{
    if(n != Abin<T>::NODO_NULO)
    {
        return 1 + max(altura(A.HijoIzqd(n), A),  altura(A.HijoDrcho(n), A));
    }else{
        return -1;
    }
}

//Ejercicio 3Profundidad
int profundidad (typename Abin<T> nodo::n, const Abin<T> &A)
{
    if(n != A.raiz(n))
    {
        return 1 + profundidad(A.padre(n), A);  
    }else return 0;
}


//Ejercicio 6Desequilibrio
int caclular (typename Abin<T> nodo::n, const Abin<T> &A)
{
    if(n != Abin<T>::NODO_NULO)
    {
        max(abs(altura(A.HijoIzqd(n), A) - altura(A.HijoDrcho(n), A)), max(calcular(A.HijoIzqd(n), A)- calcular(A.HijoDrch(n), A))));
    }else return 0;
}




///////////////Hoja 2///////////////////////////
//ejercicio 1
/*bool similar_llamada(const Abin<T> &A1, const Abin<T> &A2)
{
	if(arbolVacio(A1) == true && arbolVacio(A2) == true)
	{
		return true;
	}else{
		return similar(A1.raiz(), A1, A2.raiz(), A2);
	}
}

void similar(typename Abin<t> nodo::n1, const Abin<T> &A1, typename<T> nodo::n2, const Abin<T> &A2)
{
	if(A1.HijoIzqdo(n1) != Abin<T>::NODO_NULO || A1.HijoDrcho(n1) != Abin<T>::NODO_NULO ||
		A2.HijoIzqdo(n2) != Abin<T>::NODO_NULO || A2.HijoDrcho(n2) != Abin<T>::NODO_NULO)
	{
		if((A1.HijoIzqdo(n1) == Abin<T>::NODO_NULO && A2.HijoIqzdo(n2) == Abin<T>::NODO_NULO && A1.HijoDrcho(n1) == Abin<T>::NODO_NULO && A2.HijoDrcho(n2) == Abin<T>::NODO_NULO)    
			|| (A1.HijoIzqdo(n1) != Abin<T>::NODO_NULO && A2.HijoIqzdo(n2) != Abin<T>::NODO_NULO && A1.HijoDrcho(n1) != Abin<T>::NODO_NULO && A2.HijoDrcho(n2) != Abin<T>::NODO_NULO)
				|| (A1.HijoIzqdo(n1) != Abin<T>::NODO_NULO && A2.HijoIqzdo(n2) != Abin<T>::NODO_NULO && A1.HijoDrcho(n1) == Abin<T>::NODO_NULO && A2.HijoDrcho(n2) == Abin<T>::NODO_NULO)
					||(A1.HijoIzqdo(n1) == Abin<T>::NODO_NULO && A2.HijoIqzdo(n2) == Abin<T>::NODO_NULO && A1.HijoDrcho(n1) != Abin<T>::NODO_NULO && A2.HijoDrcho(n2) != Abin<T>::NODO_NULO))
		{
			return similar(A1.HijoIzqdo(n1), A1, A2.HijoIzqdo(n2), A2) && similar(A1.HijoDrcho(n1), A1, A2.HijoDrcho(n2), A2);				
		}else{
			return false;
		}
	else{
		return true;
	}
}
*/


//ejercicio 1 
bool similar_llamada(const Abin<T> &A1, const Abin<T> &A2)
{
	return similar_rec(A1.raiz(), A1, A2.raiz(), A2);

}

template <typename T> bool similar_rec(typename Abin<T> nodo::n1, const Abin<T> &A1, typename<T> nodo::n2, const Abin<T> &A2)
{
	if(n1 == Abin<T>::NODO_NULO || n2 == Abin<T>::NODO_NULO)
	{
		if(n1 == Abin<T>::NODO_NULO && n2 == Abin<T>::NODO_NULO)
		{
			return true;
		}else{
			return false;
		}
	}else{
		return similar(A1.HijoIzqdo(n1), A1, A2.HijoIzqdo(n2), A2) && similar(A1.HijoDrcho(n1), A1, A2.HijoDrcho(n2), A2);
	}
}

//Ejercicio 2 Hoja 2
Abin<T> funcion_llamada(const Abin<T> &AbinA)
{
	AbinB = Abin();	
	
	if(AbinA.arbolVacio() == false)
	{
		AbinB.insertarRaiz(AbinA.elemento(AbinA.raiz()));
		
		reflejo_rec(AbinA.raiz(), AbinA, AbinB.raiz(), AbinB);
	}
	return AbinB;
}

template <typename T> void reflejo_rec(typename Abin<T>::nodo n1, const Abin<T> &AbinA, typename Abin<T>::nodo n2, const Abin<T> &AbinB)
{
	if(n1 != Abin<T>::NODO_NULO)
	{
		if(AbinA.HijoIZqdo(n1) != Abin<T>::NODO_NULO)
		{
			AbinB.insertarHijoDrcho(n2, AbinA.elemento(AbinA.HijoIzqdo(n1)));
		}
		if(AbinA.HijoDrcho(n1) != Abin<T>::NODO_NULO)
		{
			AbinB.insertarHijoIzqdo(n2, AbinA.elmento(AbinA.HijoDrcho(n1)));
		}
		
		reflejo_rec(AbinA.HijoIzqo(n1), AbinA, AbinB.HijoDrcho(n2), AbinB);
		reflejo_rec(AbinA.HijoDrcho(n1), AbinA, AbinB.HijoIzqdo(n2), AbinB);
	}
}


//Ejercicio NODOS VERDES
int num_NODOS_VERDES_llamada(const Abin<T> &Abin)
{
	return num_NODOS_VERDES_rec(AbinA.raiz(), AbinA);
}

template <typename T> int num_NODOS_VERDES_rec(typename Abin<T> nodo::a1, const Abin<T> &AbinA)
{
	if(a1 != Abin<T>::NODO_NULO){
		if(nodo_verde(a1, AbinA) == true)
		{
			
			return 1 + num_NODOS_VERDES_rec(AbinA.HijoIzqdo(a1)) + num_NODOS_VERDES_rec(AbinA.HijoDrcho(a1));
			
		}else{
			
			return num_NODOS_VERDES_rec(AbinA.HijoIzqdo(a1)) + num_NODOS_VERDES_rec(AbinA.HijoDrcho(a1));
			
		}
	}else{
		return 0;
	}
}

template <typename T> bool nodo_verde(typename Abin<T> nodo::a1, const Abin<T> &AbinA)
{
	int cont = 0;
	
	if(AbinA.HijoIzqdo(a1) == Abin<T>::NODO_NULO || AbinA.HijoDrcho(a1) == Abin<T>::NODO_NULO)
	{
		return false;
	}else{
		
		if(AbinA.HijoIzqdo(AbinA.HijoIZqdo(a1)) != Abin<T>::NODO_NULO) cont++;
		if(AbinA.HijoIzqdo(AbinA.HijoDrcho(a1)) != Abin<T>::NODO_NULO) cont++;
		if(AbinA.HijoDrcho(AbinA.HijoIZqdo(a1)) != Abin<T>::NODO_NULO) cont++;
		if(AbinA.HijoDrcho(AbinA.HijoDrcho(a1)) != Abin<T>::NODO_NULO) cont++;
		
		if(cont == 3) return true;
		else return false;
	}
}

//Ejercicio 3 Hoja 2
struct Elemento{
	float var;
	char op;
};

float resultado_llamada(const Abin<T> &AbinA)
{
	if(AbinA.arbolVacio(a1) != true) return resultado_rec(AbinA.raiz(), AbinA);
	else return 0;
}

template <typename T> float resultado_rec(typename Abin<T> nodo::a1, const Abin<T> &AbinA)
{
	if(a1 != Abin<T>::NODO_NULO)
	{
		if(AbinA.HijoIzqdo(a1) != Abin<T>::NODO_NULO|| AbinA.HijoDrcho(a1) != Abin<T>::NODO_NULO)
		{
			switch(AbinA.elemento(a1).op)
			{
				case "+": return resultado_rec(AbinA.HijoIzqdo(a1), AbinA) + resultado_rec(AbinA.HijoDrcho(a1), AbinA);
				break;
				case "-": return resultado_rec(AbinA.HijoIzqdo(a1), AbinA) - resultado_rec(AbinA.HijoDrcho(a1), AbinA);
				break;
				case "*": return resultado_rec(AbinA.HijoIzqdo(a1), AbinA) * resultado_rec(AbinA.HijoDrcho(a1), AbinA);
				break;
				case "/": return resultado_rec(AbinA.HijoIzqdo(a1), AbinA) / resultado_rec(AbinA.HijoDrcho(a1), AbinA);
				break;
			}
		}else{
			return AbinA.elemento(a1).var;
		}
	}
}

//Ejercicio nodos nostalgicos:  más antecesores propios que descendientes propios.
int num_nodo_nostalgico_llamada(const Abin<T> &AbinA)
{
	if(AbinA.arbolVacio() != true)
	{
		return num_nodo_nostalgico_rec(AbinA.raiz(), AbinA);
	}else{
		return 0;
	}
}

template <typename T> int num_nodo_nostalgico_rec(typename Abin<T> nodo::a1, const Abin<T> &AbinA)
{
	if(a1 != Abin<T>::NODO_NULO)
	{
		if(nodo_nostalgico(a1, AbinA) == true)
		{
			return 1 + num_nodo_nostalgico_rec(AbinA.HijoIzqdo(a1), AbinA) + num_nodo_nostalgico_rec(AbinA.HijoDrcho(a1), AbinA);
		}else{
			return num_nodo_nostalgico_rec(AbinA.HijoIzqdo(a1), AbinA) + num_nodo_nostalgico_rec(AbinA.HijoDrcho(a1), AbinA);
		}
	}else{
		return 0;
	}
}

bool nodo_nostalgico(typename Abin<T>::nodo a1, const Abin<T> &AbinA)
{
	if(profundiad(a1, AbinA) > num_hijos(a1, AbinA) - 1) return true;
	else return false;
}

int num_hijos (typename Abin<T> nodo::a1, const Abin<T> &AbinA)
{
	if(a1 != Abin<T>::NODO_NULO)
	{
		return 1 + altura(AbinA.HijoIzqdo(a1), AbinA) + altura(AbinA.HijoDrcho(a1), AbinA);
	}else{
		return 0;
	}
}

int profundidad(typename Abin<T> nodo::a1, const Abin<T> &AbinA)
{
	if(a1 != AbinA.raiz())
	{
		return 1 + profundidad(AbinA.padre(a1), AbinA);
	}else{
		return -1;
	}
}


//Ejercicio 2 Juanma:
/*
1-Dado una arbol, con el mensaje  "Que me ha dado antes", eeeeh, debnes sacar el mensaje ecrito en el arbol. 
2- Recorrer el mismo arbol en inorden, y sacar el mensaje de recorrerlo en inorden
*/
 
std::vector<char> leermensaje(const Abin<T> &AbinA)
{
	Cola<typename Abin<T>::nodo> C;//cola de nodos
	std::vector<char> V;
	C.push(AbinA.raiz());
	
	while(!C.vacia())
	{
		a1 = C.frente();
		C.pop();
		
		if(a1 != Abin<T>::NODO_NULO)
		{
			V.push_back(AbinA.elemento(a1));
			
			C.push(AbinA.HijoIzqdo(a1));
			C.push(AbinA.HijoDrcho(a1));
		}
	}
	return V;
}

std::vector<char> leer_inorden_llamada(const Abin<T> &AbinA)
{
	std::vector<char> V;
	leer_inorden(AbinA.raiz(), AbinA, V);
	
	return V;
}

void leer_inorden(typename Abin<T> nodo::a1, const Abin<T> &AbinA, std::vector<char> &V)
{
	if(a1 != Abin<T>::NODO_NULO)
	{
		return leer_inorden(AbinA.HijoIzqdo(a1), AbinA, *V);
		
		V.push_back(a1);
		
		return leer_inorden(AbinA.HijoDrcho(a1), AbinA, *V);
	}
}

//Ejercicio EXAMEN 3 Septiembre 2020

void construir_llamada(std::vector<char> &V)
{
	Abin<T> AbinA;
	int cont = 0, tam = V.size();
	
	AbinA.insertarRaiz(V[1]);
	cont++;
	
	construir(AbinA.raiz(), AbinA, V, cont, tam);
}

template <typename T> void construir(typename Abin<T> nodo::a1, Abin<T> AbinA, std::vector<char> &V, int &cont, int tam)
{
	Cola<typename Abin<T>::nodo> C;
	C.push(a1);
	
	while(C != C.vacio() && cont <= tam)
	{
		a1 = C.frente();
		C.pop();
		
		if(a1 != Abin<T>::NODO_NULO)
		{
			AbinA.insertarHijoIzqdo(a1, V[cont]);
			C.push(AbinA.HijoIzqdo(a1));
			cont++;
			
			if(cont <= tam)
			{
				AbinA.insertarHijoDrcho(a1, V[cont]);
				C.push(AbinA.HijoDrcho(a1));
				cont++;	
			}
			
		}
	}
}

std::vector<char> descifrar_llamada(const Abin<T> &A)
{
	std::vector<char> V;
	
	descifrar_rec(AbinA.raiz(), AbinA, V);
	
	return V;
}

template <typename T> std::vector<char> descifrar_rec(typename Abin<T> nodo::a1, const Abin<T> &AbinA)
{
	if(a1 != Abin<T>::NODO_NULO)
	{
		V.push_back(AbinA.elemento(a1));
		return descifrar_rec(AbinA.HijoIzqdo(a1), AbinA, V);
		return descifrar_rec(AbinA.HijoDrcho(a1), AbinA, V);
	}
}


//Ejercicio Examen 2020 Mayo

bool funcion_llamada(const Abin<T> &AbinA, std::vector<bool> V)
{
	int cont = 0;
	
	if(AbinA.arbolVacio() != true) return funcion_rec(AbinA.raiz(), AbinA, V, n, cont);
	else return false;
}

template <typename T> bool funcion_llamada(typename Abin<T> nodo::a1, const Abin<T> &AbinA, std::vector<bool> &V, int cont)
{
	if(a1 != Abin<T>::NODO_NULO)
	{
		if(AbinA.HijoIzqdo(a1) == Abin<T>::NODO_NULO || AbinA.HijoDrcho(a1) == Abin<T>::NODO_NULO)//si alguno de los hijos es nulo
		{
			if(AbinA.HijoIzqdo(a1) == Abin<T>::NODO_NULO && AbinA.HijoDrcho(a1) == Abin<T>::NODO_NULO)//si es un nodo hoja
			{
				cont++;
				return V[cont - 1];//retorna la posicion actual del vector -1 que corresponde a la actual
			}
			
			if(AbinA.HijoIzqdo(a1) == Abin<T>::NODO_NULO)//si no es nodo hoja pero solo tiene hijo derecho
			{
				return !AbinA.HijoDrcho(a1);	
			}
			
			if(AbinA.HIjoDrcho(a1) == Abin<T>::NODO_NULO)//si no es nodo hoja pero solo tiene hijo izquierdo
			{
				return !AbinA.HijoIzqdo(a1);
			}
			
		}else{//si todos sus hijos son no nulos
			
			switch(AbinA.elemento(a1).signo)
			{
				case "Y": return funcion_rec(AbinA.HijoIzqdo(a1), AbinA, V, n, cont) && funcion_rec(AbinA.HijoIzqdo(a1), AbinA, V, cont);	
				break;
					
				case "O": return funcion_rec(AbinA.HijoIzqdo(a1), AbinA, V, n, cont) || funcion_rec(AbinA.HijoDrcho(a1), AbinA, V, cont);
				break;
			}
		}
	}
}

struct Elemento{
	char signo;
	int indice;
};

template <typename T> bool funcion_llamada(typename Abin<T> nodo::a1, const Abin<T> &AbinA, std::vector<bool> &V)
{
	if(AbinA.HijoIzqdo(a1) == Abin<T>::NODO_NULO && AbinA.HijoDrcho(a1) == Abin<T>::NODO_NULO)
	{
		return V[AbinA.elemento(a1).indice];
		
	}else{
		
		switch(AbinA.elemento(a1).signo)
		{
			case "Y": return funcion_rec(AbinA.HijoIzqdo(a1), AbinA, V, n, cont) && funcion_rec(AbinA.HijoIzqdo(a1), AbinA, V, cont);	
			break;
				
			case "O": return funcion_rec(AbinA.HijoIzqdo(a1), AbinA, V, n, cont) || funcion_rec(AbinA.HijoDrcho(a1), AbinA, V, cont);
			break;
				
			case "NO": if(AbinA.HijoIzqdo(a1) == Abin<T>::NODO_NULO) return !AbinA.HijoDrcho(a1);
			break;
				
			case "NO": if(AbinA.HIjoDrcho(a1) == Abin<T>::NODO_NULO) return !AbinA.HijoIzqdo(a1);
			break;
		
			}

	}
}



/////////////////////////////////////Repeat///////////////////////////////////////////////////
bool similares_llamada(const Abin<T> &Aa, const Abin<T> &Ab)
{
	if(Aa.arbolVacio() == true && Ab.arbolVacio() == true) return true;
	else return similares_rec(Aa.raiz(), Aa, Ab.raiz(), Ab);
}

template <typename T> bool similares_rec(typename Abin<T>::nodo n1, const Abin<T> &Aa, typename Abin<T>::nodo n2, const Abin<T> &Ab)
{
	if(n1 !== Abin<T>::NODO_NULO || n2 == Abin<T>::NODO_NULO)
	{
		if(n1 == Abin<T>::NODO_NULO && n2 == Abin<T>::NODO_NULO)
		{
			return true;
		}else{
			return false;
		}
	}else{
		return similares_rec(Aa.HijoIzqdo(n1), Aa, Ab.HijoIzqdo(n2), Ab) && similares_rec(Aa.HijoDrcho(n1), Aa, Ab.HijoDrcho(n2), Ab);
	}
	
}



//Nodos Verdes//////////
int nodos_verdes_llamada(const Abin<T> &AbinA)
{
	if(AbinA.arbolVacio() == true)
	{
		return 0;
	}else{
		return nodos_verdes_rec(AbinA.raiz(), AbinA);
	}
}

template <typename T> int nodos_verdes_rec(typename Abin<T>::nodo n1, const Abin<T> &AbinA)
{
	if(n1 != Abin<T>::NODO_NULO)
	{
		if(nodo_verde(n1, AbinA) == true)
		{
			return 1 + nodos_verdes_rec(AbinA.HijoIzqdo(n1), AbinA) + nodos_verdes_rec(AbinA.HijoDrcho(n1), AbinA);
		}else{
			return nodos_verdes_rec(AbinA.HijoIzqdo(n1), AbinA) + nodos_verdes_rec(AbinA.HijoDrcho(n1), AbinA);
		}
	}else{
		return 0;
	}
}

bool nodo_verde (typename Abin<T>::nodo n1, const Abin<T> &AbinA)
{
	int cont = 0;
	
	if(AbinA.HijoIzqdo(AbinA.HijoIzqdo(n1)) != Abin<T>::NODO_NULO) cont++;
	if(AbinA.HijoDrcho(AbinA.HijoIzqdo(n1)) != Abin<T>::NODO_NULO) cont++;
	if(AbinA.HijoIzqdo(AbinA.HijoDrcho(n1)) != Abin<T>::NODO_NULO) cont++;
	if(AbinA.HijoDrcho(AbinA.HijoDrcho(n1)) != Abin<T>::NODO_NULO) cont++;
	
	if(cont == 3) return true;
	else return false;
}


//nodos nostalgicos//
int nodos_nos_llamada(const Abin<T> &AbinA)
{
	if(AbinA.arbolVacio() == true)
	{
		return 0;
	}else{
		return nodos_nos_rec(AbinA.raiz(), AbinA);
	}
}

template <typename T> int nodos_nos_rec(typename Abin<T>::nodo n1, const Abin<T> &AbinA)
{
	if(n1 != Abin<T>::NODO_NULO)
	{
		if(nodo_nos(n1, AbinA) == true)
		{
			return 1 + nodos_nos_rec(AbinA.HijoIzqdo(n1), AbinA) + nodos_nos_rec(AbinA.HijoDrcho(n1), AbinA);
		}else{
			return nodos_nos_rec(AbinA.HijoIzqdo(n1), AbinA) + nodos_nos_rec(AbinA.HijoDrcho(n1), AbinA);
		}
	}else{
		return 0;
	}
}

bool nodo_nos (typename Abin<T>::nodo n1, const Abin<T> &AbinA)
{
	if(num_antepasados(n1, AbinA) > num_descendientes(n1, AbinA) - 1)
	{
		return true;
	}else{
		return false;
	}
}

int num_antepasados(typename Abin<T>::nodo n1, const Abin<T> &AbinA)
{
	if(n1 != Abin<T>::NODO_NULO)
	{
		return 1 + num_antepasados(AbinA.padre(n1), AbinA);
	}else{
		return -1;
	}
}

int num_descendientes(typename Abin<T>::nodo n1, const Abin<T> &AbinA)
{
	if(n1 != Abin<T>::NODO_NULO)
	{
		return 1 + num_descendientes(AbinA.HijoIzqdo(n1), AbinA) + num_descendientes(AbinA.HijoDrcho(n1), AbinA)
	}else{
		return 0;
	}
}



//arboles similares

bool similares_llamada(const Abin<T> &AbinA, const Abin<T> &AbinB)
{
	if(AbinA.arbolVacio() == true && AbinB.arbolVacio() == true) return true;
	else return similares_rec(AbinA.raiz(), AbinA, AbinB.raiz(), AbinB);
}

template <typename T> bool similares_rec(typename Abin<T>::nodo a1, const Abin<T> &AbinA, typename Abin<T>::nodo a1, const Abin<T> &AbinB)
{
	if(a1 == Abin<T>::NUO_NULO || a2 == Abin<T>::NODO_NULO)
	{
		if(a1 == Abin<T>::NUO_NULO && a2 == Abin<T>::NODO_NULO) return true;
		else return false;
	}else{
		return similares_rec(AbinA.HijoIzqdo(a1), AbinA, AbinB.HijoIzqdo(a1), AbinB) && similares_rec(AbinA.HijoDrcho(a1), AbinA, AbinB.HijoDrcho(a1), AbinB);
	}
}

//arbol espejo

Abin<T> espejo_llamada(const Abin<T> &AbinA)
{
	
	AbinB = Abin();
	
	if(AbinA.arbolVacio() == true) return AbinB;
	else{
		
		AbinB.insertarraiz(AbinA.raiz());
		espejo_rec(AbinA.raiz(), AbinA, AbinB.raiz(), AbinB);
		
		return AbinB;
		
	}
}


template <typename T> void espejo_rec(typename Abin<T>::nodo a1, const Abin<T> &AbinA, typename Abin<T>::nodo a2, Abin<T> &AbinB)
{
	if(a1 != Abin<T>::NODO_NULO)
	{
		if(AbinA.HijoIzqdo(a1) != Abin<T>::NDOO_NULO)
		{
			AbinB.insertarHijoDrcho(a2);
			return espejo_rec(AbinA.HijoIzqdo(a1), AbinA, AbinB.HijoDrcho(a2), AbinB);
		}
		if(AbinA.HijoDrcho(a1) != Abin<T>::NODO_NULO)
		{
			AbinB.insertarHijoIzqdo(a2);
			return espejo_rec(AbinA.HijoDrcho(a1), AbinA, AbinB.HijoIzqdo(a2), AbinB);
		}
	}
}



//vector y proposciones

union elemento{
	int posicion_vector;
	char signo;
};

template<typename elemento> bool proposicion_llamada(std::vector<bool> V, const Abin<elemento> &AbinA)
{
	if(AbinA.arbolVacio() == true) return false;
	else return proposicion_rec(V, AbinA.raiz(), AbinA);
}

template<typename elemento> bool proposicion_rec(std::vector<char> V, typename Abin<elemento>::nodo a1, const Abin<elemento> &AbinA)
{
	if(AbinA.HijoIzqdo(a1) == Abin<T>::NODO_NULO && AbinA.HijoDrcho(a1) == Abin<T>::NODO_NULO)
	{
		return V[AbinA.elemento(a1).posicion_vector];
	}else{
		swtich(AbinA.elemento(a1).signo)
		{
			case "Y": return proposicion(V, AbinA.HijoIzqdo(a1), AbinA) && proposicion(V, AbinA.HijoDrcho(a1), AbinA);
			break;
			case "O": return proposicion(V, AbinA.HijoIzqdo(a1), AbinA) || proposicion(V, AbinA.HijoDrcho(a1), AbinA);
			break;
			case "N": if(AbinA.HijoIzqdo(a1) == Abin<T>::NODO_NULO) return !proposicion_rec(V, AbinA.HijoDrcho(a1), AbinA);
						else return !proposicion_rec(V, AbinA.HijoIzqdo(a1), AbinA);
			break;
		}
	}
}



//Eliminar descendientes de nodos con un solo hijo

template<typename T> void funcion_llamada(Abin<T> &AbinA)
{
	if(AbinA.arbolVacio() != true) funcion_rec(AbinA.raiz(), AbinA);
}


template<typename T> void funcion_rec(typename Abin<T>::nodo a1, Abin<T> &AbinA)
{
	if(a1 != Abin<T>::NODO_NULO)
	{
		if((AbinA.hijoIzqdo(a1) == Abin<T>::NODO_NULO && AbinA.hijoDrcho(a1) != Abin<T>::NODO_NULO) ||
			AbinA.hijoIzqdo(a1) != Abin<T>::NODO_NULO && AbinA.hijoDrcho(a1) == Abin<T>::NODO_NULO)
			{
				
				eliminar(a1, AbinA);
				
			}else{
				
				funcion_rec(AbinA.hijoIzqdo(a1), AbinA);
				funcion_rec(AbinA.hijoDrcho(a1), AbinA);
				
			}
	}
}

template<typename T> void eliminar(typename Abin<T>::nodo a1, Abin<T> &AbinA)
{
	if(a1 != Abin<T>::NODO_NULO)
	{
		eliminar(AbinA.hijoIzqdo(a1), AbinA);
		eliminar(AbinA.hijoDrcho(a1), AbinA);
		
		if(AbinA.hijoIzqdo(a1) != Abin<T>::NODO_NULO) AbinA.eliminarHijoIzqdo(a1);
		if(AbinA.hijoDrcho(a1) != Abin<T>::NODO_NULO) AbinA.eliminarHijoDrcho(a1);
	}
}


//Ejercicio parcial 1: Contar descendientes: 'Dado un árbol binario, contar el
//número de nodos de dicho árbol que tienen 4
//descendientes.

template<typename T> int funcion_llamada(const Abin<T> &AbinA)
{
	if(AbinA.arbolVacio() == true)
	{
		return 0;
	}else{
		return funcion_rec(AbinA.raiz(), AbinA);
	}
}

template<typename T> int funcion_rec(typename Abin<T>::nodo a1, const Abin<T> &AbinA)
{
	if(a1 != Abin<T>::NODO_NULO)
	{
		if(num_descendientes(a1, AbinA) - 1 == 4)
		{
			
			return 1 + funcion_rec(AbinA.hijoIzqdo(a1), AbinA) + funcion_rec(AbinA.hijoDrcho(a1), AbinA);
			
		}else{
			
			return funcion_rec(AbinA.hijoIzqdo(a1), AbinA) + funcion_rec(AbinA.hijoDrcho(a1), AbinA);
			
		}
	}else return 0;
}

template<typename T> int num_descendientes(typename Abin<T>::nodo a1, const Abin<T> &AbinA)
{
	if(a1 != Abin<T>::NODO_NULO)
	{
		return 1 + num_descendientes(AbinA.hijoIzqdo(a1), AbinA) + num_descendientes(AbinA.hijoDrcho(a1), AbinA);
	}else{
		return 0;
	}
}



//Ejercicio Nodos Rebeldes

template<typename bool> int nodos_rebeldes_llamada(const Abin<bool> &AbinA)
{
	if(AbinA.arbolVacio() == true)
	{
		return 0;
	}else{
		return nodos_rebeldes_rec(AbinA.raiz(), AbinA);
	}
}

template<typename bool> int nodos_rebeldes_rec(typename Abin<bool>::nodo a1, const Abin<bool> &AbinA)
{
	if(a1 != Abin<bool>::NODO_NULO)
	{
		switch(AbinA.elemento(a1))
		{
			case true: if((cont_true_antepasados(a1, AbinA) - 1) + ((cont_true_descendientes(a1, AbinA) - 1)) < cont_false_antepasados(a1, AbinA) + cont_false_descendientes(a1, AbinA))
						{
							return 1 + nodos_rebeldes_rec(AbinA.hijoIzqdo(a1), AbinA) + nodos_rebeldes_rec(AbinA.hijoDrcho(a1), AbinA);
						}else{
							return nodos_rebeldes_rec(AbinA.hijoIzqdo(a1), AbinA) + nodos_rebeldes_rec(AbinA.hijoDrcho(a1), AbinA);
						}
			break;
			
			case false:  if((cont_false_antepasados(a1, AbinA) - 1) + ((cont_false_descendientes(a1, AbinA) - 1)) < cont_true_antepasados(a1, AbinA) + cont_true_descendientes(a1, AbinA))
						{
							return 1 + nodos_rebeldes_rec(AbinA.hijoIzqdo(a1), AbinA) + nodos_rebeldes_rec(AbinA.hijoDrcho(a1), AbinA);
						}else{
							return nodos_rebeldes_rec(AbinA.hijoIzqdo(a1), AbinA) + nodos_rebeldes_rec(AbinA.hijoDrcho(a1), AbinA);
						}
			break;
		}
	}else{
		return 0;
	}
}


template<typename bool> int cont_true_antepasados(typename Abin<bool>::nodo a1, const Abin<bool> &AbinA)
{
	if(a1 != Abin<bool>::NODO_NULO)
	{
		if(AbinA.elemento(a1) == true)
		{
			return 1 + AbinA.padre(a1);
		}else{
			return AbinA.padre(a1);
		}
		
	}else{
		return 0;
	}
}

template<typename bool> int cont_false_antepasados(typename Abin<bool>::nodo a1, const Abin<bool> &AbinA)
{
	if(a1 != Abin<bool>::NODO_NULO)
	{
		if(AbinA.elemento(a1) == false)
		{
			return 1 + AbinA.padre(a1);
		}else{
			return AbinA.padre(a1);
		}
		
	}else{
		return 0;
	}
}

template<typename bool> int cont_true_descendientes(typename Abin<bool>::nodo a1, const Abin<bool> &AbinA)
{
	if(a1 != Abin<bool>::NODO_NULO)
	{
		if(AbinA.elemento(a1) == true)
		{
			return 1 + AbinA.hijoIzqdo(a1) + AbinA.hijoDrcho(a1);
		}else{
			return AbinA.hijoIzqdo(a1) + AbinA.hijoDrcho(a1);
		}
		
	}else{
		return 0;
	}
}

template<typename bool> int cont_false_descendientes(typename Abin<bool>::nodo a1, const Abin<bool> &AbinA)
{
	if(a1 != Abin<bool>::NODO_NULO)
	{
		if(AbinA.elemento(a1) == false)
		{
			return 1 + AbinA.hijoIzqdo(a1) + AbinA.hijoDrcho(a1);
		}else{
			return AbinA.hijoIzqdo(a1) + AbinA.hijoDrcho(a1);
		}
		
	}else{
		return 0;
	}
}



std::vector<char> descifrar(typename Abin<char>::nodo n, const Abin<char> &AbinA)
{
	Cola<Abin<char>::nodo> C;
	std::vector<char> V;
	
	C.push(AbinA.raiz());
	
	while(!C.vacia())
	{
		n = C.frente();
		C.pop();
		V.push_back(AbinA.elemento(n));
		
		if(n != Abin<char>::NODO_NULO)
		{
			C.push(AbinA.hijoIzqdo(n));
			C.push(AbinA.hijoDrcho(n));
		}
	}
	
	return V;
}


//Ejercicio nodos rebeldes

int num_rebeldes_llamada(const Abin<bool> &AbinA)
{
	if(AbinA.arbolVacio() == true)
	{
		return 0;
	}else{
		return num_arbol_llamadA(AbinA.raiz(), AbinA);
	}
}

int num_rebeldes_rec(Abin<bool>::nodo n, const Abin<bool> &abinA)
{
	if(n != Abin<bool>::NODO_NULO)
	{
		switch(AbinA.elemento(n))
		{
			case true: if(num_true(n, AbinA) - 1 < num_false(n, AbinA))
			{
				return 1 + num_rebeldes_rec(AbinA.hijoIzqdo(n), AbinA) + num_rebeldes_rec(AbinA.hijoDrcho(n), AbinA);
			}else{
				return num_rebeldes_rec(AbinA.hijoIzqdo(n), AbinA) + num_rebeldes_rec(AbinA.hijoDrcho(n), AbinA);
			}
			break;
			
			case false: if(num_true(n, AbinA) > num_false(n, AbinA) - 1)
			{
				return 1 + num_rebeldes_rec(AbinA.hijoIzqdo(n), AbinA) + num_rebeldes_rec(AbinA.hijoDrcho(n), AbinA);
			}else{
				return num_rebeldes_rec(AbinA.hijoIzqdo(n), AbinA) + num_rebeldes_rec(AbinA.hijoDrcho(n), AbinA);
			}
			break;
		}
	}else{
		return 0;
	}
}

int num_false(Abin<bool>::nodo n, const Abin<bool> &abinA)
{
	if(n != Abin<bool>::NODO_NULO)
	{
		if(AbinA.elemento(n) == false)
		{
			return 1 + num_false(AbinA.padre(n), AbinA);
		}else{
			return num_false(AbinA.padre(n), AbinA);
		}
	}else{
		return 0;
	}
}

int num_true(Abin<bool>::nodo n, const Abin<bool> &abinA)
{
	if(n != Abin<bool>::NODO_NULO)
	{
		if(AbinA.elemento(n) == true)
		{
			return 1 + num_false(AbinA.padre(n), AbinA);
		}else{
			return num_false(AbinA.padre(n), AbinA);
		}
	}else{
		return 0;
	}
}

//Ejercicio Nodos 4 descendientes

template<typename T> int num_nodos(typename Abin<T>::nodo n, const Abin<T> &AbinA)
{
	if(AbinA.arbolVacio() == true)
	{
		return 0;
	}else{
		return num_nodosrec(AbinA.raiz(), AbinA);
	}
}

template<typename T> int num_nodosrec(typename Abin<T>::nodo n, const Abin<T> &AbinA)
{
	if(n != Abin<T>::NODO_NULO)
	{
		if(num_descendientes(n, AbinA) - 1 == 4)
		{
			return 1 + num_nodosrec(AbinA.hijoIzqdo(n), AbinA) + num_nodosrec(AbinA.hijoDrcho(n), AbinA);
		}else{
			return num_nodosrec(AbinA.hijoIzqdo(n), AbinA) + num_nodosrec(AbinA.hijoDrcho(n), AbinA);
		}
	}else{
		return 0;
	}
}

template<typename T> int num_descendientes(typename Abin<T>::nodo n, const Abin<T> &AbinA)
{
	if(n != Abin<T>::NODO_NULO)
	{
		return 1 + num_descendientes(AbinA.hijoIzqdo(n), AbinA) + num_descendientes(AbinA.hijoDrcho(n), AbinA);
	}else{
		return 0;
	}
}



//circular anchura

template<typename T> void recorrido(typename Abin<T>::nodo n, const Abin<T> &AbinA)
{
	Cola<Abin<T>::nodo> C;
	C.push(AbinA.raiz());
}






template<typename T> int altura(template Agen<T>::nodo n, const Agen<T> &A)
{
	if(n != Agen<T>::NODO_NULO)
	{
		Agen<T>::nodo hijo = A.hijoIzqdo(n);
		
		while(n != Agen<T>::NODO_NULO)
		{
			return 1 + max(altura(hijo, A), altura(A.hermanoDrcho(hijo), A));
			hijo = A.hermanoDrcho(hijo);
		}
	}else{
		return -1;
	}
}















