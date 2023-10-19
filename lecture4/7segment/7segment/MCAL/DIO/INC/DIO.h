/*
 * DIO.h
 *
 * Created: 10/17/2023 2:40:36 PM
 *  Author: amlta
 */ 


#ifndef DIO_H_
#define DIO_H_

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//============== Includes ==============
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#include "Atmega32.h"


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//========== Type Definitions ==========
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

typedef struct DIO_CFG_t {
	unsigned char DIO_PinNumber;		//Specifies the number bit number used
										//Configurations @ref DIO_PinNumber_define
	
	unsigned char DIO_Mode;			//Specifies the mode of the pin
									//Configurations @ref DIO_Mode_define
}DIO_CFG_t;




//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//== Macros Configuration References ==
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


//@ref DIO_PinNumber_define
#define DIO_PinNumber_0	0
#define DIO_PinNumber_1	1
#define DIO_PinNumber_2	2
#define DIO_PinNumber_3	3
#define DIO_PinNumber_4	4
#define DIO_PinNumber_5	5
#define DIO_PinNumber_6	6
#define DIO_PinNumber_7	7

//@ref DIO_Mode_define
#define DIO_Mode_INPUT		0
#define DIO_Mode_INPUT_FLO 2
#define DIO_Mode_OUTPUT	1



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//========== APIs Supported by "MCAL DIO DRIVER" ===========
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

/**================================================================
* @Fn - MCAL_DIO_INIT
* @brief - Initialize the portx
* @param[in] - DIO port
* @param[out] - DIO pin in the specific port (in the last parameter)
*               takes values @ref DIO_PinNumber  @ref GPIO_MODE  @ref DIO_FREQ
*/
void MCAL_DIO_INIT_PIN( DIO_t* PORTx ,  DIO_CFG_t* PIN);
//void MCAL_DIO_INIT_PORT(struct DIO_t * DIOx ,DIO_PortConfig_t *PORT_CONFIG);



/**================================================================
* @Fn - MCAL_DIO_RESET
* @brief - PORT needed to be reset -> takes values included GENERIC MACROS  DIO_RESET section in DIO header
* @param[in] - portx
*/
void MCAL_GPIO_RESET( DIO_t* PORTx_RESET);



/**================================================================
* @Fn - MCAL_DIO_READ_PIN
* @brief - Read a pin from portx
* @param[in] - portx
* @param[out] - Pin number in portx (the first parameter)
* @retval- 8 bit return value read from the pin (the second parameter)
*/
unsigned char MCAL_DIO_READ_PIN( DIO_t* PORTx , unsigned char PIN_NUMBER);



/**================================================================
* @Fn - MCAL_DIO_READ_PORT
* @brief - Read the whole port
* @param[in] - portx
* @retval- 16 bit value read from portx
*/
unsigned char MCAL_DIO_READ_PORT(  DIO_t * PORTx);



/**================================================================
* @Fn - MCAL_DIO_WRITE_PIN
* @brief - Write a value in a specific pin portx
* @param[in] - portx
* @param[in] - number of a specific pint in portx
* @param[out] - 8 bit value Written to pinx in portx
*/
void MCAL_DIO_WRITE_PIN( DIO_t * PORTx , unsigned char PIN_NUMBER , unsigned char VAL);



/**================================================================
* @Fn - MCAL_DIO_WRITE_PORT
* @brief - Write a value in the whole port
* @param[in] - portx
* @param[out] - 8 bit value Written to portx
*/
void MCAL_DIO_WRITE_PORT( DIO_t* PORTx , unsigned char VAL);



/**================================================================
* @Fn - MCAL_DIO_tOGGLE_PIN
* @brief - toggle a specific pin
* @param[in] - portx
* @param[in] - pin number
*/
void MCAL_DIO_tOGGLE_PIN( DIO_t* PORTx , unsigned char PIN_NUMBER);


/**================================================================
* @Fn - MCAL_struct DIO_tOGGLE_PORT
* @brief - toggle a specific pin
* @param[in] - portx
*
*/
void MCAL_DIO_tOGGLE_PORT( DIO_t* PORTx );


#endif /* DIO_H_ */