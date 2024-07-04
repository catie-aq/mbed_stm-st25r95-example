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
    st25r95.select_14443_a_protocol();
    while (true) {
        if (st25r95.get_tag_value(test) != 0)
        {
            for (size_t i = 0; i < 4; i++)
            {
                printf("%02X ",test[i]);
            }
            printf("\n");
        }
        led1 = !led1;
    }
}
