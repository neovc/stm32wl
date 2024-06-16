/** @defgroup syscfg_defines SYSCFG Defines
 *
 * @ingroup STM32WLxx_defines
 *
 * @brief Defined Constants and Types for the STM32WLxx Sysconfig
 *
 * @version 1.0.0
 *
 * @date 28 December 2017
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) Bruno Randolf <br1@einfach.org>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_SYSCFG_H
#define LIBOPENCM3_SYSCFG_H
/**@{*/

/* --- SYSCFG registers ---------------------------------------------------- */

#define SYSCFG_MEMRMP			MMIO32(SYSCFG_BASE + 0x00)
#define SYSCFG_CFGR1			MMIO32(SYSCFG_BASE + 0x04)
#define SYSCFG_EXTICR(i)		MMIO32(SYSCFG_BASE + 0x08 + (i)*4)
#define SYSCFG_EXTICR1			SYSCFG_EXTICR(0)
#define SYSCFG_EXTICR2			SYSCFG_EXTICR(1)
#define SYSCFG_EXTICR3			SYSCFG_EXTICR(2)
#define SYSCFG_EXTICR4			SYSCFG_EXTICR(3)
#define SYSCFG_SCSR			MMIO32(SYSCFG_BASE + 0x18)
#define SYSCFG_CFGR2			MMIO32(SYSCFG_BASE + 0x1C)
#define SYSCFG_SWPR			MMIO32(SYSCFG_BASE + 0x20)
#define SYSCFG_SKR			MMIO32(SYSCFG_BASE + 0x24)
#define SYSCFG_RFDCR			MMIO32(SYSCFG_BASE + 0x208)

/* --- SYSCFG_MEMRMP Values ------------------------------------------------ */

#define SYSCFG_MEMRMP_MEM_MODE_MASK	7
#define SYSCFG_MEMRMP_MEM_MODE_FLASH	0
#define SYSCFG_MEMRMP_MEM_MODE_SYSTEM	1
#define SYSCFG_MEMRMP_MEM_MODE_SRAM1	3

/* --- SYSCFG_CFGR1 Values ------------------------------------------------- */

#define SYSCFG_CFGR1_I2C3_FMP		(1 << 22)
#define SYSCFG_CFGR1_I2C2_FMP		(1 << 21)
#define SYSCFG_CFGR1_I2C1_FMP		(1 << 20)

#define SYSCFG_CFGR1_I2C_PB9_FMP	(1 << 19)
#define SYSCFG_CFGR1_I2C_PB8_FMP	(1 << 18)
#define SYSCFG_CFGR1_I2C_PB7_FMP	(1 << 17)
#define SYSCFG_CFGR1_I2C_PB6_FMP	(1 << 16)

#define SYSCFG_CFGR1_BOOSTEN		(1 << 8)

/* --- SYSCFG_EXTICR Values -------------------------------------------------*/

#define SYSCFG_EXTICR_FIELDSIZE		4
#define SYSCFG_EXTICR_GPIOA		0
#define SYSCFG_EXTICR_GPIOB		1
#define SYSCFG_EXTICR_GPIOC		2
#define SYSCFG_EXTICR_GPIOH		7

/* --- SYSCFG_SCSR Values -------------------------------------------------- */

#define SYSCFG_SCSR_PKASRAMBSY		(1 << 8)
#define SYSCFG_SCSR_SRAMBSY		(1 << 1)
#define SYSCFG_SCSR_SRAM2ER		(1 << 0)

/* --- SYSCFG_CFGR2 Values ------------------------------------------------- */

#define SYSCFG_CFGR2_SPF		(1 << 8)
#define SYSCFG_CFGR2_ECCL		(1 << 3)
#define SYSCFG_CFGR2_PVDL		(1 << 2)
#define SYSCFG_CFGR2_SPL		(1 << 1)
#define SYSCFG_CFGR2_CCL		(1 << 0)

/* --- SYSCFG_SWPR Values -------------------------------------------------- */

/* 0 - 31 */
#define SYSCFG_SWPR_PxWP(x)		(1 << x)

/* --- SYSCFG_SKR Values --------------------------------------------------- */

#define SYSCFG_SKR_KEY1			0xCA
#define SYSCFG_SKR_KEY2			0x53

/* --- SYSCFG_RFDCR Values --------------------------------------------------- */
#define SYSCFG_RFDCR_RFTBSEL		(1 << 0)

/**@}*/

#endif
