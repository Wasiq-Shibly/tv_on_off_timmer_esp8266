void check_time()
{
timeClient.update();

  
 /* String formattedTime = timeClient.getFormattedTime();
  Serial.print("Formatted Time: ");
  Serial.println(formattedTime);  
  */

  
 currentHour = timeClient.getHours();
 Serial.print("Hour: ");
 Serial.println(currentHour);  


currentMinute = timeClient.getMinutes();
Serial.print("Minutes: ");
Serial.println(currentMinute); 

delay(2000);
  

  
}
