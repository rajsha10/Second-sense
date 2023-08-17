#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <NewPing.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define TRIGGER_PIN1  2
#define ECHO_PIN1   3
#define TRIGGER_PIN2 12
#define ECHO_PIN2   11
#define MAX_DISTANCE 200

NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(1000);  // Set PWM frequency to 1000 Hz

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Initialize the OLED display
}

void vib(int pinNo, int time) {
  int on = 4095;  // Set a value between 0 and 4095 for the motor speed
  int off = 0;
  pwm.setPWM(pinNo, 0, on);
  delay(time);
  pwm.setPWM(pinNo, 0, off);
}

void loop() {
  delay(50); // Small delay before the next measurement
  unsigned int distance1 = sonar1.ping_cm();
  unsigned int distance2 = sonar2.ping_cm();
  
  // Clear the display
  display.clearDisplay();
  
  // Draw a vertical line in the center
  display.drawFastVLine(63, 0, 64, SSD1306_WHITE);
  
  // Display distance1 on the right side
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(80, 10);
  display.print("Dist1:");
  display.setCursor(80, 20);
  display.print(distance1);
  
  // Display distance2 on the left side
  display.setCursor(10, 10);
  display.print("Dist2:");
  display.setCursor(10, 20);
  display.print(distance2);
  
  // Display the OLED content
  display.display();
     if(Serial.available()>0)
   {     
      char data= Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case '1': vib(4,500);
                  break; 
        case '2': vib(5,500);
                  break; // when a is pressed on the app on your smart phone
        case '3': vib(6,500);
                  break; // when d is pressed on the app on your smart phone
        case '4': vib(7,500);
                  break; // 
        case '5': vib(8,500);
                  break; // 
        case '6': vib(9,500);
                  break; //           
        default : break;
      }

   }
  
}
