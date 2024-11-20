/* 
 * File:   ext_eeprom.h
 * Author: gowri
 *
 * Created on 31 October, 2024, 10:54 AM
 */

#ifndef EXT_EEPROM_H
#define EXT_EEPROM_H

#define SLAVE_READ_EE               0xA1
#define SLAVE_WRITE_EE              0xA0
//#define _XTAL_FREQ                  20000000

unsigned char eeprom_at24c04_random_read(unsigned char memory_loc);
void eeprom_at24c04_byte_write(unsigned char memory_loc, unsigned char data);
void eeprom_at24c04_str_write(unsigned char memory_loc, char *data);

#endif /* EXT_EEPROM_H */
