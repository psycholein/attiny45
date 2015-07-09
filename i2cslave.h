void i2c_init(uint8_t address);

#define buffer_size 16 /*!< I2C buffer size (in bytes (2..254)) */
volatile uint8_t i2c_buffer[buffer_size]; /*!< I2C buffer */
volatile uint8_t buffer_adr; /*!< Virtual buffer address register */

#if 	(buffer_size > 254)
#error Buffer to big! 254 bytes max.

#elif 	(buffer_size < 2)
#error Buffer to small! 2 bytes min.
#endif

#define DDR_USI             DDRB
#define PORT_USI            PORTB
#define PIN_USI             PINB
#define PORT_USI_SDA        PB0
#define PORT_USI_SCL        PB2
#define PIN_USI_SDA         PINB0
#define PIN_USI_SCL         PINB2
#define USI_START_COND_INT  USISIF
#define USI_START_VECTOR    USI_START_vect
#define USI_OVERFLOW_VECTOR USI_OVF_vect

