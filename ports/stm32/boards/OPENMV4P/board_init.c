#include "py/mphal.h"
#include "storage.h"
#include "sdram.h"

void board_low_power(int mode)
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
    mp_spiflash_deepsleep(&spi_bdev.spiflash, (mode != 0));
}
