/*
  Copyright (c) 2012 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#define ARDUINO_MAIN
#include "Arduino.h" 




void setup(void) {
	Serial.begin(115200);
	
#ifdef HID_ENABLED
	Mouse.begin();
#endif
}

void loop(void) {

#ifdef HID_ENABLED
	Mouse.move(1, 0, 0);
#endif

//	if (Serial.available() > 0)
//	{
//		char inChar = Serial.read();
//		Serial.print(inChar);
//		Serial1.print(inChar);
//	}

//	delay(10);
}

int main(void)
{
	//JCB init();   not compile at this time
    //JCB already in Reset_Handler  SystemInit();

	USBDevice.attach();
	
	setup();
    
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
        
	return 0;
}
 