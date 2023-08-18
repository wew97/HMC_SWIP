#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define BLOCK_SIZE          (4*1024)

#define GPIO_BASE           0x7E200000
#define GPFSEL1_OFFSET      0x04
#define GPSET0_OFFSET       0x1C
#define GPCLR0_OFFSET       0x28

#define GPIO_PIN            17

int main() 
{
    int gpio_fd;                // file descriptor of memory object
    unsigned int *gpio;         // pointer to memory-mapped region

    // Open GPIO memory
    gpio_fd = open("/dev/gpiomem", O_RDWR);
    if (gpio_fd < 0) {
        printf("Error opening /dev/gpiomem");
        return 1;
    }
    
    // Get a memeory-mapped address that corresponds to GPIO_BASE
    gpio = (unsigned int *)mmap(NULL, BLOCK_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, gpio_fd, GPIO_BASE);

    // Now gpio address points to GPIO_BASE
    // Since gpio's type is "unsigned int",
    // "gpio[i]" maps to the address of "gpio" + "4*i"

    // The function of GPIO 17 is controlled via GPFSEL1 (GPIO Function Select Register 1)
    // The offset of GPFSEL1 is 4 (meaning the address is GPIO_BASE + 4)
    // GPIO 17's function selection can be configured by 23th ~ 21th bit field
    // To set GIPO 17 as output, we need to set them to "001"
    gpio[GPFSEL1_OFFSET/4] = (1 << 21);     // This means "gpio[1] = (1 << 21);"
                                            // or "gpio[1] = 0000 0000 0010 0000 0000 0000 0000 0000"
    printf("gpio = %p\n", gpio);            // Just wanted to see the mapped address in user space
    
    while (1) {
        // The output "HIGH" of GPIO 17 can be controlled via GPSET0 (GPIO Pin Output Set Register 0)
        // The offset of GPSET0 is 0x1C (the address is GPIO_BASE + 0x1C)
        // GPIO 17's output "HIGH" can be set at the 23th bit position
        // To make GIPO 17 "HIGH", we need to set it to "1"
        gpio[GPSET0_OFFSET/4] = (1 << GPIO_PIN);    // This means "gpio[7] = (1 << 17);"
                                                    // or "gpio[7] = 0000 0000 0000 0010 0000 0000 0000 0000"
        sleep(1);

        // The output "LOW" of GPIO 17 can be controlled via GPCLR0 (GPIO Pin Output Clear Register 0)
        // The offset of GPCLR0 is 0x28 (the address is GPIO_BASE + 0x28)
        // GPIO 17's output "LOW" can be set at the 23th bit position
        // To make GIPO 17 "LOW", we need to set it to "1"
        gpio[GPCLR0_OFFSET/4] |= (1 << GPIO_PIN);   // This is the same as writing "gpio[10] = (1 << 17);"
                                                    // or "gpio[10] = 0000 0000 0000 0010 0000 0000 0000 0000" 
        sleep(1);
    }

    return 0;
}