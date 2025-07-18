int irSensors[8] = {5, 6, 7, 8, 9, 10, 11, 12};
#define LDR_PIN A0  
#define LED_CONTROL_PIN 3

void setup() {
    Serial.begin(9600);
    pinMode(LED_CONTROL_PIN, OUTPUT);
    for (int i = 0; i < 8; i++) {
        pinMode(irSensors[i], INPUT);
    }
}

void loop() {
    int ldrValue = analogRead(LDR_PIN);
    bool anyMotion = false;

    for (int i = 0; i < 8; i++) {
        if (digitalRead(irSensors[i]) == LOW) {
            anyMotion = true;
            break;
        }
    }

    Serial.print("LDR: "); Serial.print(ldrValue);
    Serial.print(" | Motion: "); Serial.println(anyMotion);

    if (ldrValue >= 800) {
        Serial.println("Daytime - LEDs OFF");
        analogWrite(LED_CONTROL_PIN, 0);
    } 
    else {
        if (anyMotion) {
            Serial.println("Motion detected - LEDs ON (100%)");
            analogWrite(LED_CONTROL_PIN, 255);
        } 
        else {
            Serial.println("No motion - LEDs Dim (30%)");
            analogWrite(LED_CONTROL_PIN, 20);
        }
    }

    delay(200);
}