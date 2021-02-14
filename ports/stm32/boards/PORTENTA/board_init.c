#include <string.h>
#include "py/mphal.h"
#include "storage.h"
#include "sdram.h"

#if OPENAMP_PY
#include "modopenamp.h"
#endif

void PORTENTA_board_early_init(void) {

    /* Enable oscillator pin */
    __HAL_RCC_GPIOH_CLK_ENABLE();
    GPIO_InitTypeDef  gpio_osc_init_structure;
    gpio_osc_init_structure.Pin = GPIO_PIN_1;
    gpio_osc_init_structure.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_osc_init_structure.Pull = GPIO_PULLUP;
    gpio_osc_init_structure.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOH, &gpio_osc_init_structure);
    HAL_GPIO_WritePin(GPIOH, GPIO_PIN_1, 1);

    __HAL_RCC_GPIOJ_CLK_ENABLE();
    GPIO_InitTypeDef  gpio_eth_rst_init_structure;
    gpio_eth_rst_init_structure.Pin = GPIO_PIN_15;
    gpio_eth_rst_init_structure.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_eth_rst_init_structure.Pull = GPIO_PULLUP;
    gpio_eth_rst_init_structure.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOJ, &gpio_eth_rst_init_structure);
    HAL_GPIO_WritePin(GPIOJ, GPIO_PIN_15, 1);

    // Explicitly init SPI2 because it's not enabled as a block device
    // spi_bdev_ioctl(&spi_bdev2, BDEV_IOCTL_INIT, (uint32_t)&spiflash2_config);

    #if OPENAMP_PY
    OpenAMP_MPU_Config();
    SystemCoreClockUpdate();
    #endif
}

void PORTENTA_reboot_to_bootloader(void) {
    extern RTC_HandleTypeDef RTCHandle;
    HAL_RTCEx_BKUPWrite(&RTCHandle, RTC_BKP_DR0, 0xDF59);
    NVIC_SystemReset();
}

void PORTENTA_board_low_power(int mode)
{
    switch (mode) {
        case 0:     // Leave stop mode.
            __HAL_RCC_JPEG_CLK_SLEEP_DISABLE();
            sdram_leave_low_power();
            break;
        case 1:     // Enter stop mode.
            __HAL_RCC_JPEG_CLK_SLEEP_ENABLE();
            sdram_enter_low_power();
            break;
        case 2:     // Enter standby mode.
            sdram_powerdown();
            break;
    }
    // Enable QSPI deepsleep for modes 1 and 2
    mp_spiflash_deepsleep(&spi_bdev2.spiflash, (mode != 0));
}
