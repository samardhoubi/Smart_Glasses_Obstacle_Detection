const int echoPin = 25;
const int trigPin = 26;
const int buzzerPin = 27;

float readSensorData();

void setup() {
  Serial.begin(115200);

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(buzzerPin, HIGH); 
}

void loop() {
  float distance = readSensorData();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 100) {
    // More than 100 cm → OFF
    digitalWrite(buzzerPin, HIGH);
    delay(100);

  } else if (distance > 50) {
    // 50–100 cm → slow beep
    digitalWrite(buzzerPin, LOW);
    delay(100);
    digitalWrite(buzzerPin, HIGH);
    delay(600);

  } else if (distance > 20) {
    // 20–50 cm → fast beep
    digitalWrite(buzzerPin, LOW);
    delay(100);
    digitalWrite(buzzerPin, HIGH);
    delay(100);

  } else {
    digitalWrite(buzzerPin, LOW);
    delay(100);
  }
}

float readSensorData() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);

  float distance = duration / 29.0 / 2.0;

  return distance;
}