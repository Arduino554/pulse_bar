#define CONTROL_PIN  9
 
// переменные верхнего уровня, т.е. объявленные вне функций,
// называют глобальными. Их значения сохраняются всё время,
// пока работает микроконтроллер
int brightness = 0;
 
void setup()
{
  pinMode(CONTROL_PIN, OUTPUT);
}
 
void loop()
{
  // увеличиваем значение яркости на единицу, чтобы нарастить
  // яркость. Однако яркость не должна быть более 255, поэтому
  // используем операцию остатка от деления, чтобы при
  // достижении значения 255, следующим значением снова стал 0
  // Y % X — это остаток от деления Y на X;
  // плюс, минус, делить, умножить, скобки — как в алгебре.
  brightness = (brightness + 1) % 256;
 
  // подаём вычисленный ШИМ-сигнал яркости на пин с базой
  // управляющего транзистора
  analogWrite(CONTROL_PIN, brightness);
 
  // ждём 10 мс перед следующим наращиванием яркости. Таким
  // образом, полный накал будет происходить в течение
  // 256×10 = 2560 мс
  delay(10);
}
