

#include <stdio.h>
#include <stdlib.h>
#define WITH_ENGINE_CONTROLLER 1

char take_input(void);
void sensors_choose_menu(void);
char traffic_color_sensor(void);
void room_temp_sensor(void);
#if (WITH_ENGINE_CONTROLLER==1)
void engine_temp_sensor(void);
#endif
int speed_test(char);
void display_current_vechile_state(void);
void intial_values(void);

enum state{ ON , OFF };

struct engine{
	int speed ;
	int room_temp;
#if (WITH_ENGINE_CONTROLLER==1)
	int engine_temp;
#endif
	char AC_state ;
#if (WITH_ENGINE_CONTROLLER==1)
	char Engine_Temperature_Controller_state;
#endif
	char engine_state;
}engine;

int main(void) {
	setbuf(stdout,NULL);
	char input;
	intial_values();
	input= take_input();
	while(1){
		switch (input){
		case 'a':
			printf("Turn on the vehicle engine\n\n");
			engine.engine_state=ON;
			sensors_choose_menu();
			input= take_input();
			break;
		case 'b':
			printf("Turn off the vehicle engine\n\n");
			engine.engine_state=OFF;
			input= take_input();
			break;
		case 'c':
			printf("Quit the system\n\n");
			return 0;

		}
	}
}


char take_input(void){
	char input;
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
	do {
		printf("enter required option\n");
		scanf(" %c",&input);
	} while ((input!='a')&&(input!='b')&&(input!='c'));
	return input;

}


void sensors_choose_menu(void){
	char input2;
	char traffic_input;
	printf("a. Turn off the engine\n");
	printf("b. Set the traffic light color.\n");
	printf("c. Set the room temperature (Temperature Sensor)\n");
#if (WITH_ENGINE_CONTROLLER==1)
	printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
#endif
	do {
		printf("enter required option\n");
		scanf(" %c",&input2);
	} while ((input2!='a')&&(input2!='b')&&(input2!='c')&&(input2!='d'));

	switch(input2){
	case 'a':
		engine.engine_state=OFF;
		break;
	case 'b':
		traffic_input=traffic_color_sensor();
		engine.speed=speed_test(traffic_input);
		if (engine.speed==30){
				engine.AC_state=ON;
				engine.room_temp=engine.room_temp*(5/4)+1;
#if (WITH_ENGINE_CONTROLLER==1)
				engine.Engine_Temperature_Controller_state=ON;
				engine.engine_temp=engine.engine_temp*(5/4)+1;
#endif
			}
		display_current_vechile_state();
		sensors_choose_menu();
		break;
	case 'c':
		room_temp_sensor();
		if (engine.room_temp<10)
		{
			engine.AC_state=ON;
			engine.room_temp=20;
		}
		else if (engine.room_temp>30)
		{
			engine.AC_state=ON;
			engine.room_temp=20;
		}
		else engine.AC_state=OFF;
		display_current_vechile_state();
		sensors_choose_menu();
		break;
#if (WITH_ENGINE_CONTROLLER==1)
	case 'd':
		engine_temp_sensor();
		if (engine.engine_temp<100)
		{
			engine.Engine_Temperature_Controller_state=ON;
			engine.engine_temp=125;
		}
		else if (engine.engine_temp>150)
		{
			engine.Engine_Temperature_Controller_state=ON;
			engine.engine_temp=125;
		}
		else engine.Engine_Temperature_Controller_state=OFF;
		display_current_vechile_state();
		sensors_choose_menu();
		break;
#endif
	default:
		printf("you enter wrong option\n\n");
		sensors_choose_menu();
	}



}


char traffic_color_sensor(void){
	char input3;
	do {
		printf("enter required color\n");
		scanf(" %c",&input3);
	} while ((input3!='G')&&(input3!='O')&&(input3!='R')&&(input3!='g')&&(input3!='o')&&(input3!='r'));
	return input3;
}


void room_temp_sensor(void){
	printf("enter room_temp\n");
	scanf("%d",&engine.room_temp);
}


#if (WITH_ENGINE_CONTROLLER==1)
void engine_temp_sensor(void){
	printf("enter engine_temp\n");
	scanf("%d",&engine.engine_temp);
}
#endif


int speed_test(char x){
	if (('g'==x)||('G'==x))
		return 100;
	else if (('O'==x)||('o'==x))
		return 30;
	else
		return 0;
}


void display_current_vechile_state(void){
	printf("engine state : ON\n");
	if (engine.AC_state==ON)
		printf("AC:ON\n");
	else printf("AC:OFF\n");
	printf("speed = %d\n",engine.speed);
	printf("room temperature= %d\n",engine.room_temp);
#if (WITH_ENGINE_CONTROLLER==1)
	if (engine.Engine_Temperature_Controller_state==OFF)
		printf("Engine_Temperature_Controller_state:OFF\n");
	else printf("Engine_Temperature_Controller_state:ON\n");
	printf("room temperature= %d\n\n",engine.engine_temp);
#endif
}

void intial_values(void){
		engine.speed=0;
		engine.room_temp=25;
#if (WITH_ENGINE_CONTROLLER==1)
		engine.engine_temp=110;
#endif
		engine.AC_state=OFF;
#if (WITH_ENGINE_CONTROLLER==1)
		engine.Engine_Temperature_Controller_state=OFF;
#endif
		engine.engine_state=OFF;
}