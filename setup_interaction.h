#define PINLEDWIFI D6
#define PINLEDSTATUS D7
#define PINBUTTON D8

void onLedWifi()
{
  pinMode(PINLEDWIFI, OUTPUT);
  digitalWrite(PINLEDWIFI, HIGH);
}

void offLedWifi()
{
  pinMode(PINLEDWIFI, OUTPUT);
  digitalWrite(PINLEDWIFI, LOW);
}

void onLedStatus()
{
  pinMode(PINLEDSTATUS, OUTPUT);
  digitalWrite(PINLEDSTATUS, HIGH);
}

void offLedStatus()
{
  pinMode(PINLEDSTATUS, OUTPUT);
  digitalWrite(PINLEDSTATUS, LOW);
}

bool buttonStatus()
{

  pinMode(PINBUTTON, INPUT);

  if (digitalRead(PINBUTTON) == HIGH) {
    return true;
  } else {
    return false;
  }


}
