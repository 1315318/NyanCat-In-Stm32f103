#include "adc.h"
#include "register_option.h"

//ADC初始化
void adc_init(volatile struct ADC_REG *adc) {
    SET_SMP1(adc);     // 1. 设置采样时间
    CONV1(adc);        // 2. 选择通道 1
    EXTTRIG(adc);      // 3. 开启外部触发
    TIM3_TRGO(adc);    // 4. 绑定 TIM3_TRGO
    EOCIE(adc);        // 5. 开启中断使能
    ADC_ON(adc);       // 6. 开启 ADC
}