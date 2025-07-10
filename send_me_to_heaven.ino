#define trigPin 9
#define echoPin 10

long duration;
float distance;
float maxDistance = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Изпращане на ултразвуков импулс
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Засичане на времето за отразения импулс
  duration = pulseIn(echoPin, HIGH);

  // Преобразуване във физическо разстояние (в см)
  distance = duration * 0.034 / 2 / 100;

  // Ако разстоянието е по-голямо от досегашното максимум – запомни го
  if (distance > maxDistance && distance < 1.90) { // 400 см = макс обхват на HC-SR04
    maxDistance = distance;
  }

  Serial.print("RESULT ");
  Serial.print(maxDistance);
  Serial.println("m");

  delay(50); // Пауза между измерванията
}
