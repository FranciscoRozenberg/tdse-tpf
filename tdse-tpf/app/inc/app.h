// Guarda contra C++
#ifndef APP_INC_APP_H_
#define APP_INC_APP_H_

#ifdef __cplusplus
extern "C" {
#endif

// Includes
#include <stdbool.h>

// Definiciones
typedef enum
{
	TEMPERATURA = 0,
	  CAPACIDAD = 1,
	  	  NIVEL = 2
}Estado_Menu_Ppal_t;

typedef enum
{
	MENU_PPAL = 0,
	MENU_INTERNO = 1
}Navegacion_Menu_t;

// Declaro funciones de app
void app_init(void);
void app_update(void);
void Probar_Capacidad(void);
void Probar_Temperatura(void);

// Fin de la guarda
#ifdef __cplusplus
}
#endif

#endif /* APP_INC_APP_H_ */
