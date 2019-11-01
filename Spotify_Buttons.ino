/* Spotify Buttons
 * Creator: M. Lemcke
 * Description: Play, pause, and skip tracks with three buttons.
 * Last Modified: 2019-06-20
 * Note: Use Spotify_Buttons.py with this sketch
 */
const int leftButtonPin = 2;
const int centreButtonPin = 4;
const int rightButtonPin = 7;

int leftButtonState = 0;
int centreButtonState = 0;
int rightButtonState = 0;

int prevLeftButtonState = 0;
int prevCentreButtonState = 0;
int prevRightButtonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(leftButtonPin, INPUT);
  pinMode(centreButtonPin, INPUT);
  pinMode(rightButtonPin, INPUT);
}

void loop() {
  leftButtonState = digitalRead(leftButtonPin);
  centreButtonState = digitalRead(centreButtonPin);
  rightButtonState = digitalRead(rightButtonPin);

  if((centreButtonState != prevCentreButtonState)&&(centreButtonState == LOW)){
    Serial.println("pause");
    delay(30);
  }
  else if((rightButtonState != prevRightButtonState)&&(rightButtonState == LOW)){
    Serial.println("skip");
    delay(30);
  }
  else if((leftButtonState != prevLeftButtonState)&&(leftButtonState == LOW)){
    Serial.println("previous");
    delay(30);
  }
  
  prevLeftButtonState = leftButtonState;
  prevCentreButtonState = centreButtonState;
  prevRightButtonState = rightButtonState;

}
