
#include "main.h"
#include "Leer_Encoder.h"
#include "app.h"

// Definiciones Internas

#define VALOR_ENCODER_MEDIO 1
#define ENCODER_EN_ESPERA 	2
# define PERIODO 65535
# define VALOR_DE_UN_PASO 2
# define CICLOS_DE_ESPERA 5



void Leer_Encoder_Init(void *param, void *timer)
{

Encoder_t *Encoder = (Encoder_t *) param;

Encoder->Timer= (TIM_HandleTypeDef *) timer;
Encoder->Posicion=0;
Encoder->Tick = 0;

HAL_TIM_Encoder_Start(Encoder->Timer, TIM_CHANNEL_ALL);

Encoder->Ultimo_Valor = __HAL_TIM_GET_COUNTER(Encoder->Timer);

}

//uint32_t Cuenta_Encoder = 0;


void Leer_Encoder_Update(void *param)
{
	// Cuenta_Encoder = (__HAL_TIM_GET_COUNTER(Encoder.Timer)/VALOR_DE_UN_PASO)%PASOS_ENCODER;

	// Se carga el puntero a estructura
	Encoder_t *Encoder = (Encoder_t *) param;

	// Se guardan valores pertimentes
	uint32_t Cuenta_Cruda = __HAL_TIM_GET_COUNTER(Encoder->Timer);
	uint16_t estado = Encoder->Estado;

	switch (estado)
	{
	case VALOR_ENCODER_MEDIO :
		if (Cuenta_Cruda >= Encoder->Ultimo_Valor + VALOR_DE_UN_PASO)
		{
			Encoder->Posicion++;
			Encoder->Ultimo_Valor = Cuenta_Cruda;
			Encoder->Estado = ENCODER_EN_ESPERA;
			Encoder->Tick = 0;
			break;
		}
		else if (Cuenta_Cruda <= Encoder->Ultimo_Valor - VALOR_DE_UN_PASO)
		{
			Encoder->Posicion--;
			Encoder->Ultimo_Valor = Cuenta_Cruda;
			Encoder->Estado = (uint16_t) ENCODER_EN_ESPERA;
			Encoder->Tick = 0;
			break;
		}
		else
		{
			Encoder->Ultimo_Valor = Cuenta_Cruda;
			break;
		}
	case VALOR_ENCODER_CERO :
			if (Cuenta_Cruda >= Encoder->Ultimo_Valor + VALOR_DE_UN_PASO)
			{
				Encoder->Posicion++;
				Encoder->Ultimo_Valor = Cuenta_Cruda;
				Encoder->Estado = (uint16_t) ENCODER_EN_ESPERA;
				Encoder->Tick = 0;
				break;
			}
			else if (Cuenta_Cruda <= Encoder->Ultimo_Valor - VALOR_DE_UN_PASO)
			{
				Encoder->Posicion = VALOR_ENCODER_FINAL	-1;
				Encoder->Ultimo_Valor = Cuenta_Cruda;
				Encoder->Estado = (uint16_t) ENCODER_EN_ESPERA;
				Encoder->Tick = 0;
				break;
			}
	case VALOR_ENCODER_FINAL :
			if (Cuenta_Cruda >= Encoder->Ultimo_Valor + VALOR_DE_UN_PASO)
			{
				Encoder->Posicion = VALOR_ENCODER_CERO;
				Encoder->Ultimo_Valor = Cuenta_Cruda;
				Encoder->Estado = ENCODER_EN_ESPERA;
				Encoder->Tick = 0;
				break;
			}
			else if (Cuenta_Cruda <= Encoder->Ultimo_Valor - VALOR_DE_UN_PASO)
			{
				Encoder->Posicion = 19;
				Encoder->Ultimo_Valor = Cuenta_Cruda;
				Encoder->Estado = ENCODER_EN_ESPERA;
				Encoder->Tick = 0;
				break;
			}
			else
			{
				Encoder->Ultimo_Valor = Cuenta_Cruda;
				break;
			}
	case ENCODER_EN_ESPERA:
		if (Encoder->Tick < CICLOS_DE_ESPERA)
		{
			Encoder->Tick++;
		}
		else if(VALOR_ENCODER_CERO < Encoder->Posicion && Encoder->Posicion < VALOR_ENCODER_FINAL)
		{
			Encoder->Estado = (uint16_t) VALOR_ENCODER_MEDIO;
			Encoder->Ultimo_Valor = Cuenta_Cruda;
			break;
		}
		else
		{
			Encoder->Estado = Encoder->Posicion;
			break;
		}
	}

	//Cuenta_Encoder = (__HAL_TIM_GET_COUNTER(&htim1)/VALOR_DE_UN_PASO)%PASOS_ENCODER;
}



