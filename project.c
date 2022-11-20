#include"project.h"
u8 g_sec = 15;
u8 g_min = 59;
u8 g_hour = 11;
u8 day[3] ="AM";


	int main(){
		M_GIE_Void_GlobalInterruptEnable();
		st_normal_mode();
		 return 0;

	}

void st_normal_mode(void){
	 	M_Timer_Void_SetCallBack(A_Timer0Excution);
		 M_Timer_Void_TimerInit();
		 M_Timer_Void_TimerSetTime(1000);
		 M_Timer_Void_TimerStart(TIMER0_CHANNEL);

}

void A_Timer0Excution(void){
	g_sec++;
	if (g_sec == 60) {
		g_min++;
		g_sec = 0;
	}
	if (g_min == 60) {
		g_hour++;
		g_min = 0;
		g_sec = 0;
	}
	if (g_hour == 12) {
		g_hour = 1;
		g_min = 0;
		g_sec=0;
		day[0]='P';
		}
	}
}
