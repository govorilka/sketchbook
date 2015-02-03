#include <Shieldbot.h>

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

Shieldbot shieldbot = Shieldbot();

void setup()
{
  // Инициализируем соединение по serial-порту
  Serial.begin(9600);

  // Задаём максимальную скорость нашей машинки
  shieldbot.setMaxSpeed(255); //255 -- это максимум

  // Каждая команда содержит два символа
  inputString.reserve(2);
}

void loop()
{
  // print the string when a newline arrives:
  if (stringComplete)
  {
    if (inputString == "fw") //движение вперёд
    {
      shieldbot.drive(127, 127); //straight forward
      delay(500);
      shieldbot.stop();
    }
    else if (inputString == "bw") //движение назад
    {
      shieldbot.drive(-127, -127);
      delay(500);
      shieldbot.stop();
    }
    if (inputString == "tl") //поворот влево
    {
      shieldbot.drive(0, 127); //straight forward
      delay(500);
      shieldbot.stop();
    }
    else if (inputString == "tr") //поворот направо
    {
      shieldbot.drive(127, 0);
      delay(500);
      shieldbot.stop();
    }

    Serial.println(inputString);

    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent()
{
  while (Serial.available())
  {
    // get the new byte:
    char inChar = (char)Serial.read();
    if (inChar == '\n')
    {
      stringComplete = true;
    }
    else
    {
      inputString += inChar;
    }
  }
}
