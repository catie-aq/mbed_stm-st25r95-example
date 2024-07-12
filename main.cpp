/*
 * Copyright (c) 2024, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mbed.h"
#include "st25r95.h"

static DigitalOut led1(LED1);
SPI spi(SPI1_MOSI, SPI1_MISO, SPI1_SCK);
DigitalOut cs(SPI1_CS);
DigitalOut irq_n(PWM1_OUT);
ST25R95 st25r95(&spi, &cs, &irq_n);
char test[4];

int main()
{
    st25r95.initialize();
    st25r95.protocol(0x02);
    while (true) {
        if (st25r95.tag_is_detected()) {
            if (st25r95.no_multiple_tag()) {
                st25r95.fill_response(test);
                for (size_t i = 0; i < 4; i++) {
                    printf("%02X ", test[i]);
                }
                printf("\n");
            } else {
                printf("Multiple Tag Detected\n");
            }

        } else {
        }
        led1 = !led1;
    }
}
