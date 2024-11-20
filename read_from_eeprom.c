#include "main.h"

/**
 * Reads 8 bytes from the internal EEPROM.
 * Reads 6 bytes for the clock value, 1 byte for the event value, 
 * and 1 byte for the speed value, storing them in `eeprom_log_reg`.
 */
void read_from_eeprom(void) {
    read_addr = disp_num * 8 + PASSWORD_LENGTH + 4;

    // Read 8 bytes from EEPROM into eeprom_log_reg
    for (unsigned char i = 0; i < 8; i++) {
        eeprom_log_reg[i] = read_ext_eeprom(read_addr + i);
    }
}

/**
 * Initializes values from EEPROM.
 * Retrieves the original password, EEPROM write address, 
 * scroll flag, first index, and last index from EEPROM storage.
 */
void get_initial_values_from_eeprom(void) {
    // Retrieve original password from EEPROM
    for (unsigned char i = 0; i < PASSWORD_LENGTH; i++) {
        org_passwd[i] = (read_ext_eeprom(i) - '0') ? '1' : '0';
    }
    org_passwd[PASSWORD_LENGTH] = '\0';

    // Retrieve write address, scroll flag, first and last index values
    write_addr = read_ext_eeprom(PASSWORD_LENGTH);
    scroll = read_ext_eeprom(PASSWORD_LENGTH + 1);
    first_index = read_ext_eeprom(PASSWORD_LENGTH + 2);
    last_index = read_ext_eeprom(PASSWORD_LENGTH + 3);
}
