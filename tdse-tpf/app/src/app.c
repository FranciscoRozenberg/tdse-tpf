// Includes
# include "main.h"
# include "app.h"
// Definiciones
# define PERIODO 65535


// Declaración de variables externas
extern TIM_HandleTypeDef htim1;

uint32_t Cuenta_Encoder = 0;

// Funciones de la aplicación

void app_init(void)
{
	// INICIALIZA ENCODER
	HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
}

void app_update(void)
{
	Cuenta_Encoder = __HAL_TIM_GET_COUNTER(&htim1);
}
