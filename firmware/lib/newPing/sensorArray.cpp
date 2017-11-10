/* -------------------------------------------------------------------------
 *  Project: sumoGeek
 *  Author:  Germán Sc, Jander.
 *  Date:    07-10-17
 *  Version: 0.2
 *
 *  Description:
 *  Biblioteca de funciones encargadas de la lectura e interpretación de
 *	los datos de los sensores.
 * ------------------------------------------------------------------------- */
 #include <Arduino.h>
 #include <config.h>
 #include <newPing.h>

 #include "sensorArray.h"

 NewPing sensorL(SENSOR_LEFT_TRIGGER, SENSOR_LEFT_ECHO, SENSOR_MAX_DISTANCE);
 NewPing sensorR(SENSOR_RIGHT_TRIGGER, SENSOR_RIGHT_ECHO, SENSOR_MAX_DISTANCE);
 NewPing sensorC(SENSOR_CENTER_TRIGGER, SENSOR_CENTER_ECHO, SENSOR_MAX_DISTANCE);


 /* -------------------------------------------------------------------------
  *  Función de incialización del arreglo de sensores.
  * ------------------------------------------------------------------------- */
 void sensorInit(void)
 {
	 pinMode(SENSOR_CNY_PIN, INPUT_PULLUP);
 }


/* -------------------------------------------------------------------------
 *  Función para evaluar la direción del objetivo más cercano.
 * ------------------------------------------------------------------------- */
sensorResponse sensorEvaluate(void)
{
	unsigned long tempL = sensorL.ping_median(5, SENSOR_MAX_DISTANCE);
	unsigned long tempR = sensorR.ping_median(5, SENSOR_MAX_DISTANCE);
	unsigned long tempC = sensorC.ping_median(5, SENSOR_MAX_DISTANCE);

	if (tempL == 0)
	{
		tempL = 0xFFFF;
	}

	if (tempR == 0)
	{
		tempR = 0xFFFF;
	}

	if (tempC == 0)
	{
		tempC = 0xFFFF;
	}

	/* Evaluo Left vs Right si es que ambas son válidas. */
	if (tempL < tempR)
	{
		/* Evaluo Left vs Center. */
		if (tempL < tempC)
		{
			/* El menor es Left. */
			return SENSOR_LEFT;
		} else {
			/* El menor es Center. */
			return SENSOR_CENTER;
		}

	/*	Evalúo los casos de Right solo si esa medida es válida.	*/
	} else {

		/* Evaluo Right vs Center. */
		if (tempR < tempC)
		{
			/* El menor es Right. */
			return SENSOR_RIGHT;
		} else {
			/* El menor es Center. */
			if (tempC != 0xFFFF)
			{
				return SENSOR_CENTER;
			} else {
				return SENSOR_FAIL;
			}
		}
	}

	/*	No hay medida válida. */
	return SENSOR_FAIL;
}

/* -------------------------------------------------------------------------
 *  Función para evaluar las distancias laterales del objetivo
 * ------------------------------------------------------------------------- */
sysResponse sensorRight(float* distR){
	unsigned long tempR = sensorR.ping_median(5,SENSORR_MAX_DISTANCE);

  *distR = sensorConvert_cm(tempR);

  if(*distR==0)
      return SYS_FAIL;
  return SYS_SUCCESS;
}

sysResponse sensorLeft(float* distL){
	unsigned long tempL = sensorL.ping_median(5,SENSORL_MAX_DISTANCE);

  *distL = sensorConvert_cm(tempL);

  if(*distL==0)
      return SYS_FAIL;
  return SYS_SUCCESS;
}

sysResponse sensorCenter(float* distC){
	unsigned long tempC = sensorC.ping_median(5,SENSORC_MAX_DISTANCE);

  *distC = sensorConvert_cm(tempC);

  if(*distC==0)
      return SYS_FAIL;
  return SYS_SUCCESS;
}

uint8_t sensorScanner(void){
float dist;
uint8_t flag=0;
    if(sensorCenter(&dist) == SYS_SUCCESS)
        if(dist<10)
          flag |= (1<<SENSOR_CENTER);
		if(sensorRight(&dist) == SYS_SUCCESS)
        if(dist<10)
          flag |= (1<<SENSOR_RIGHT);
    if(sensorLeft(&dist) == SYS_SUCCESS)
        if(dist<10)
          flag |= (1<<SENSOR_LEFT);
return flag;
}

float sensorConvert_cm(unsigned long echoTime){
  return (echoTime / US_ROUNDTRIP_CM_FLOAT);
}
