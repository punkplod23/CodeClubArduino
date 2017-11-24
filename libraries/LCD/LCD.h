/** Arduino library for LCD screen Matrix Orbital GLK24064-25
 *
 * Copyright 2011 Nicolas Herment
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef LCD_h
#define LCD_h

#include "WProgram.h"

class LCD {
    public:
        LCD(int i2cAddress);
        void setBacklight(boolean on, int minutesOn);
        void setBrightness(int brightness);
        void clearScreen();
        void drawPixel(int x, int y);
        void drawRect(int color, int x1, int y1, int x2, int y2);
        void fillRect(int color, int x1, int y1, int x2, int y2);
        void drawLine(int x1, int y1, int x2, int y2);
        void continueLine(int x, int y);
        void drawText(int x, int y, String text);
        void resetCursor();
        void setCursor(int x, int y);
        void selectFont(int fontId);
        void setColor(int color);
    private:
        int _i2cAddress;
};

#endif