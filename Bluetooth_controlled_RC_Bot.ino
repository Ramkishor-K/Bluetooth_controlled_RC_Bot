
#include <Servo.h>
#include <SoftwareSerial.h>
#define RxD 3 // Pin that the Bluetooth (BT_TX) will transmit to the Arduino (RxD)
#define TxD 2

const int lPWM = 7;
const int rPWM = 6;
const int lM1 = 9, lM2 = 10;
const int rM1 = 7, rM2 = 8;
SoftwareSerial blueToothSerial(RxD, TxD);
void moveForward();
void spotLeft();
void spotRight();
void moveBackward();
void arcFLeft();
void arcBLeft();
void arcFRight();
void arcBRight();
void Stop();


void setup()
{
  Serial.begin(9600); // Allow Serial communication via USB cable to computer (if required)
  pinMode(RxD, INPUT); // Set pin to receive INPUT from bluetooth shield on Digital Pin 3
  pinMode(TxD, OUTPUT); // Set pin to send data (OUTPUT) to bluetooth shield on Digital Pin 2
  pinMode(lM1, OUTPUT);
  pinMode(lM2, OUTPUT);
  pinMode(rM1, OUTPUT);
  pinMode(rM2, OUTPUT);
  pinMode(rPWM, OUTPUT);
  pinMode(lPWM, OUTPUT);
  //setupBlueToothConnection(); //Used to initialise the Bluetooth shield
  //  analogWrite(10, 100);
  //  analogWrite(11, 100);
  Stop();
}
void loop()
{
  while (1)
  {
    if (blueToothSerial.available())
    { //check for data sent from the remote bluetooth shield
      char recvChar = blueToothSerial.read();
      Serial.println(recvChar);
      switch (recvChar)
      {
        case '0': analogWrite(lPWM , 0);
          analogWrite(rPWM , 0);
          break;
        case '1' : analogWrite(lPWM , 25.5);
          analogWrite(rPWM , 25.5);
          break;
        case '2' : analogWrite(lPWM , 25.5 * 2 );
          analogWrite(rPWM , 25.5 * 2 );
          break;
        case '3' : analogWrite(lPWM , 25.5 * 3 );
          analogWrite(rPWM , 25.5 * 3 );
          break;
        case '4' : analogWrite(lPWM , 25.5 * 4);
          analogWrite(rPWM , 25.5 * 4);
          break;
        case '5' : analogWrite(lPWM , 25.5 * 5);
          analogWrite(rPWM , 25.5 * 5);
          break;
        case '6' : analogWrite(lPWM , 25.5 * 6);

          analogWrite(rPWM , 25.5 * 6);
          break;
        case '7' : analogWrite(lPWM , 25.5 * 7);
          analogWrite(rPWM , 25.5 * 7);
          break;
        case '8' : analogWrite(lPWM , 25.5 * 8);
          analogWrite(rPWM , 25.5 * 8);
          break;
        case '9' : analogWrite(lPWM , 25.5 * 9);
          analogWrite(rPWM , 25.5 * 9);
          break;
        case 'F' : moveForward();
          break;
        case 'B' : moveBackward();
          break;
        case 'R' : spotRight();
          break;
        case 'L' : spotLeft();
          break;
        case 'J' : arcBLeft();
          break;
        case 'G' : arcFRight();
          break;
        case 'H' : arcBRight();
          break;
        case 'I' : arcFLeft();
          break;
        case 'S' : Stop();
          break;

      }
    }
  }
}

// void setupBlueToothConnection()
// {
//   blueToothSerial.begin(9600); //Set BluetoothBee BaudRate to default baud rate 38400
//   blueToothSerial.print("\r\n+STWMOD=0\r\n"); //set the bluetooth work in slave mode
//   blueToothSerial.print("\r\n+STNA=SeeedBTSlave\r\n"); //set bluetooth name as "SeeedBTSlave"
//   blueToothSerial.print("\r\n+STOAUT=1\r\n"); // Permit Paired device to connect me
//   blueToothSerial.print("\r\n+STAUTO=0\r\n"); // Auto-connection should be forbidden here
//   delay(2000); // This delay is required.
//   blueToothSerial.print("\r\n+INQ=1\r\n"); //make the slave bluetooth inquirable
//   Serial.println("The slave bluetooth is inquirable!");
//   delay(2000); // This delay is required.
//   blueToothSerial.flush();
// }

void moveForward()
{
  Serial.println("FORWARD");
  digitalWrite(lM1, HIGH);
  digitalWrite(lM2, LOW);
  digitalWrite(rM1, HIGH);
  digitalWrite(rM2, LOW);
  digitalWrite(lPWM, HIGH);
  digitalWrite(rPWM, LOW);
}
void moveBackward()
{
  Serial.println("BACKWARD");
  digitalWrite(lM1, LOW);
  digitalWrite(lM2, HIGH);
  digitalWrite(rM1, LOW);
  digitalWrite(rM2, HIGH);
}
void spotLeft()
{
  Serial.println("SPOTRIGHT");
  digitalWrite(lM1, HIGH);
  digitalWrite(lM2, LOW);
  digitalWrite(rM1, LOW);
  digitalWrite(rM2, HIGH);

}
void spotRight()
{
  Serial.println("SPOTLEFT");
  digitalWrite(lM1, LOW);
  digitalWrite(lM2, HIGH);
  digitalWrite(rM1, HIGH);
  digitalWrite(rM2, LOW);
}
void arcFRight()
{
  Serial.println("ARCRIGHT");
  digitalWrite(lM1, HIGH);
  digitalWrite(lM2, LOW);
  digitalWrite(rM1, LOW);
  digitalWrite(rM2, LOW);
}
void arcFLeft()
{
  Serial.println("ARCLEFT");
  digitalWrite(lM1, LOW);
  digitalWrite(lM2, LOW);
  digitalWrite(rM1, HIGH);
  digitalWrite(rM2, LOW);
}
void arcBRight()
{
  digitalWrite(lM1, LOW);
  digitalWrite(lM2, HIGH);
  digitalWrite(rM1, LOW);
  digitalWrite(rM2, LOW);
}
void arcBLeft()
{
  digitalWrite(lM1, LOW);
  digitalWrite(lM2, LOW);
  digitalWrite(rM1, LOW);
  digitalWrite(rM2, HIGH);
}

void Stop()
{
  digitalWrite(lM1, LOW);
  digitalWrite(lM2, LOW);
  digitalWrite(rM1, LOW);
  digitalWrite(rM2, LOW);
 
}

