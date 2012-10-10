/*const int dataLength = 6;          // number of bytes to request
static byte rawData[dataLength];   // array to store nunchuck data

enum nunchuckItems { 
  joyX, joyY, accelX, accelY, accelZ, btnZ, btnC
};
*/

void nunchuckInit(){
  Wire.begin();                // join i2c bus as master
  Wire.beginTransmission(0x52);// transmit to device 0x52
  Wire.write((byte)0x40);      // sends memory address
  Wire.write((byte)0x00);      // sends sent a zero.  
  Wire.endTransmission();      // stop transmitting
}

// Send a request for data to the nunchuck
static void nunchuckRequest(){
  Wire.beginTransmission(0x52);// transmit to device 0x52
  Wire.write((byte)0x00);      // sends one byte
  Wire.endTransmission();      // stop transmitting
}

// Receive data back from the nunchuck, 
// returns true if read successful, else false
boolean nunchuckRead(){
  int cnt=0;
  Wire.requestFrom (0x52, dataLength); // request data from nunchuck
  while (Wire.available ()) {
    rawData[cnt] = nunchuckDecode(Wire.read());
    cnt++;
  }
  nunchuckRequest();  // send request for next data payload
  if (cnt >= dataLength) 
    return true;     // success if all 6 bytes received
  else
    return false;    //failure
}

// Encode data to format that most wiimote drivers except
static char nunchuckDecode (byte x) {
  return (x ^ 0x17) + 0x17;
}

int getValue(int item){
  if (item <= accelZ)
    return (int)rawData[item]; 
  else if (item  == btnZ) 
    return bitRead(rawData[5], 0) ? 0: 1;
  else if (item  == btnC) 
    return bitRead(rawData[5], 1) ? 0: 1;    
}

