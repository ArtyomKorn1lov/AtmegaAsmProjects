extern "C"
{
  void onSetup();
  void onLoop();
}

void setup()
{
  onSetup();
}

void loop()
{
  onLoop();
}