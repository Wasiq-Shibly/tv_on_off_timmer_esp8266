void database()
{
  if(Firebase.getInt(fbdo, "/BAR_100920_294562129482664344_1599721915/hh/"))
{
  //Success
  Serial.print("Get int data success, int = ");
   hh=fbdo.intData();
  Serial.println(hh);

}else{
  //Failed?, get the error reason from fbdo

  Serial.print("Error in getInt, ");
  Serial.println(fbdo.errorReason());
}




  if(Firebase.getInt(fbdo, "/BAR_100920_294562129482664344_1599721915/mm/"))
{
  //Success
  Serial.print("Get int data success, int = ");
   mm=fbdo.intData();
  Serial.println(mm);

}else{
  //Failed?, get the error reason from fbdo

  Serial.print("Error in getInt, ");
  Serial.println(fbdo.errorReason());
}



  
}
