# mbed_stm-st25r95
Mbed OS Example for the NFC reader ST25R95 from STMicroelectronics

## Requirements
### Hardware requirements
The following boards are required:
- Zest_Core_STM32L4A6RG
- Zest_Adapter_Click, with mounted NFC Click 6

### Software requirements
mbed_stm-st25r95 makes use of the following libraries (automatically
imported by `mbed deploy` or `mbed import`):
- [Mbed OS](https://github.com/ARMmbed/mbed-os)
- [ST25R95](https://github.com/catie-aq/mbed_stm-st25r95.git)

## Usage
To clone **and** deploy the project in one command, use `mbed import` and skip to the
target and toolchain definition:
```shell
mbed import https://github.com/catie-aq/mbed_stm-st25r95-example.git mbed-stm-st25r95
```

Alternatively:

- Clone to "mbed-stm-st25r95" and enter it:
  ```shell
  git clone https://github.com/catie-aq/mbed_stm-st25r95-example.git mbed-stm-st25r95
  cd mbed-stm-st25r95
  ```

- Deploy software requirements with:
  ```shell
  mbed deploy
  ```

- Clone custom target repository if necessary:
  ```shell
  git clone YOUR_CUSTOM_TARGET_REPOSITORY your-custom-target
  ```

Define your target and toolchain:
```shell
cp your-custom-target/custom_targets.json . # In case of custom target
mbed target YOUR_MBED_OS_TARGET
mbed toolchain GCC_ARM
```

Compile the project:
```shell
mbed compile
```

Program the target device with a Segger J-Link debug probe and
[`sixtron_flash`](https://github.com/catie-aq/6tron_flash) tool:
```shell
sixtron_flash YOUR_JLINK_DEVICE BUILD/YOUR_MBED_OS_TARGET/GCC_ARM/mbed-stm-st25r95.elf
```

Debug on the target device with the probe and Segger
[Ozone](https://www.segger.com/products/development-tools/ozone-j-link-debugger)
software.
