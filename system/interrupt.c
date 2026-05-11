#include "interrupt.h"
#include "nvic.h"
#include "exti.h"
#include "afio.h"
#include "gpio.h"

//配置外部中断
void set_interrupt(struct INTERRUPT_CONFIG *interrupt_config)
{
    enr_gpio(interrupt_config->gpio_type);
    init_gpio(interrupt_config->gpio_type, interrupt_config->pin_num, interrupt_config->mode);
    set_gpio(interrupt_config->gpio_type, interrupt_config->pin_num, interrupt_config->level);
    
    enr_afio();
    exti_afio(interrupt_config->afio, interrupt_config->exti_num, interrupt_config->port_type);
    
    imr_exti(interrupt_config->exti, interrupt_config->exti_num);
    if (interrupt_config->trig_method == RAS_EDG)
    {
        rtsr_exti(interrupt_config->exti, interrupt_config->exti_num);
    }
    if (interrupt_config->trig_method == FAL_EDG)
    {
        ftsr_exti(interrupt_config->exti, interrupt_config->exti_num);
    }
    
    cpr_nvic(interrupt_config->nvic, interrupt_config->interrupts_location, interrupt_config->interrupts);
    pri_nvic(interrupt_config->nvic, interrupt_config->interrupts, interrupt_config->pri_num);
    senr_nvic(interrupt_config->nvic, interrupt_config->interrupts_location, interrupt_config->interrupts);
}