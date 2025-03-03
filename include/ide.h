/*
 * (C) Copyright 2000
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef	_IDE_H
#define _IDE_H

#define IDE_BUS(dev)	(dev / (CONFIG_SYS_IDE_MAXDEVICE / CONFIG_SYS_IDE_MAXBUS))

#define	ATA_CURR_BASE(dev)	(CONFIG_SYS_ATA_BASE_ADDR+ide_bus_offset[IDE_BUS(dev)])
//extern unsigned long ide_bus_offset[];	//scl

#ifdef CONFIG_IDE_LED

/*
 * LED Port
 */
#define	LED_PORT	((unsigned char *)(PER8_BASE + 0x3000))
#define LED_IDE1	0x01
#define LED_IDE2	0x02
#define	DEVICE_LED(d)	((d & 2) | ((d & 2) == 0)) /* depends on bit positions! */

#endif /* CONFIG_IDE_LED */

#ifdef CONFIG_SYS_64BIT_LBA
typedef uint64_t lbaint_t;
#define LBAF "%llx"
#define LBAFU "%llu"
#else
//typedef unsigned long lbaint_t;	//scl
#define LBAF "%lx"
#define LBAFU "%lu"
#endif

/*
 * Function Prototypes
 */

void ide_init(void);
//unsigned long ide_read(int device, lbaint_t blknr, lbaint_t blkcnt, void *buffer);	//scl
//unsigned long ide_write(int device, lbaint_t blknr, lbaint_t blkcnt,	\
		const void *buffer);	//scl

#ifdef CONFIG_IDE_PREINIT
int ide_preinit(void);
#endif

#ifdef CONFIG_IDE_INIT_POSTRESET
int ide_init_postreset(void);
#endif

#if defined(CONFIG_OF_IDE_FIXUP)
int ide_device_present(int dev);
#endif

#if defined(CONFIG_IDE_AHB)
unsigned char ide_read_register(int dev, unsigned int port);
void ide_write_register(int dev, unsigned int port, unsigned char val);
void ide_read_data(int dev, unsigned long *sect_buf, int words);
void ide_write_data(int dev, const unsigned long *sect_buf, int words);
#endif

/*
 * I/O function overrides
 */
void ide_input_swap_data(int dev, unsigned long *sect_buf, int words);
void ide_input_data(int dev, unsigned long *sect_buf, int words);
void ide_output_data(int dev, const unsigned long *sect_buf, int words);
void ide_input_data_shorts(int dev, unsigned short *sect_buf, int shorts);
void ide_output_data_shorts(int dev, unsigned short *sect_buf, int shorts);

/**
 * board_start_ide() - Start up the board IDE interfac
 *
 * @return 0 if ok
 */
int board_start_ide(void);

#endif /* _IDE_H */
