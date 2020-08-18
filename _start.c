#include "latte.h"

#define ON_THE_GROUND   99
#define KEY_SPACE       32
#define CENTER          15
#define GROUND          22



void _start(){
    // Initialize
    const int32_t sacchanX = CENTER;
          int32_t sacchanY = GROUND-6;
          int32_t sacchanV = 0;                 // Current Speed
          int32_t sacchanJ = -3;                // Jump Power
          int32_t nawaX = CENTER;
    const int32_t nawaY = GROUND;
          int32_t nawaV = 5;                    // Current Speed
          int32_t gravity = 1;
          int32_t slowness = 66;
          int32_t landingCount = 0;

    // Game loop
    while(!(  (sacchanX==nawaX) && (sacchanY==nawaY)  )){
        // Check Jumping key
        if(latte.keyboard_deqKeyBuf() == KEY_SPACE){
            sacchanV = sacchanJ;
        }

        // Move the Sacchan
        if(sacchanV != ON_THE_GROUND){
            sacchanY += sacchanV;
            if(GROUND < sacchanY){
                // Landed
                sacchanV = ON_THE_GROUND;
                sacchanY = GROUND;
                landingCount += 1;
            }else{
                sacchanV += gravity;
            }
        }

        // Move the Nawa
        nawaX += nawaV;
        nawaV += (nawaX<CENTER) - (CENTER<nawaX);

        // Draw
        latte.screen_clear();
        latte.printf("SCORE:%d\n", landingCount);
        *latte.screen_buf(sacchanX, sacchanY) = '@';
        *latte.screen_buf(nawaX, nawaY) = '-';

        // Show slowly to player
        latte.sleep(slowness, 0);
    }
}


