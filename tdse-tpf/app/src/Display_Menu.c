#include "app.h"
#include "main.h"

#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "ssd1306_tests.h"
#include "Display_Menu.h"
#include <stdbool.h>
#include <string.h>

#define ALTO_LETRA_MEDIANA 18
#define LARGO_LETRA_MEDIANA 11

void Opcion_Init(void* Salida, char* Etiqueta, void* Dato)
{
	Opcion_t *Output = (Opcion_t *) Salida;
	Output->Etiqueta = Etiqueta;
	Output->Valor = Dato;
}

void Menu_init(void* Salida, char* Etiqueta, Opcion_t* Opciones)
{
	Menu_t *Output = (Menu_t*) Salida;
	Output->Etiqueta = Etiqueta;
	Output->Opciones = (Opcion_t *) Opciones;
	Output->Opciones->Seleccionado=1;

}

void Display_Menu_Init(void)
{
	ssd1306_Init();
}


//display
void Display_Menu_Update(void* Menu_Data)
{
	Opcion_t* Display_Data = (Opcion_t*) Menu_Data;
	ssd1306_Fill(Black);
	for (uint16_t i=0 ;i < 3;i++) //En la pantalla entran hasta 3 elementos en este formato
	{
		ssd1306_SetCursor( 0, 18*i);
		ssd1306_DrawRectangle(0, 18, 11*strlen((Display_Data+i)->Etiqueta), 20,  (Display_Data+i)->Seleccionado);
		ssd1306_WriteString((Display_Data+i)->Etiqueta, Font_11x18, !((Display_Data+i)->Seleccionado));
	}
	/*ssd1306_SetCursor( 0, 0);
	ssd1306_WriteString(Display_Data->Etiqueta, Font_11x18, White);

	ssd1306_SetCursor( 0, 18);
	ssd1306_DrawRectangle(0, 18, 11*strlen((Display_Data+1)->Etiqueta), 20,  White);
	ssd1306_WriteString((Display_Data+1)->Etiqueta, Font_11x18, Black);

	ssd1306_SetCursor( 0, 18* 2);
	ssd1306_WriteString((Display_Data+2)->Etiqueta, Font_11x18, White);
*/
	ssd1306_SetCursor( 0, SSD1306_HEIGHT-8);
	ssd1306_WriteString("Salir", Font_6x8, White);
	ssd1306_SetCursor( SSD1306_WIDTH-6*7, SSD1306_HEIGHT-8);
	ssd1306_WriteString("Guardar", Font_6x8, White);

    ssd1306_UpdateScreen();
}

