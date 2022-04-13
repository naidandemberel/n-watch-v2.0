void setRTC()
{
  digitalWrite(backLight,LOW);
  val = SerialBT.readString();
  char buf[val.length() + 1];
  val.toCharArray(buf,val.length() + 1);
  sscanf(buf,"%d,%d,%d,%d,%d,%d", &tim[0], &tim[1], &tim[2], &tim[3], &tim[4], &tim[5]);
  rtc.setTime(tim[0],tim[1],tim[2],tim[3],tim[4],tim[5]);
  Serial.println("timeseted");
  timeseted = true;
}
