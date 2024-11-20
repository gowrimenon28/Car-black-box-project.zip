#include "main.h"

void write_onto_eeprom(EVENTS store_event) {
    unsigned char write_offset = PASSWORD_LENGTH + 4;
    unsigned char scroll_addr = 8 * UART_LOG_ENTRIES_COUNT + write_offset;

    if (store_event == EVENT_CL) {
        write_addr = write_offset;
        scroll = SYSTEM_OFF;
    }

    // Write 6 bytes from time string (HH, MM & SS)
    for (unsigned char i = 0; i < 8; i++) {
        if (i != 2 && i != 5) {
            write_ext_eeprom(write_addr++, time_reg[i]);
        }
    }

    write_ext_eeprom(write_addr++, store_event);
    write_ext_eeprom(write_addr++, speed);

    if (write_addr == scroll_addr) {
        write_addr = write_offset;
    }

    if (scroll) {
        last_index = first_index;
        first_index = (write_addr == write_offset) ? 0 : (write_addr - write_offset) / 8;
    } else {
        first_index = 0;
        last_index = (write_addr == write_offset) ? UART_LOG_ENTRIES_COUNT - 1 : (write_addr - 2 * write_offset) / 8;
        if (write_addr == write_offset)
            scroll = SYSTEM_ON;
    }

    write_ext_eeprom(PASSWORD_LENGTH, write_addr);
    write_ext_eeprom(PASSWORD_LENGTH + 1, scroll);
    write_ext_eeprom(PASSWORD_LENGTH + 2, first_index);
    write_ext_eeprom(PASSWORD_LENGTH + 3, last_index);
}
