#pragma once
#include "quantum.h"

#define ___ KC_NO

/*
 *  ,---------------------------------------.       ,---------------------------------------.
 *  |  L00  |  L01  |  L02  |  L03  |  L04  |       |  R00  |  R01  |  R02  |  R03  |  R04  |
 *  |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 *  |  L10  |  L11  |  L12  |  L13  |  L14  |       |  R10  |  R11  |  R12  |  R13  |  R14  |
 *  |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 *  |  L20  |  L21  |  L22  |  L23  |  L24  |       |  R20  |  R21  |  R22  |  R23  |  R24  |
 *  |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
 *  |               |  L32  |  L33  |  L34  |       |  R30  |  R31  |  R32  |               |
 *  `---------------------------------------'       `---------------------------------------'
 */


#define LAYOUT_3x5_3( \
  K00, K10, K20, K30, K40,    K44, K34, K24, K14, K04,  \
  K01, K11, K21, K31, K41,    K45, K35, K25, K15, K05,  \
  K02, K12, K22, K32, K42,    K46, K36, K26, K16, K06,  \
            K23, K33, K43,    K47, K37, K27  \
) { \
  { K00, K01, K02, ___, K04, K05, K06, ___ }, \
  { K10, K11, K12, ___, K14, K15, K16, ___ }, \
  { K20, K21, K22, K23, K24, K25, K26, K27 }, \
  { K30, K31, K32, K33, K34, K35, K36, K37 }, \
  { K40, K41, K42, K43, K44, K45, K46, K47 }  \
}

#define LAYOUT LAYOUT_3x5_3

#include "keyboards/fingerpunch/fp.h"
