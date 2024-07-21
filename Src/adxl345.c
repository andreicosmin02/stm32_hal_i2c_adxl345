#include "main.h"
#include "adxl345.h"

void ADXL345_Init(I2C_HandleTypeDef *hi2c)
{
    uint8_t id_status;
    uint8_t data[I2C_W_DATA_SIZE];

    // Reading the device ID
    if (HAL_I2C_Mem_Read(hi2c, I2C_READ_ADD, DEVID, I2C_SIZE_1,
                         &id_status, I2C_SIZE_1,
                         I2C_TIMEOUT) == HAL_ERROR)
    {
        Error_Handler();
    }

    // Verifying the ID
    if (id_status != ID_CODE)
    {
        Error_Handler();
    }

    // Data format range 4g
    data[0] = DATA_FORMAT;
    data[1] = RANGE_4G;
    if (HAL_I2C_Master_Transmit(hi2c, I2C_WRITE_ADD, data, I2C_SIZE_2,
                                I2C_TIMEOUT) == HAL_ERROR)
    {
        Error_Handler();
    }

    // Reset all bits
    data[0] = POWER_CTL;
    data[1] = POWER_CTL_RESET;
    if (HAL_I2C_Master_Transmit(hi2c, I2C_WRITE_ADD, data, I2C_SIZE_2,
                                I2C_TIMEOUT) == HAL_ERROR)
    {
        Error_Handler();
    }

    // Measure and wake up 8hz
    data[0] = POWER_CTL;
    data[1] = POWER_CTL_VALUE;
    if (HAL_I2C_Master_Transmit(hi2c, I2C_WRITE_ADD, data, I2C_SIZE_2,
                                I2C_TIMEOUT) == HAL_ERROR)
    {
        Error_Handler();
    }
}

void ADXL345_GetValues(I2C_HandleTypeDef *hi2c, adxl345_values *values)
{
    uint8_t data[VALUES_SIZE];

    if (HAL_I2C_Mem_Read(hi2c, I2C_READ_ADD, DATAX0, I2C_SIZE_1,
                         data, VALUES_SIZE,
                         I2C_TIMEOUT) == HAL_ERROR)
    {
        Error_Handler();
    }

    values->ax = (float) ((uint16_t)(data[AX_INDEX_H] << BYTE_SIZE) | (data[AX_INDEX_L])) * RESOLUTION_4G;
    values->ay = (float) ((uint16_t)(data[AY_INDEX_H] << BYTE_SIZE) | (data[AY_INDEX_L])) * RESOLUTION_4G;
    values->az = (float) ((uint16_t)(data[AZ_INDEX_H] << BYTE_SIZE) | (data[AZ_INDEX_L])) * RESOLUTION_4G;
}
