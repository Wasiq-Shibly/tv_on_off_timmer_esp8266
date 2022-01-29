void tv_on()
{



  results.value = 0x40BE629D;

  for (int i = 0; i < 5; i++)

  {
    irsend.send(NEC, results.value, 32);
    delay(10);
  }



  Serial.println("tv is onnn delay end ");
  delay(50000);



  
}
