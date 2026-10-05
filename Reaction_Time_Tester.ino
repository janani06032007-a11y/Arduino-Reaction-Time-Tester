#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

const int ledPin = 8;
const int buttonPin = 2;

unsigned long ledOnTime;
unsigned long reactionTime;

int attempt = 0;
unsigned long bestTime = 0;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(ledPin, LOW);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  randomSeed(analogRead(A0));

  showStartScreen();
}

void loop() {

  // Wait for button press to start
  if (digitalRead(buttonPin) == LOW) {

    delay(50);

    if (digitalRead(buttonPin) == LOW) {

      waitForReaction();

      // Wait until button is released
      while (digitalRead(buttonPin) == LOW) {
        delay(10);
      }
    }
  }
}

void showStartScreen() {

  display.clearDisplay();
  display.setTextColor(WHITE);

  display.setTextSize(2);
  display.setCursor(10, 5);
  display.println("REACTION");

  display.setCursor(25, 28);
  display.println("TEST");

  display.setTextSize(1);
  display.setCursor(20, 52);
  display.println("Press Button");

  display.display();
}

void waitForReaction() {

  // Show waiting message
  display.clearDisplay();

  display.setTextColor(WHITE);
  display.setTextSize(2);

  display.setCursor(15, 10);
  display.println("GET READY");

  display.setTextSize(1);
  display.setCursor(20, 40);
  display.println("Wait for LED...");

  display.display();

  // Random delay
  int randomDelay = random(2000, 5000);
  delay(randomDelay);

  // Turn LED ON
  digitalWrite(ledPin, HIGH);

  // Record exact LED ON time
  ledOnTime = millis();

  // Wait for button press
  while (digitalRead(buttonPin) == HIGH) {
    // Waiting for player reaction
  }

  // Record reaction time
  reactionTime = millis() - ledOnTime;

  // Turn LED OFF
  digitalWrite(ledPin, LOW);

  attempt++;

  // Update best time
  if (bestTime == 0 || reactionTime < bestTime) {
    bestTime = reactionTime;
  }

  showResult();
}

void showResult() {

  display.clearDisplay();
  display.setTextColor(WHITE);

  display.setTextSize(2);
  display.setCursor(20, 2);
  display.println("RESULT");

  display.setTextSize(2);
  display.setCursor(15, 25);
  display.print(reactionTime);
  display.println(" ms");

  display.setTextSize(1);
  display.setCursor(5, 48);
  display.print("Attempt: ");
  display.print(attempt);

  display.setCursor(70, 48);
  display.print("Best: ");
  display.print(bestTime);

  display.display();

  delay(3000);

  showStartScreen();
}
