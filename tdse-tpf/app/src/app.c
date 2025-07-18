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
#define CANTIDAD_DE_OPCIONES_MENU_PPAL sizeof(Opciones_Menu_Ppal)/sizeof(Opcion_t)

// Variables Generales
extern TIM_HandleTypeDef htim1;
Encoder_t Encoder;

unsigned char temperaturas_43x43[] = {
		// 'Temperaturas 43x43png', 43x43px
		0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x60, 0xd8, 0x30, 0x00, 0x00, 0x40, 0xe0, 0x20, 0x38, 0x00,
		0x00, 0x80, 0xe0, 0x20, 0x38, 0x00, 0x01, 0x00, 0x12, 0xda, 0x40, 0x00, 0x02, 0x00, 0x0c, 0x21,
		0x80, 0x00, 0x04, 0x00, 0x0c, 0x21, 0x80, 0x00, 0x08, 0x00, 0x12, 0x22, 0x40, 0x00, 0x10, 0x00,
		0x01, 0x24, 0x00, 0x00, 0x20, 0x00, 0x90, 0xf8, 0x48, 0x00, 0x40, 0x00, 0x90, 0xf8, 0x48, 0x00,
		0x80, 0x00, 0x6f, 0xdf, 0xb0, 0x01, 0x10, 0x00, 0x90, 0xf8, 0x48, 0x02, 0x10, 0x00, 0x90, 0xf8,
		0x48, 0x04, 0x70, 0x00, 0x01, 0x24, 0x00, 0x08, 0x70, 0x00, 0x12, 0x22, 0x40, 0x10, 0x70, 0x00,
		0x0c, 0x21, 0x80, 0x23, 0x90, 0x00, 0x0c, 0x21, 0x80, 0x43, 0x90, 0x00, 0x12, 0xda, 0x40, 0x8c,
		0x0e, 0x00, 0xe0, 0x20, 0x39, 0x0c, 0x0e, 0x00, 0xe0, 0x20, 0x3a, 0x0c, 0x0e, 0x00, 0x60, 0xd8,
		0x34, 0x0c, 0x0e, 0x00, 0x00, 0x00, 0x08, 0x70, 0x01, 0x80, 0x00, 0x00, 0x10, 0x80, 0x61, 0x80,
		0x00, 0x00, 0x20, 0x80, 0x61, 0x80, 0x00, 0x00, 0x40, 0x80, 0x61, 0x80, 0x00, 0x00, 0x80, 0x80,
		0x70, 0x40, 0x00, 0x01, 0x00, 0x80, 0x70, 0x40, 0x00, 0x02, 0x03, 0x83, 0x90, 0x40, 0x00, 0x04,
		0x03, 0x83, 0x90, 0x40, 0x00, 0x08, 0x03, 0x83, 0x90, 0x40, 0x00, 0x10, 0x03, 0x03, 0x91, 0xc0,
		0x00, 0x20, 0x03, 0x03, 0x91, 0xc0, 0x00, 0x40, 0x03, 0x03, 0x9f, 0xc0, 0x00, 0x80, 0x03, 0x03,
		0x9f, 0xc0, 0x01, 0x00, 0x04, 0x0f, 0x80, 0x40, 0x02, 0x00, 0x04, 0x0f, 0x80, 0x40, 0x04, 0x00,
		0x03, 0x0c, 0x00, 0x40, 0x08, 0x00, 0x03, 0x0c, 0x00, 0x40, 0x10, 0x00, 0x03, 0x0c, 0x00, 0x40,
		0x20, 0x00, 0x00, 0xff, 0xff, 0x80, 0x40, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x00, 0x00, 0x00,
		0x00, 0x00
};

unsigned char mate_43x43[] = {
		// 'Dibujo Mate Vacio', 43x43px
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x1f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x01, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x01,
		0x00, 0x00, 0x00, 0x10, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x70, 0x00, 0x00, 0xc0, 0x00, 0x00, 0xff,
		0xff, 0xff, 0xe0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x00,
		0x00, 0xe0, 0x00, 0x00, 0x38, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x38, 0x00, 0x03, 0x80, 0x00, 0x00,
		0x38, 0x00, 0x03, 0x80, 0x00, 0x00, 0x38, 0x00, 0x03, 0x80, 0x00, 0x00, 0x18, 0x00, 0x03, 0x80,
		0x00, 0x00, 0x18, 0x00, 0x03, 0x80, 0x00, 0x00, 0x18, 0x00, 0x03, 0x80, 0x00, 0x00, 0x18, 0x00,
		0x03, 0x80, 0x00, 0x00, 0x38, 0x00, 0x03, 0x80, 0x00, 0x00, 0x38, 0x00, 0x03, 0x80, 0x00, 0x00,
		0x38, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x38, 0x00, 0x00, 0x70, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x70,
		0x00, 0x00, 0xe0, 0x00, 0x00, 0x1c, 0x00, 0x07, 0xc0, 0x00, 0x00, 0x1f, 0xc0, 0x1f, 0x00, 0x00,
		0x00, 0x00, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00};

unsigned char termo_43x43[] = {
		// 'Sprite Termo 43x43png', 43x43px
		0x00, 0x07, 0xff, 0xff, 0x80, 0x00, 0x00, 0x07, 0xff, 0xff, 0x80, 0x00, 0x00, 0x18, 0x00, 0x00,
		0x60, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x60, 0x00, 0x00, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x00, 0x18,
		0x00, 0x00, 0x60, 0x00, 0x00, 0x18, 0x00, 0x00, 0x60, 0x00, 0x00, 0x18, 0x00, 0x00, 0x60, 0x00,
		0x00, 0x18, 0x00, 0x00, 0x60, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x1f, 0xff, 0xff,
		0xe0, 0x00, 0x00, 0x18, 0x00, 0x00, 0x60, 0x00, 0x00, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x00, 0xfa,
		0x00, 0x00, 0x60, 0x00, 0x1f, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x1f, 0x1a, 0x00, 0x00, 0x60, 0x00,
		0x70, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x70, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x70, 0x1a, 0x00, 0x00,
		0x60, 0x00, 0x70, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x70, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x70, 0x1a,
		0x00, 0x00, 0x60, 0x00, 0x70, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x70, 0x1a, 0x00, 0x00, 0x60, 0x00,
		0x70, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x70, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x70, 0x1a, 0x00, 0x00,
		0x60, 0x00, 0x70, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x70, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x70, 0x1a,
		0x00, 0x00, 0x60, 0x00, 0x70, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x70, 0x1a, 0x00, 0x00, 0x60, 0x00,
		0x1f, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x1f, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x00, 0xfa, 0x00, 0x00,
		0x60, 0x00, 0x00, 0xfa, 0x00, 0x00, 0x60, 0x00, 0x00, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x00, 0x1a,
		0x00, 0x00, 0x60, 0x00, 0x00, 0x18, 0x00, 0x00, 0x60, 0x00, 0x00, 0x07, 0x00, 0x03, 0x80, 0x00,
		0x00, 0x07, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfc,
		0x00, 0x00
};
//___________________DECLARO ELEMENTOS DEL MENU PRINCIPAL___________________
static uint16_t Default_Data[]= {75, 100, 1500};
Opcion_t Opciones_Menu_Ppal[3];
char* Etiquetas_Menu_Ppal[] = {"Temperatura", "Capacidad", "Nivel"};
char* Etiqueta_De_Menu = "Menu Principal";
unsigned char* Iconos_Menu_Ppal[] = {temperaturas_43x43, mate_43x43, termo_43x43};

Menu_t Menu_Ppal;

Estado_Menu_Ppal_t Posicion_Menu;
Navegacion_Menu_t Navegacion_Menu;


//________________VARIABLES DE PRUEBA (BORRAR O COMENTAR EN PRODUCTO FINAL)________________
uint16_t Temperatura_Medida_Por_Sensor = 90;
uint16_t Nivel_De_Agua_Medido = 1500;


// Funciones de la aplicación

void app_init(void)
{


	// INICIALIZA ENCODER
	Leer_Encoder_Init(&Encoder, &htim1);

	//INICIALIZA MENU Y DISPLAY
	ssd1306_Init();
	for (int i = 0; i < CANTIDAD_DE_OPCIONES_MENU_PPAL; i++)
		{
			Opcion_Init(Opciones_Menu_Ppal+i, Etiquetas_Menu_Ppal[i], &(Default_Data[i]), Iconos_Menu_Ppal[i]);
		}

	Menu_init(&Menu_Ppal, Etiqueta_De_Menu, Opciones_Menu_Ppal, CANTIDAD_DE_OPCIONES_MENU_PPAL);
	Navegacion_Menu = MENU_PPAL;

}

void app_update(void)
{

	Leer_Encoder_Update(&Encoder);
	Posicion_Menu = (Encoder.Posicion)%3;

	if(!HAL_GPIO_ReadPin(GPIOC, B1_Pin))
	{
		Navegacion_Menu = !Navegacion_Menu;
	}

	switch(Navegacion_Menu)
	{
	case MENU_PPAL:
		Display_Menu_Ppal((Menu_Ppal.Opciones) + Posicion_Menu);
		break;
	case MENU_INTERNO:
		switch(Posicion_Menu)
		{
		case TEMPERATURA:
			Display_Temperatura(Menu_Ppal.Opciones, Temperatura_Medida_Por_Sensor);
			break;
		case CAPACIDAD:
			Display_Capacidad((Menu_Ppal.Opciones)+1);
			break;
		case NIVEL:
			Display_Nivel((Menu_Ppal.Opciones)+2, Nivel_De_Agua_Medido);
			break;
		break;
		}
	}

	ssd1306_UpdateScreen();
}


void Probar_Temperatura(void)
{
	Display_Temperatura(Menu_Ppal.Opciones, Temperatura_Medida_Por_Sensor);
		ssd1306_UpdateScreen();
		if(Temperatura_Medida_Por_Sensor > 60)
		{
			Temperatura_Medida_Por_Sensor--;
			HAL_Delay(1000);
		}
}

void Probar_Capacidad(void)
{
	if(Nivel_De_Agua_Medido > 00)
		{
			Display_Nivel((Menu_Ppal.Opciones)+2, Nivel_De_Agua_Medido);
			ssd1306_UpdateScreen();
			HAL_Delay(1000);
			Nivel_De_Agua_Medido-=0.1* *((uint16_t *)((Menu_Ppal.Opciones)+2)->Valor); //10% del nivel de agua total
		}
}
