// digital pin 2 is the hall pin
int hall_pin = 7;
// set number of hall trips for RPM reading (higher improves accuracy)
float hall_thresh = 5.0;
#define LED_PIN_GND 11
#define LED_PIN_VCC 12
#define RPM_MODE 1  // set RPM mode on

void init_hall() {
  pinMode(hall_pin, INPUT);
  pinMode(LED_PIN_GND, INPUT);
  pinMode(LED_PIN_VCC, INPUT);
  digitalWrite(LED_PIN_GND, 0);
  digitalWrite(LED_PIN_VCC, 1);
}
void blink() {
  digitalWrite(LED_PIN_GND, 0);
  digitalWrite(LED_PIN_VCC, 1);
}
float detect() {
  float hall_count = 1.0;
  float start = micros();
  bool on_state = false;
  while (true) {
    if (digitalRead(hall_pin) == 0) {
      blink();
      if (on_state == false) {
        on_state = true;
        hall_count += 1.0;
      }
    } else {
      on_state = false;
    }

    if (hall_count >= hall_thresh) {
      break;
    }
  }
  if (RPM_MODE == 1) {
    float end_time = micros();
    float time_passed = ((end_time - start) / 1000000.0);
    float rpm_val = (hall_count / time_passed) * 60.0;
    return rpm_val;
  } else {
    return time_passed
  }
  delay(1);
}
void setup() {
  init_hall();
  Serial.begin(115200);
}
void loop() {
  Serial.println(detect());
}
