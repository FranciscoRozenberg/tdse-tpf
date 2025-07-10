// Includes
#include <stdio.h>

# include "main.h"
# include "app.h"

#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "ssd1306_tests.h"

#include "Display_Menu.h"
#include "Leer_Encoder.h"

// Definiciones


// Variables Generales
extern TIM_HandleTypeDef htim1;
Encoder_t Encoder;


static uint16_t Default_Data[]= {75, 100, 1.5};
Opcion_t Opciones_Menu_Ppal[4];
char* Etiquetas_Menu_Ppal[] = {"Ver Temp.", "Ver Capa. ", "Ver Agua","Ajustes"};
Menu_t Menu_Ppal;

Menu_t Menu_Ajustes;


uint16_t coso = 3;

Opcion_t Opciones_De_Prueba[5];
uint16_t* Dato_De_Prueba[] = {&coso, &coso, &coso, &coso, &coso};
char* Etiqueta_De_Prueba[] = {"prueba0", "prueba1", "prueba2","prueba3", "prueba4",};
char* Etiqueta_De_Menu = "Menu";


Menu_t Menu_De_Prueba;
// Funciones de la aplicación

void app_init(void)
{
	/*Opciones_De_Prueba[0].Etiqueta=*Etiqueta_De_Prueba;
	Opciones_De_Prueba[1].Etiqueta=*(Etiqueta_De_Prueba)+ 2*sizeof(*Etiqueta_De_Prueba);
	Opciones_De_Prueba[2].Etiqueta=*(Etiqueta_De_Prueba)+ 2*2*sizeof(*Etiqueta_De_Prueba);*/

	Leer_Encoder_Init(&Encoder, &htim1);
	Display_Menu_Init();
	for (int i = 0; i < sizeof(Opciones_Menu_Ppal)/sizeof(Opcion_t)-1; i++)
		{
			Opcion_Init(Opciones_Menu_Ppal+i, Etiquetas_Menu_Ppal[i], &(Default_Data[i]));
		}
	Opcion_Init(Opciones_Menu_Ppal+3, Etiquetas_Menu_Ppal[3], &Menu_Ajustes);
	Menu_init(&Menu_Ppal, Etiqueta_De_Menu, Opciones_Menu_Ppal);
	// INICIALIZA ENCODER
}

void app_update(void)
{
	//sprintf();
	Leer_Encoder_Update(&Encoder);
	Display_Menu_Update(Menu_Ppal.Opciones);
	HAL_Delay(2000);
	Display_Menu_Update( ( Menu_Ppal.Opciones) +1);
	HAL_Delay(2000);
	Display_Menu_Update( ( Menu_Ppal.Opciones) );



}
