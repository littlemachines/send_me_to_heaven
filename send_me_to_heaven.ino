#define trigPin 9
#define echoPin 10
#define buzzerPin 3

long duration;
float distance;
float maxDistance = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
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

  // Преобразуване във физическо разстояние в метри
  distance = duration * 0.034 / 2 / 100.0;

  // Проверка дали е нова максимална дистанция
  if (distance > maxDistance && distance < 1.90) {
    maxDistance = distance;

    // Ако мине 1 метър – писка
    if (maxDistance >= 1.0) {
      tone(buzzerPin, 1000, 200); // писка с 1000 Hz за 200 ms
    }
  }

  // Постоянно показване на текущата максимална стойност
  Serial.print("RESULT ");
  Serial.print(maxDistance);
  Serial.println("m");

  delay(50); // измерване през 50 милисекунди
}
