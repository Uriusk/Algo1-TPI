#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"


// EJERCICIO 1
bool posicionValida (pair < tablero, int > const &p) {
    return esPosicionValida(p);
}

// EJERCICIO 2
bool posicionInicial (posicion const &p) {
    return piezasEnCoordenadas(tableroA(p)) && cantidadDePiezasAlInicio(tableroA(p)) && jugador(p) == BLANCO;
}

// EJERCICIO 3
vector <coordenada> casillasAtacadas (posicion const &p, int j) {
    vector <coordenada> atacadas;
    coordenada c;
    coordenada o;
    for(c.first = 0; c.first < LARGO_TABLERO; c.first++){
        for(c.second = 0; c.second < ANCHO_TABLERO; c.second++){
            for(o.first = 0; o.first < LARGO_TABLERO; o.first++){
                for(o.second = 0; o.second < ANCHO_TABLERO && (!casillaAtacada(tableroA(p), o, c) || color(tableroA(p), o) != j); o.second++){
                }
                if(o.second < ANCHO_TABLERO){
                    atacadas.push_back(c);
                    o.first = LARGO_TABLERO;
                }
            }
        }
    }
    return atacadas;
}

// EJERCICIO 4
bool posicionSiguienteCorrecta (posicion const &p1, posicion const &p2, coordenada o, coordenada d) {
    return posicionSiguiente(p1, p2, o, d);
}

// EJERCICIO 5
void ordenarTablero(posicion &p){
    for(int i = 0; i < p.first.size(); i++){
        insertionSort(p.first[i]);
    }
}

// EJERCICIO 6
bool finDeLaPartida (posicion const &p, int &j) {
    bool result;
    if(esEmpate(p)){
        j = 0;
        result = true;
    } else if(esJaqueMate(p)){
        j = contrincante(jugador(p));
        result = true;
    } else {
        result = false;
    }
    return result;
}

// EJERCICIO 7
bool hayJaqueDescubierto (posicion const &p) {
    return alMoverQuedaEnJaque(p);
}
// EJERCICIO 8
void ejecutarSecuenciaForzada (posicion &p, secuencia s) {
    p = posicionFinalDeSecuenciaForzada(p, s);
}
// EJERCICIO 9
int seVieneElJaqueEn (posicion const & p) {
    return jaqueMateEnSecuenciaForzada(p);
}
