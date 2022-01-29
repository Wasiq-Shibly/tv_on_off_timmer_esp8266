void run_app()
{
  
  Serial.println("run app");
  Serial.println("changing");

  results.value = 0x40BEB24D;

  for (int i = 0; i < 6; i++)

  {
    irsend.send(NEC, results.value, 32);
    delay(200);
  }

  delay(1000);

  results.value = 0x40BE52AD;

  Serial.println("ok button is pressed ");

  for (int i = 0; i < 6; i++)

  {
    irsend.send(NEC, results.value, 32);
    delay(200);
  }


  Serial.println("run complete");
 

delay(1000);
  
}
