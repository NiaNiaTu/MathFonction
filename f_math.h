#include "math.h"
#define Q15 		32768    		// 2^15
#define PIf 		3.141592654f  	// Valeur de PI en flottant
#define PIQ15 		32767   		// Valeur de PI normalisée en Q15
#define PIQ15SUR2 	16384   		// Valeur de PI normalisée en Q15

/************************************************************************
  LIMITED_ATAN(X,Y) est une fonction a_tangente 
  
  La focntion travaille avec des nombre au format Q15 (Valeur codée sur 15bits + 1 bits de signe, fractions de 2^15)
  
  Entrée: 2 points en coordonnées cartésienne (-32767 < entier <32767)
    	  (LIMITED_ATAN ne fait pas de test)
  Sortie: -32767(-PI) < angle < 32767(+PI)  	  
  
  LIMITED_ATAN(0,0)  retourne 0.   
                              _ y_max=32767
                              |
                              |     ° point(x,y)
                              |    /
                              |   /
                              |  /
                              | / angle
         x_min=-32767         |/\              x_max=32767
             |----------------+----------------|
                              |
                              |
                              |
                              |
                              |
                              |
                              |
                              - y_min=-32767                            */          
/************************************************************************/
short Limited_atan(short x, short y);

// Fonction qui divise deux nombre positifs fournis au format Q15
unsigned short q15_div(short a, short b);
// Fonction qui calcule l'arctangeante d'un nombre positif fournit au format Q15
// L'angle retourné est fourni au format Q15, normalisé à PI
// Entrée comprise entre 0 et 1
// Sortie comprise entre 0 et 0x2000, soit 0 et PI/4

unsigned short q15p_atan(short x);

// Convertit un fomat Q15 en float
float Q15toF (short x);

// Convertit un float en format Q15
unsigned short FtoQ15 (float x);

/*****************************************************************/
/*
  My_int_sqrt(initial_number) is used to determine the closest 16-bit integer
  that is the result of the square root of the initial_number.
  
											                      */          
/******************************************************************/
unsigned short My_int_sqrt(long initial_number);
