/* -------------------------------------------------------------------------
 *  Project: sumoGeek
 *  Author:  Germán Sc.
 *  Date:    18-08-17
 *  Version: 0.1
 *
 *  Description:
 *  Archivo de configuración. Declaración de pines y constantes principales
 *	de funcionamiento.
 * ------------------------------------------------------------------------- */
#ifndef SRC_CONFIGURATION_H_
#define SRC_CONFIGURATION_H_

/* Declaracion de Tipos de Respuesta. */
typedef enum {
	SYS_SUCCESS = 0,                /* Respuesta Exitosa.           */
	SYS_FAIL                        /* Respuesta de Falla genérica. */
} sysResponse;

/* Declaración de pines y constantes de Motores. */
#define MOTOR_L_PIN_E	6          /* Enable del motor L. */
#define MOTOR_L_PIN_A	5          /*  Pin A del motor L. */
#define MOTOR_L_PIN_B	4          /*  Pin B del motor L. */

#define MOTOR_R_PIN_E	7          /* Enable del motor R. */
#define MOTOR_R_PIN_A	3          /*  Pin A del motor R. */
#define MOTOR_R_PIN_B	2          /*  Pin B del motor R. */

#define MOTOR_LR_OFFSET   0.8  /* Offset para igualar velocidad de motores. */

#define MOTOR_CRUISE_SPEED    100  /* Velocidad para movimientos.  */
#define MOTOR_ATTACK_SPEED    200  /* Velocidad de ataque.         */
#define MOTOR_TURN_SPEED      150  /* Velocidad de giro.           */
#define MOTOR_TURN_TIME       650  /* Tiempo en ms para girar 90º. */

/* Declaración de pines de Sensores. */
#define SENSOR_LEFT_TRIGGER     0  /*  Pin Trigger del sensor Izquierdo. */
#define SENSOR_LEFT_ECHO        0  /*  Pin Echo del sensor Izquierdo.    */

#define SENSOR_RIGHT_TRIGGER	0  /*  Pin Trigger del sensor Derecho.   */
#define SENSOR_RIGHT_ECHO       0  /*  Pin Echo del sensor Derecho.      */

#define SENSOR_CENTER_TRIGGER   0  /*  Pin Trigger del sensor Central.   */
#define SENSOR_CENTER_ECHO      0  /*  Pin Echo del sensor Central.      */

#define SENSOR_MAX_DISTANCE    50  /*  Distancia máxima a evaluar.       */

/* Declaracion de pines del módulo BT. */
#define COMMS_BT_RX    10
#define COMMS_BT_TX    11

#endif	/* SRC_CONFIGURATION_H_ */
