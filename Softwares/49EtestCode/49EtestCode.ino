// 定义连接到49E霍尔传感器的模拟输入引脚
const int hallSensorPin[9] = { A0, A1, A2, A3, A4, A5, A6, A7, A8 };
int maxValue[9];
int minValue[9];
int oldValue[9];
int nowValue[9];
float output[9];


void setup() {
  // 开始串行通信
  Serial.begin(9600);
  for (int i = 0; i < 9; i++) {
    maxValue[i] = 0;
    minValue[i] = 1024;
    oldValue[i] = 0;
    nowValue[i] = 0;
  }
}

void loop() {
  // 读取传感器值

  for (int i = 0; i < 9; i++) {
    nowValue[i] = analogRead(hallSensorPin[i]);
    if (nowValue[i] >= maxValue[i]) {
      maxValue[i] = nowValue[i];
    }
    if (nowValue[i] <= minValue[i]) {
      minValue[i] = nowValue[i];
    }
    output[i] = (float)(nowValue[i] - minValue[i]) / (float)(maxValue[i] - minValue[i]);
  }

  Serial.print('<');
  Serial.print(output[0]);
  for (int i = 1; i < 9; i++) {
    Serial.print(',');
    Serial.print(output[i]);}
  Serial.println('>');




  // 稍作延时
  delay(20);
}
