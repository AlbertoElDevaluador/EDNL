#include <iostream>
struct carretera{
    typename GrafosP<tCoste>::vertice v1;
    typename GrafosP<tCoste>::vertice v2;
}

using namespace std;
/*
Se hace dijkstra dos veces para poder obtener depsuede haber eliminado(hacer infinito) las ciudades y carreteras cortadas para saber la distancia entre
un sitio y la capital(dijkstra normal) y desde la capital hasta la ciudad destino(dijkstraInv).
*/
template <typename tCoste>
void funcion_llamada(typename GrafoP<tCoste>&G, vector<typename GrafoP<tCoste>::vertice> Ciudades_tomadas, vector<carretera> carreteras_tomadas, 
typename GrafoP<tCoste>::vertice capital)
{

    for(carretera c : carreteras_tomadas)//eliminamos las carreteras que han sido destruidas.
    {
        G[c.v1][c.v2] = GrafoP<tCoste>::INFINITO;
    }
    
    for(GradoP<tCoste>::vertice ciudad_tomada : Ciudades_tomadas)//eliminamos los caminos que vayan a las ciudades tomadas.
    {
        for(int j = 0; j < G.numVert(); j++)
        {
            G[ciudad_tomada][j] = GrafoP<tCoste>::INFINITO;
        }

        for(j = 0; j< G.numVert(); j++)
        {
            G[j][ciudad_tomada] = GrafoP<tCoste>::INFINITO;
        }
    }

    //llamada Dijkstra
    vector<GrafoP<tCoste>::vertice> p;
    vector<tCoste> distancia_ciudades_capital = Dijkstra(G, capital, p);

    vector<GrafoP<tCoste>::vertice> c;
    vector<tCoste> distancia_capital_ciudades = DijkstraInv(G, capital, c);


    for(int i = 0; i < G.numVert(); i++)
    {
        for(j = 0; j < G.numVert(); j++)
        {
            if(G[i][j] != GrafoP<tCoste>::INFINITO)
            {
                G[i][j] = distancia_ciudades_capital[i] + distancia_capital_ciudades[j];
            }

            if(i == j) G[i][j] == GrafoP<tCoste>::INFINITO;
        }
    }
}


/*
Definiremos el pseudocentro de un grafo conexo como el nodo del mismo que
minimiza la suma de las distancias mínimas a sus dos nodos más alejados. Definiremos
el diámetro del grafo como la suma de las distancias mínimas a los dos nodos más
alejados del pseudocentro del grafo.
 Dado un grafo conexo representado mediante matriz de costes, implementa un
subprograma que devuelva la longitud de su diámetro.
*/
template <typename tCoste>
int longitud(typename GrafoP<tCoste>&G)
{
    std::vector<typename GrafoP<tCoste>::vertice> p;
    std::vector<typename GrafoP<tCoste>::vertice> distancia_minima;
    int min = 0, nodo = 0;

    for(int i = 0; i < G.numVert(); i++)
    {
        distancia_minima = Dijkstra(g, i, p);
        std::sort(distancia_minima.begin(), distancia_minima.end());
        if(min > distancia_minima[G.numVert - 1] + distancia_minima[G.numVert - 2])
        {
            min = distancia_minima[G.numVert - 1] + distancia_minima[G.numVert - 2];
            nodo = i;//siendo i cuando termine el bucle el psedocentro
        }
    }

    return min;
}

/*
3. Tu empresa de transportes “PEROTRAVEZUNGRAFO S.A.” acaba de recibir la
lista de posibles subvenciones del Ministerio de Fomento en la que una de las más
jugosas se concede a las empresas cuyo grafo asociado a su matriz de costes sea
acíclico. ¿Puedes pedir esta subvención?
 Implementa un subprograma que a partir de la matriz de costes nos indique si tu
empresa tiene derecho a dicha subvención. 
*/
//aciclico quiere decir que no haya mas de un camino hacia un vertice
//Para ello miraremos que asabiendo que es una matriz de costes, observaremos si por cada fila existe mas de un camino que llegue a ese vertice en concreto
template <typename tCoste>
bool podemos_subvencion(typename GrafoP<tCoste>&G)
{/*
    bool aciclico = false;
    int contador_caminos = 0;

    for(int i = 0; i < G.numVert() && aciclico == false; i++)
    {
        contador_caminos = 0;

        for(int j = 0; j < G.numVert(); j++)
        {
            if(G[i][j] != GrafoP<tCoste>::INFINITO) contador_camino++;
        }

        if(contador_caminos > 2) aciclico = true;
    }

    return aciclico; */

    //si podemos podar todos los nodos que se podan al ser hojas se puede
    for(int i = 0; i < G.numVert(); i++)
    {
        if(nodo_hoja(i, G)) poda(i, G);
    }

    if(existe_nodo(G)) return false;
    else return true;
}

template <typename T>
bool nodo_hoja(int i, typename GrafoP<tCoste>&G)
{
    bool hoja = true;

    for(int j = 0; j < G.numVert && hoja == false; j++)
    {
        if(G[i][j] != GrafoP<tCoste>::INFINITO) hoja = false
    }

    return hoja;
}
template <typename T>
void poda(int i, typename GrafoP<tCoste>&G)
{
    for(j = 0; j < G.numVert(); j++)
    {
        G[j][i] = Grafo<tCoste>::INFINITO;
        if(nodo_hoja(j, G)) poda(j, G);
    }
}


/*
1. Tu agencia de viajes “OTRAVEZUNGRAFO S.A.” se enfrenta a un curioso cliente.
Es un personaje sorprendente, no le importa el dinero y quiere hacer el viaje más caro
posible entre las ciudades que ofertas. Su objetivo es gastarse la mayor cantidad de
dinero posible (ojalá todos los clientes fueran así), no le importa el origen ni el destino
del viaje.
Sabiendo que es imposible pasar dos veces por la misma ciudad, ya que casualmente
el grafo de tu agencia de viajes resultó ser acíclico, devolver el coste, origen y destino
de tan curioso viaje. Se parte de la matriz de costes directos entre las ciudades del grafo. 
*/
//quiere el mayor coste
//Para ello modificaremos floyd para obtener los maximos en vez de los minimos.

template <typename tCoste>
int coste (typename GrafoP<tCoste>&G)
{
    for(int i = 0; i < G.numVert(); i++)//hacemos a 0 todos los ccaminos no conexos (actualmente inifinitos) ya que vamos a coger los de mayor coste.
    {
        for(int j = 0; j < G.numVert(); j++)
        {
            if(G[i][j] == GrafoP<tCoste>::INFINITO) G[i][j] = 0;
        }
    }//preparamos la matriz para que no coja los infinitos.

    matriz<typename GrafoP<tCoste>::vertice> M;
    matriz<typename GrafoP<tCoste>::vertice> R = Floyd(G, M);//llamamos a Floyd y nos devuelve la matriz de coste con los mayores costes para viajar
    //entre ciudades.

    int max = 0;

    for(int i = 0; i < G.numVert(); i++)
    {
        for(int j = 0; j < G.numVert(); j++)
        {
            if(G[i][j] > max) max = G[i][j];
        }
    }

    return max;
}


template <typename tCoste>
matriz<tCoste> Floyd(const GrafoP<tCoste>& G, matriz<typename GrafoP<tCoste>::vertice>& P)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t n = G.numVert();
    matriz<tCoste> A(n); // matriz de costes mínimos
    // Iniciar A y P con caminos directos entre cada par de vértices.
    P = matriz<vertice>(n);
    for (vertice i = 0; i <= n-1; i++) {
    A[i] = G[i]; // copia costes del grafo
    A[i][i] = GrafoP<tCoste>::INFINITO; // diagonal a infinito CSMBIO REALIZADO POR MI
    P[i] = vector<vertice>(n, i); // caminos directos
    }
    // Calcular costes mínimos y caminos correspondientes
    // entre cualquier par de vértices i, j
    for (vertice k = 0; k <= n-1; k++)
        for (vertice i = 0; i <= n-1; i++)
            for (vertice j = 0; j <= n-1; j++) {
                A[i][j] = max(A[i][j], A[i][k] + A[k][j]);
    }
    return A;
}


/*
Se dispone de un laberinto de NxN casillas del que se conocen las casillas de entrada
y salida del mismo. Si te encuentras en una casilla sólo puedes moverte en las siguientes
cuatro direcciones (arriba, abajo, derecha, izquierda). Por otra parte, entre algunas de las
casillas hay una pared que impide moverse entre las dos casillas que separa dicha pared
(en caso contrario no sería un verdadero laberinto).
Implementa un subprograma que dados
     N (dimensión del laberinto),
     la lista de paredes del laberinto,
     la casilla de entrada, y
     la casilla de salida, Calcule el camino más corto para ir de la entrada a la salida y su longitud
*/
using namespace std;

struct paredes{
    typename GrafoP<tCoste>::vertice v1;
    typename GrafoP<tCoste>::vertice v2;
}
//N*X + Y casilla to nodo
//
template <typename tCoste>
vector<tCoste> camino(int N, vector<paredes> paredes_vec, int entrada, int salida, int &longitud)
{
    //lo primmero que haremos sera crear el tablero del laberinto
    typename GrafoP<tCoste> G(N*N);
    int casilla = 0;
    for(int i = 0; i < N*N; i++)
    {
        for(int j = 0; j < N*N; j++)
        {
            casilla = coord_to_casilla(i, j, N);
            if(i - 1 >= 0) G[casilla][coord_to_casilla(i - 1, j,  N)] = 1;
            if(j - 1 >= 0) G[casilla][coord_to_casilla(i, j - 1, N)] = 1; 
            if(j + 1 < N) G[casilla][coord_to_casilla(i, j + 1, N)] = 1;
            if(i + 1 < N) G[casilla][coord_to_casilla(i + 1, j, N)] = 1;
        }
    }

    //ahora pondremos las paredes
    for(paredes p : paredes_vec)
    {
        G[p.v1][p.v2] = typename GrafoP<tCoste>::INFINITO;
        G[p.v2][p.v1] = typename GrafoP<tCoste>::INFINITO;
    }

    vector<typename GrafoP<tCoste>::vertice> P(N*N);
    vector<tCoste> vector_dijkstra(N * N) = Dijkstra(G, entrada, P);

    vector<typename GrafoP<tCoste>::vertice> solucion;
    for(i = salida; i < P.size(); i--)
    {
        solucion.push_back(P[i]);
    }

    return solucion;
}

int coord_to_casilla(int x, int y, int N)
{
    return x * N + y;
}

/*
    Eres el orgulloso dueño de una empresa de distribución. Tu misión radica en
distribuir todo tu stock entre las diferentes ciudades en las que tu empresa dispone de
almacén.
    Tienes un grafo representado mediante la matriz de costes, en el que aparece el coste
(por unidad de producto) de transportar los productos entre las diferentes ciudades del
grafo.
    Pero además resulta que los Ayuntamientos de las diferentes ciudades en las que
tienes almacén están muy interesados en que almacenes tus productos en ellas, por lo
que están dispuestos a subvencionarte con un porcentaje de los gastos mínimos de
transporte hasta la ciudad. Para facilitar el problema, consideraremos despreciables los
costes de volver el camión a su base (centro de producción).
He aquí tu problema. Dispones de
     el centro de producción, nodo origen en el que tienes tu producto (no tiene
    almacén),
     una cantidad de unidades de producto (cantidad),
     la matriz de costes del grafo de distribución con N ciudades,
     la capacidad de almacenamiento de cada una de ellas,
     el porcentaje de subvención (sobre los gastos mínimos) que te ofrece cada
    Ayuntamiento.
    Las diferentes ciudades (almacenes) pueden tener distinta capacidad, y además la
capacidad total puede ser superior a la cantidad disponible de producto, por lo que
debes decidir cuántas unidades de producto almacenas en cada una de las ciudades.
Debes tener en cuenta además las subvenciones que recibirás de los diferentes
    Ayuntamientos, las cuales pueden ser distintas en cada uno y estarán entre el 0% y el
100% de los costes mínimos.
La solución del problema debe incluir las cantidades a almacenar en cada ciudad bajo
estas condiciones y el coste mínimo total de la operación de distribución para tu
empresa. 
*/

//tiene matriz de coste de transportar mercancia entre ciudades(x unidades)

template <typename tCoste>
int coste_minimo_total(typename GrafoP<tCoste>::vertice centro_produccion, int cantidad_productos, typename GrafoP<tCoste> G
vector<int> capacidad_ciudades, vector<int> subvenciones, int &coste_total)
{
    //queremos transportar una cantidad de productos determinada, luego lo que haremos sera 
    //lo primero que haremos sera eliminar (hacer infinito) aquellas ciudades que tengan una capacidad de alamcenaje inferior que la que queremos llevar
    for(i = 0; i < G.numVert(); i++)//aplicamos las subvenciones por llegar a la ciudad.
    {
        for(j = 0; j < G.numVert(); j++)
        {//de la forma G[j][i]
            G[j][i] = G[j][i] * (subvenciones[i] / 100);
        }
    }

    vector<tCoste>::vertice> P(G.numVert());
    vector<tCoste> vector_dijkstra = Dijkstra(G, centor_produccion, P);

    vector<int> cantidades_dep(G.numVert(), 0);
    std::vector<bool> V_can(G.numVert(), true);
    int candidato;

    while(cantidad_productos > 0)//vemos en funcion del coste donde dejar la mercancia
    {
        candidato = seleccion(vector_dijkstra, V_can)//cogeremos el menor
        V_can[candidato] = false;
        //depositamos la cantidad en la ciudad
        if(capacidad_ciudades[candidato] - cantidad_productos >= 0)
        {
            cantidades_dep[candidato] = capacidad_ciudades[candidato] - cantidad_productos;
        }
    }

    for(i = 0; i < G.numVert(); i++)//sacamos el coste total del tramite
    {
        if(cantidades_dep[i] != 0)
        {
            coste_total = coste_total + vector_dijkstra[i];
        }
    }

    return V_can;
}

int seleccion(vector<tCoste> vector_dijkstra, vector<bool> &V_can)
{
    int min = 0, candidato = 0;
    for(int i = 0; i < G.numVert(); i++)
    {
        if(V_can[i] != false)
        {
            if(min > vector_dijkstra[i])
            {
                min = vector_dijkstra[i];
                candidato = i;
            }
        }
    }
}


/*
4. Eres el orgulloso dueño de la empresa “Cementos de Zuelandia S.A”. Empresa
dedicada a la fabricación y distribución de cemento, sita en la capital de Zuelandia. Para
la distribución del cemento entre tus diferentes clientes (ciudades de Zuelandia)
dispones de una flota de camiones y de una plantilla de conductores zuelandeses.
El problema a resolver tiene que ver con el carácter del zuelandés. El zuelandés es
una persona que se toma demasiadas “libertades” en su trabajo, de hecho, tienes
fundadas sospechas de que tus conductores utilizan los camiones de la empresa para
usos particulares (es decir indebidos, y a tu costa) por lo que quieres controlar los
kilómetros que recorren tus camiones. 

Todos los días se genera el parte de trabajo, en el que se incluyen el número de
cargas de cemento (1 carga = 1 camión lleno de cemento) que debes enviar a cada
cliente (cliente = ciudad de Zuelandia). Es innecesario indicar que no todos los días hay
que enviar cargas a todos los clientes, y además, puedes suponer razonablemente que tu
flota de camiones es capaz de hacer el trabajo diario.
Para la resolución del problema quizá sea interesante recordar que Zuelandia es un
país cuya especial orografía sólo permite que las carreteras tengan un sentido de
circulación.
Implementa una función que dado el grafo con las distancias directas entre las
diferentes ciudades zuelandesas, el parte de trabajo diario, y la capital de Zuelandia,
devuelva la distancia total en kilómetros que deben recorrer tus camiones en el día, para
que puedas descubrir si es cierto o no que usan tus camiones en actividades ajenas a la
empresa. 
*/
template <typename T>
int empresa_cemento(typename GrafoP<tCoste>&G, vector<int> v_parte, typename GrafoP<tCoste>::vertice capital)
{
    int total_km = 0;//los km totales recorridos entre todos los camiones
    //queremos devolver el coste en km totales
    //para ello deberemos 
    vector<typename GrafoP<tCoste>::vertice> P(G.numVert());
    //coste minimo entre la capital y el resto de ciudades dond hacer las entregas.
    vector<tCoste> capital_ciudades = Dijkstra(G, capital, P);

    //deberemos ahora obtener la distancia entre el resto de las ciudades y la capital
    vector<tCoste> ciudades_capital = DijkstraInv(G, capital, P);

    for(int i = 0; i < G.numVert(); i++)
    {
        total_km = total_km + (capital_ciudades[i] * v_parte[i]) + (ciudades_capital[i] * v_parte[i]);
        //total de kilometros recorridos = al total de kilometros + (la distancia entre la capital y la ciudad i * el numero de cargas que se llevan) + 
        //(la distancia entre la ciudad i y la capital * el numero de cargaas que se llevan)
    }

    return total_km;//total de km recorridos entre todos los camiones haciendo ida y vuelta.  
}

/*
Se dispone de tres grafos que representan la matriz de costes para viajes en un
determinado país pero por diferentes medios de transporte, por supuesto todos los grafos
tendrán el mismo número de nodos. El primer grafo representa los costes de ir por
carretera, el segundo en tren y el tercero en avión. Dado un viajero que dispone de una
determinada cantidad de dinero, que es alérgico a uno de los tres medios de transporte, y
que sale de una ciudad determinada, implementar un subprograma que determine las
ciudades a las que podría llegar nuestro infatigable viajero. 
*/

template <typename T>
vector<typename GrafoP<tCoste>::vertice> ciudaddes_visitadas(typename GrafoP<tCoste>&GC, typename GrafoP<tCoste>&GT, typename GrafoP<tCoste>&GA, char alergia,
typename GrafoP<tCoste>::vertice origen, float dinero)
{
    assert(alergia == "A" || alergia == "C" || alergia == "T");
    vector<typename GrafoP<tCoste>::vertice> ciudades_visitadas;

    switch(alergia)
    {
        case "A": funcion(ciudades_visitados, GC, GT, origen, dinero); break;

        case "C": funcion(ciudades_visitados, GA, GT, origen, dinero); break;

        case "T": funcion(ciudades_visitados, GA, GC, origen, dinero); break;
    }

    return ciudades_visitadas;
}

template <typename T>
vector<typename GrafoP<tCoste>::vertice> ciudaddes_visitadas(vector<typename GrafoP<tCoste>::vertice> &ciudades_visitadas, typename GrafoP<tCoste>&G1, typename GrafoP<tCoste>&G2, 
typename GrafoP<tCoste>::vertice origen, float dinero)
{
    vector<bool> candidatos(GT.numVert(), true);
    int min = typename GrafoP<tCoste>::INFINITO, min2 = typename GrafoP<tCoste>::INFINITO;
    int candidato = 0, candidato2 = 0;

    //metemos el origen dentro de la solucion y lo sacamos de candidatos.
    ciudades_visitadas.push_back(origen);
    candidatos[origen] = false;

    //haremos un bucle para buscar la mejor opcion y obtener las ciudades en funcion del coste
    while(dinero > 0)
    {
        for(int i = 0; i < G1.numVert(); i++)
        {
            if(candidatos[i] != false)
            {
                if(G1[origen][i] < min)
                {
                    candidato = i;
                    min = G1[origen][i]
                }
            }
        }//obtenemos la ciudad a la que podemos ir por el minimo coste posible de G1

        for(int i = 0; i < G1.numVert(); i++)
        {
            if(candidatos2[i] != false)
            {
                if(G2[origen][i] < min2)
                {
                    candidato2 = i;
                    min2 = G1[origen][i]
                }
            }
        }//obtenemos la ciudad a la que podemos ir por el minimo coste posible de G2

        if(min < min2)//si la obtenida en el medio 1 es menor que el medio 2 nos quedamos con su candidato y si no al reves
        {
            origen = candidato;
            ciudades_visitadas.push_back(origen);
            candidatos[origen] = false;
            dinero = dinero - min;
        }else{
            origen = candidato2;
            ciudades_visitadas.push_back(origen);
            candidatos[origen] = false;
            dinero = dinero - min2;
        }
    }
}

/*
. Disponemos de tres grafos (matriz de costes) que representan los costes directos de
viajar entre las ciudades de tres de las islas del archipiélago de las Huríes (Zuelandia).
Para poder viajar de una isla a otra se dispone de una serie de puentes que conectan
ciudades de las diferentes islas a un precio francamente asequible (por decisión del
Prefecto de las Huríes, el uso de los puentes es absolutamente gratuito).
Si el alumno desea simplificar el problema, puede numerar las N1 ciudades de la isla
1, del 0 al N1-1, las N2 ciudades de la isla 2, del N1 al N1+N2-1, y las N3 de la última, del
N1+ N2 al N1+N2+ N3-1.
Disponiendo de las tres matrices de costes directos de viajar dentro de cada una de
las islas, y la lista de puentes entre ciudades de las mismas, calculad los costes mínimos
de viajar entre cualesquiera dos ciudades de estas tres islas.
¡¡¡ QUE DISFRUTÉIS EL VIAJE !!!
*///EJERCICIO DE ISLAS Y PUENTES IMPORTANTE!!!!!
struct puente
{
    typename GrafoP<tCoste>::vertice v1;
    typename GrafoP<tCoste>::vertice v2;

}

template <typename T>
matriz<tCoste> calculo(typename GrafoP<tCoste>&Isla1, typename GrafoP<tCoste>&Isla2, typename GrafoP<tCoste>&Isla3, vector<puente> puentes)
{
    GrafoP<tCoste> Archipielago((Isla1.numVert() + Isla2.numVert() + Isla3.numVert()) * (Isla1.numVert() + Isla2.numVert() + Isla3.numVert()));
    int N = Isla1.numVert() + Isla2.numVert() + Isla3.numVert();

    for(int i = 0; i < Isla1.numVert(); i++)
    {
        for(int j = 0; j < Isla1.numVert(); j++)
        {
            Archipielago[i][j] = Isla1[i][j];
        }
    }

    int k = 0, u = 0;

    for(i = Isla1.numVert(); i < (Isla2.numVert() + Isla1.numVert()); i++)
    {
        for(j = Isla1.numVert(); i < Isla2.numVert(); j++)
        {
            Archipielago[i][j] = Isla2[k][u];
            u++;
        }

        k++;
    }

    k = 0;
    u = 0;

    for(i = Isla2.numVert() + Isla1.numVert(); i < N; i++)
    {
        for(j = Isla2.numVert() + Isla1.numVert(); i < N; j++)
        {
            Archipielago[i][j] = Isla2[k][u];
            u++;
        }

        k++;
    }

    for(puente p : puentes)
    {
        Archipielago[p.v1][p.v2] = 0;
    }

    Matriz<typename GrafoP<tCoste>::vertice> P(N);
    return floyd(Archipielago, P);
}


/*
 El archipiélago de Tombuctú, está formado por un número indeterminado de islas,
cada una de las cuales tiene, a su vez, un número indeterminado de ciudades. En
cambio, sí es conocido el número total de ciudades de Tombuctú (podemos llamarlo N,
por ejemplo).
Dentro de cada una de las islas existen carreteras que permiten viajar entre todas
las ciudades de la isla. Se dispone de las coordenadas cartesianas (x, y) de todas y cada
una de las ciudades del archipiélago. Se dispone de un grafo (matriz de adyacencia) en
el que se indica si existe carretera directa entre cualesquiera dos ciudades del
archipiélago. El objetivo de nuestro problema es encontrar qué ciudades de Tombuctú
pertenecen a cada una de las islas del mismo y cuál es el coste mínimo de viajar entre
cualesquiera dos ciudades de una misma isla de Tombuctú.
Así pues, dados los siguientes datos:
- Lista de ciudades de Tombuctú representada cada una de ellas por sus
coordenadas cartesianas.
- Matriz de adyacencia de Tombuctú, que indica las carreteras existentes en
dicho archipiélago.
Implementen un subprograma que calcule y devuelva la distribución en islas de las
ciudades de Tombuctú, así como el coste mínimo de viajar entre cualesquiera dos
ciudades de una misma isla del archipiélago.  
*/
struct ciudad{
    int x;
    int y;
}

template <typename T>
Matriz<tCoste> tombuctu(Matriz<tCoste> &M, vector<ciudad> ciudades, Matriz<typename GrafoP<tCoste>::vertice> &P)
{
    //lo primero que haremos sera construit un grafo de coste a partir de la matriz de adyacencia y las coordenadas.
    GrafoP<tCoste> G(M.numVert() * M.numVert());

    for(int i = 0; i < M.numVert(); i++)
    {
        for(in j = 0; j < M.numVert(); j++)
        {
            if(M[i][j] == true)//si existe camino calculamos la distancia
            {
                G[i][j] = sqrt(pow((ciudades[i].x + ciudades[j].x), 2) + pow((ciudades[i].y + ciudades[j].y), 2));//calculamos la distnacia entre las ciudades para saber el coste
            }
        }
    }

    // y en P tenemos la matriz que nos dice como estan distribuidas las ciudades entre las islas.

    return floyd(G, P);//devolvemos la matriz de costes minimos para moverte entre las ciudades que estan conectadas 
}

/*
El archipiélago de Tombuctú2 está formado por un número desconocido de islas,
cada una de las cuales tiene, a su vez, un número desconocido de ciudades, las cuales
tienen en común que todas y cada una de ellas dispone de un aeropuerto. Sí que se
conoce el número total de ciudades del archipiélago (podemos llamarlo N, por ejemplo).
Dentro de cada una de las islas existen carreteras que permiten viajar entre todas
las ciudades de la isla. No existen puentes que unan las islas y se ha decidido que la
opción de comunicación más económica de implantar será el avión.
Se dispone de las coordenadas cartesianas (x, y) de todas y cada una de las
ciudades del archipiélago. Se dispone de un grafo (matriz de adyacencia) en el que se
indica si existe carretera directa entre cualesquiera dos ciudades del archipiélago. El
objetivo de nuestro problema es encontrar qué líneas aéreas debemos implantar para
poder viajar entre todas las ciudades del archipiélago, siguiendo los siguientes criterios:
1) Se implantará una y sólo una línea aérea entre cada par de islas.
2) La línea aérea escogida entre cada par de islas será la más corta entre todas
las posibles.
Así pues, dados los siguientes datos:
• Lista de ciudades de Tombuctú2 representada cada una de ellas por sus
coordenadas cartesianas.
• Matriz de adyacencia de Tombuctú que indica las carreteras existentes en
dicho archipiélago,
Implementen un subprograma que calcule y devuelva las líneas aéreas necesarias para
comunicar adecuadamente el archipiélago siguiendo los criterios anteriormente
expuestos. 
*/
struct ciudad{
    int x;
    int y;
}

template <typename T>
GrafoP<tCoste> aerolinea(vector<ciudad> ciudades, typename GrafoP<tCoste> &G)
{
    //lo primero que haremos sera delimitar cuales son las ciudades de cada isla.
    //para ello usaremos warshall
    GrafoP<tCoste> G(M.numVert() * M.numVert());
    Matriz<bool> M(N * N) = warshall(G);

    //una vez que lo tenemos comenzaremos a delimitar las islas.
    int contador_islas = 0;
    bool salto = false;
    vector<int> num_ciudades;

    int i = 0;
    int cont = 0;

    for(int j = 0; j < N; j++)
    {
        cont++;
        if(M[i][j] == false)
        {
            num_ciudades.push_back(cont - 1);
            i = j;
            cont = 1;
        } 
    }

    num_ciudades.push_back(cont);//ya tenemos con num_ciudades.size() el numero de islas y de que a que ciudad es cada una.

    GrafoP<tCoste> G(M.numVert() * M.numVert());

    for(int i = 0; i < M.numVert(); i++)
    {
        for(in j = 0; j < M.numVert(); j++)
        {
            if(M[i][j] == false)//si existe camino calculamos la distancia
            {
                G[i][j] = sqrt(pow((ciudades[i].x + ciudades[j].x), 2) + pow((ciudades[i].y + ciudades[j].y), 2));//calculamos la distnacia entre las ciudades para saber el coste
            }
        }
    }//ya sabemos los costes volando entre ciudades que noe staban conectadas

    //COMO RECOGERR LAS AEROLINEAS
}


/*
La empresa EMASAJER S.A. tiene que unir mediante canales todas las ciudades del
valle del Jerte (Cáceres). Calcula qué canales y de qué longitud deben construirse
partiendo del grafo con las distancias entre las ciudades y asumiendo las siguientes
premisas:
− el coste de abrir cada nuevo canal es casi prohibitivo, luego la solución final
debe tener un número mínimo de canales.
− el Ministerio de Fomento nos subvenciona por Kms de canal, luego los canales
deben ser de la longitud máxima posible. 
*/
//APLICAR KRUSKAL O PRIM MODIFICAONDO PARA QUE COJAN EL MAXIMO NO EL MINIMO
template <typename T>
GrafoP<tCoste> canales (typenamer GrafoP<tCoste> &G)
{
    //para ello haremos kruskal modificando para que se cojan el maximo posible. Ya que es aciclico(no abrimos muchos canales)
    //y al coger el maximo aprovbechamos las subvenciones.
        return kruskal(G);//modificado para obtener el mayor.

}

template <typename tCoste>
GrafoP<tCoste> Kruskall(const GrafoP<tCoste>& G){
    typedef typename GrafoP<tCoste>::vertice vertice;
    typedef typename GrafoP<tCoste>::arista arista;
    const tCoste INFINITO = GrafoP<tCoste>::INFINITO;
    const size_t n = G.numVert();
    GrafoP<tCoste> g(n); // Árbol generador de coste mínimo.
    Particion P(n); // Partición inicial de los vértices de G.
    Apo<arista> A(n*(n-1)/2);// Aristas de G ordenadas por cost
    // Copiar aristas del grafo G en el APO A.
    for (vertice u = 0; u <= n-2; u++)
    for (vertice v = u+1; v <= n-1; v++)
    if (G[u][v] != INFINITO)
    A.insertar(arista(u, v, G[u][v]));
    size_t i = 1;
    while (i <= n-1) { // Seleccionar n-1 aristas.
    arista a = A.cima(); // arista de menor coste
    A.suprimir();
    vertice u = P.encontrar(a.orig);
    vertice v = P.encontrar(a.dest);
    if (u != v) {// extremos de a pertenecen a distintos componentes
    P.unir(u, v);
    // Incluir la arista a en el árbol g.
    g[a.orig][a.dest] = g[a.dest][a.orig] = a.coste;
    i++;
    }
    }
    return g;
}

/*
5. La nueva compañía de telefonía RETEUNI3 tiene que conectar entre sí, con fibra
óptica, todas y cada una de las ciudades del país. Partiendo del grafo que representa las
distancias entre todas las ciudades del mismo, implementad un subprograma que
calcule la longitud mínima de fibra óptica necesaria para realizar dicha conexión. 
*/

template <typename T>
int longitud_minima(typename GrafoP<tCoste> &G)
{
    //para hacer esto llamaremos tanto a kruskal como a prim, ya que necesitamos un grafo que sea un arbol de expansion minimo, ya que unimos
    //con el menor coste posible y utilizando un solo camino evitando un grafo ciclico.
    typename GrafoP<tCoste> Grafo_kruskal = kruskal(G);

    //una vez que tenemos el arbol de expansion minimo, vamos a sumar el coste de cada camino creado mediante un bucle.
    int longitud_total = 0;

    for(int i = 0; i < G.numVert(); i++)
    {
        for(int j = 0; j < G.numVert(); j++)
        {
            if(Grafo_kruskal[i][j] != typename GrafoP<tCoste>::INFINITO)
            {
                longitud_total = longitud_total + Grafo_kruskal[i][j];
            }
        }
    }

    return longitud_total;
}

/*
 La empresa EMASAJER S.A. tiene que unir mediante canales todas las ciudades del
valle del Jerte (Cáceres), teniendo en cuenta las siguientes premisas:
− El coste de abrir cada nuevo canal es casi prohibitivo, luego la solución final debe
tener un número mínimo de canales.
− El Ministerio de Fomento nos subvenciona por m3
/sg de caudal, luego el conjunto
de los canales debe admitir el mayor caudal posible, pero por otra parte, el coste
de abrir cada canal es proporcional a su longitud, por lo que el conjunto de los
canales también debería medir lo menos posible. Así pues, la solución óptima
debería combinar adecuadamente ambos factores.
Dada la matriz de distancias entre las diferentes ciudades del valle del Jerte, otra
matriz con los diferentes caudales máximos admisibles entre estas ciudades teniendo en
cuenta su orografía, la subvención que nos da Fomento por m3
/sg. de caudal y el coste
por km. de canal, implementen un subprograma que calcule qué canales y de qué
longitud y caudal deben construirse para minimizar el coste total de la red de canales.



Tenemos que: 
    - Se debe admitir el mayor caudal posible. A - B - C.
    - Ha de media lo menos posible, es decir que tenemos que hacerlo con los costes minimos.

Nos dan: 
    - Un matriz de distancias entre ciudades.
    - Una matriz de caudales maximos.
    - La subvencion por caudal.
    - Coste por KM

Calcularemos:
    - Que canales, de que longitud y que caudal.
*/
template <typename T>
Matriz<tCoste> canales(typename GrafoP<tCoste>&caudales,typename GrafoP<tCoste>&distancias, float subvencion, float coste_km)
{
   typename GrafoP<tCoste> coste(distancias.numVert());
   
    for(int i = 0; i < distancias.numVert(); i++)
    {
        for(int j = 0; j < distancias.numVert(); j++)
        {
            costes[i][j] = (distancia[i][j] * coste_km ) - (caudales[i][j] * (subvencion/100));
        }
    }

    for(int i = 0; i < distancias.numVert(); i++)
    {
        for(int j = 0; j < distancias.numVert(); j++)
        {
            if(costes[i][j] == typename GrafoP<tCoste>::INFINITO)
            {
                caudales[i][j] = typename GrafoP<tCoste>::INFINITO;
                distancias[i][j] = typename GrafoP<tCoste>::INFINITO;
            }
        }
    }

   return Kruskall(costes);
}

/*
El archipiélago de Grecoland (Zuelandia) está formado únicamente por dos islas,
Fobos y Deimos, que tienen N1 y N2 ciudades, respectivamente, de las cuales C1 y C2
ciudades son costeras (obviamente C1 ≤ N1 y C2 ≤ N2 ). Se dispone de las coordenadas
cartesianas (x, y) de todas y cada una de las ciudades del archipiélago. El huracán
Isadore acaba de devastar el archipiélago, con lo que todas las carreteras y puentes
construidos en su día han desaparecido. En esta terrible situación se pide ayuda a la
ONU, que acepta reconstruir el archipiélago (es decir volver a comunicar todas las
ciudades del archipiélago) siempre que se haga al mínimo coste.
 De cara a poder comparar costes de posibles reconstrucciones se asume lo
siguiente:
1. El coste de construir cualquier carretera o cualquier puente es proporcional a su
longitud (distancia euclídea entre las poblaciones de inicio y fin de la carretera o
del puente).  EL COSTE DE CONSTRUIR DEPENDE DE LA LONGITUD/DISTANCIA LUEGO CALCULAR BUSCANDO EL MINIMO DE ESTA
2. Cualquier puente que se construya siempre será más caro que cualquier carretera
que se construya. LOS PUENTES SON MAS CAROS
 De cara a poder calcular los costes de VIAJAR entre cualquier ciudad del
archipiélago se considerará lo siguiente:
1. El coste directo de viajar, es decir de utilización de una carretera o de un puente,
coincidirá con su longitud (distancia euclídea entre las poblaciones origen y
destino de la carretera o del puente).
 En estas condiciones, implementa un subprograma que calcule el coste mínimo
de viajar entre dos ciudades de Grecoland, origen y destino, después de haberse
reconstruido el archipiélago, dados los siguientes datos:
1. Lista de ciudades de Fobos representadas mediante sus coordenadas cartesianas.
2. Lista de ciudades de Deimos representadas mediante sus coordenadas
cartesianas.
3. Lista de ciudades costeras de Fobos.
4. Lista de ciudades costeras de Deimos.
5. Ciudad origen del viaje.
6. Ciudad destino del viaje. 
*/
struct ciudades
{
    int x;
    int y;
}
template <typename T>
T coste_minimo (typename GrafoP<tCoste>::vertice  ciudad_1 , typename GrafoP<tCoste>::vertice  ciudad_2, vector<ciudad> ciudades_fobos, vector<ciudad> ciudades_Deimos,
vector<int> CFobos, vector<int> CDeimos)
{
    //unimos las dos islas en una misma matriz comenzando con la matriz de coste a partir de la distancia euclidea.
    typename GrafoP<tCoste> costes(ciudades_fobos.size() + ciudades_Deimos.size());

    for(int i = 0; i < ciudades_fobos.size(); i++)
    {
        for(int j = 0; j < ciudades_fobos.size(); j++)
        {
            costes[i][j] = sqrt(pow(ciudades_fobos[i].x + ciudades_fobos[j].x) + pow(ciudades_fobos[i] + ciudades_fobos[j]));
        }
    }//rellenamos costes de carreteras entre la ciudades de Fobos.

    for( i = ciudades_fobos.size(); i < ciudades_fobos.size() + ciudades_deimos.size(); i++)
    {
        for( j = ciudades_fobos.size(); j < ciudades_fobos.size() + ciudades_deimos.size(); j++)
        {
            costes[i][j] = sqrt(pow(ciudades_Deimos[i].x + ciudades_Deimos[j].x) + pow(ciudades_Deimos[i] + ciudades_Deimos[j]));
        }
    }//rellenamos costes de carreteras entre la ciudades de Deimos.

    //ahora uniremos los puentes para obtener los menores costes posibles.
    for(int costera_fobos : CFobos)
    {
        for(int costera_deimos : CDeimos)
        {
            costes[costera_fobos][costera_deimos] = sqrt(pow(ciudades_fobos[costera_fobos].x + ciudades_deimos[costera_deimos].x) + 
                pow(ciudades_fobos[costera_fobos].y + ciudades_deimos[costera_deimos].y));

            costes[costera_deimos][costera_fobos] = costes[costera_fobos][costera_deimos];
        }
    }


    typename GrafoP<tCoste> costes_minimos(ciudades_fobos.size() + ciudades_Deimos.size()) = kruskall(costes);

    return costes_minimos[ciudad_1][ciudad_2];
}

/*
EJERCICIOS EXAMEN JUNIO TAPETO
*/
using namespace std;
template <typename T>
bool coste_total(typename GrafoP<tCoste> &G, int capital, vector<vector<int>> num_viajes, float max_km)
{
    //vamos a obtener los km recorridos actualmente
    float total_km_antes = 0;
    //ahora haremos floyd para tenerlo antes los km que se hacian y cuanto costaba ir d euna ciudad a otra antes y despues de haber eliminado la capital
    Matriz<typename GrafoP<tCoste>::vertice> P;
    Matriz<tCoste> M(G.numVert()) = floyd(G, P);
    for(int i = 0; i < G.numVert(); i++)
    {
        for(int j = 0; j < G.numVert(); j++)
        {
            if(M[i][j] != typename GrafoP<tCoste>::INFINITO)
            {
               if(j != capital || i != capital)  total_km_antes = total_km_antes + (M[i][j] * num_viajes[i][j]);
            }
        }
    }

    //ahora eliminaremos la capital de la matriz de costes
    for(i = 0; i < G.numVert(); i++)
    {
        G[i][capital] = typename Grafo<tCoste>::INFINITO;
    }

    int total_km_despues = 0;
    //ahora deberemos volver a llamar a floyd para obtener los caminos sin la capital para ver si aumentan muchos los km al tener que desviare los caminos entre las ciudades.
    M = floyd(G, P);
    for(i = 0; i < G.numVert(); i++)
    {
        for(int j = 0; j < G.numVert(); j++)
        {
            if(M[i][j] != typename GrafoP<tCoste>::INFINITO)
            {
                total_km_despues = total_km_despues + (M[i][j] * num_viajes[i][j]);
            }
        }
    }

    return abs(total_km_antes - total_km_despues);
}


/*
12. El archipiélago de Grecoland (Zuelandia) está formado únicamente por dos islas,
Fobos y Deimos, que tienen N1 y N2 ciudades, respectivamente, de las cuales C1 y C2
ciudades son costeras (obviamente C1 ≤ N1 y C2 ≤ N2). Se desea construir un puente
que una ambas islas. Nuestro problema es elegir el puente a construir entre todos los
posibles, sabiendo que el coste de construcción del puente se considera irrelevante. Por
tanto, escogeremos aquel puente que minimice el coste global de viajar entre todas las
ciudades de las dos islas, teniendo en cuenta las siguientes premisas:
1. Se asume que el coste viajar entre las dos ciudades que una el puente es 0.
2. Para poder plantearse las mejoras en el transporte que implica la construcción de
un puente frente a cualquier otro, se asume que se realizarán exactamente el
mismo número de viajes entre cualesquiera ciudades del archipiélago. Por
ejemplo, se considerará que el número de viajes entre la ciudad P de Fobos y la
Q de Deimos será el mismo que entre las ciudades R y S de la misma isla. Dicho
de otra forma, todos los posibles trayectos a realizar dentro del archipiélago son
igual de importantes.
Dadas las matrices de costes directos de Fobos y Deimos y las listas de ciudades
costeras de ambas islas, implementa un subprograma que calcule las dos ciudades que
unirá el puente. 
*/
struct puente{
    typename GrafoP<tCoste>::vertice v1;
    typename GrafoP<tCoste>::vertice v2;
}

template <typename T>
puente devolver_puente(typename GrafoP<tCoste> &Fobos, typename GrafoP<tCoste> &Deimos, vector<int> costera_fobos, vector<int> costera_deimos)
{
    //unimos ambas islas.
    typename GrafoP<tCoste> Archipielago(Fobos.numVert() + Deimos.numVert());

    for(int i = 0; i < Fobos.numVert(); i++)
    {
        for(int j = 0; j < Deimos.numVert(); j++)
        {
            if(Fobos[i][j] != typename GrafoP<tCoste>::INFINITO)
                Archipielago[i][j] = Fobos[i][j];
            
        }
    }

    int u = 0, v = 0;
    for(i = Fobos.numVert(); i < Fobos.numVert() + Deimos.numVert(); i++)
    {   
        u++;
        for(j = Fobos.numVert(); j < Fobos.numVert() + Deimos.numVert(); j++)
        {
            if(Deimos[u][k] != typename GrafoP<tCoste>::INFINITO)
                Archipielago[i][j] = Deimos[u][k];
            k++;
        }
    }

    //una vez tenemos unidos ambas islas en un mismo grafo
    //vamos a unir las ciudades costeras para obtener la mejor

    for(int cF : costera_fobos)
    {
        for(int cD : costera_deimos)
        {
            Archipielago[cF][cD] = 0;
            Archipielago[cD][CF] = 0;
        }
    }

    //una vez tenemos todo unido basta con realizar kruskal
    typename GrafoP<tCoste> Archipielago_kruskal(Archipielago.numVert()) = kruskall(Archipielago);
    bool encontrado = false;
    //buscaremos las ciudades costeras que unen los puentes que hemos obtenido del arbol de expansion minimo
    for(i = 0; i < Fobos.numVert() && encontrado == false; i++)
    {
        for(j = Fobos.numVert(); j < Fobos.numVert() + Deimos.numVert() && encontrado == false; j++)
        {
            if(Archipielago_kruskal[i][j] != typename GrafoP<tCoste>::INFINITO)
            {
                puente p;
                p.v1 = i;
                p.v2 = j;
                encontrado = true;
            }
        }
    }

    return p;
}


/*
12. El archipiélago de Grecoland (Zuelandia) está formado únicamente por dos islas,
Fobos y Deimos, que tienen N1 y N2 ciudades, respectivamente, de las cuales C1 y C2
ciudades son costeras (obviamente C1 ≤ N1 y C2 ≤ N2). Se desea construir un puente
que una ambas islas. Nuestro problema es elegir el puente a construir entre todos los
posibles, sabiendo que el coste de construcción del puente se considera irrelevante. Por
tanto, escogeremos aquel puente que minimice el coste global de viajar entre todas las
ciudades de las dos islas, teniendo en cuenta las siguientes premisas:
1. Se asume que el coste viajar entre las dos ciudades que una el puente es 0.
2. Para poder plantearse las mejoras en el transporte que implica la construcción de
un puente frente a cualquier otro, se asume que se realizarán exactamente el
mismo número de viajes entre cualesquiera ciudades del archipiélago. Por
ejemplo, se considerará que el número de viajes entre la ciudad P de Fobos y la
Q de Deimos será el mismo que entre las ciudades R y S de la misma isla. Dicho
de otra forma, todos los posibles trayectos a realizar dentro del archipiélago son
igual de importantes.
Dadas las matrices de costes directos de Fobos y Deimos y las listas de ciudades
costeras de ambas islas, implementa un subprograma que calcule las dos ciudades que
unirá el puente. 
*/

//solo queremos 1 puente
//queremos minimizar el coste global (floyd o Kruskall) grafos conexos, no dirigidos y ponderados.
struct puente{
    typename GrafoP<tCoste>::vertice v1;
    typename GrafoP<tCoste>::vertice v2;
}
using namespace std;
template <typename tCoste>
puente Grecoland(typename GrafoP<tCoste>&Fobos, typename GrafoP<tCoste>&Deimos, vector<typename GrafoP<tCoste>::vertice> cFobos, vector<typename GrafoP<tCoste>::vertice> cDeimos)
{
    typename GrafoP<tCoste> Archipielago(Fobos.numVert() + Deimos.numVert());

    //Vamos a darle valores a las conexiones entre las ciudades de ambas islas dentro del grafo general(Arcipielago)
    for(int i = 0; i < Fobos.numVert(); i++)
    {
        for(int j = 0; j < Fobos.numVert(); j++)
        {
            if(Fobos[i][j] != typename GrafoP<tCoste>::INFINITO)
            {
                Archipielago[i][j] = Fobos[i][j];
            }
        }
    }

    int u = 0, v = 0;
    for(i = Fobos.numVert(); i < Fobo.numVert() + Deimos.numVert(); i++)
    {
        v = 0;
        for(j = Fobos.numVert(); j < Fobos.numVert() + Deimos.numVert(); j++)
        {
            if(Deimos[u][v] != typename GrafoP<tCoste>::INFINITO)
            {
                Archipielago[i][j] = Deimos[u][v];
            }

            v++;
        }
        u++;
    }
    //yta tenemos rellenado nuestro archipielago ahora falta conectar las ciudades.

    for(typename GrafoP<tCoste>::vertice pFobos : cFobos)
    {
        for(typename GrafoP<tCoste>::vertice pDiemos : cDeimos)
        {
            Archipielago[pFobos][pDeimos] = typename GrafoP<tCoste>::INFINITO - 1;
            Archipielago[pDeimos][pFobos] = typename GrafoP<tCoste>::INFINITO - 1;
        }
    }

    typename GrafoP<tCoste> costes_minimos = Kruskall(Archipielago);
    bool encontrado = false;
    for(i = 0; i < Fobos.numVert() && encontrado == false; i++)
    {
        for(j = Fobos.numVert(); j < Fobos.numVert() + Deimos.numVert() && encontrado == false; j++)
        {
            if(Archipielago[i][j] != typename GrafoP<tCoste>::INFINITO)
            {
                encontrado = true;
                puente p;
                p.v1 = i;
                p.v2 = j;
            }
        }
    }

    return p;
}

/*
Ejercicio de GRafos de examen de grupo de EDNL ---3---(el orden de envio de trucketo)
*/
using namespace std;
struct ciudades{
    int x;
    int y;
}
template <typename tCoste>
GrafoP<tCoste> funcion(Matriz<bool> &Fobos, Matriz<bool> &Deimos, vector<ciudades> cFobos, vector<ciudades> cDeimos, vector<typername GrafoP<tCoste>::vertice> cosFobos, vector<typername GrafoP<tCoste>::vertice> cosDeimos)
{
    typename GrafoP<tCoste> Archipielago(Fobos.numVert() + Deimos.numVert());//costes calculados a partir de lo que haremos ahora que es ver que ciudades 
    //tienen conexion y realizar la operacion de la distancia euclidea mirando cuales con true

    for(int i = 0; i < Fobos.numVert(); i++)
    {
        for(int j = 0; j < Fobos.numVert(); j++)
        {
            if(Fobos[i][j] == true)
            {
                Archipielago[i][j] = sqrt(pow((cFobos[i].x - cFobos[j].x), 2) + pow((cFobos[i].y - cFobos[j]).y, 2));
            }
        }
    }

    int u = 0, v = 0;
    for(i = Fobos.numVert(); i < Fobos.numVert() + Deimos.numVert(); i++)
    {
        
        v = 0;
        for(j = Fobos.numVert(); j < Fobos.numVert() + Deimos.numVert(); j++)
        {
            if(Deimos[u][v] == true)
            {
                Archipielago[i][j] = sqrt(pow((cDeimos[u].x - cDeimos[v].x), 2) + pow((cDeimos[u].y - cDeimos[v]).y, 2));
            }
            v++;
        }
        u++;
    }//ya tenemos el grafo relleno con ls valores

    //ahora uniremos los puertos.
    for(costeras cF : cosFobos)
    {
        for(costeras cD : cosDeimos)
        {
            Archipielago[cF][cD] = sqrt(pow((cFobos[cF].x - cDeimos[cD].x), 2) + pow((cFobos[cF].y - cDeimos[cD]).y, 2));
            Archipielago[cD][cF] = Archipielago[cF][cD];
        }
    }
    //llamamos a kruskal para obtener los costes minimos
    return kruskall(Archipielago);
}


/*
Archipielago tiene 3 islas Fobos, Deimos, Europa
cada una con N1, N2 y N3 ciudades TODAS COSTERAS

Tenemos vectores de las coordenadas de sus ejes cartesianos.
Queremos comunicar todo de la forma mas barata posible (Kruskall)

construir un puente genera un coste.
*/
using namespace std;
struct ciudades{
    int x;
    int y;
}
template <typename tCoste>
typename GrafoP<tCoste> funcion(vector<ciudades> cFobos, vector<ciudades> cDeimos, vector<ciudades> cEuropa, tCoste CF_puente, tCoste CF_carretera, tCoste CA_puente
, tCoste CA_carretera)
{
    typename GrafoP<tCoste> costes(Fobos.size() + Deimos.size() + Europa.size());
    //Una vez creado el grafo procederemos a rellenarlo

    //----conectamos las ciudades de cada ciudad entre si----//
    //primero con la relacion de coste de la ciudad de Fobos.
    //solo van a crearse las carreteras en cada ciudad relacionando todas y cada una de ellas y luego relacionaremos 
    for(int i = 0; i < Fobos.size(); i++)
    {
        for(int j = 0; j < Fobos.size(); j++)
        {
            coste[i][j] = (sqrt(pow(cFobos[i].x - cFobos[j].x,2) + pow(cFobos[i].y - cFobos[j].y, 2)) * CA_carretera) + CF_carretera;
        }
    }

    //deimos
    int u = 0, v = 0;
    for(i = Fobos.size(); i < Fobos.size() + Deimos.size(); i++)
    {
        v = 0;
        for(j = Fobos.size(); j < Fobos.size() + Deimos.size(); j++)
        {
            coste[i][j] = (sqrt(pow(cDeimos[u].x + cDeimos[v].x,2) + pow(cDeimos[u].y + cDeimos[v].y, 2)) * CA_carretera) + CF_carretera;
            v++;
        }
        u++;
    }

    //europa
    u = 0;
    for(i = Fobos.size() + Deimos.size(); i < Fobos.size() + Deimos.size() + Europa.size(); i++)
    {
        v = 0;
        for(j = Fobos.size() + Deimos.size(); j < Fobos.size() + Deimos.size() + Europa.size(); j++)
        {
            coste[i][j] = (sqrt(pow(cEuropa[u].x + cEuropa[v].x,2) + pow(cEuropa[u].y + cEuropa[v].y, 2)) * CA_carretera) + CF_carretera;
            v++;
        }
        u++;
    }

    //-------conectamos puentes--------//

    //conectamos los puentes de fobos y deimos.
    u = 0;
    for(i = 0; i < Fobos.size(); i++)
    {
        v = 0;
        for(j = Fobos.size(); j < Fobos.size() + Deimos.size(); j++)
        {
            costes[i][j] = (sqrt(pow(cFobos[u].x + cDeimos[v].x,2) + pow(cFobos[u].y + cDeimos[v].y, 2)) * CA_puente) + CF_puente;
            costes[j][i] = costes[i][j];
            v++;
        }
        u++;
    }

    //conectamos los puentes de fobos yeuropa.
    u = 0;
    for(i = 0; i < Fobos.size(); i++)
    {
        v = 0;
        for(j = Fobos.size() + Deimos.size(); j < Fobos.size() + Deimos.size() + Europa.size(); j++)
        {
            costes[i][j] = (sqrt(pow(cFobos[u].x + cDeimos[v].x,2) + pow(cFobos[u].y + cDeimos[v].y, 2)) * CA_puente) + CF_puente;
            costes[j][i] = costes[i][j];
            v++;
        }
        u++;
    }

    //ahora conectaremos los puentes de deimos a eruopa
    u = 0;
    for(i = Fobos.size(); i < Fobos.size() + Deimos.size(); i++)
    {
        v = 0;
        for(j = Fobos.size() + Deimos.size(); j < Fobos.size() + Deimos.size() + Europa.size(); j++)
        {
            costes[i][j] = (sqrt(pow(cFobos[u].x + cDeimos[v].x,2) + pow(cFobos[u].y + cDeimos[v].y, 2)) * CA_puente) + CF_puente;
            costes[j][i] = costes[i][j];
            v++;
        }
        u++;
    }

    return Kruskall(costes);//prim(coste);

}


/*
-------19 junio de 2020
GrafoP<tCoste> distancias caminos directos entre clientes entre ellos y la central
Capacidad del camion
int pedido() que devuelve el numero de cajas que quedan por servir.
*/
template <typename tCoste>
int total_km(typename GrafoP<tCoste> &G, int capacidad_max, typename GrafoP<tCoste>::vertice central)
{
    Matriz<typename GrafoP<tCoste>::vertice> P(G.numVert());
    Matriz<tCoste> MF(G.numVert()) = Floyd(G, P);

    //definimos variables utiles para el algoritmo devorador.
    vector<bool> visitados(G.numVert(), false);
    int capacidad = capacidad_max, total_km = 0;
    visitador[central] = true;
    candidato = central;

    while(solucion(visitados) == false)
    {
        anterior = candidato;
        candidato = seleccion(MF, visitados, anterior);

        total_km = total_km + M[anterior][candidato];

        capacidad = capacidad - pedido(candidato);
        if(capacidad == 0)
        {
            visitados[candidato] = true;
            capacidad = capacidad_max;
            total_km = total_km + M[candidato][central];
            candidato = central;
        }else if(capacidad < 0)
        {
            capacidad = capacidad_max;
            total_km = total_km + M[candidato][central];
            candidato = central;
        }else if(capacidad > 0)
        {
            visitados[candidato] = true;
        }

    }

    return total_km;

}

bool solucion(vector<bool> &visitados)const
{
    for(bool b : visitados)
    {
        if(b == false) return false;
    }

    return true;
}

int seleccion(Matriz<tCoste> &M, visitados<bool> &visitados, int anterior)
{
    int min = typename GrafoP<tCoste>::INFINITO;
    int candidato;

    for(int i = 0; i < visitados.size(); i++)
    {
        if(visitados[i] != true)
        {
            if(min > M[anterior][i])
            {
                min = M[anterior][i];
                candidato = i;
            }
        }
    }

    return candidato;
}


/*
Tenemos dos islas Fobos Deimos, del archipielago Nozuelandia.
Queremos: 
    - En funcion del coste minimo, UN puente que conecte ambas islas

Tenemos:
    - Matriz adyacencia ambas islas
    - vector de ciudades de ambas islas con sus ejes cardinales
    - vector con la ciudades costeras de ambas islas
*/
struct ciudad{
    int x;
    int y;
}
struct puente
{
    typename GrafoP<tCoste>::vertice v1;
    typename GrafoP<tCoste>::vertice v2;
    tCoste coste;

}
template <typename tCoste>
puente funcion(Matriz<bool>&Fobos, Matriz<bool>&Deimos, vector<ciudad> cFobos, vector<ciudad> cDeimos, vector<typename GrafoP<tCoste>::vertice> cosFobos, 
vector<typename GrafoP<tCoste>::vertice> cosDeimos)
{
    //crearemos el grafo donde englobaremos ambas islas para luego conectarlas mediante un puente en funcion al coste minimo.
    GrafoP<tCoste> Nozuelandia(cFobos.size() + cDeimos.size());

    //rellenamos el grafo con ambas islas
    //Fobos
    for(int i = 0; i < cFobos.size(); i++)
    {
        for(int j = 0; j < cFobos.size(); i++)
        {
            if(Fobos[i][j] == true) Nozuelandia[i][j] = sqrt(pow((cFobos[i].x + cFobos[j].x), 2) - pow((cFobos[i].y + cFobos[j].y), 2));
        }
    }

    //Deimos
    int u = 0, v = 0;
    for(int i = cFobos.size(); i < cFobos.size() + cDeimos.size(); i++)
    {
        v = 0;
        for(int j = cFobos.size(); j < cFobos.size() + cDeimos.size(); i++)
        {
            if(Deimos[u][v] == true) Nozuelandia[i][j] = sqrt(pow((cDeimos[u].x + cDeimos[v].x), 2) - pow((cDeimos[u].y + cDeimos[v].y), 2));
            v++;
        }
        u++;
    }

    //ahora miraremos el mejor puente de todos haciendo una suma de costes por cada uno de los puentes y los almacenaremos en un vector, el que menos cpste de nos lo quedamos
    vector<typename GrafoP<tCoste>::vertice> P(cFobos.size() + cDeimos.size());
    vector<tCoste> vector_dijkstra(cFobos.size() + cDeimos.size());

    puente p;
    vector<puente> solucion;
    float total = 0;
    for(typename GrafoP<tCoste>::vertice cF : cosFobos)
    {
        for(typename GrafoP<tCoste>::vertice cD : cosDeimos)
        {
            Nozuelandia[cF][cD] = sqrt(pow((cFobos[cF].x + cDeimos[cD].x), 2) - pow((cFobos[cF].y + cDeimos[cD].y), 2));
            vector_dijkstra = Dijkstra(Nozuelandia, cF, P);

            total = 0;
            //ahora sumaremos todos los costes de ir a todas las ciudades desde el puente en cuestion
            for(i = 0; i < cFobos.size() + cDeimos.size(); i++)
            {
                total = total + vector_Dijkstra[i];
            }

            p.v1 = cF;
            p.v2 = cD;
            p.coste = total;
            solucion.push_back(p);

            Nozuelandia[cF][cD] = typename GrafoP<tcoste>::INFINITO;
        }
    }

    //ahora buscaremos de todos los puentes cual es el que ha proporcionado el menor coste.
    tCoste  min = typename GrafoP<tCoste>::INFINITO;
    puente respuesta;
    for(puente pu : solucion)
    {
        if(min > pu.coste)
        {
            min = pu.coste;
            respuesta.coste = pu.coste;
            respuesta.v1 = pu.v1;
            respuesta.v2 = pu.v2;
        }
    }

    return respuesta;
}













