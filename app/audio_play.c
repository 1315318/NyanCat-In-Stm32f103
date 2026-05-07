#include "base_define.h"
#include "audio_play.h"
#include "nyancat_audio.h"
#include "timx.h"
#include "dma.h"
#include "gpio.h"

//音频播放
void audio_play(void)
{
    enr_tim(TIM2);
    enr_tim(TIM3);
    struct INIT_CONFIG tim2_config = { 
        .tim_type    = TIM2,
        .channel_num = TIM_CH1,
        .apre        = APRE_ON,
        .ali_type    = EDGE_ALI,
        .dir         = DIR_UP,
        .opm         = OPM_OFF,
        .urs         = URS_SINGL,
        .tde         = TDE_OFF,
        .ug          = UG_ON,
        .ocm         = OCM_PWM1,
        .ocpe        = OCPE_ON,
    };
    struct INIT_CONFIG tim3_config = {
        .tim_type    = TIM3,
        .channel_num = TIM_CH1,
        .apre        = APRE_ON,
        .ali_type    = EDGE_ALI,
        .dir         = DIR_UP,
        .opm         = OPM_OFF,
        .urs         = URS_SINGL,
        .tde         = TDE_ON,
        .ug          = UG_ON,
        .ocm         = OCM_FRZE,
        .ocpe        = OCPE_OFF,
    };
    init_tim(&tim2_config);
    init_tim(&tim3_config);
    set_tim(TIM2, TIM_CH1, 0, 255, 0, HIGH);                                              //TIM2作为载波，时钟72MHZ
    set_tim(TIM3, TIM_CH1, 35, 249, 0, HIGH);                                             //TIM3触发DMA请求，时钟8KHZ
    enr_dma();
    init_dma(DMA_CH3, DMA_ULTRA, MSIZE_8BIT, PSIZE_16BIT, MINC_ON, CIRC_ON, DIR_MSI);
    set_dma(DMA_CH3, AUDIO_SIZE, (unsigned int)&TIM2->CCR1, (unsigned int)nyancat_audio); //通过DMA直接将音频数据传输到CRR1
    enr_gpio(GPIOA);
    init_gpio(GPIOA, GPIO_CH0, GPIO_MODE_AFPP);
}