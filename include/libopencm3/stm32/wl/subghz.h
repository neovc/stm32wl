#ifndef LIBOPENCM3_SUBGHZ_H
#define LIBOPENCM3_SUBGHZ_H

#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/gpio.h>

#define SUBGHZ_DEFAULT_TIMEOUT    100U /* SUBGHZ default timeout: 100ms */
#define SUBGHZ_RFBUSY_LOOP_TIME   ((rcc_ahb_frequency*24U)>>20U)

/* Registers */
#define SUBGHZ_RAMPUPH               0x0F0
#define SUBGHZ_RAMPUPL               0x0F1
#define SUBGHZ_RAMPDNH               0x0F2
#define SUBGHZ_RAMPDNL               0x0F3
#define SUBGHZ_FRAMELIMH             0x0F4
#define SUBGHZ_FRAMELIML             0x0F5

#define SUBGHZ_GBSYNCR               0x6AC
#define SUBGHZ_GBSYNCR_SBITSYNCEN    (1 << 6)
#define SUBGHZ_GBSYNCR_RXDINV        (1 << 5)
#define SUBGHZ_GBSYNCR_BITSYNCDIS    (1 << 4)

#define SUBGHZ_GCFORH                0x6B0
#define SUBGHZ_GCFORL                0x6B1

#define SUBGHZ_GPKTCTL1R                  0x6B4
#define SUBGHZ_GPKTCTL1R_PBDETON          (1 << 2)
#define SUBGHZ_GPKTCTL1R_PBDETLEN_8BIT    0x0
#define SUBGHZ_GPKTCTL1R_PBDETLEN_16BIT   0x1
#define SUBGHZ_GPKTCTL1R_PBDETLEN_24BIT   0x2
#define SUBGHZ_GPKTCTL1R_PBDETLEN_32BIT   0x3
#define SUBGHZ_GPKTCTL1R_PBDETLEN_OFFSET  0
#define SUBGHZ_GPKTCTL1R_PBDETLEN_MASK    0x03

#define SUBGHZ_GPKTCTL1AR            0x6B8
#define SUBGHZ_GPKTCTL1AR_SYNCDETEN  (1 << 5)
#define SUBGHZ_GPKTCTL1AR_CONTTX     (1 << 4)
#define SUBGHZ_GPKTCTL1AR_INFSQEQEN  (1 << 1)
#define SUBGHZ_GPKTCTL1AR_WHITEINI8  (1 << 0)

#define SUBGHZ_GPKTCTL1AR_INFSEQSEL_5555   0x0
#define SUBGHZ_GPKTCTL1AR_INFSEQSEL_0000   0x1
#define SUBGHZ_GPKTCTL1AR_INFSEQSEL_FFFF   0x2
#define SUBGHZ_GPKTCTL1AR_INFSEQSEL_PRBS9  0x3
#define SUBGHZ_GPKTCTL1AR_INFSEQSEL_OFFSET 2
#define SUBGHZ_GPKTCTL1AR_INFSEQSEL_MASK   0x3

#define SUBGHZ_GWHITEINIRL           0x6B9
#define SUBGHZ_GRTXPLDLEN            0x6BB

#define SUBGHZ_GCRCINIRH             0x6BC
#define SUBGHZ_GCRCINIRL             0x6BD
#define SUBGHZ_GCRCPOLRH             0x6BE
#define SUBGHZ_GCRCPOLRL             0x6BF

#define SUBGHZ_GSYNCR0               0x6C0
#define SUBGHZ_GSYNCR1               0x6C1
#define SUBGHZ_GSYNCR2               0x6C2
#define SUBGHZ_GSYNCR3               0x6C3
#define SUBGHZ_GSYNCR4               0x6C4
#define SUBGHZ_GSYNCR5               0x6C5
#define SUBGHZ_GSYNCR6               0x6C6
#define SUBGHZ_GSYNCR7               0x6C7

/*
#define SUBGHZ_GSYNCR0               0x6C7
#define SUBGHZ_GSYNCR1               0x6C6
#define SUBGHZ_GSYNCR2               0x6C5
#define SUBGHZ_GSYNCR3               0x6C4
#define SUBGHZ_GSYNCR4               0x6C3
#define SUBGHZ_GSYNCR5               0x6C2
#define SUBGHZ_GSYNCR6               0x6C1
#define SUBGHZ_GSYNCR7               0x6C0
*/

#define SUBGHZ_GNODEADR              0x6CD
#define SUBGHZ_GBCASTADDR            0x6CE

#define SUBGHZ_GAFCR                 0x6D1

#define SUBGHZ_LPLDLENR              0x702
#define SUBGHZ_LSYNCTIMEOUTR         0x706
#define SUBGHZ_LIQPOMR               0x735
#define SUBGHZ_LIQPOLR               0x736

#define SUBGHZ_LSYNCRH               0x740
#define SUBGHZ_LSYNCRL               0x741

#define SUBGHZ_TXADRPTR              0x802
#define SUBGHZ_RXADRPTRR             0x803
#define SUBGHZ_BWSELR                0x807

#define SUBGHZ_RNGR3                 0x819
#define SUBGHZ_RNGR2                 0x81A
#define SUBGHZ_RNGR1                 0x81B
#define SUBGHZ_RNGR0                 0x81C

#define SUBGHZ_SDCFG0R               0x889
#define SUBGHZ_AGCRSSIC0R            0x89B
#define SUBGHZ_AGCRSSICTL0R          0x89C

#define SUBGHZ_RXGAINCR              0x8AC
#define SUBGHZ_RXGAINCR_PMODE_SAVING 0x00
#define SUBGHZ_RXGAINCR_PMODE_BOOST1 0x01
#define SUBGHZ_RXGAINCR_PMODE_BOOST2 0x02
#define SUBGHZ_RXGAINCR_PMODE_BOOST3 0x03

#define SUBGHZ_AGCGFORSTCFGR         0x8B8
#define SUBGHZ_AGCGFORSTPOWTHR       0x8B9

#define SUBGHZ_TXCLAMPR              0x8D9
#define REG_ANA_LNA                  0x8E2
#define REG_ANA_MIXER                0x8E5

#define SUBGHZ_PAOCPR                0x8E7
#define SUBGHZ_PAOCPR_OCP_MAX60MA    0x18
#define SUBGHZ_PAOCPR_OCP_MAX140MA   0x38

#define SUBGHZ_RTCCTLR               0x902
#define SUBGHZ_RTCCTLR_RTCEN         (1 << 0)

#define SUBGHZ_RTCPRDR2              0x906
#define SUBGHZ_RTCPRDR1              0x907
#define SUBGHZ_RTCPRDR0              0x908

#define SUBGHZ_HSEINTRIMR            0x911
#define SUBGHZ_HSEINTRIMR_113PF      0x00
#define SUBGHZ_HSEINTRIMR_203PF      0x12
#define SUBGHZ_HSEINTRIMR_334PF      0x2F
#define SUBGHZ_HSEINTRIMR_OFFSET     0
#define SUBGHZ_HSEINTRIMR_MASK       0x2F

#define SUBGHZ_HSEOUTTRIMR           0x912
#define SUBGHZ_HSEOUTTRIMR_113PF     0x00
#define SUBGHZ_HSEOUTTRIMR_203PF     0x12
#define SUBGHZ_HSEOUTTRIMR_334PF     0x2F
#define SUBGHZ_HSEOUTTRIMR_OFFSET    0
#define SUBGHZ_HSEOUTTRIMR_MASK      0x2F

#define SUBGHZ_SMPSC0R               0x916
#define SUBGHZ_SMPSC0R_CLKDE         (1 << 6)

#define SUBGHZ_PCR                   0x91A
#define SUBGHZ_PCR_CLE               (1 << 6)
#define SUBGHZ_PCR_CLV_25MA          0x0
#define SUBGHZ_PCR_CLV_50MA          0x1
#define SUBGHZ_PCR_CLV_100MA         0x2
#define SUBGHZ_PCR_CLV_200MA         0x3
#define SUBGHZ_PCR_CLV_OFFSET        4
#define SUBGHZ_PCR_CLV_MASK          0x3

#define SUBGHZ_REGDRVCR              0x91F
#define SUBGHZ_REGDRVCR_EN           (1 << 0)
#define SUBGHZ_REGDRVCR_TRIM_122     0x0
#define SUBGHZ_REGDRVCR_TRIM_124     0x1
#define SUBGHZ_REGDRVCR_TRIM_126     0x2
#define SUBGHZ_REGDRVCR_TRIM_128     0x3
#define SUBGHZ_REGDRVCR_TRIM_130     0x4
#define SUBGHZ_REGDRVCR_TRIM_132     0x5
#define SUBGHZ_REGDRVCR_TRIM_134     0x6
#define SUBGHZ_REGDRVCR_TRIM_OFFSET  1
#define SUBGHZ_REGDRVCR_TRIM_MASK    0x7

#define SUBGHZ_SMPSC2R               0x923
#define SUBGHZ_SMPSC2R_DRV_20MA      0x0
#define SUBGHZ_SMPSC2R_DRV_40MA      0x1
#define SUBGHZ_SMPSC2R_DRV_60MA      0x2
#define SUBGHZ_SMPSC2R_DRV_100MA     0x3
#define SUBGHZ_SMPSC2R_DRV_OFFSET    1
#define SUBGHZ_SMPSC2R_DRV_MASK      0x3

/* Commands */
#define SUBGHZ_CALIBRAT_IMAGE        0x98
#define SUBGHZ_CALIBRATE             0x89
#define SUBGHZ_CFG_DIO_IRQ           0x08
#define SUBGHZ_CLR_ERROR             0x07
#define SUBGHZ_CLR_IRQ_STATUS        0x02
#define SUBGHZ_GET_ERROR             0x17
#define SUBGHZ_GET_IRQ_STATUS        0x12
#define SUBGHZ_GET_PACKET_STATUS     0x14
#define SUBGHZ_GET_PACKET_TYPE       0x11
#define SUBGHZ_GET_RSSI_INST         0x15
#define SUBGHZ_GET_RX_BUFFER_STATUS  0x13
#define SUBGHZ_GET_STATS             0x10
#define SUBGHZ_GET_STATUS            0xC0
#define SUBGHZ_READ_BUFFER           0x1E
#define SUBGHZ_READ_REGISTER         0x1D
#define SUBGHZ_RESET_STATS           0x00
#define SUBGHZ_SET_BUFFER_BA         0x8F
#define SUBGHZ_SET_CAD               0xC5
#define SUBGHZ_SET_CAD_PARAMS        0x88
#define SUBGHZ_SET_FS                0xC1
#define SUBGHZ_SET_LORA_SYMB_TO      0xA0
#define SUBGHZ_SET_MOD_PARAMS        0x8B
#define SUBGHZ_SET_PA_CONFIG         0x95
#define SUBGHZ_SET_PACKET_PARAMS     0x8C
#define SUBGHZ_SET_PACKET_TYPE       0x8A
#define SUBGHZ_SET_REGULATOR_MODE    0x96
#define SUBGHZ_SET_RF_FREQ           0x86
#define SUBGHZ_SET_RX                0x82
#define SUBGHZ_SET_RX_DUTY_CYCLE     0x94
#define SUBGHZ_SET_TXRX_FALLBACK     0x93
#define SUBGHZ_SET_SLEEP             0x84
#define SUBGHZ_SET_STANDBY           0x80
#define SUBGHZ_SET_STOP_RX_TIMER     0x9F
#define SUBGHZ_SET_TCXO_MODE         0x97
#define SUBGHZ_SET_TX                0x83
#define SUBGHZ_SET_TX_CONT_WAVE      0xD1
#define SUBGHZ_SET_TX_CONT_PREAMBLE  0xD2
#define SUBGHZ_SET_TX_PARAMS         0x8E
#define SUBGHZ_WRITE_BUFFER          0x0E
#define SUBGHZ_WRITE_REGISTER        0x0D

/* Registers masks */
#define SUBGHZ_GPKTCTL1AR_SYNCDETEN_MSK     (1 << 5)

/* Constants */
#define SUBGHZ_STATUS_MODE_MASK      (7 << 4)
#define SUBGHZ_STATUS_CMD_MASK       (7 << 1)
#define SUBGHZ_STATUS_CMD_SUCCESS    (6 << 1)
#define SUBGHZ_STATUS_MODE(x)        ((x & SUBGHZ_STATUS_MODE_MASK) >> 4)
#define SUBGHZ_STATUS_CMD(x)         ((x & SUBGHZ_STATUS_CMD_MASK) >> 1)
#define SUBGHZ_CMD_SUCCESS(x)        ((SUBGHZ_STATUS_CMD(x) & 0x03) == 2)
#define SUBGHZ_CMD_FAILED(x)         (!(SUBGHZ_CMD_SUCCESS(x)))

#define SUBGHZ_ERROR_PARAMP         (1 << 8)
#define SUBGHZ_ERROR_RFPLL_LOCK     (1 << 6)
#define SUBGHZ_ERROR_HSE32          (1 << 5)
#define SUBGHZ_ERROR_IMAGE          (1 << 4)
#define SUBGHZ_ERROR_RFADC          (1 << 3)
#define SUBGHZ_ERROR_RFPLL          (1 << 2)
#define SUBGHZ_ERROR_RC13M          (1 << 1)
#define SUBGHZ_ERROR_RC64K          (1 << 0)

#define SUBGHZ_CALIB_RC64K          (1 << 0)
#define SUBGHZ_CALIB_RC13M          (1 << 1)
#define SUBGHZ_CALIB_RFPLL          (1 << 2)
#define SUBGHZ_CALIB_RFADC_PULSE    (1 << 3)
#define SUBGHZ_CALIB_RFADCN         (1 << 4)
#define SUBGHZ_CALIB_RFADCP         (1 << 5)
#define SUBGHZ_CALIB_RFADCN         (1 << 4)
#define SUBGHZ_CALIB_IMAGE          (1 << 6)
#define SUBGHZ_CALIB_ALL            (SUBGHZ_CALIB_RC64K | SUBGHZ_CALIB_RC13M | \
                                    SUBGHZ_CALIB_RFPLL | SUBGHZ_CALIB_RFADC_PULSE | \
                                    SUBGHZ_CALIB_RFADCN | SUBGHZ_CALIB_RFADCP | \
                                    SUBGHZ_CALIB_IMAGE)

#define SUBGHZ_DEFAULT_CURMAX_LP    0x18
#define SUBGHZ_DEFAULT_CURMAX_HP    0x38

#endif /* LIBOPENCM3_SUBGHZ_H */
