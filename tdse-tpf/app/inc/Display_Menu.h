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
	unsigned char* Icono;
	bool Seleccionado;
}Opcion_t;

typedef struct
{
	char* Etiqueta;
	Opcion_t* Opciones;
	uint16_t Cantidad_De_Elementos;
}Menu_t;

void Menu_init(void* Salida, char* Etiqueta, Opcion_t* Opciones, uint16_t Cantidad_De_Elementos);
void Opcion_Init(Opcion_t* Salida, char* Etiqueta, void* Dato, unsigned char* Icono);
void Display_Menu_Init(void);
void Display_Menu_Lista(void* Opcion_Data);
void Display_Menu_Ppal(void* Opcion_Data);
void Display_Temperatura(void* Opcion_Data, uint16_t Temperatura_Leida);
void Display_Nivel(void* Opcion_Data, uint16_t Nivel_De_Agua);
void Display_Capacidad(void* Opcion_Data);


// Fin de la guarda
#ifdef __cplusplus
}
#endif

#endif /* APP_INC_APP_H_ */
