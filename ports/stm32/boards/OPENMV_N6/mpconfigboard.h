#define MICROPY_HW_BOARD_NAME       "OpenMV N6"
#define MICROPY_HW_MCU_NAME         "STM32N657X0"

#define MICROPY_GC_STACK_ENTRY_TYPE uint32_t
#define MICROPY_ALLOC_GC_STACK_SIZE (128)

#define MICROPY_HW_HAS_SWITCH       (0)
#define MICROPY_HW_HAS_FLASH        (0)
#define MICROPY_HW_FLASH_MOUNT_AT_BOOT (0)
#define MICROPY_HW_ENABLE_RNG       (0)
#define MICROPY_HW_ENABLE_RTC       (0)
#define MICROPY_HW_ENABLE_ADC       (0)
#define MICROPY_HW_ENABLE_DAC       (0)
#define MICROPY_HW_ENABLE_USB       (1)
#define MICROPY_PY_PYB_LEGACY       (0)

#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (0)
#define MICROPY_HW_ENTER_BOOTLOADER_VIA_RESET   (0)

extern void board_early_init(void);
#define MICROPY_BOARD_EARLY_INIT    board_early_init

extern void board_enter_bootloader(void);
#define MICROPY_BOARD_ENTER_BOOTLOADER(nargs, args) board_enter_bootloader()

// HSE is 48MHz, this gives a CPU frequency of 800MHz.
#define MICROPY_HW_CLK_PLLM         (6)
#define MICROPY_HW_CLK_PLLN         (100)
#define MICROPY_HW_CLK_PLLP1        (1)
#define MICROPY_HW_CLK_PLLP2        (1)
#define MICROPY_HW_CLK_PLLFRAC      (0)

// Uart buses
#define MICROPY_HW_UART2_TX         (pyb_pin_BT_TXD)
#define MICROPY_HW_UART2_RX         (pyb_pin_BT_RXD)
#define MICROPY_HW_UART2_RTS        (pyb_pin_BT_RTS)
#define MICROPY_HW_UART2_CTS        (pyb_pin_BT_CTS)

#define MICROPY_HW_UART7_TX         (pyb_pin_PE8)
#define MICROPY_HW_UART7_RX         (pyb_pin_PE7)

// I2C buses
//#define MICROPY_HW_I2C2_SCL         (pyb_pin_PB10)
//#define MICROPY_HW_I2C2_SDA         (pyb_pin_PB11)
//
//#define MICROPY_HW_I2C4_SCL         (pyb_pin_PE13)
//#define MICROPY_HW_I2C4_SDA         (pyb_pin_PE14)

// SPI buses
#define MICROPY_HW_SPI2_NSS         (pyb_pin_PA11)
#define MICROPY_HW_SPI2_SCK         (pyb_pin_PA12)
#define MICROPY_HW_SPI2_MISO        (pyb_pin_PD11)
#define MICROPY_HW_SPI2_MOSI        (pyb_pin_PD7)

#define MICROPY_HW_SPI4_NSS         (pyb_pin_PE11)
#define MICROPY_HW_SPI4_SCK         (pyb_pin_PE12)
#define MICROPY_HW_SPI4_MISO        (pyb_pin_PB6)
#define MICROPY_HW_SPI4_MOSI        (pyb_pin_PB7)

// USER is pulled high, and pressing the button makes the input go low.
#define MICROPY_HW_USRSW_PIN        (pyb_pin_BUTTON)
#define MICROPY_HW_USRSW_PULL       (GPIO_NOPULL)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED    (0)

// LEDs
#define MICROPY_HW_LED1             (pyb_pin_LED_RED)
#define MICROPY_HW_LED2             (pyb_pin_LED_GREEN)
#define MICROPY_HW_LED3             (pyb_pin_LED_BLUE)
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_low(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_high(pin))

// WiFi SDMMC
#define MICROPY_HW_SDIO_SDMMC       (2)
#define MICROPY_HW_SDIO_CK          (pyb_pin_WL_SDIO_CK)
#define MICROPY_HW_SDIO_CMD         (pyb_pin_WL_SDIO_CMD)
#define MICROPY_HW_SDIO_D0          (pyb_pin_WL_SDIO_D0)
#define MICROPY_HW_SDIO_D1          (pyb_pin_WL_SDIO_D1)
#define MICROPY_HW_SDIO_D2          (pyb_pin_WL_SDIO_D2)
#define MICROPY_HW_SDIO_D3          (pyb_pin_WL_SDIO_D3)

// SD Card SDMMC
#define MICROPY_HW_SDCARD_SDMMC     (1)
#define MICROPY_HW_SDCARD_CK        (pyb_pin_SD_SDIO_CK)
#define MICROPY_HW_SDCARD_CMD       (pyb_pin_SD_SDIO_CMD)
#define MICROPY_HW_SDCARD_D0        (pyb_pin_SD_SDIO_D0)
#define MICROPY_HW_SDCARD_D1        (pyb_pin_SD_SDIO_D1)
#define MICROPY_HW_SDCARD_D2        (pyb_pin_SD_SDIO_D2)
#define MICROPY_HW_SDCARD_D3        (pyb_pin_SD_SDIO_D3)
#define MICROPY_HW_SDCARD_MOUNT_AT_BOOT (1)

// USB config
#define MICROPY_HW_USB_HS           (1)
#define MICROPY_HW_USB_HS_IN_FS     (1)
#define MICROPY_HW_USB_MAIN_DEV     (USB_PHY_HS_ID)
#define MICROPY_HW_USB_MSC          (0)
#define MICROPY_HW_USB_HID          (0)
#define MICROPY_HW_USB_VID          0x37C5
#define MICROPY_HW_USB_PID          0x1206
#define MICROPY_HW_USB_PID_CDC      (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_MSC      (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC_MSC  (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC_HID  (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC_MSC_HID  (MICROPY_HW_USB_PID)

// Murata 1YN configuration
#define CYW43_CHIPSET_FIRMWARE_INCLUDE_FILE     "lib/cyw43-driver-spi/firmware/w43439_sdio_1yn_7_95_59_combined.h"
#define CYW43_WIFI_NVRAM_INCLUDE_FILE           "lib/cyw43-driver-spi/firmware/wifi_nvram_1yn.h"
#define CYW43_BT_FIRMWARE_INCLUDE_FILE          "lib/cyw43-driver-spi/firmware/cyw43_btfw_1yn.h"

// Bluetooth config
#define MICROPY_HW_BLE_UART_ID              (PYB_UART_2)
#define MICROPY_HW_BLE_UART_BAUDRATE        (115200)
#define MICROPY_HW_BLE_UART_BAUDRATE_SECONDARY (3000000)
#define MICROPY_HW_BLE_UART_BAUDRATE_DOWNLOAD_FIRMWARE (3000000)
