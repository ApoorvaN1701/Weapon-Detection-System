#include <LiquidCrystal.h>

const int trigEchoPin = 9;  // Single pin for Trigger and Echo
const int buzzer = 13;      // Buzzer pin
bool alertSent = false;     // Flag to prevent repeated alerts
int lastValidDistance = 999;  // Stores last known valid distance
int noObjectCounter = 0;     // Counter to track consecutive 999 cm readings
unsigned long lastAlertTime = 0; // Stores last alert time
const int alertDelay = 5000; // Minimum time (in ms) between alerts

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // LCD pins

void setup() {
    pinMode(trigEchoPin, OUTPUT);
    pinMode(buzzer, OUTPUT);
    lcd.begin(16, 2);
    Serial.begin(9600);

    lcd.setCursor(0, 0);
    lcd.print("Weapon Detector");
    lcd.setCursor(0, 1);
    lcd.print("Initializing...");
    Serial.println("System Initialized... Scanning for weapons...");
    delay(3000);
    lcd.clear();
}

// Function to get stable sensor readings using a Moving Average Filter
int getStableDistance() {
    int total = 0;
    int samples = 5;  // Number of samples
    int validSamples = 0;

    for (int i = 0; i < samples; i++) {
        long duration;
        pinMode(trigEchoPin, OUTPUT);
        digitalWrite(trigEchoPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigEchoPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigEchoPin, LOW);
        
        pinMode(trigEchoPin, INPUT);
        duration = pulseIn(trigEchoPin, HIGH, 30000); // Timeout after 30ms

        int distance = duration * 0.034 / 2; // Convert to cm
        
        // Ignore extreme outliers (sensor errors)
        if (distance > 2 && distance < 300) {
            total += distance;
            validSamples++;
        }
        
        delay(10); // Small delay between readings
    }

    if (validSamples > 0) {
        lastValidDistance = total / validSamples;  // Update last valid reading
        noObjectCounter = 0; // Reset no object counter
        return lastValidDistance;
    } else {
        noObjectCounter++; // Increase counter if 999 cm is received
        if (noObjectCounter >= 5) { // Only confirm no object after 5 consecutive readings
            return 999;
        }
        return lastValidDistance; // Keep last valid distance
    }
}

// Function to check distance and trigger alerts
void checkDistance() {
    int distance = getStableDistance(); // Get filtered distance

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm  --> ");

    // Handle Out of Range Condition (No object detected after multiple 999 cm readings)
    if (distance == 999) {
        Serial.println("No object detected");
        lcd.setCursor(0, 0);
        lcd.print("Scanning...");
        lcd.setCursor(0, 1);
        lcd.print("No Object     ");  // Clears previous text
        return;
    }

    // Update LCD Display
    lcd.setCursor(0, 0);
    lcd.print("Scanning...");
    lcd.setCursor(0, 1);
    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print(" cm   ");

    // Weapon Detection Logic
    if (distance < 10 && !alertSent) { 
        unsigned long currentTime = millis(); // Get current time
        if (currentTime - lastAlertTime > alertDelay) { // Only trigger if alert delay has passed
            alertSent = true;  
            digitalWrite(buzzer, HIGH);

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("!! ALERT !!");
            lcd.setCursor(0, 1);
            lcd.print("Weapon Detected!");

            Serial.println("!! ALERT !! Weapon Detected in the Public Transport.");
            Serial.println("Sending SMS Alert to Authorities...");
            lastAlertTime = currentTime; // Update last alert time
            delay(2000);
        }
    } 
    else if (distance >= 20 && alertSent) { // Reset alert only when object moves past 20 cm
        alertSent = false;
        digitalWrite(buzzer, LOW);
        Serial.println("No weapon detected");
    }
}

void loop() {
    checkDistance();
    delay(500);
}
