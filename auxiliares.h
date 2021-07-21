//


#ifndef AJEDREZLITE_AUXILIARES_H
#define AJEDREZLITE_AUXILIARES_H

#include "definiciones.h"

using namespace std;


tablero tableroA (posicion const &p);
tablero inicializarTablero();
vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v);
pair<int,int> mp(int a, int b);
coordenada setCoord(int i, int j);
int jugador(posicion const &p);
int pieza(tablero const &t, coordenada const &c);
int color(tablero const &t, coordenada const &c);
int menor(int n, int m);
int mayor (int n, int m);

bool esPosicionValida(posicion const &p);
bool esJugadorValido(int j);
bool esTableroValido(tablero const &t);
bool esMatriz(tablero const &t);
bool casillasValidas(tablero const &t);
bool casillaVacia(tablero const &t, coordenada const &o);
bool sinPeonesNoCoronados(tablero const &t);
bool cantidadValidadDePiezas(tablero const &t);
bool piezasPeonesValidas(tablero const &t);
bool piezasAlfilesValidas(tablero const &t);
bool piezasTorresValidas(tablero const &t);
bool piezasReyesValidas(tablero const &t);
int aparicionesEnElTablero(tablero const &t, casilla const &p);

bool piezasEnCoordenadas(tablero const &t);
bool peonesEnCoordenadas(tablero const &t);
bool torresEnCoordenadas(tablero const &t);
bool alfilesEnCoordenadas(tablero const &t);
bool reyesEnCoordenadas(tablero const &t);
bool piezaEnCoordenada(tablero const &t, coordenada const &c, int pieza, int color);
bool cantidadDePiezasAlInicio(tablero const &t);

bool casillaAtacada(tablero const &t, coordenada const &o, coordenada const &d);
bool movimientoPiezaValido(tablero const &t, coordenada const &o, coordenada const &d);
bool movimientoPeonValido(int color, coordenada const &o, coordenada const &d);
bool movimientoAlfilValido(tablero const &t, coordenada const &o, coordenada const &d);
bool movimientoTorreValido(tablero const &t, coordenada const &o, coordenada const &d);
bool movimientoReyValido(coordenada const &o, coordenada const &d);
bool mueveEnDiagonal(coordenada const &o, coordenada const &d);
bool mueveEnVertical(coordenada const &o, coordenada const &d);
bool mueveEnHorizontal(coordenada const &o, coordenada const &d);
bool capturaPeonValida(tablero const &t, coordenada const &o, coordenada const &d);

bool posicionSiguiente(posicion const &p, posicion const &q, coordenada const &o, coordenada const &d);
bool posicionesIgualesExceptoEn(posicion const &p, posicion const &q, vector <coordenada> const &C);
bool esMovimientoValido(posicion const &p, coordenada const &o, coordenada const &d);
bool esCapturaValida(posicion const &p, coordenada const &o, coordenada const &d);
bool piezaCorrectaEnDestino(posicion const &p, posicion const &q, coordenada const &o, coordenada const &d);
bool enLineaFinalInicial(coordenada const &c);

void insertionSort(vector <coordenada> &f);
void insertar(vector <coordenada> &f, int i);
void swap(vector<coordenada> &f, int i, int j);

bool esEmpate(posicion const &p);
bool soloHayReyes(tablero const &t);
bool jugadorEnJaque(posicion const &p, int j);
bool hayMovimientosLegales(posicion const &p);
bool piezaDeJugador(posicion const &p, coordenada const &C);
bool tieneMovimiento(posicion const &p, coordenada const &pieza);
bool esJugadaLegal(posicion const &p, coordenada const &o, coordenada const &d);
bool loPoneEnJaque(posicion const &p, coordenada const &o, coordenada const &d);
posicion crearPosicionSiguiente(posicion const &p, coordenada const &o, coordenada const &d);
bool esJaqueMate(posicion const &p);
int contrincante (int j);
bool atacaAlRey(posicion const &p, coordenada const &o);
bool existeMovimientoParaSalirDelJaque(posicion const &p);


bool alMoverQuedaEnJaque(posicion const &p);

posicion posicionFinalDeSecuenciaForzada(posicion const &p, secuencia &s);
posicion movimientoForzadoImpar(posicion const &p, pair <coordenada, coordenada>  m);
posicion movimientoForzadoPar(posicion const &p);
bool esUnicaMovidaPosibleJugador(posicion const &p, coordenada const &o, coordenada const &d);






#endif //AJEDREZLITE_AUXILIARES_H
