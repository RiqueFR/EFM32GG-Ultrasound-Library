#include "ultrasound.h"

static int EC_PIN;
static int TG_PIN;
static GPIO_t GPIO_global;

void Ultrasound_Init(const GPIO_t GPIO_func, int TG_PIN_f, int EC_PIN_f) {
    EC_PIN = EC_PIN_f;
    TG_PIN = TG_PIN_f;
    GPIO_global = GPIO_func;

    GPIO_Init(GPIO_global, EC_PIN, TG_PIN);
}

void delay(uint32_t *ticks, uint32_t v) {
    uint32_t lim = *ticks+v;       // Missing processing of overflow here

    while ( *ticks < lim ) {}
}

int Ultrasound_Read_Cm(uint32_t *ticks, uint32_t timeout) {
    GPIO_WritePins(GPIO_global, TG_PIN, 0);
    delay(ticks, 2);
    GPIO_WritePins(GPIO_global, 0, TG_PIN);
    delay(ticks, 11);
    GPIO_WritePins(GPIO_global, TG_PIN, 0);
    
    uint32_t previousMicros = *ticks;
    while(!(GPIO_ReadPins(GPIO_global)&EC_PIN) && (*ticks - previousMicros) <= timeout);   // wait for the echo pin HIGH or timeout
    previousMicros = *ticks;
    
    while((GPIO_ReadPins(GPIO_global)&EC_PIN) && (*ticks - previousMicros) <= timeout);    // wait for the echo pin LOW or timeout
    uint32_t duration = *ticks - previousMicros;
    int dist = duration / 58; // distance in CM
    return dist;
}