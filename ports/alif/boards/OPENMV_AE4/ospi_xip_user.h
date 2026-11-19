// This file is needed by ospi_xip/source/ospi/ospi_drv.c.
#define OSPI_XIP_ENABLE_AES_DECRYPTION (0)
#define OSPI_XIP_RX_SAMPLE_DELAY (4)
// At 200MHz (baud divider 2) the drive edge must be 0, so the TXD/OE
// lines are delayed instead. Each delay step is ~350ps.
#define OSPI_XIP_DDR_DRIVE_EDGE (0)
#define OSPI_XIP_TXD_DELAY (4)
// At 200MHz, an RXDS delay of 5 or less fails, and 7 or more fails
// under sustained reads (e.g. from the NPU), independent of the TXD
// delay (3..5).
#define OSPI_XIP_RXDS_DELAY (6)
