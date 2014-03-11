#include <IRremote.h>

const int INFRARED_PIN = 11;
IRrecv irrecv(INFRARED_PIN);
decode_results results;

const int POWER_PIN = 2;        // the number of the power pushbutton pin
const int MIMIC_PIN = 3;        // the number of the mimic pushbutton pin
const int CHANNEL_UP_PIN = 4;   // the number of the channel up pushbutton pin
const int CHANNEL_DOWN_PIN = 5; // the number of the channel down pushbutton pin
const int CHANNEL_FAV_PIN = 6;  // the number of the channel favorite pushbutton pin
const int VOLUME_UP_PIN = 7;    // the number of the volume up pushbutton pin
const int VOLUME_DOWN_PIN = 8;  // the number of the volume down pushbutton pin
const int VOLUME_FAV_PIN = 9;   // the number of the volume favorite pushbutton pin

const int LED_PIN =  13;      // the number of the LED pin

const int POWER_BUTTON = 0;
const int MIMIC_BUTTON = 1;

const int CHANNEL_PLUS = 2;
const int CHANNEL_MINUS = 3;
const int CHANNEL_FAVORITE = 4;

const int VOLUME_PLUS = 5;
const int VOLUME_MINUS = 6;
const int VOLUME_FAVORITE = 7;

int states[8];
unsigned int values[8];

bool mimic_mode = false;

unsigned long lastValue = 0xFFFFFFFF;

void setup() {
  
    // Initialize the LED pin as Output:
    pinMode(LED_PIN, OUTPUT);

    // Initialize the pushbuttons as Input
    initButtons();
  
    states = {0, 0, 0, 0, 0, 0, 0, 0};

    //Load values from eeprom
    values = {0, 0, 0, 0, 0, 0, 0, 0};

    Serial.begin(9600);

}

void loop(){

    //Read the state of the PushButtons:
    state[POWER_BUTTON] = digitalRead(POWER_PIN);
    state[MIMIC_BUTTON] = digitalRead(MIMIC_PIN);

    digitalWrite(ledPin, LOW);

    handleButton(POWER_BUTTON);
    handleButton(CHANNEL_UP_BUTTON);
    handleButton(CHANNEL_DOWN_BUTTON);
    handleButton(VOLUME_UP_BUTTON);
    handleButton(VOLUME_DOWN_BUTTON);

    handleMimicButton();

    delay(300);

}

void initButtons() {

    pinMode(POWER_PIN, INPUT);
    pinMode(MIMIC_PIN, INPUT);
    pinMode(CHANNEL_UP_PIN, INPUT);
    pinMode(CHANNEL_DOWN_PIN, INPUT);
    pinMode(CHANNEL_FAV_PIN, INPUT);
    pinMode(VOLUME_UP_PIN, INPUT);
    pinMode(VOLUME_DOWN_PIN, INPUT);
    pinMode(VOLUME_FAV_PIN, INPUT);

}

void handleMimicButton() {

    if (state[MIMIC_BUTTON] == HIGH) {
        
        Serial.println("Mimic Mode On");

	mimic_mode = true;

        irrecv.enableIRIn();
        
        if (irrecv.decode(&results)) {
            lastValue = results.value;
            Serial.println(lastValue, HEX);
            irrecv.resume(); // Resume infrared
        }

        Serial.println("Signal Received");

    }

}

void handleButton(int button) {

    // Check if button is pressed.
    if (state[button] == HIGH) {

        if(!mimic_mode) {
        
            //send infrared values[button]

        } else {

            values[button] = lastValue;

            mimic_mode = false;

            //save value in eeprom
        }

        // turn LED on:
        digitalWrite(ledPin, HIGH);

    }

}
