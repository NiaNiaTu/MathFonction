#include "Main.h"  
#include "f_math.h"

/************************************************************************
  LIMITED_ATAN(X,Y) est une fonction a_tangente 
  
  La focntion travaille avec des nombre au format Q15 (Valeur codï¿½e sur 15bits + 1 bits de signe, fractions de 2^15)
  
  Entrï¿½e: 2 points en coordonnï¿½es cartï¿½sienne (-32767 < entier <32767)
    	  (LIMITED_ATAN ne fait pas de test)
  Sortie: -32767(-PI) < angle < 32767(+PI)  	  
  
  LIMITED_ATAN(0,0)  retourne 0.   
                              _ y_max=32767
                              |
                              |     ï¿½ point(x,y)
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
short Limited_atan(short x, short y)
{
    short ys=(y>=0);  // Flag y positif
    short xs=(x>=0);  // Flag x positif
    short   y1;
    unsigned short x1;
    
    if(!ys) y=-y;
    if(!xs) x=-x;		// Travaille en positif uniquement
    
    // Calcul de la tangeante de l'angle ramenÃ© dans le cadrant positif
	if(x==y)			// Angle= PI/4 (moduloPI/2)
        x1=32767;       // Pas besoin de diviser, le rÃ©sultat est 1
    else
    {
        if(x>y)					// Les coordonnÃ©es reprÃ©sentent une fraction du sinus et du cosinus
            x1=q15_div(y,x);	// Calcul de la tangeante de l'angle
        else   // y>x
            x1=q15_div(x,y);
    }

	// Calcul de l'angle
    x1=q15p_atan(x1);

// Ramï¿½ne l'angle dans le bon cadrant en fonction des signes de dï¿½part	
    
    if(y>x)	x1=PIQ15SUR2-x1;			// PI/2 - alpha
		
    y1=x1;

    if(xs)
    { 
  //  	if(ys) 	y1=y1;
    	if(!ys) y1=-y1;
    }
    else
    {
        if(ys) 	y1=PIQ15-y1;  // PI-alpha
        else	y1=-PIQ15+y1;  // Alpha-PI  
    }
    return y1;
}

// Fonction qui divise deux nombre positifs fournis au format Q15
unsigned short q15_div(short a, short b)
{
	float TempA, TempB, TempResult;
	
	TempA = Q15toF(a);  // Convertit en float
	TempB = Q15toF(b); 	// Convertit en float
	
	TempResult = TempA / TempB; 
	
	return (FtoQ15(TempResult));

}

// Focntion qui calcule l'arctangeante d'un nombre positif fournit au format Q15
// L'angle retournï¿½ est fourni au format Q15, normalisï¿½ ï¿½ PI
// Entrï¿½e comprise entre 0 et 1
// Sortie comprise entre 0 et 0x2000, soit 0 et PI/4

unsigned short q15p_atan(short x)
{
	float TempA, TempResult;
	
	TempA = Q15toF(x);			// Converti en float

	TempResult = atanf(TempA);	// Calcule Artangeante

	TempResult /= PIf;			// Normalisation Ã  PI
	
	return (FtoQ15(TempResult));
}

// Convertit un fomat Q15 en float
float Q15toF (short x)
{
	return ((float) (x) / (float)(Q15));
}

// Convertit un float en format Q15
unsigned short FtoQ15 (float x)
{
	return ((short)(x*(float)(Q15)));
}

/*****************************************************************/
/*
  My_int_sqrt(initial_number) is used to determine the closest 16-bit integer
  that is the result of the square root of the initial_number.
  
											                      */          
/******************************************************************/
unsigned short My_int_sqrt(long initial_number)
{
	short index_bit;
	unsigned short sqrted_number = 0;

	for(index_bit = 31; index_bit >= 0; index_bit--)
	{
		sqrted_number += (1 << index_bit);
		if(((long)sqrted_number * sqrted_number) > initial_number)
			sqrted_number -= (1 << index_bit);
	}
	return sqrted_number;
}
