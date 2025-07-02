# Proyecto Final T. de Sist. Embebidos
En este documento se detallan los distintos objetivos del Trabajo Práctico Final para la materia Taller de Sistemas Embebidos de la carrera de Ing. Electrónica - FIUBA. También se analizan distintas propuestas para alcanzar las metas enunciadas.
# Objetivos
Se busca construir una primera instancia del prototipo mínimo funcional para un sistema de cebador de mate automático con control de temperatura, el mismo deberá cumplir con las siguientes especificaciones:
- Ser capaz de detectar cuando un recipiente se coloca en una posición previamente establecida.
- Calcular el volumen interno del recipiente.
- Expulsar un caudal de agua por una boquilla, medirlo y frenar cuando se llegue un volumen en el que el recipiente se considere "lleno" .
- Escrutar de manera digital la temperatura y el nivel del agua dentro de su receptáculo interno antes de expulsarla, verificar que la temperatura de la misma sea correcta para evitar el cebado de bebidas demasiado frías o calientes y presentar esta información al usuario mediante un display LCD.
- Poseer un mecanismo de configuración que permita definir manualmente la temperatura óptima de agua a ser expulsada.

Todo esto debe ser logrado utilizando una placa de desarrollo STM con un procesador de 32 Bits. En este caso se seleccionó el modelo NUCLEO-F103RB. 

Finalmente, debe tenerse en cuenta que al ser esta una primera iteración solo se centra en los subsistemas básicos para que el proyecto se considere funcional. Sucesivas iteraciones podrían agregar más funcionalidades como un calentador para mantener la temperatura del agua dentro del receptáculo, un yerbatero automático o incluso un "modo cafetera" para aquellas personas que no disfrutan de nuestra bebida nacional.

# Subsistemas
Para cumplir los objetivos planteados anteriormente se plantea una serie de subsistemas que deberán funcionar de forma conjunta y sincronizada:
- ## Bomba Peristáltica: 
	- Construida usando motores paso a paso y una serie de mecanismos permitirá tener un caudal de agua estable, regulable y fácilmente medible en función de los pasos del motor. Esto último nos permitirá medir el caudal suministrado.
- ## Interfaz de usuario: 
	- Consiste de un display TFT y botones correspondientes a los comandos "escape", "siguiente" y "aceptar" que permitan desplazarse entre el menú de configuración del dispositivo así como observar información importante sobre el estado de distintos parámetros.
- ## Arreglo de sensores:
	- Una serie de sensores que permitan medir distintas magnitudes relevantes para el correcto funcionamiento del dispositivo:
	- ### Sensor de Distancia: 
		- Será el encargado de detectar la presencia del recipiente a rellenar.
		- Se usa un módulo VL6180x 
	- ### Sensor de temperatura: 
		- Permite medir la temperatura del agua dentro del receptáculo interno del dispositivo
	- ### Caudalímetro: 
		- Se integra un caudalímetro que, en base a los pasos que da el motor permite medir indirectamente la cantidad de agua expulsada a lo largo del tiempo.
# Croquis del Proyecto
Se realiza para ilustrar un diagrama simplificado de la estructura y forma física que tendrá. **ESTÁ LA FOTO DE LA PANTALLA DE UNA TABLET QUE MANDARON. CAMBIAR POR EL ARCHIVO DEL DIBUJO**
!['croquis del proyecto.jpg'](https://github.com/FranciscoRozenberg/tdse-tpf/blob/main/croquis%20del%20proyecto.jpg)
# Fuentes y Referencias
- [Video Explicativo Bombas Peristálticas](https://www.youtube.com/watch?si=b-XAVWznQKpABlHj&v=4RCeaTug2eA&feature=youtu.be)
- [Cómo conectar un encoder](https://done.land/components/humaninterface/rotaryencoder/usingmechanicalrotaryencoder/)
- 
