#include "../definiciones.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
# include <utility>

using namespace std;

TEST(seVieneElJaqueEnTEST, hayMateEn1) {
    tablero t = { // Figura del ej16 del enunciado del TPE
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N},
            {cPEON_N, cPEON_N, cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cALFIL_B, cALFIL_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t,BLANCO);

    int K_esperado = 1;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}

TEST(seVieneElJaqueEnTEST, hayMateEn2conTresTorres) {
    tablero t = { // tablero de ejercicio 17 del TPE pero tiene una solucion en 2 movimientos al coronar el peon y
// moverlo a la ultima columna haciendo jaque mate al rey
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA},
            {cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B},
    };
    posicion p = make_pair(t,BLANCO);

    int K_esperado = 2;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}

TEST(seVieneElJaqueEnTEST, hayMateEn2) {
    tablero t = { // tablero de ejercicio 17 del TPE
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N},
            {cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA},
            {cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B},
    };
    posicion p = make_pair(t,BLANCO);

    int K_esperado = 2;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}

TEST(seVieneElJaqueEnTEST, noHayMateEn1) {
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cREY_N, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cTORRE_N, cVACIA, cALFIL_N, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cPEON_N, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cREY_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t,NEGRO);

    int K_esperado = 2;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}

TEST(seVieneElJaqueEnTEST, hayMateEn1ConCoronacion) {
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cREY_N, cVACIA, cVACIA, cVACIA},
            {cVACIA, cPEON_B, cTORRE_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cTORRE_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cALFIL_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cALFIL_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cPEON_B, cPEON_B, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, BLANCO);

    int K_esperado = 1;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}

TEST(seVieneElJaqueEnTEST, hayMateEn1ConJaqueDescubierto) {
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cALFIL_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cREY_N},
            {cPEON_N, cALFIL_N, cTORRE_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cTORRE_N, cVACIA, cVACIA, cVACIA, cVACIA},
            {cREY_B, cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_N},
            {cVACIA, cVACIA, cPEON_B, cVACIA, cTORRE_N, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, NEGRO);

    int K_esperado = 1;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}

TEST(seVieneElJaqueEnTEST, hayMateEn3ConJaqueDescubierto) {
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cALFIL_N},
            {cVACIA, cALFIL_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cREY_B, cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_N},
            {cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cPEON_N, cVACIA, cPEON_N, cVACIA, cTORRE_N, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_N, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, NEGRO);

    int K_esperado = 3;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}
