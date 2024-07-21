#ifndef INC_ADXL345_H_
#define INC_ADXL345_H_

#define DEVID           0x00
#define OFSX            0x1E
#define OFSY            0x1F
#define OFSZ            0x20
#define DUR             0x21
#define LATENT          0x22
#define WINDOW          0x23
#define THRESH_ACT      0x24
#define THRESH_INACT    0x25
#define TIME_INACT      0x26
#define ACT_INACT_CTL   0x27
#define THRESH_FF       0x28
#define TIME_FF         0x29
#define TAP_AXES        0x2A
#define ACT_TAP_STATUS  0x2B
#define BW_RATE         0x2C
#define POWER_CTL       0x2D
#define INT_ENABLE      0x2E
#define INT_MAP         0x2F
#define INT_SOURCE      0x30
#define DATA_FORMAT     0x31
#define DATAX0          0x32
#define DATAX1          0x33
#define DATAY0          0x34
#define DATAY1          0x35
#define DATAZ0          0x36
#define DATAZ1          0x37
#define FIFO_CTL        0x38
#define FIFO_STATUS     0x39

#define ID_CODE         0xE5
#define RANGE_4G        0x01
#define POWER_CTL_RESET 0x00
#define POWER_CTL_VALUE 0x08    // MEASURE AND WAKE UP 8Hz

#define I2C_ADDRESS     0x53
#define I2C_READ        0x01
#define I2C_WRITE       0x00
#define I2C_READ_ADD    (I2C_ADDRESS << 1 | I2C_READ)
#define I2C_WRITE_ADD   (I2C_ADDRESS << 1 | I2C_WRITE)
#define I2C_TIMEOUT     100

#define I2C_SIZE_1      1
#define I2C_SIZE_2      2
#define I2C_W_DATA_SIZE 2

#define BYTE_SIZE       8

#define AX_INDEX_H      1
#define AX_INDEX_L      0
#define AY_INDEX_H      3
#define AY_INDEX_L      2
#define AZ_INDEX_H      5
#define AZ_INDEX_L      4

#define VALUES_SIZE     6

#define RESOLUTION_4G   ((float)1/128)

typedef struct values
{
    float ax;
    float ay;
    float az;
} adxl345_values;


void ADXL345_Init(I2C_HandleTypeDef *hi2c);

void ADXL345_GetValues(I2C_HandleTypeDef *hi2c, adxl345_values *values);

#endif /* INC_ADXL345_H_ */
