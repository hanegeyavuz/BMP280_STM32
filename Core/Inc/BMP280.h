/*
 * BMP280.h
 *
 *  Created on: Jun 25, 2024
 *      Author: yhanege
 */

#ifndef INC_BMP280_H_
#define INC_BMP280_H_

#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <math.h>

//#define READ_START_ADRESS  0xF7
//#define CALIB_START_ADRESS 0x88
//#define BMP280_DEV_ID      0xEE

//REGISTER 0xF4
#define F4_osrs_t_skipped			0b00000000
#define F4_osrs_t_oversampling1		0b00100000
#define F4_osrs_t_oversampling2		0b01000000
#define F4_osrs_t_oversampling4		0b01100000
#define F4_osrs_t_oversampling8		0b10000000
#define F4_osrs_t_oversampling16	0b10100000
#define F4_osrs_p_skipped			0b00000000
#define F4_osrs_p_oversampling1		0b00000100
#define F4_osrs_p_oversampling2		0b00001000
#define F4_osrs_p_oversampling4		0b00001100
#define F4_osrs_p_oversampling8		0b00010000
#define F4_osrs_p_oversampling16	0b00010100

#define F4_mode_sleep				0b00000000
#define F4_mode_forced				0b00000001
#define F4_mode_normal				0b00000011

//REGISTER 0xF5
#define F5_t_sb_500us				0b00000000
#define F5_t_sb_62500us				0b00100000
#define F5_t_sb_125ms				0b01000000
#define F5_t_sb_250ms				0b01100000
#define F5_t_sb_500ms				0b10000000
#define F5_t_sb_1sec				0b10100000
#define F5_t_sb_2sec				0b11000000
#define F5_t_sb_4sec				0b11100000

#define F5_filter_1					0b00000000
#define F5_filter_2					0b00000010
#define F5_filter_5					0b00000100
#define F5_filter_11				0b00000110
#define F5_filter_22				0b00001010

#define F5_spi4w_en					0b00000000
#define F5_spi3w_en					0b00000001

typedef struct {

	I2C_HandleTypeDef *hi2c;
	signed long temperature_raw, pressure_raw;
	unsigned short reg_T1, reg_P1;
	signed short reg_T2, reg_T3, reg_P2, reg_P3, reg_P4, reg_P5, reg_P6, reg_P7,
			reg_P8, reg_P9;
	float temperature, pressure, altitude, init_height;

} bmp280_t;

uint8_t I2C_Read_Register(bmp280_t *bmp280, uint8_t device_adr,
		uint8_t internal_adr);

void I2C_Write_Register(bmp280_t *bmp280, uint8_t device_adr,
		uint8_t internal_adr, uint8_t data);

void BMP280_Init(bmp280_t *bmp280, uint8_t F4, uint8_t F5,
		I2C_HandleTypeDef *hi2c);

void BMP280_Calibration(bmp280_t *bmp280);

void BMP280_Read_All(bmp280_t *bmp280);

#endif /* INC_BMP280_H_ */
