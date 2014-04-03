/* Basic Digital Read
 * ------------------ 
 *
 * turns on and off a light emitting diode(LED) connected to digital  
 * pin 13, when pressing a pushbutton attached to pin 7. It illustrates the
 * concept of Active-Low, which consists in connecting buttons using a
 * 1K to 10K pull-up resistor.
 *
 * Created 1 December 2005
 * copyleft 2005 DojoDave <http://www.0j0.org>
 * http://arduino.berlios.de
 *
 */

const int ledPin = 13;     // choose the pin for the LED
const int realLedPin = 12; // choose the pin for the LED
const int inPin = 7;       // choose the input pin (for a pushbutton)
int button = 0;            // variable for reading the pin status

void setup() {

    pinMode(ledPin, OUTPUT);     // declare LED as output
    pinMode(realLedPin, OUTPUT); // declare red LED as output
    pinMode(inPin, INPUT);       // declare pushbutton as input

    //Open Serial
    //Serial.begin(9600);
}

void loop() {

    button = digitalRead(inPin);  // read input value

    // check if the input is HIGH (button released)
    if (button == HIGH) {
        // turn LEDs OFF
        digitalWrite(ledPin, LOW);
        digitalWrite(realLedPin, LOW);
    //  Serial.println("Button Pressed"); //Show message in Serial
    } else {
        // turn LEDs ON
        digitalWrite(ledPin, HIGH);
        digitalWrite(realLedPin, HIGH);
    }

}
