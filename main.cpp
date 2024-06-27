/*
 * Copyright (c) 2024, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mbed.h"
#include "st25r95.h"

namespace {
#define HALF_PERIOD 500ms
}

static DigitalOut led1(LED1);
SPI spi(SPI1_MOSI, SPI1_MISO, SPI1_SCK);
DigitalOut cs(SPI1_CS);
DigitalOut irq_n(PWM1_OUT);
ST25R95 st25r95(&spi, &cs, &irq_n);

int main()
{
    st25r95.initialize();
    st25r95.select_14443_A_protocol();
    while (true) {
        st25r95.get_tag_value();
        led1 = !led1;
        if (led1) {
        }
    }
}
