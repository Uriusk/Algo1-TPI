#include <iostream>
#include "definiciones.h"
#include "auxiliares.h"

using namespace std;




tablero tableroA (posicion const &p) {
    return p.first;
}

tablero inicializarTablero(){
    vector<casilla> fila(ANCHO_TABLERO, cVACIA);
    tablero out(ANCHO_TABLERO, fila);
    return out;
}

vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v) {
    sort(v.begin(), v.end());
    return v;
}

pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}

coordenada setCoord(int i, int j) {
    return make_pair(i,j);
}

int jugador(posicion const &p){
    return p.second;
}

int pieza(tablero const &t, coordenada const &c){
    return t[c.first][c.second].first;
}

int color(tablero const &t, coordenada const &c){
    return t[c.first][c.second].second;
}

int menor(int n, int m){
    if(n > m){
        return m;
    } else {
        return n;
    }
}

int mayor (int n, int m){
    if(n > m){
        return n;
    } else {
        return m;
    }
}


// EJERCICIO 1


bool esPosicionValida(posicion const &p){
    return esJugadorValido(jugador(p)) && esTableroValido(tableroA(p));
}

bool esJugadorValido(int j){
    return j == BLANCO || j == NEGRO;
}

bool esTableroValido(tablero const &t){
    return esMatriz(t) && casillasValidas(t) && sinPeonesNoCoronados(t) && cantidadValidadDePiezas(t);
}

bool esMatriz(tablero const &t){
    bool es_matriz = t.size() == LARGO_TABLERO;
    for(int i = 0; i < LARGO_TABLERO && es_matriz; i++){
        es_matriz = t[i].size() == ANCHO_TABLERO;
    }
    return es_matriz;
}

bool casillasValidas(tablero const &t){
    bool cs_validas = true;
    coordenada c;
    for(c.first = 0; c.first < LARGO_TABLERO && cs_validas; c.first++){
        for(c.second = 0; c.second < ANCHO_TABLERO && (casillaVacia(t, c) || (PEON <= pieza(t, c) && pieza(t, c) <= REY && BLANCO <= color(t, c) && color(t, c) <= NEGRO)); c.second++){
        }
        cs_validas = c.second == DIM;
    }
    return cs_validas;
}

bool casillaVacia(tablero const &t, coordenada const &o){
    return t[o.first][o.second] == mp(VACIO, VACIO);
}

bool sinPeonesNoCoronados(tablero const &t){
    bool result = true;
    for(int i = 0; i < DIM; i++){
        result = result && pieza(t, setCoord(0, i)) != PEON;
    }
    for(int i = 0; i < DIM; i++){
        result = result && pieza(t, setCoord(DIM - 1, i)) != PEON;
    }
    return result;
}

bool cantidadValidadDePiezas(tablero const &t){
    return piezasPeonesValidas(t) && piezasAlfilesValidas(t) && piezasTorresValidas(t) && piezasReyesValidas(t);
}

bool piezasPeonesValidas(tablero const &t){
    return aparicionesEnElTablero(t, cPEON_B) <= DIM && aparicionesEnElTablero(t, cPEON_N) <= DIM;
}

bool piezasAlfilesValidas(tablero const &t){
    return aparicionesEnElTablero(t, cALFIL_B) <= 2 && aparicionesEnElTablero(t, cALFIL_N) <= 2;
}

bool piezasTorresValidas(tablero const &t){
    return aparicionesEnElTablero(t, cTORRE_B) <= 2 + (DIM - aparicionesEnElTablero(t, cPEON_B)) && 
    aparicionesEnElTablero(t, cTORRE_N) <= 2 + (DIM - aparicionesEnElTablero(t, cPEON_N));
}

bool piezasReyesValidas(tablero const &t){
    return aparicionesEnElTablero(t, cREY_B) == 1 && aparicionesEnElTablero(t, cREY_N) == 1;
}

int aparicionesEnElTablero(tablero const &t, casilla const &p){
    int apariciones = 0;
    for(int i = 0; i < t.size(); i++) {
        for (int j = 0; j < t[0].size(); j++) {
            if (t[i][j] == p) {
                apariciones++;
            }
        }
    }
    return apariciones;
}


// EJERCICIO 2


bool piezasEnCoordenadas(tablero const &t){
    return peonesEnCoordenadas(t) && torresEnCoordenadas(t) && alfilesEnCoordenadas(t) && reyesEnCoordenadas(t);
}

bool peonesEnCoordenadas(tablero const &t){
    int x;
    for(x = 0; x < ANCHO_TABLERO && piezaEnCoordenada(t, setCoord(1, x), PEON, NEGRO) && piezaEnCoordenada(t, setCoord(6, x), PEON, BLANCO); x++){
    }
    return x == ANCHO_TABLERO;
}

bool torresEnCoordenadas(tablero const &t){
    return piezaEnCoordenada(t, setCoord(0, 0), TORRE, NEGRO) && piezaEnCoordenada(t, setCoord(0, DIM - 1), TORRE, NEGRO) && 
           piezaEnCoordenada(t, setCoord(DIM - 1,0), TORRE, BLANCO) && piezaEnCoordenada(t, setCoord(DIM - 1, DIM - 1), TORRE, BLANCO);
}

bool alfilesEnCoordenadas(tablero const &t){
    return piezaEnCoordenada(t, setCoord(0, 2), ALFIL, NEGRO) && piezaEnCoordenada(t, setCoord(0, DIM - 3), ALFIL, NEGRO) && 
           piezaEnCoordenada(t, setCoord(DIM - 1, 2), ALFIL, BLANCO) && piezaEnCoordenada(t, setCoord(DIM - 1, DIM - 3), ALFIL, BLANCO);
}

bool reyesEnCoordenadas(tablero const &t){
    return piezaEnCoordenada(t, setCoord(0, 4), REY, NEGRO) && piezaEnCoordenada(t, setCoord(DIM - 1, 4), REY, BLANCO);
}

bool piezaEnCoordenada(tablero const &t, coordenada const &c, int pza, int col){
    return pieza(t, c) == pza && color(t, c) == col;
}


bool cantidadDePiezasAlInicio(tablero const &t){
    return aparicionesEnElTablero(t, cTORRE_N) == 2 && aparicionesEnElTablero(t, cTORRE_B) == 2 && 
           aparicionesEnElTablero(t, cALFIL_N) == 2 && aparicionesEnElTablero(t, cALFIL_B) == 2 && 
           aparicionesEnElTablero(t, cPEON_N) == DIM && aparicionesEnElTablero(t, cPEON_B) == DIM;
}



// EJERCICIO 3


bool casillaAtacada(tablero const &t, coordenada const &o, coordenada const &d){
    return !casillaVacia(t, o) && 
           ((pieza(t, o) != PEON && movimientoPiezaValido(t, o, d)) || (pieza(t, o) == PEON && capturaPeonValida(t, o, d)));
}

bool movimientoPiezaValido(tablero const &t, coordenada const &o, coordenada const &d){
    return pieza(t, o) == PEON && movimientoPeonValido(color(t, o), o, d) || 
           pieza(t, o) == ALFIL && movimientoAlfilValido(t, o, d) || 
           pieza(t, o) == TORRE && movimientoTorreValido(t, o, d) || 
           pieza(t, o) == REY && movimientoReyValido(o, d);
}

bool movimientoPeonValido(int color, coordenada const &o, coordenada const &d){
    return d.second == o.second && ((color == BLANCO && d.first == o.first - 1) || (color == NEGRO && d.first == o.first + 1));
}

bool movimientoAlfilValido(tablero const &t, coordenada const &o, coordenada const &d){
    bool mov_valA = abs(d.first - o.first) == abs(d.second - o.second) && o != d;
    for(int x = menor(0, d.first - o.first) + 1; x < mayor(0, d.first - o.first); x++){
        for(int y = menor(0, d.second - o.second) + 1; y < mayor(0, d.second - o.second); y++){
            if(abs(x) == abs(y)){
                mov_valA = mov_valA && casillaVacia(t, setCoord(o.first + x, o.second + y));
            }
        }
    }
    return mov_valA;
}

bool movimientoTorreValido(tablero const &t, coordenada const &o, coordenada const &d){
    bool mov_valT1 = d.second == o.second && o != d;
    for(int x = menor(o.first, d.first) + 1; x < mayor(o.first, d.first) && mov_valT1; x++){
        mov_valT1 = pieza(t, setCoord(x, o.second)) == VACIO && color(t, setCoord(x, o.second)) == VACIO; 
    }
    bool mov_valT2 = d.first == o.first && o != d;
    for(int y = menor(o.second, d.second) + 1; y < mayor(o.second, d.second) && mov_valT2; y++){
        mov_valT2 = pieza(t, setCoord(o.first, y)) == VACIO && color(t, setCoord(o.first, y)) == VACIO;
    }
    return mov_valT1 || mov_valT2;
}

bool movimientoReyValido(coordenada const &o, coordenada const &d){
    return mueveEnDiagonal(o,d) || mueveEnVertical(o,d) || mueveEnHorizontal(o,d);
}

bool mueveEnDiagonal(coordenada const &o, coordenada const &d){
    return abs(d.first - o.first) == 1 && abs(d.second - o.second) == 1;
}

bool mueveEnVertical(coordenada const &o, coordenada const &d){
    return abs(d.first - o.first) == 1 && abs(d.second - o.second) == 0;
}

bool mueveEnHorizontal(coordenada const &o, coordenada const &d){
    return abs(d.first - o.first) == 0 && abs(d.second - o.second) == 1;
}

bool capturaPeonValida(tablero const &t, coordenada const &o, coordenada const &d){
    return abs(d.first - o.first) == 1 &&
           (d.second == o.second - 1 ||  d.second == o.second + 1) &&
           ((color(t, o) == BLANCO && d.first == o.first - 1) || (color(t, o) == NEGRO && d.first == o.first + 1));
}


// EJERCICIO 4 


bool posicionSiguiente(posicion const &p, posicion const &q, coordenada const &o, coordenada const &d){
    vector<casilla> mov(2, cVACIA); mov[0] = o; mov[1] = d;
    return posicionesIgualesExceptoEn(p, q, mov) && casillaVacia(tableroA(q), o) && (esMovimientoValido(p, o, d) || esCapturaValida(p, o, d)) && piezaCorrectaEnDestino(p, q, o, d);
}

bool posicionesIgualesExceptoEn(posicion const &p, posicion const &q, vector <coordenada> const &C){
    bool iguales = true;
    coordenada c;
    for(c.first = 0; c.first < LARGO_TABLERO; c.first++){
        for(c.second = 0; c.second < ANCHO_TABLERO; c.second++){
            if(c != C[0] && c != C[1]){
                iguales = iguales && pieza(tableroA(p), c) == pieza(tableroA(q), c) && color(tableroA(p), c) == color(tableroA(q), c);
            }
        }
    }
    return iguales;
}

bool esMovimientoValido(posicion const &p, coordenada const &o, coordenada const &d){
    return jugador(p) == color(tableroA(p), o) && !casillaVacia(tableroA(p), o) && casillaVacia(p.first, d) && movimientoPiezaValido(tableroA(p), o, d);
}

bool esCapturaValida(posicion const &p, coordenada const &o, coordenada const &d){
    return !casillaVacia(tableroA(p), o) && !casillaVacia(tableroA(p), d) && color(tableroA(p), o) != color(tableroA(p), d) && casillaAtacada(tableroA(p), o, d);
}

bool piezaCorrectaEnDestino(posicion const &p, posicion const &q, coordenada const &o, coordenada const &d){
    return color(tableroA(p), o) == color(tableroA(q), d) && ((enLineaFinalInicial(d) && pieza(tableroA(p), o) == PEON && pieza(tableroA(q), d) == TORRE) || (!enLineaFinalInicial(d) && pieza(tableroA(q), d) == pieza(tableroA(p), o)));
}

bool enLineaFinalInicial(coordenada const &c){
    return c.first == 0 || c.first == DIM - 1;
}


// EJERCICIO 5


void insertionSort(vector <coordenada> &f){
    for(int i = 0; i < f.size(); i++){
        if(f[i] != mp(0,0)){
            insertar(f,i);
        }
    }
}  

void insertar(vector <coordenada> &f, int i){
    int k = i;
    for(int j = i; j > 0; j--){
        if(f[k].first < f[j - 1].first && f[j - 1] != mp(0,0)){
            swap(f, j - 1, k);
            k = j - 1;
        }
    }
}

void swap(vector<coordenada> &f, int i, int j){
    coordenada aux = f[i];
     f[i] = f[j];
     f[j] = aux;
}


// EJERCICIO 6


bool esEmpate(posicion const &p){
    return soloHayReyes(tableroA(p)) || (!jugadorEnJaque(p, jugador(p)) && !hayMovimientosLegales(p));
}

bool soloHayReyes(tablero const &t){
    bool reyOVacio = true;
    coordenada c;
    for(c.first = 0; c.first < LARGO_TABLERO; c.first++){
        for(c.second = 0; c.second < ANCHO_TABLERO && (casillaVacia(t, c) || pieza(t, c) == REY); c.second++){
        }
        reyOVacio = reyOVacio && c.second == t.size();
    }
    return reyOVacio;
}

bool jugadorEnJaque(posicion const &p, int j){
    bool enJaque = false;
    coordenada o;
    for(o.first = 0 ; o.first < LARGO_TABLERO; o.first++){
        for(o.second = 0; o.second < ANCHO_TABLERO && (color(tableroA(p), o) != contrincante(j) || !atacaAlRey(p, o)); o.second++){
        }
        enJaque = enJaque || o.second < ANCHO_TABLERO;
    }
    return enJaque;
}

bool hayMovimientosLegales(posicion const &p){
    vector<coordenada> movibles;
    coordenada pieza;
    for(pieza.first = 0; pieza.first < LARGO_TABLERO; pieza.first++){
        for(pieza.second = 0; pieza.second < ANCHO_TABLERO; pieza.second++){
            if(piezaDeJugador(p, pieza) && tieneMovimiento(p, pieza)){
                movibles.push_back(pieza);
            }
        }
    }
    return movibles.size() > 0;
}

bool piezaDeJugador(posicion const &p, coordenada const &C){
    return color(tableroA(p), C) == jugador(p);
}

bool tieneMovimiento(posicion const &p, coordenada const &pieza){
    bool mueveOCaptura = false;
    coordenada d;
    for(d.first = 0; d.first < LARGO_TABLERO ; d.first++){
        for(d.second = 0; d.second < ANCHO_TABLERO && !esJugadaLegal(p, pieza, d); d.second++){
        }
        mueveOCaptura = mueveOCaptura || d.second < ANCHO_TABLERO;
    }
    return mueveOCaptura;
}

bool esJugadaLegal(posicion const &p, coordenada const &o, coordenada const &d){
    return (esMovimientoValido(p, o, d) || esCapturaValida(p, o, d)) && !loPoneEnJaque(p, o, d);
}

bool loPoneEnJaque(posicion const &p, coordenada const &o, coordenada const &d){
    posicion q = crearPosicionSiguiente(p, o, d);
    q.second = jugador(p);
    return jugadorEnJaque(q, p.second);
}

posicion crearPosicionSiguiente(posicion const &p, coordenada const &o, coordenada const &d){
    posicion q = p;
    q.first[o.first][o.second] = cVACIA;
    q.first[d.first][d.second].second = color(tableroA(p), o);
    q.second = contrincante(jugador(p));
    if(enLineaFinalInicial(d) && p.first[o.first][o.second].first == PEON){
        q.first[d.first][d.second].first = TORRE;
    } else {
        q.first[d.first][d.second].first = pieza(tableroA(p), o);
    }
    return q;
}

bool esJaqueMate(posicion const &p){
    return jugadorEnJaque(p, jugador(p)) && !existeMovimientoParaSalirDelJaque(p);
}

int contrincante (int j){
    if (j == 1){
        j = 2;
    } else if (j == 2){
        j = 1;
    }
    return j;
}

bool atacaAlRey(posicion const &p, coordenada const &o){
    bool reyAtacado = false;
    coordenada d;
    for(d.first = 0; d.first < LARGO_TABLERO; d.first++){
        for(d.second = 0; d.second < ANCHO_TABLERO && (pieza(tableroA(p), d) != REY || color(tableroA(p), d) != jugador(p) || !esCapturaValida(p, o, d)); d.second++){
        }
        reyAtacado = reyAtacado || d.second < ANCHO_TABLERO;
    }
    return reyAtacado;
}

bool existeMovimientoParaSalirDelJaque(posicion const &p){
    bool existeMovimiento = false;
    coordenada o; coordenada d;
    for(o.first = 0; o.first < LARGO_TABLERO; o.first++){
        for(o.second = 0; o.second < ANCHO_TABLERO; o.second++){
            if(color(tableroA(p), o) == jugador(p)){
                for(d.first = 0; d.first < LARGO_TABLERO; d.first++){
                    for(d.second = 0; d.second < ANCHO_TABLERO && !esJugadaLegal(p, o, d); d.second++){
                    }
                    existeMovimiento = existeMovimiento || d.second < ANCHO_TABLERO;
                }
            }
        }
    }
    return existeMovimiento;
}


// EJERCICIO 7 


bool alMoverQuedaEnJaque(posicion const &p){
    bool enJaque = false;
    coordenada o; coordenada d;
    for(o.first = 0; o.first < LARGO_TABLERO; o.first++){
        for(o.second = 0; o.second < ANCHO_TABLERO; o.second++){
            if(color(tableroA(p), o) == jugador(p)){
                for(d.first = 0; d.first <LARGO_TABLERO; d.first++){
                    for(d.second = 0; d.second < ANCHO_TABLERO; d.second++){
                        if(esJugadaLegal(p, o, d)){
                            posicion q = crearPosicionSiguiente(p, o, d);
                            enJaque = enJaque || jugadorEnJaque(q, jugador(q));
                        }
                    }
                }
            }
        }
    }
    return enJaque;
}


// EJERCICIO 8


posicion posicionFinalDeSecuenciaForzada(posicion const &p, secuencia &s){
    vector<posicion> P (2*s.size() + 1, make_pair(inicializarTablero(), 0));
    P[0] = p; 
    for(int i = 0; i < s.size(); i++){
        P[2*i + 1] = movimientoForzadoImpar(P[2*i], s[i]);
        P[2*i + 2] = movimientoForzadoPar(P[2*i + 1]);
    }
    return P[P.size() - 1];
}

posicion movimientoForzadoImpar(posicion const &pi, pair <coordenada, coordenada>  m){
    posicion pm;
    if(esJugadaLegal(pi, m.first, m.second)){
        pm = crearPosicionSiguiente(pi, m.first, m.second);
    }
    return pm;
}

posicion movimientoForzadoPar(posicion const &pm){
    posicion pf;
    coordenada o; coordenada d;
    for(o.first = 0; o.first < LARGO_TABLERO; o.first++){
        for(o.second = 0; o.second < ANCHO_TABLERO; o.second++){
            if(color(tableroA(pm), o) == jugador(pm)){
                for(d.first = 0; d.first < LARGO_TABLERO; d.first++){
                    for(d.second = 0; d.second < ANCHO_TABLERO; d.second++){
                        if(o != d && esJugadaLegal(pm, o, d) && esUnicaMovidaPosibleJugador(pm, o, d)){
                            pf = crearPosicionSiguiente(pm, o, d);
                        }
                    }
                }
            }
        }
    }
    return pf;
}

bool esUnicaMovidaPosibleJugador(posicion const &p, coordenada const &o, coordenada const &d){
     bool unicaMovida = true;
     coordenada o1; coordenada d1;
      for(o1.first = 0; o1.first < LARGO_TABLERO; o1.first++){
        for(o1.second = 0; o1.second < ANCHO_TABLERO; o1.second++){
            if(color(tableroA(p), o1) == jugador(p)){
                for(d1.first = 0; d1.first < LARGO_TABLERO; d1.first++){
                    for(d1.second = 0; d1.second < ANCHO_TABLERO; d1.second++){
                        if(esJugadaLegal(p, o1, d1)){
                            unicaMovida = unicaMovida && o1 == o && d1 == d;
                        }
                    }
                }
            }
        }
    }
    return unicaMovida;
}

// Ejercicio 9

int jaqueMateEnSecuenciaForzada(posicion const &p){
    secuencia s = crearSecuenciaForzada(p);
    return s.size();
}

secuencia crearSecuenciaForzada(posicion p){
    secuencia secuenciaForzada; secuencia s; secuencia t;
    posicion ps; posicion pi = p;
    coordenada o; coordenada d; coordenada a; coordenada b;
    for(int i = 1; i <= 3; i++){
        for(o.first = 0; o.first < LARGO_TABLERO; o.first++){
            for(o.second = 0; o.second < ANCHO_TABLERO; o.second++){
                if(color(tableroA(p), o) == jugador(p)){
                    for(d.first = 0; d.first < LARGO_TABLERO; d.first++){
                        for(d.second = 0; d.second < ANCHO_TABLERO; d.second++){
                            if(esJugadaLegal(p,o,d)){
                                ps = crearPosicionSiguiente(p,o,d);
                                if(esJaqueMate(ps)){
                                    s.push_back(make_pair(o,d));
                                    o = make_pair(LARGO_TABLERO, ANCHO_TABLERO);
                                    d = make_pair(LARGO_TABLERO, ANCHO_TABLERO);
                                }
                            }
                        }
                    }
                }
            }
        }
        o.first = 0;
        if(s.size() > 0){
            o.first = LARGO_TABLERO;
            i = 4;
        }
        while(o.first < LARGO_TABLERO){
            for(o.second = 0; o.second < ANCHO_TABLERO; o.second++){
                if(color(tableroA(p), o) == jugador(p) && o != a && o != b){
                    for(d.first = 0; d.first < LARGO_TABLERO; d.first++){
                        for(d.second = 0; d.second < ANCHO_TABLERO; d.second++){
                            if(esJugadaLegal(p,o,d)){
                                ps = crearPosicionSiguiente(p,o,d);
                                if(estaForzado(ps)){
                                    if(i == 1){
                                        a = o;
                                    }
                                    if(i == 2){
                                        b = o;
                                    }
                                    t.push_back(make_pair(o,d));
                                    p = movimientoForzadoPar(ps);
                                    o = make_pair(LARGO_TABLERO, ANCHO_TABLERO);
                                    d = make_pair(LARGO_TABLERO, ANCHO_TABLERO);
                                }
                            }
                        }
                    }
                }
            }
            o.first++;
        }
        if(t.size() > 2){
            i = 0;
            p = pi;
            t.clear();
        }
    }
    secuenciaForzada = concat(s,t);
    return secuenciaForzada;
}

bool estaForzado(posicion const &pm){
    bool forzado = false;
    coordenada o; coordenada d;
    for(o.first = 0; o.first < LARGO_TABLERO; o.first++){
        for(o.second = 0; o.second < ANCHO_TABLERO; o.second++){
            if(color(tableroA(pm), o) == jugador(pm)){
                for(d.first = 0; d.first < LARGO_TABLERO; d.first++){
                    for(d.second = 0; d.second < ANCHO_TABLERO; d.second++){
                        if(o != d && esJugadaLegal(pm, o, d) && esUnicaMovidaPosibleJugador(pm, o, d)){
                            forzado = forzado || d.second < ANCHO_TABLERO;
                        }
                    }
                }
            }
        }
    }
    return forzado;
}

secuencia concat (secuencia s, secuencia t){
    secuencia result;
    for(int i = 0; i < s.size(); i++){
        result.push_back(s[i]);
    }
    for(int i = 0; i < t.size(); i++){
        result.push_back(t[i]);
    }
    return result;


