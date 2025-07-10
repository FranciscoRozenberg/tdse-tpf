#ifndef DISPLAY_MENU_H
#define DISPLAY_MENU_H

#ifdef __cplusplus
extern "C" {
#endif

// Includes
#include <stdbool.h>

// Definiciones

// Declaro funciones de app

typedef struct
{
	char* Etiqueta;
	void* Valor;
	bool Seleccionado;
}Opcion_t;

typedef struct
{
	char* Etiqueta;
	Opcion_t* Opciones;
}Menu_t;

void Menu_init(void* Salida, char* Etiqueta, Opcion_t* Opciones);
void Opcion_Init(void* Salida, char* Etiqueta, void* Dato);
void Display_Menu_Init(void);
void Display_Menu_Update(void* Menu_Data);


// Fin de la guarda
#ifdef __cplusplus
}
#endif

#endif /* APP_INC_APP_H_ */
