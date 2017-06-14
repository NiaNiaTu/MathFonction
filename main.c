#include "main.h"
#include "atan2s16.h"
#include "f_math.h"
signed short m11,m12,m13,m14,m15,m16,m17,m18,m19; //my new function to calculate arctan
signed short m21,m22,m23,m24,m25,m26,m27,m28,m29; //old function to calcule arctan

int main(void)
{

	HAL_Init();
	SystemClock_Config();

/*These two functions has same output between 0~pi and 0~-pi*/
	m21=Limited_atan(32766, 5)>> SHIFT_ATAN;
	m22=Limited_atan(32766, 32766)>> SHIFT_ATAN;
	m23=Limited_atan(5, 32766)>> SHIFT_ATAN;
	m24=Limited_atan(-5, 32766)>> SHIFT_ATAN;
	m25=Limited_atan(-32766, 5)>> SHIFT_ATAN;
	m26=Limited_atan(-32766, -5)>> SHIFT_ATAN;
	m27=Limited_atan(-5, -32766)>> SHIFT_ATAN;
	m28=Limited_atan(5, -32766)>> SHIFT_ATAN;
	m29=Limited_atan(32766, -5)>> SHIFT_ATAN;

	m11= atan2s16(32766, 5);//0
	m12= atan2s16(32766, 32766);//45
	m13= atan2s16(5, 32766);//89
	m14= atan2s16(-5, 32766);//91
	m15= atan2s16(-32766, 5);//179
	m16= atan2s16(-32766, -5);//-180
	m17= atan2s16(-5, -32766);///-91
	m18= atan2s16(5, -32766);//-89
	m19= atan2s16(32766, -5);//0

/*use TogglePin to test the time used by fonction*/
  TogglePin();
  atan2s16(32766, 5);
  TogglePin();

}
