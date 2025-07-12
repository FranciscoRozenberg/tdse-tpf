#include "app.h"
#include "main.h"

#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "ssd1306_tests.h"
#include "Display_Menu.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define  ALTO_LETRA_MEDIANA 18
#define LARGO_LETRA_MEDIANA 11
#define  ALTO_LETRA_GRANDE 24
#define LARGO_LETRA_GRANDE 16
#define RANGO_TEMPERATURA_ACEPTABLE 10

// Sprites para display (solo uso interno)____________________________________________________________

const unsigned char Sprite_Hielo_16x24[] = {
	// 'Copo De Nieve 16x24', 16x24px
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x42, 0x60, 0x83, 0x15, 0x54,
	0x08, 0x88, 0x14, 0x94, 0x02, 0xa0, 0x51, 0xc5, 0x2f, 0x7a, 0x51, 0xc5, 0x02, 0xa0, 0x14, 0x94,
	0x08, 0x88, 0x15, 0x54, 0x60, 0x83, 0x21, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	};
const unsigned char Sprite_Fuego_16x24 [] = {
	// 'Sprite Fuego 16x24', 16x24px
	0x00, 0x00, 0x00, 0x20, 0x00, 0x20, 0x00, 0x60, 0x00, 0x60, 0x01, 0xa0, 0x02, 0x18, 0x02, 0x18,
	0x02, 0x18, 0x0c, 0x04, 0x10, 0x44, 0x10, 0x44, 0x10, 0x62, 0x31, 0xa2, 0x31, 0xa2, 0x21, 0xa6,
	0x21, 0xbe, 0x21, 0xbe, 0x43, 0x82, 0x22, 0x02, 0x22, 0x02, 0x12, 0x04, 0x1f, 0xfc, 0x00, 0x00
	};
const unsigned char Sprite_Termo_0_16x24[] = {
	// 'Sprite Termo V2 0 16x24', 16x24px
	0x03, 0xfc, 0x04, 0x02, 0x04, 0x02, 0x04, 0x02, 0x04, 0x02, 0x07, 0xfe, 0x04, 0x02, 0x0c, 0x02,
	0x34, 0x02, 0x44, 0x02, 0x44, 0x02, 0x44, 0x02, 0x44, 0x02, 0x44, 0x02, 0x44, 0x02, 0x44, 0x02,
	0x44, 0x02, 0x44, 0x02, 0x34, 0x02, 0x0c, 0x02, 0x04, 0x02, 0x04, 0x02, 0x02, 0x04, 0x01, 0xf8
	};
const unsigned char Sprite_Termo_20_16x24[] = {
	// 'Sprite Termo V2 20 16x24', 16x24px
	0x03, 0xfc, 0x04, 0x02, 0x04, 0x02, 0x04, 0x02, 0x04, 0x02, 0x07, 0xfe, 0x04, 0x02, 0x0c, 0x02,
	0x34, 0x02, 0x44, 0x02, 0x44, 0x02, 0x44, 0x02, 0x44, 0x02, 0x44, 0x02, 0x44, 0x02, 0x44, 0x02,
	0x44, 0x02, 0x44, 0x02, 0x34, 0x02, 0x0f, 0xfe, 0x07, 0xfe, 0x07, 0xfe, 0x03, 0xfc, 0x01, 0xf8,
	};
const unsigned char Sprite_Termo_40_16x24[] = {
	// 'Sprite Termo V2 40 16x24', 16x24px
	0x03, 0xfc, 0x04, 0x02, 0x04, 0x02, 0x04, 0x02, 0x04, 0x02, 0x07, 0xfe, 0x04, 0x02, 0x0c, 0x02,
	0x34, 0x02, 0x44, 0x02, 0x44, 0x02, 0x44, 0x02, 0x44, 0x02, 0x44, 0x02, 0x44, 0x02, 0x44, 0x02,
	0x47, 0xfe, 0x47, 0xfe, 0x37, 0xfe, 0x0f, 0xfe, 0x07, 0xfe, 0x07, 0xfe, 0x03, 0xfc, 0x01, 0xf8,
	};
const unsigned char Sprite_Termo_60_16x24[] = {
	// 'Sprite Termo V2 60 16x24', 16x24px
	0x03, 0xfc, 0x04, 0x02, 0x04, 0x02, 0x04, 0x02, 0x04, 0x02, 0x07, 0xfe, 0x04, 0x02, 0x0c, 0x02,
	0x34, 0x02, 0x44, 0x02, 0x44, 0x02, 0x44, 0x02, 0x44, 0x02, 0x47, 0xfe, 0x47, 0xfe, 0x47, 0xfe,
	0x47, 0xfe, 0x47, 0xfe, 0x37, 0xfe, 0x0f, 0xfe, 0x07, 0xfe, 0x07, 0xfe, 0x03, 0xfc, 0x01, 0xf8,
	};
const unsigned char Sprite_Termo_80_16x24[] = {
	// 'Sprite Termo V2 80 16x24', 16x24px
	0x03, 0xfc, 0x04, 0x02, 0x04, 0x02, 0x04, 0x02, 0x04, 0x02, 0x07, 0xfe, 0x04, 0x02, 0x0c, 0x02,
	0x34, 0x02, 0x44, 0x02, 0x47, 0xfe, 0x47, 0xfe, 0x47, 0xfe, 0x47, 0xfe, 0x47, 0xfe, 0x47, 0xfe,
	0x47, 0xfe, 0x47, 0xfe, 0x37, 0xfe, 0x0f, 0xfe, 0x07, 0xfe, 0x07, 0xfe, 0x03, 0xfc, 0x01, 0xf8,
	};
const unsigned char Sprite_Termo_100_16x24[] = {
	// 'Sprite Termo V2 100 16x24', 16x24px
	0x03, 0xfc, 0x04, 0x02, 0x04, 0x02, 0x04, 0x02, 0x04, 0x02, 0x07, 0xfe, 0x07, 0xfe, 0x0f, 0xfe,
	0x37, 0xfe, 0x47, 0xfe, 0x47, 0xfe, 0x47, 0xfe, 0x47, 0xfe, 0x47, 0xfe, 0x47, 0xfe, 0x47, 0xfe,
	0x47, 0xfe, 0x47, 0xfe, 0x37, 0xfe, 0x0f, 0xfe, 0x07, 0xfe, 0x07, 0xfe, 0x03, 0xfc, 0x01, 0xf8
	};

//____________________________________________________________________________________________________

void Opcion_Init(Opcion_t* Salida, char* Etiqueta, void* Dato, unsigned char* Icono)
{
	//Opcion_t *Output = (Opcion_t *) Salida;
	//Output->Etiqueta = Etiqueta;
//	Output->Valor = Dato;
	//Output->Icono = Icono;
	Salida->Etiqueta = Etiqueta;
	Salida->Icono = Icono;
	Salida->Valor = Dato;
}

void Menu_init(void* Salida, char* Etiqueta, Opcion_t* Opciones, uint16_t Cantidad_De_Elementos)
{
	Menu_t *Output = (Menu_t*) Salida;
	Output->Etiqueta = Etiqueta;
	Output->Opciones = (Opcion_t *) Opciones;
	Output->Opciones->Seleccionado = true; //Marca el primer elemento de la lista de opciones como seleccionado
	Output->Cantidad_De_Elementos = Cantidad_De_Elementos;

}

void Display_Menu_Init(void)
{
	ssd1306_Init();
}


//display
void Display_Menu_Lista(void* Opcion_Data)
{
	Opcion_t* Display_Data = (Opcion_t*) Opcion_Data;
	//Ultimo_Elemento= (Display_Data->Cantidad_De_Elementos) -1;
	ssd1306_Fill(Black);
	for (uint16_t i=0 ;i < 3;i++) //En la pantalla entran hasta 3 elementos en este formato
	{
		ssd1306_SetCursor( 0, 18*i);
		ssd1306_DrawRectangle(0, 18*i, 11*strlen((Display_Data+i)->Etiqueta), 18*(i+1),  (Display_Data+i)->Seleccionado); //Si el elemento está seleccionado, Se dibuja el rectángulo en la misma posición
		ssd1306_WriteString((Display_Data+i)->Etiqueta, Font_11x18, !((Display_Data+i)->Seleccionado));
	}
/*
	ssd1306_SetCursor( 0, SSD1306_HEIGHT-8);
	ssd1306_DrawRectangle(0, SSD1306_HEIGHT-8, 11*strlen((Display_Data + Ultimo_Elemento-1)->Etiqueta), SSD1306_HEIGHT,  (Display_Data + Ultimo_Elemento-1)->Seleccionado);
	ssd1306_WriteString((Display_Data + Ultimo_Elemento-1)->Etiqueta, Font_6x8, !((Display_Data + Ultimo_Elemento-1)->Seleccionado));
	//ssd1306_WriteString("Salir", Font_6x8, White);

	ssd1306_SetCursor( SSD1306_WIDTH-6*7, SSD1306_HEIGHT-8);
	ssd1306_DrawRectangle(SSD1306_WIDTH - 11*strlen((Display_Data + Ultimo_Elemento)->Etiqueta) , SSD1306_HEIGHT-8, SSD1306_WIDTH, SSD1306_HEIGHT,  (Display_Data + Ultimo_Elemento)->Seleccionado);
	ssd1306_WriteString((Display_Data + Ultimo_Elemento)->Etiqueta , Font_6x8 , !((Display_Data + Ultimo_Elemento)->Seleccionado));
*/
	//ssd1306_WriteString("Guardar", Font_6x8, White);
}
void Display_Menu_Ppal(void* Opcion_Data)
{
	Opcion_t* Display_Data = (Opcion_t*) Opcion_Data;
	ssd1306_Fill(Black);
	ssd1306_SetCursor( SSD1306_WIDTH/2 - LARGO_LETRA_MEDIANA* ((float)strlen(Display_Data->Etiqueta))/2, 0);
	ssd1306_WriteString((Display_Data)->Etiqueta, Font_11x18, White);
	ssd1306_SetCursor(0,ALTO_LETRA_MEDIANA);
	ssd1306_DrawBitmap(41, 18, Display_Data->Icono, 43, 43, White);
}

void Display_Temperatura(void* Opcion_Data, uint16_t Temperatura_Leida)
{
	Opcion_t* Display_Data = (Opcion_t*) Opcion_Data;
	ssd1306_Fill(Black);
	ssd1306_SetCursor( SSD1306_WIDTH/2 - LARGO_LETRA_MEDIANA*strlen(Display_Data->Etiqueta)/2, 0);
	ssd1306_WriteString((Display_Data)->Etiqueta, Font_11x18, White);

	char buffer[] = {"000 C"};
	sprintf(buffer, "0%hu C", Temperatura_Leida );
	//sprintf(buffer, "0%hu C", *(( uint16_t *) ( Display_Data->Valor)) );
	if (Temperatura_Leida>=100)
	{
		char buffer[] = {">100 C"};
		ssd1306_SetCursor( SSD1306_WIDTH/2 - (3.5*LARGO_LETRA_GRANDE), SSD1306_HEIGHT/2);
		ssd1306_WriteString(buffer, Font_16x24, White);
		ssd1306_DrawCircle(SSD1306_WIDTH/2 +LARGO_LETRA_GRANDE+2, SSD1306_HEIGHT/2, 3, White);
		ssd1306_DrawBitmap(SSD1306_WIDTH/2 + 2.5*LARGO_LETRA_GRANDE + 2, SSD1306_HEIGHT/2, Sprite_Fuego_16x24, 16,24, White);
	} else if (Temperatura_Leida > *(( uint16_t *) ( Display_Data->Valor)) + RANGO_TEMPERATURA_ACEPTABLE)
	{
		ssd1306_SetCursor( SSD1306_WIDTH/2 - (2.5*LARGO_LETRA_GRANDE), SSD1306_HEIGHT/2);
		ssd1306_WriteString(buffer, Font_16x24, White);
		ssd1306_DrawCircle(SSD1306_WIDTH/2 +LARGO_LETRA_GRANDE+2, SSD1306_HEIGHT/2, 3, White);
		ssd1306_DrawBitmap(SSD1306_WIDTH/2 + 2.5*LARGO_LETRA_GRANDE + 2, SSD1306_HEIGHT/2, Sprite_Fuego_16x24, 16,24, White);
	} else if (Temperatura_Leida < *(( uint16_t *) ( Display_Data->Valor)) - RANGO_TEMPERATURA_ACEPTABLE)
	{
		ssd1306_SetCursor( SSD1306_WIDTH/2 - (2.5*LARGO_LETRA_GRANDE), SSD1306_HEIGHT/2);
		ssd1306_WriteString(buffer, Font_16x24, White);
		ssd1306_DrawCircle(SSD1306_WIDTH/2 +LARGO_LETRA_GRANDE+2, SSD1306_HEIGHT/2, 3, White);
		ssd1306_DrawBitmap(SSD1306_WIDTH/2 + 2.5*LARGO_LETRA_GRANDE + 2, SSD1306_HEIGHT/2 - 2, Sprite_Hielo_16x24, 16,24, White);
	}else if (Temperatura_Leida<=10)
	{
		char buffer[] = {">10 C"};
		ssd1306_SetCursor( SSD1306_WIDTH/2 - (2.5*LARGO_LETRA_GRANDE), SSD1306_HEIGHT/2);
		ssd1306_WriteString(buffer, Font_16x24, White);
		ssd1306_DrawCircle(SSD1306_WIDTH/2 +LARGO_LETRA_GRANDE+2, SSD1306_HEIGHT/2, 3, White);
		ssd1306_DrawBitmap(SSD1306_WIDTH/2 + 2.5*LARGO_LETRA_GRANDE + 2, SSD1306_HEIGHT/2, Sprite_Fuego_16x24, 16,24, White);
	} else
	{
	ssd1306_SetCursor( SSD1306_WIDTH/2 - (2.5*LARGO_LETRA_GRANDE), SSD1306_HEIGHT/2);
	ssd1306_WriteString(buffer, Font_16x24, White);
	ssd1306_DrawCircle(SSD1306_WIDTH/2 +LARGO_LETRA_GRANDE+2, SSD1306_HEIGHT/2, 3, White);
	}
}

void Display_Capacidad(void* Opcion_Data)
{
	Opcion_t* Display_Data = (Opcion_t*) Opcion_Data;
	ssd1306_Fill(Black);
	ssd1306_SetCursor( SSD1306_WIDTH/2 - LARGO_LETRA_MEDIANA*strlen(Display_Data->Etiqueta)/2, 0);
	ssd1306_WriteString((Display_Data)->Etiqueta, Font_11x18, White);
	uint16_t Capacidad_Mate = *(( uint16_t *) ( Display_Data->Valor));

	char buffer[] = {"000 ml"};
	uint16_t Capacidad_Mayor_a_100 = Capacidad_Mate - Capacidad_Mate%100;

	switch (Capacidad_Mayor_a_100)
	{
	case 0:
		sprintf(buffer, "0%hu ml", Capacidad_Mate);
		ssd1306_SetCursor( SSD1306_WIDTH/2 - (2.5*LARGO_LETRA_GRANDE), SSD1306_HEIGHT/2);
		ssd1306_WriteString(buffer, Font_16x24, White);
		break;

	default:
		sprintf(buffer, "%hu ml", Capacidad_Mate);
		ssd1306_SetCursor( SSD1306_WIDTH/2 - (2.5*LARGO_LETRA_GRANDE), SSD1306_HEIGHT/2);
		ssd1306_WriteString(buffer, Font_16x24, White);
		break;
	}

}

void Display_Nivel(void* Opcion_Data, uint16_t Nivel_De_Agua)
{
	Opcion_t* Display_Data = (Opcion_t*) Opcion_Data;
	uint16_t Nivel_En_Porcentaje = 100 * Nivel_De_Agua/ (*( (uint16_t *)Display_Data->Valor));
	ssd1306_Fill(Black);
	ssd1306_SetCursor( SSD1306_WIDTH/2 - LARGO_LETRA_MEDIANA*strlen(Display_Data->Etiqueta)/2, 0);
	ssd1306_WriteString((Display_Data)->Etiqueta, Font_11x18, White);


	uint16_t estado = Nivel_En_Porcentaje - Nivel_En_Porcentaje%20; //Nomas cambia de a 20 puntos
	char buffer[] = {"100 %%"};

	switch (estado)
	{
	case 100:
		sprintf(buffer, "%hu %%", Nivel_En_Porcentaje );
		ssd1306_SetCursor( SSD1306_WIDTH/2 - (2.5*LARGO_LETRA_GRANDE), SSD1306_HEIGHT/2);
		ssd1306_WriteString(buffer, Font_16x24, White);
		ssd1306_DrawBitmap(SSD1306_WIDTH/2 + 2.5*LARGO_LETRA_GRANDE + 2, SSD1306_HEIGHT/2, Sprite_Termo_100_16x24, 16,24, White);
		break;

	case 80:
		sprintf(buffer, "0%hu %%", Nivel_En_Porcentaje );
		ssd1306_SetCursor( SSD1306_WIDTH/2 - (2.5*LARGO_LETRA_GRANDE), SSD1306_HEIGHT/2);
		ssd1306_WriteString(buffer, Font_16x24, White);
		ssd1306_DrawBitmap(SSD1306_WIDTH/2 + 2.5*LARGO_LETRA_GRANDE + 2, SSD1306_HEIGHT/2, Sprite_Termo_80_16x24, 16,24, White);
		break;

	case 60:
		sprintf(buffer, "0%hu %%", Nivel_En_Porcentaje );
		ssd1306_SetCursor( SSD1306_WIDTH/2 - (2.5*LARGO_LETRA_GRANDE), SSD1306_HEIGHT/2);
		ssd1306_WriteString(buffer, Font_16x24, White);
		ssd1306_DrawBitmap(SSD1306_WIDTH/2 + 2.5*LARGO_LETRA_GRANDE + 2, SSD1306_HEIGHT/2, Sprite_Termo_60_16x24, 16,24, White);
		break;

	case 40:
		sprintf(buffer, "0%hu %%", Nivel_En_Porcentaje );
		ssd1306_SetCursor( SSD1306_WIDTH/2 - (2.5*LARGO_LETRA_GRANDE), SSD1306_HEIGHT/2);
		ssd1306_WriteString(buffer, Font_16x24, White);
		ssd1306_DrawBitmap(SSD1306_WIDTH/2 + 2.5*LARGO_LETRA_GRANDE + 2, SSD1306_HEIGHT/2, Sprite_Termo_40_16x24, 16,24, White);
		break;

	case 20:
		sprintf(buffer, "0%hu %%", Nivel_En_Porcentaje );
		ssd1306_SetCursor( SSD1306_WIDTH/2 - (2.5*LARGO_LETRA_GRANDE), SSD1306_HEIGHT/2);
		ssd1306_WriteString(buffer, Font_16x24, White);
		ssd1306_DrawBitmap(SSD1306_WIDTH/2 + 2.5*LARGO_LETRA_GRANDE + 2, SSD1306_HEIGHT/2, Sprite_Termo_20_16x24, 16,24, White);
		break;

	case 0:
		char* Template []= {"00%hu %%","0%hu %%"};
		bool Mayor_Que_10 = Nivel_En_Porcentaje - Nivel_En_Porcentaje%10;
		sprintf(buffer, (Template[Mayor_Que_10]), Nivel_En_Porcentaje );
		ssd1306_SetCursor( SSD1306_WIDTH/2 - (2.5*LARGO_LETRA_GRANDE), SSD1306_HEIGHT/2);
		ssd1306_WriteString(buffer, Font_16x24, White);
		ssd1306_DrawBitmap(SSD1306_WIDTH/2 + 2.5*LARGO_LETRA_GRANDE + 2, SSD1306_HEIGHT/2, Sprite_Termo_0_16x24, 16,24, White);
		break;
	}
}
