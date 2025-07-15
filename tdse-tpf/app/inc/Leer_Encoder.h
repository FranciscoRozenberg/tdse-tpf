// Guarda contra C++
#ifndef __ENCODER_H
#define __ENCODER_H

#ifdef __cplusplus
extern "C" {
#endif

// Includes
#include <stdbool.h>

// Definiciones Externas
#define VALOR_ENCODER_CERO 	0
#define VALOR_ENCODER_FINAL	20


typedef struct
{
	TIM_HandleTypeDef* Timer;
	uint16_t Posicion;
	uint16_t Estado;
	uint16_t Tick;
	uint32_t Ultimo_Valor;
} Encoder_t;

// Declaro funciones de app
void Leer_Encoder_Init(void *param, void *timer);
void Leer_Encoder_Update(void *param);

// Fin de la guarda
#ifdef __cplusplus
}
#endif

#endif /* APP_INC_APP_H_ */
