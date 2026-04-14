class Counter {
private:
  int count;
public:
  Counter(int count = 1) {
    this->count = count;
  }
  void increment() {
    this->count++;
  }
  void decrement() {
    this->count--;
  }
  int getCount() {
    return this->count;
  }
};

bool flag = true;
Counter object(5);

void setup() {
  Serial.begin(9600);
  Serial.println(object.getCount());
}

void loop() {
  if (flag) {
    object.increment();
  } else {
    object.decrement();
  }
  Serial.println(object.getCount());
  if (object.getCount() >= 10) {
    flag = false;
  } else if (object.getCount() <= 4) {
    flag = true;
  }
  delay(1000);
}
