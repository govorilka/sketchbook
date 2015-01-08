
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  
  // initialize serial:
  Serial.begin(9600);

  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);
    if (inputString == "on")
    {
      digitalWrite(13, HIGH);    
    }
    else if (inputString == "off")
    {
      digitalWrite(13, LOW);
    }
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
void serialEvent() {
  while (Serial.available()) {
    
    // get the new byte:
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      stringComplete = true;
    }
    else
    {
      inputString += inChar; 
    }
  }
}

